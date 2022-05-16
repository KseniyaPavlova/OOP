//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------------------\n"
class Point
{
	double x;
	double y;
public:
	double get_x()const
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

	//			Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Single argument constructor:\t" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//			Operators:
	Point operator =(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	//			Methods
	double distance(const Point& other)
	{
		//this (эта точка) - точка, для которой вызвался метод 
		//       (от которой нужно найти расстояние)
		//other (другая точка) - точка, до которой нужно найти расстояние
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance + y_distance*y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY =" << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	//A.set_x(-10);
	double distance = sqrt(x_distance*x_distance + y_distance*y_distance);
	return distance;
}
	

//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK_1
#define ASSIGNMENT_CHECK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	Point A; //Объявление переменной 'А' типа 'Point'
//Объявление объекта 'А' структуры 'Point'
//Создание экземпляра 'А' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A; // объявляем указатель на Point и берем адрес точки 'А'
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками A и В: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE
	 
#ifdef CONSTRUCTORS_CHECK
	int a(2);
	cout << a << endl;

	Point A;
	//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;  //Single Aegument Constructor
	B.print();

	Point C(8); //Single Aegument Constructor
	C.print();

	Point D(2, 3);
	D.print();

	Point E = D; //Copy constructor
	E.print();

	Point F(D); //Copy constructor
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK_1
	//CopyAssignment
	Point A(2, 3);
	Point B = A; //CopyConstructor потому что объект 'B' создается 
	Point C; // Default Constructor
	C = B; //Copy Assignment потому что объект 'C' уже существует  
#endif // ASSIGNMENT_CHECK_1

	int a, b, c;
		a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
}