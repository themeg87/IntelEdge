//BankAccount 클래스를 작성, 계좌번호 예금주,잔액 멤버 변수를 가지고, 
//출금, 입금 잔액 조회 기능을 수행하는 멤버 함수와 생성자,소멸자,setter, getter구현
#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string number;
    string holder;
    double balance;

public:
    BankAccount(const string& num, const string& name, double initialBalance)
        : number(num), holder(name), balance(initialBalance) {}

    void in(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "입금 완료: " << amount << "원을 계좌 " << number << "에 입금" << endl;
        }
    }

    bool out(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "출금 완료: " << amount << "원을 계좌 " << number << "에서 출금" << endl;
            return true;
        }
        cout << "계좌 " << number << "에서 출금 실패" << endl;
        return false;
    }

    double getBalance() const {
        return balance;
    }

    const string& getNumber() const {
        return number;
    }

    const string& getHolder() const {
        return holder;
    }

    ~BankAccount() {
        cout << number << " 계좌 해지" << endl;
    }
};

int main() {
    BankAccount account("123456", "홍길동", 1000);
    account.in(500);
    account.out(200);

    cout << "예금주: " << account.getHolder() << endl;
    cout << "계좌번호: " << account.getNumber() << endl;
    cout << "현재 잔액: " << account.getBalance() << "원" << endl;

    return 0;
}
