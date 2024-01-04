// 2���� ���� ��� ������ ������ Calculato �߻� Ŭ���� �ۼ�, ��ӹ޴� Adder, Subtract, Multiply, Divide Ŭ����
#include <iostream>
using namespace std;

class Calculator {
protected:
    int a, b;
public:
    Calculator(int x, int y) : a(x), b(y) {}
    virtual int calculate() = 0; 
};

class Adder : public Calculator {
public:
    Adder(int x, int y) : Calculator(x, y) {}
    int calculate() { return a + b; }
};

class Subtract : public Calculator {
public:
    Subtract(int x, int y) : Calculator(x, y) {}
    int calculate() { return a - b; }
};

class Multiply : public Calculator {
public:
    Multiply(int x, int y) : Calculator(x, y) {}
    int calculate() { return a * b; }
};

class Divide : public Calculator {
public:
    Divide(int x, int y) : Calculator(x, y) {}
    int calculate() { return a / b; } 
};

int main() {
    int n1, n2;
    cin >> n1 >> n2;
    Adder adder(n1, n2);
    Subtract subtract(n1, n2);
    Multiply multiply(n1, n2);
    Divide divide(n1, n2);

    
    cout << "Add: " << adder.calculate() << std::endl;
    cout << "Subtract: " << subtract.calculate() << std::endl;
    cout << "Multiply: " << multiply.calculate() << std::endl;
    cout << "Divide: " << divide.calculate() << std::endl;

    return 0;
}
