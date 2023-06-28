#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n----------------------------------------------------------\n";
class Point
{
private:
	double x;
	double y;
public:
	double get_x(void)const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	// Constructor
	/*Point()
	{
		x = y = double(); //type() - Значение по умолчанию для заданного типа 
						  //Таким образом якобы вызываем конструктор по умолчанию для заданного типа
		cout << "DefaultConstructor:\t" << this << endl;
	}
	// Distructor
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1argConstructor:\t" << this << endl;

	}*/
	Point(double x=0, double y=0)
	{
		this->x=x;
		this->y=y;
		cout << "Constructor:\t\t" << this << endl;

	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point ()
	{
		cout << "Distructor:\t\t" << this << endl;
	}
	//	Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment\t\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}
	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this; // сохраняем исходное значение объекта
		x++;
		y++;
		return old;
	}
	//  Methods
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
	
};
ostream& operator <<(ostream& os, const Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}

double distance(const Point& A,const Point& B)
{
	//pow(base, exponent
	//base - Основание степени
	//exponent - Показатель степени
	//return pow(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2),.5);
	//return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;

}

Point operator+(const Point& left, const Point& right)
{
	/*Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());*/
	//Point result
	//(
	//	left.get_x() + right.get_x(), 
	//	left.get_y() + right.get_y()
	//);
	//return result;
	return Point
		(
			left.get_x() + right.get_x(),
			left.get_y() + right.get_y()
		);
}

//Point A;

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define constructors_check
//#define ASSIGMENT_CHECK
//#define INCREMENT_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCKT_POINT


	int a;	  // Объявления переменной типа int
	Point A;  // Объявление переменной А типа Point
			  //создание объекта А структцры Point
			  //создание экземпляра структуры Point
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // struckt_point
#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << "A: \t" << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << "B: \t" << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter;

	cout << "Расстояние от точки 'A' до точки 'B': \t" << A.distance(B) << endl;
	cout << delimiter;
	cout << "Расстояние от точки 'B' до точки 'A': \t" << B.distance(A) << endl;
	cout << delimiter;
	cout << "Расстояние между точками 'A' и 'B': \t " << distance(A, B)<< endl;
	cout << delimiter;
	cout << "Расстояние между точками 'B' и 'A': \t " << distance(B, A)<< endl;
	cout << delimiter;
#endif DISTANCE_CHECK

	/*for (int i; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << i << endl;
	cout << endl;*/
#ifdef CONSTRUCTORS_CHECK
	cout << double() << endl;

	Point A; // Default constructor он должен выделяяет память под объект
	A.print();
	Point B = 5; // Single-argument constructor
	B.print();
	Point C(2, 3);
	C.print();

	Point D = C; //
	D.print();

	Point E; // Copy
	E = D;
	E.print();


#endif CONSTRUCTORS_CHECK

#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;
	Point A, B, C;
	A = B = C=Point(2,3);
	A.print();
	B.print();
	C.print();
#endif 
#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << "A: \t" << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << "B: \t" << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter;

	cout << "Расстояние от точки 'A' до точки 'B': \t" << A.distance(B) << endl;
	cout << delimiter;
	cout << "Расстояние от точки 'B' до точки 'A': \t" << B.distance(A) << endl;
	cout << delimiter;
	cout << "Расстояние между точками 'A' и 'B': \t " << distance(A, B)<< endl;
	cout << delimiter;
	cout << "Расстояние между точками 'B' и 'A': \t " << distance(B, A)<< endl;
	cout << delimiter;
#endif

#ifdef INCREMENT_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.print();

	A = B++;
	A.print();
	B.print();
#endif
	Point A(2, 3);
	A.print();
	Point B(7, 8);
	B.print();

	A += B;
	//A.print();
	cout << A << endl;
}