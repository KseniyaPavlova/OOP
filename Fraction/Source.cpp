﻿#include<iostream>
using namespace std;

#define delimiter "\n------------------------------------------\n"

class Fraction
{
	int integer;		//целое число
	int numerator;	//числитель
	int denominator;//знаменатель
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
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
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}
	//Constructors
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
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
		cout << "1argConstructor:\t\t" << this << endl;
	}
	Fraction(double buffer)
	{
		integer = buffer;
		buffer -= integer;
		numerator = buffer*100;
		denominator = 100;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator+= (Fraction right)
	{
		this->to_improper();
		right.to_improper();
		this->numerator = this->numerator*right.denominator + right.numerator*this->denominator;
		this->denominator = this->denominator*right.denominator;
		return *this;
	}
	Fraction& operator-= (Fraction right)
	{
		this->to_improper();
		right.to_improper();
		this->numerator = this->numerator*right.denominator - right.numerator*this->denominator;
		this->denominator = this->denominator*right.denominator;
		return *this;
	}
	Fraction& operator*=(Fraction right)
	{
		this->to_improper();
		right.to_improper();
		this->numerator = this->numerator*right.numerator;
		this->denominator = this->denominator*right.denominator;
		return *this;
	}
	Fraction& operator/=(Fraction right)
	{
		this->to_improper();
		right.to_improper();
		this->numerator = this->numerator*right.denominator;
		this->denominator = this->denominator*right.numerator;
		return *this;
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++ (int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator-- (int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	// Type-cast operators:
	explicit operator int()const
	{
		return integer;
	}
	operator double() const
	{
		return integer + (double)numerator / denominator;
	}
	// Methods
	void to_proper()
	{
		//переводит дробь в правильную (выделяет целую часть)
		integer += numerator / denominator;
		numerator %= denominator;
	}
	void to_improper()
	{
		//переводит дробь в неправильную (выделяет целую часть)
		numerator += integer*denominator;
		integer = 0;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
};
Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result
	(
		left.get_numerator()*right.get_denominator(),
		left.get_denominator()*right.get_numerator()
	);
	return result;
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result
	(
		left.get_numerator()*right.get_denominator() + right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result
	(
		left.get_numerator()*right.get_denominator() - right.get_numerator()*left.get_denominator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result;
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator()*right.get_denominator() < right.get_numerator()*left.get_denominator())
		return true;
	else return false;
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator()*right.get_denominator() > right.get_numerator()*left.get_denominator())
		return true;
	else return false;
}
bool operator<=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator()*right.get_denominator() <= right.get_numerator()*left.get_denominator())
		return true;
	else return false;
}
bool operator>=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator()*right.get_denominator() >= right.get_numerator()*left.get_denominator())
		return true;
	else return false;
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
		return true;
	else return false;
}
bool operator!=(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator()*right.get_denominator() != right.get_numerator()*left.get_denominator())
		return true;
	else return false;
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	return os;
}
istream& operator>>(istream& is, /*const*/ Fraction& obj)
{
	int integer = 0, numerator = 0, denominator = 0;
	//int OPERATOR [3] = {integer,numerator,denominator};
	is >> integer;
	is >> numerator;
	is >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;

}

//#define CONSTRUCTORS_CHECK
//#define COMPARISON_OPERATOR_CHEK
//#define OSTREAM_OPERATOR_CHEK
//#define TYPE_CONVERSION_BASE
//#define CONVERSION_FROM_OTHER_TO_CLASS

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C;
	E.print();

	A = D;
	A.print();
#endif // CONSTRUCTORS_CHECK

#ifdef COMPARISON_OPERATOR_CHEK
	Fraction A(2, 3, 4);
	Fraction B(9, 5);
	A.print();
	B.print();

	int a = 2;
	int b = 3;
	int c = a*b;

	Fraction C = A - B;
	C.print();

	Fraction D = A != B;
	D.print();

	cout << A << endl;
#endif // COMPARISON_OPERATOR_CHEK

#ifdef OSTREAM_OPERATOR_CHEK
	Fraction A;
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
#endif // OSTREAM_OPERATOR_CHEK

#ifdef TYPE_CONVERSION_BASE
	cout << typeid(7 / .2).name() << endl;
	int a = 2;   //No conversions
	double b = 3;//Conversion from less to more
	int c = b;	 //Conversion from more to less without data loss
	int d = 5.5; //Conversion from more to less with data loss  
#endif // TYPE_CONVERSION_BASE

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
			//Fraction A = 5;  //Conversion from int to Fraction
//cout << A << endl;
	Fraction B;
	cout << "\n---------------------------------------\n";
	B = (Fraction)8;
	cout << "\n---------------------------------------\n";
	cout << B << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

	//Fraction A = Fraction (2,3,4);
	//int a = A;
	//cout << a << endl;
	//double b = A;
	//cout << b << endl;

	Fraction A = 2.75;
	cout <<(double)A << endl;
}