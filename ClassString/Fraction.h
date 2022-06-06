#pragma once
#include<iostream>
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
	int get_numerator() const;
	int get_denominator() const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	//Constructors
	Fraction(int integer, int numerator, int denominator);
	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	// Operators
	Fraction& operator=(const Fraction& other);
	Fraction& operator+= (Fraction right);
	Fraction& operator-= (Fraction right);
	Fraction& operator*=(Fraction right);
	Fraction& operator/=(Fraction right);
	Fraction& operator++();
	Fraction operator++ (int);
	Fraction& operator--();
	Fraction operator-- (int);
	Fraction& operator()(int inteteger, int numerator, int denominator);
	// Type-cast operators:
	explicit operator int()const;
	operator double() const;
	// Methods
	Fraction& to_proper();
	void to_improper();
	void print()const;
	Fraction inverted()const;
	Fraction& reduce();
};
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);
Fraction operator*(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator<=(Fraction left, Fraction right);
bool operator>=(Fraction left, Fraction right);
bool operator==(Fraction left, Fraction right);
bool operator!=(Fraction left, Fraction right);

ostream& operator<<(ostream& os, const Fraction& obj);
istream& operator>>(istream& is, Fraction& obj);