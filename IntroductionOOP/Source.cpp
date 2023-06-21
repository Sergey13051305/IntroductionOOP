#include <iostream>
using namespace std;

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
	double distance(Point other)
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

double distance(Point A, Point B)
{
	//pow(base, exponent
	//base - Основание степени
	//exponent - Показатель степени
	//return pow(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2),.5);
	//return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_x() - B.get_x();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;

}
Point A;

//#define struct_point
//#define DISTANCE_CHECK

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

	cout << "Расстояние от точки 'A' до точки 'B': \t" << A.distance(B) << endl;
	cout << "Расстояние от точки 'B' до точки 'A': \t" << B.distance(A) << endl;

	cout << "Расстояние между точками 'A' и 'B': \t " << distance(A, B)<< endl;
	cout << "Расстояние между точками 'B' и 'A': \t " << distance(B, A)<< endl;
#endif DISTANCE_CHECK

	/*for (int i; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << i << endl;
	cout << endl;*/

	Point A; // Default constructor он должен выделяяет память под объект
	A.print();
}