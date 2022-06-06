#include"Fraction.h"


int Fraction::get_integer() const
{
	return integer;
}
int Fraction::get_numerator() const
{
	return numerator;
}
int Fraction::get_denominator() const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0) denominator = 1;
	this->denominator = denominator;
}
//Constructors
Fraction::Fraction(int integer, int numerator, int denominator):integer(integer), numerator(numerator), denominator(denominator)
{
	/*this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);*/
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction():integer(0), numerator(0), denominator(1)
{
	/*this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;*/
	cout << "DefaultConstructor:\t" << this << endl;
}
Fraction::Fraction(int integer):integer(integer), numerator(0), denominator(1)
{
	//this->integer = integer;
	//this->numerator = 0;
	//this->denominator = 1;
	cout << "1argConstructor:\t\t" << this << endl;
}

Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	integer = decimal;
	decimal -= integer;
	denominator = 1e+9;
	numerator = decimal*denominator;
	reduce();
	cout << "ConstructorDBL:\t" << this << endl;
}
Fraction::Fraction(int numerator, int denominator):integer(0), numerator(numerator), denominator(denominator)
{
	//this->integer = 0;
	//this->numerator = numerator;
	//this->set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other):integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	//this->integer = other.integer;
	//this->numerator = other.numerator;
	//this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}

// Operators
Fraction& Fraction::operator=(const Fraction& other): integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	//this->integer = other.integer;
	//this->numerator = other.numerator;
	//this->denominator = other.denominator;
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator+= (Fraction right)
{
	this->to_improper();
	right.to_improper();
	this->numerator = this->numerator*right.denominator + right.numerator*this->denominator;
	this->denominator = this->denominator*right.denominator;
	return *this;
}
Fraction& Fraction::operator-= (Fraction right)
{
	this->to_improper();
	right.to_improper();
	this->numerator = this->numerator*right.denominator - right.numerator*this->denominator;
	this->denominator = this->denominator*right.denominator;
	return *this;
}
Fraction& Fraction::operator*=(Fraction right)
{
	this->to_improper();
	right.to_improper();
	this->numerator = this->numerator*right.numerator;
	this->denominator = this->denominator*right.denominator;
	return *this;
}
Fraction& Fraction::operator/=(Fraction right)
{
	this->to_improper();
	right.to_improper();
	this->numerator = this->numerator*right.denominator;
	this->denominator = this->denominator*right.numerator;
	return *this;
}
Fraction& Fraction:: operator++()
{
	integer++;
	return *this;
}
Fraction Fraction:: operator++ (int)
{
	Fraction old = *this;
	integer++;
	return old;
}
Fraction& Fraction:: operator--()
{
	integer--;
	return *this;
}
Fraction Fraction:: operator-- (int)
{
	Fraction old = *this;
	integer--;
	return old;
}
Fraction& Fraction:: operator()(int inteteger, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}
// Type-cast operators:
Fraction:: operator int()const
{
	return integer;
}
Fraction::operator double() const
{
	return integer + (double)numerator / denominator;
}
// Methods
Fraction& Fraction::to_proper()
{
	//переводит дробь в правильную (выделяет целую часть)
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
void Fraction::to_improper()
{
	//переводит дробь в неправильную (выделяет целую часть)
	numerator += integer*denominator;
	integer = 0;
}
void Fraction::print()const
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
Fraction Fraction:: inverted()const
{
	Fraction inverted = *this;
	inverted.to_improper();
	int buffer = inverted.numerator;
	inverted.numerator = inverted.denominator;
	inverted.denominator = buffer;
	return inverted;
}
Fraction& Fraction::reduce()
{
	int more, less, rest;
	if (numerator > denominator)
	{
		more = numerator;
		less = denominator;
	}
	else
	{
		less = numerator;
		more = denominator;
	}
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more; //GCD - Greatest Common Divisor (Наибольший общий делитель)
	if (GCD == 0)return *this;
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

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
istream& operator>>(istream& is, Fraction& obj)
{
	/*int integer = 0, numerator = 0, denominator = 0;
	is >> integer;
	is >> numerator;
	is >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;*/
	const int SIZE = 256;
	char buffer[SIZE] = {}; //Строка-это массив элементов char
							//cin >> buffer;
	cin.getline(buffer, SIZE);
	char delimiters[] = "()/ ";
	char* sz_numbers[3] = {}; //Массив строк, который будет хранить числа в строковом формате
							  //sz_-string zero (строка, заканчивающаяся нулем)
	int i = 0; //счетчик цикла
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		sz_numbers[i++] = pch;
	}
	obj = Fraction(); //Обнуляем объект (сбрасываем его в объект по умолчанию)
	switch (i)
	{
	case 1: obj.set_integer(atoi(sz_numbers[0])); break;
		//atoi() - ASCII-string to integer (преобразует строку в число)
	case 2:
		obj.set_numerator(atoi(sz_numbers[0]));
		obj.set_denominator(atoi(sz_numbers[1]));
		break;
	case 3:
		obj.set_integer(atoi(sz_numbers[0]));
		obj.set_numerator(atoi(sz_numbers[1]));
		obj.set_denominator(atoi(sz_numbers[2]));
	}
	return is;
}