#define _CRT_SECURE_NO_WARNINGS//비주얼 스튜디오에서 scanf로 인한 오류를 막기 위한 선언문
#include <stdio.h>
int sum(); // 함수 원형 선언

int main_C() {
	int n=0;
	printf("끝 수를 입력하세요>");
	scanf("%d", &n);
	printf("1에서 %d까지의 합은 %d 입니다.\n", n, sum(1, n));
	return 0;
}

int sum(int a, int b) {
	int k, res=0;
	for(k=a; k<=b; k++) {
		res += k;
	}
	return res;
}