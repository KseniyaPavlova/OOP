#include<iostream>
#include"Fraction.h"   

//#define CONSTRUCTORS_CHECK
//#define COMPARISON_OPERATOR_CHEK
//#define OSTREAM_OPERATOR_CHEK
//#define TYPE_CONVERSION_BASE
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSIONS_FROM_CLASS_TO_OTHER

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

#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER
	Fraction A = Fraction(2, 3, 4);
	int a = A;
	cout << a << endl;
	double b = A;
	cout << b << endl;

	Fraction A = (1, 2, 3);
	A.reduce();
	cout << A << endl;
#endif // CONVERSIONS_FROM_CLASS_TO_OTHER


	Fraction A = 2.76;
	cout << "Введите простую дробь: "; cin >> A;
	cout << A << endl;

	//A.set_integer(123);
	//A.set_numerator(55);
	//A.set_denominator(77);
	A(123, 55, 77);
	cout << A << endl;
}

	