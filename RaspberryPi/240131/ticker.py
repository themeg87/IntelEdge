import pandas as pd
import numpy as np
import yfinance as yf
import matplotlib.pyplot as plt

# 환율 반영 없이 KRW를 USD로 가정하고 계산하는 단순화된 예제입니다.
# 실제 구현 시 환율 정보를 적용해야 할 수 있습니다.

# 데이터 로드 함수
def fetch_data(symbol, period="1y", interval="1d"):
    return yf.download(symbol, period=period, interval=interval)

# 스토캐스틱 지표 계산 함수
def stochastic_oscillator(df, k_window=14, d_window=3):
    low_min = df['Low'].rolling(window=k_window).min()
    high_max = df['High'].rolling(window=k_window).max()
    df['%K'] = (df['Close'] - low_min) * 100 / (high_max - low_min)
    df['%D'] = df['%K'].rolling(window=d_window).mean()
    return df

# 매수, 매도 신호 생성 함수
def generate_signals(df, upper_threshold=80, lower_threshold=20):
    df['Signal'] = 0
    df['Signal'][df['%K'] > upper_threshold] = -1  # 매도 신호
    df['Signal'][df['%K'] < lower_threshold] = 1   # 매수 신호
    return df

# 거래 수수료 적용 함수
def apply_fee(price, amount, fee_rate=0.0005):
    fee = price * amount * fee_rate
    return fee

# 모의 투자 실행 함수
def simulate_trading(df, initial_krw=1000000):
    balance = initial_krw
    position = 0
    for index, row in df.iterrows():
        if row['Signal'] == 1 and balance >= row['Close']:  # 매수 조건
            fee = apply_fee(row['Close'], balance / row['Close'])
            position = (balance - fee) / row['Close']
            balance = 0
            print(f"{index.date()} - Bought: {position:.4f} BTC at {row['Close']}, Fee: {fee:.0f} KRW")
        elif row['Signal'] == -1 and position > 0:  # 매도 조건
            fee = apply_fee(row['Close'], position)
            balance = position * row['Close'] - fee
            print(f"{index.date()} - Sold: {position:.4f} BTC at {row['Close']}, Fee: {fee:.0f} KRW, Profit: {balance - initial_krw:.0f} KRW")
            position = 0
    # 마지막 포지션이 있을 경우 마감 처리
    if position > 0:
        fee = apply_fee(row['Close'], position)
        balance = position * row['Close'] - fee
        print(f"Final Sell: {position:.4f} BTC at {row['Close']}, Fee: {fee:.0f} KRW, Profit: {balance - initial_krw:.0f} KRW")
    return balance

# 데이터 로딩
df = fetch_data('BTC-USD', period="1y")

# 스토캐스틱 지표 계산
df = stochastic_oscillator(df)

# 신호 생성
df = generate_signals(df)

# 모의 투자 실행
final_balance = simulate_trading(df)
print(f"Final balance: {final_balance:.0f} KRW")
