#pragma once
#include <iostream>

using namespace std;

class String {
private:
	int len = 0;
	char* str;
public:

	String(const char* str) {//конструктор с параметром-строкой 
		len = strlen(str) + 1;
		this->str = new char[len];
			for (int i = 0; i < len; i++) {
			this->str[i] = str[i];
		}
	};

	String(int len) : len{ len } {//конструктор с параметром длина строки
		str = new char[len];
	};

	String(const String& obj) {//конструктор копирования
		this->len = obj.len;
		this->str = new char[len] {};
		for (int i = 0; i < len; i++) {
			this->str[i] = obj.str[i];
		}
	};

	String& operator = (const String& obj) {//оператор присваивания
		this->len = obj.len;
		if (this->str != nullptr) delete[] this->str;
		this->str = new char[len] {};
		for (int i = 0; i < len; i++) {
			this->str[i] = obj.str[i];
		}
		return *this;
	}

	void operator = (const char* str) {//перегрузка оператора присваивания
		len = strlen(str) + 1;
		if (this->str != nullptr) delete[] this->str;
		this->str = new char[len];
		for (int i = 0; i < len; i++) {
			this->str[i] = str[i];
		}
	}

	void set_str(const char* str) {
		len = strlen(str) + 1;
		if (this->str != nullptr) delete[] this->str;
		this->str = new char[len];
		for (int i = 0; i < len; i++) {
			this->str[i] = str[i];
		}
	}

	void print() {//вывод строки
		cout << str << endl;
	}

	int size()//вывод размера строки
	{
		return len;
	}

	~String() {//деструктор
		delete[] str;
	}
}; 