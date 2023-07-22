#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;
#define delimiter "\n-------------------------------------------------\n"
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, Fraction& right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(const Fraction left, const Fraction right);

class Fraction
{
	int numerator;	  //Числитель
	int denominator;  //Знаменатель
	int integer;	  //Целая часть
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	int set_denominator(int denominator)
	{
		if (denominator == 0)denominator == 1;
		this->denominator = denominator;
		return this->denominator;
	}

	//            Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9; //точность всегда будет 9 знаков после запятой
		numerator = decimal * denominator;
		reduce();
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator):
		integer(integer), 
		numerator(numerator),
		denominator(set_denominator(denominator))
	{
		/*this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);*/
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructuor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "destructor:\t" << this << endl;
	}
	//				Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}

	//				Type-cast operators
	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		return integer+(double)numerator / denominator;
	}
	//              Methods
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		/*int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;*/
		to_proper();
		int less = numerator;
		int more = denominator;
		int rest;
		if (less == 0)return *this;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; // GCD - Greatest Common Divisor (Наибольший общий делитель)
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	void print()const
	{
		if (integer)cout << integer;  //Если есть дробная часть, выводим ее на экран
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, Fraction& right)
{
	return left * right.inverted();
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	int a = left.get_denominator()* right.get_denominator();
	int b = left.get_numerator()* right.get_denominator() +
		right.get_numerator() * left.get_denominator();
	return Fraction(a, b);
}

Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
	left.get_denominator()* right.get_denominator(),
	left.get_numerator() * right.get_denominator() -
		right.get_numerator() * left.get_denominator()
	).to_proper().reduce();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator != (const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	//return left < right || left == right;
	return !(left > right);
}

std::ostream& operator << (std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();  //Если есть дробная часть, выводим ее на экран
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator >> (std::istream& is, Fraction& obj)
{
	/*
	-----------------------------------
	5
	1/2
	2 3/4
	2(3/4)
	------------------------------------
	*/
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is.getline(buffer, SIZE);
	is >> buffer;
	int number[3] = {};
	int n = 0; //Счетчик чисел
	char delimeters[] = "()/";
	for (char* pch = strtok(buffer, delimeters); pch; pch = strtok(NULL, delimeters))
		number[n++] = std::atoi(pch);
	//atoi() - ASCII -string to 'int', принимает строку, и возвращает целое число, которое содержится в этой строке.
		//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	switch (n)
	{
	case 1:obj.set_integer(number[0]); break;
	case 2:obj = Fraction(number[0], number[1]);
		obj.set_denominator(number[1]);
		break;
	case 3: obj = Fraction(number[0], number[1], number[2]);
	}
	return is;
}
//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATOR_CHECK
//#define INPUT_CHECK_1
//#define INPUT_CHECK_2
//#define TYPE_CONVERSION_BASIC
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_OTHER_TO_CLASS
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; // По умолчанию
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C; //CopyConstructuor
	E.print();

	Fraction F;
	F = D;
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(3, 1, 5);
	A.print();
	cout << delimiter << endl;
	Fraction B(4, 2, 3);
	B.print();
	cout << delimiter << endl;
	Fraction E = A + B;
	E.print();
	cout << delimiter << endl;
	Fraction C = A - B;
	C.print();
	/*Fraction C = A * B;
	C.print();
	cout << delimiter <<endl;
	Fraction D = A / B;
	D.print();
	cout << delimiter <<endl;*/
	//cout << delimiter <<endl;
	//A *= B;
	//A.print();
	//cout << delimiter <<endl;

#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATOR_CHECK
	Fraction A(1, 2);
	Fraction B(5, 10);
	cout << (A <= B) << endl;
#endif // COMPARISON_OPERATOR_CHECK

#ifdef INPUT_CHECK_1
	Fraction A(5, 10);
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;

	A.reduce();
	cout << A << endl;
#endif

#ifdef INPUT_CHECK_2
	Fraction A, B, C;
	cout << "Введите три простые дроби: "; cin >> A >> B >> C;
	cout << A << "\t" << B << "\t" << C << endl;
#endif
#ifdef TYPE_CONVERSION_BASIC
	//(type)value; //C-like notation (C-поджобная форма записи 
	//или же значение написать в круглх скобках, после желаемого типа данныхх)
	//type (value); //Functional notation (Функциональная форма записи)
	int a = 2;      //No conversion 
	double b = 3;   //Conversion from less to more
	int c = b;      //Conversion from  more to less without data loss
	int d = 5.7;    //Conversion from more to less with data loss
	//int e = "Hello";//Types not compatible
	cout << 7. / 2 << endl; //Implict converssion from less to more
#endif

#ifdef  CONVERSIONS_FROM_OTHER_TO_CLASS
	//1. From other to classs
//2. From classs to other
	Fraction A = (Fraction)5; //Conversion from 'int' to Fraction
	//Conversion from other to classs
	//Single-argument constructor
	cout << A << endl;
	cout << delimiter << endl;
	Fraction B;		// Default constructor
	cout << delimiter << endl;
	B = Fraction(8);
	cout << delimiter << endl;
	cout << B << endl;

	//Fraction C = 12; // explicit constructor невозможно вызвать оператором присваивания
	//Fraction C(12);    // explicit constructor можно вызвать только так
	Fraction C{ 12 };    // Или так.
	cout << C << endl;
#endif //  CONVERSIONS_FROM_OTHER_TO_CLASS

	//				Type-cast oprators
	/*
	---------------------------------------
	operator type ()
	{
	//convrsion algorithm
	...................
	...................
	return value;
	}
	----------------------------------------
	*/

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A(2, 1, 2);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;

	Fraction B(2, 3, 4);
	cout << B << endl;
	double b = (double)B;
	cout << b << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

	Fraction A = 2.77;
	cout << A << endl;

	Fraction B = 3.333;
	cout << B << endl;

	Fraction C(2, 3, 4);
	cout << C << endl;
}