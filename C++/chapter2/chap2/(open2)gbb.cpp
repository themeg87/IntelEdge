#include <iostream>
using namespace std;

int main() {
	cout << "���� ���� �� ������ �մϴ�. ����, ����, �� �߿��� �Է��ϼ���." << endl;
	
	// �Է� �ޱ�
	char s[10];
	cout << "�ι̿�>>";
	cin >> s;

	char t[10];
	cout << "�ٸ���>>";
	cin >> t;

	// Ʋ�� �Է� ��󳻱�
	if(strcmp(s, "����") != 0 && strcmp(s, "����") != 0 && strcmp(s, "��") != 0) {
		cout << "�ι̿��� �Է��� Ʋ�Ƚ��ϴ�." << endl;
		return 0;
	}
	if(strcmp(t, "����") != 0 && strcmp(t, "����") != 0 && strcmp(t, "��") != 0) {
		cout << "�ٸ����� �Է��� Ʋ�Ƚ��ϴ�." << endl;
			return 0;
	}

	// ���� ����
	if(strcmp(s, "����") == 0 && strcmp(t, "��") == 0)
		cout << "�ι̿��� �̰���ϴ�." << endl;
	else if(strcmp(s, "����") == 0 && strcmp(t, "����") == 0)
		cout << "�ٸ����� �̰���ϴ�." << endl;
	else if(strcmp(s, "����") == 0 && strcmp(t, "����") == 0)
		cout << "�ι̿��� �̰���ϴ�." << endl;
	else if(strcmp(s, "����") == 0 && strcmp(t, "��") == 0)
		cout << "�ٸ����� �̰���ϴ�." << endl;
	else if(strcmp(s, "��") == 0 && strcmp(t, "����") == 0)
		cout << "�ι̿��� �̰���ϴ�." << endl;
	else if(strcmp(s, "��") == 0 && strcmp(t, "����") == 0)
		cout << "�ٸ����� �̰���ϴ�." << endl;
	else 
		cout << "�����ϴ�." << endl;
}