#pragma once
#include <iostream>

using namespace std;

class String {
private:
	int len = 0;
	char* str;
public:

	String(const char* str) {//����������� � ����������-������� 
		len = strlen(str) + 1;
		this->str = new char[len];
			for (int i = 0; i < len; i++) {
			this->str[i] = str[i];
		}
	};

	String(int len) : len{ len } {//����������� � ���������� ����� ������
		str = new char[len];
	};

	String(const String& obj) {//����������� �����������
		this->len = obj.len;
		this->str = new char[len] {};
		for (int i = 0; i < len; i++) {
			this->str[i] = obj.str[i];
		}
	};

	String& operator = (const String& obj) {//�������� ������������
		this->len = obj.len;
		if (this->str != nullptr) delete[] this->str;
		this->str = new char[len] {};
		for (int i = 0; i < len; i++) {
			this->str[i] = obj.str[i];
		}
		return *this;
	}

	void operator = (const char* str) {//���������� ��������� ������������
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

	void print() {//����� ������
		cout << str << endl;
	}

	int size()//����� ������� ������
	{
		return len;
	}

	~String() {//����������
		delete[] str;
	}
}; 