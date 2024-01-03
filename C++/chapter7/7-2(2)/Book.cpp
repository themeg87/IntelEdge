#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title="", int price=0, int pages=0) {
		this->title = title; this->price = price; 	this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " <<pages << " 페이지" << endl;
	}
	string getTitle() { return title; }
	friend bool operator ==(Book book, int price);
	friend bool operator ==(Book book, string title);
	friend bool operator ==(Book book1, Book book2);
};

bool operator ==(Book book, int price) {
	if(book.price == price) return true;
	else return false;
}

bool operator ==(Book book, string title) {
	if(book.title == title) return true;
	else return false;
}

bool operator ==(Book book1, Book book2) {
	if(book1.title == book2.title && 
		book1.price == book2.price && 
		book1.pages == book2.pages) return true;
	else return false;
}

int main() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if(a == 30000) cout << "정가 30000원" << endl; // price 비교
	if(a == "명품 C++") cout << "명품 C++ 입니다." << endl; // 책 title 비교
	if(a == b) cout << "두 책이 같은 책입니다." << endl; // title, price, pages 모두 비교 
}