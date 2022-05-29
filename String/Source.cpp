#include<iostream>
using namespace std;

#define delimiter "\n------------------------------------------\n"

class String
{
	int size; //размер строки
	char* str;//указатель 
public:
	int get_size()const
	{
		return size;
	}
	char* get_str()const
	{
		return str;
	}
	void set_size(int size)
	{
		if (size>0)
		this->size = size;
	}
	void set_str(char* str)
	{
		this->str = str;
	}
	//Constructors
	String(int size = 80)
	{
		this->size = size;
		this ->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t\t" << this << endl;
	}
	void print()
	{
		cout << size << endl;
		cout << str << endl;
	}
};


void main()
{
	setlocale(LC_ALL, "");
	String str1;
	str1.print();
}