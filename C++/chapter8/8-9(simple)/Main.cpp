// �� ������Ʈ�� ������� �Է� ������ �ɷ����� �ʴ� �����Դϴ�.
// �׷��Ƿ� ����ڰ� �����Ͽ� �Է��Ͽ��� �մϴ�.
// �� ������ �����ϴ� ������ ���� �ҽ� ������ �ٿ��� ���ڵ��� �ҽ� �м��� ���� �ϱ� �����Դϴ�.

#include <string>
using namespace std;

#include "AirlineBook.h"

int main(){
	string sheduleTime[] = {"07��", "12��", "17��"};
	AirlineBook *p = new AirlineBook("�Ѽ��װ�", 3, sheduleTime);
	p->run();
	
	delete p;
}