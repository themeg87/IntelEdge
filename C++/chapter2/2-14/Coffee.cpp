#include <iostream>
#include <cstring>
using namespace std;

bool checkInputError() {
	if (cin.fail()) { // 정수대신 문자열이 입력되어 오류가 발생하는 경우 대처. 부록 C의 예제 C-1참고
		cin.clear();
		cin.ignore(100, '\n');
		cout << "입력 오류" << endl;
		return true; // 오류 있음
	}
	else
		return false; // 오류 없음
}

int main() {
	int totalSale = 0; // 현재까지 판매 총 금액
	int order; // 현재 주문한 금액
	char coffee[100]; // 주문한 커피 종류
	int num; // 잔 수
	cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;
	while (true) {
		cout << "주문>> ";
		cin >> coffee >> num;
		if (checkInputError()) continue; // num에 정수 외 다른 입력하였는지 검사

		// 입력이 정상적으로 이루어졌다면
		if (num <= 0) { // 잔 수를 양수가 아니게 입력한 경우
			cout << "잔 수는 양수를 입력해주세요" << endl;
			continue;
		}
		if (strcmp(coffee, "에스프레소") == 0) {
			order = 2000 * num;
		}
		else if (strcmp(coffee, "아메리카노") == 0) {
			order = 2300 * num;
		}
		else if (strcmp(coffee, "카푸치노") == 0) {
			order = 2500 * num;
		}
		else {
			order = 0;
		}

		// 사용자에게 주문한 가격 출력
		if (order > 0) { // 정상적인 주문의 경우
			cout << order << "원입니다. 맛있게 드세요" << endl;
		}
		else // 없는 커피 주문한 경우
			cout << "없는 커피입니다. 다시 입력해주세요" << endl;

		// 20000원이상 벌었는지 판단
		totalSale += order;
		if (totalSale > 20000) {
			cout << "오늘 " << totalSale << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~" << endl;
			break;
		}
	} // endl of while

}