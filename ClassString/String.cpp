#include"String.h"

//------------------------------------------------------------------------//

/////////////////////////////////////////////////////////////////////////////
////////////////	CLASS DEFINITION - ����������� ������	/////////////////
////////////////////////////////////////////////////////////////////////////
int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
void String::set_str(char* str)
{
	this->str = str;
}
//				Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "Def1aConstruct:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//this->size = other.size;
	//CopyConstrutor ������ ��������� DeepCopy (��������� �����������),
	//�.�., �������� ����� ������, � ����������� � ��� ���������� ������� �������
	//this->str = new char[size] {};
	/*for (int i = 0; i < size; i++)
	{
	this->str[i] = other.str[i];
	}*/
	//---------------------------------------------------------------------------
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//MoveConstructor ��������� ShallowCopy (������������ �����������)
	//this->size = other.size;
	//this->str = other.str; //�������� ����� ������, ������������� ������� �������
	other.size = 0;
	other.str = nullptr; //�������� ����� ������ � ������ �������, ����� ��� ������ �� ������ ����������
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//Global scope - ���������� ������������ ����
//				Operators:
String& String::operator=(const String& other)
{
	/*int a = 2;
	int b = 3;
	a = b;*/
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	*this = *this + other;
	return *this;
}
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//				Methods:
void String::print()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	//����� ������ �������� ��������������
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	//������ ������ �������� �� ��������� ������ �� ������ ����� ������ 
	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	return is >> obj.get_str();
}

/////////////////////////////////////////////////////////////////////////////
////////////////	CLASS DEFINITION END - ����� ����������� ������	/////////
////////////////////////////////////////////////////////////////////////////
