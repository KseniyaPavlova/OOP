#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------------------\n"
class Fraction
{
	int number;		//целое число
	int numerator;	//числитель
	int denominator;//знаменатель
public:
	int get_number() const
	{
		return number;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	void set_number(int number)
	{
		this->number = number;
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
	Fraction()
	{
		this->number = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int number)
	{
		this->number = number;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1Constructor:\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->number = 0;
		this->numerator = numerator;
		this->denominator = denominator;
		cout << "2Constructor:\t\t" << this << endl;
	}
	Fraction(int number, int numerator, int denominator)
	{
		this->number = number;
		this->numerator = numerator;
		this->denominator = denominator;
		/*this->set_number(number);
		this->set_numerator(numerator);
		this->set_denominator(denominator);*/
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->number = other.number;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// Methods
	void print()const
	{
		if (number)cout << number;
		if (/*number && */numerator)cout << "(" << numerator << "/" << denominator << ")";
		if (number == 0 && numerator == 0)cout << 0;
		cout << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Fraction A;
	A.print();

	Fraction B(10);
	B.print();

	Fraction C(3, 4);
	C.print();

	Fraction D(5, 2, 3);
	D.print();

	Fraction E = A;
	E.print();
}