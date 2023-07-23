#pragma once
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define tab "\t"
#define delimiter "\t" "\n-------------------------------------------------\n"

//////////////////////////////////////////////////////////////////////
/////////////// Объявление класса - Class declaration ////////////////
class String
{
	int size;   //Размер сроки в Byte 
	char* str;  //Адресс строки в динамической памяти
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	//				Concstractors
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	//				Operators
	String& operator=(const String& other);
	String& operator = (String&& other);
	char operator [](int i)const;
	char& operator [](int i);
	//				Methods
	void print()const;
};
std::ostream& operator <<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);
/////////////// Объявление класса - Class declaration ////////////////
//////////////////////////////////////////////////////////////////////
