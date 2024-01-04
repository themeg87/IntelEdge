//BankAccount Ŭ������ �ۼ�, ���¹�ȣ ������,�ܾ� ��� ������ ������, 
//���, �Ա� �ܾ� ��ȸ ����� �����ϴ� ��� �Լ��� ������,�Ҹ���,setter, getter����
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
            cout << "�Ա� �Ϸ�: " << amount << "���� ���� " << number << "�� �Ա�" << endl;
        }
    }

    bool out(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "��� �Ϸ�: " << amount << "���� ���� " << number << "���� ���" << endl;
            return true;
        }
        cout << "���� " << number << "���� ��� ����" << endl;
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
        cout << number << " ���� ����" << endl;
    }
};

int main() {
    BankAccount account("123456", "ȫ�浿", 1000);
    account.in(500);
    account.out(200);

    cout << "������: " << account.getHolder() << endl;
    cout << "���¹�ȣ: " << account.getNumber() << endl;
    cout << "���� �ܾ�: " << account.getBalance() << "��" << endl;

    return 0;
}
