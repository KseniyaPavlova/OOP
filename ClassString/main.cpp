#include<iostream>
using std::cin;
using std::cout;
using std::endl;
class String;
String operator+(const String& left, const String& right);
class String
{
	int size;	//Размерстроки в Байтах
	char* str;	//Указатель на строку
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	void set_str(char* str)
	{
		this->str = str;
	}
	//				Constructors:
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "Def1aConstruct:\t" << this << endl;
	}
	String(const char* str) :size(strlen(str) + 1), str(new char[size] {})
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other) :size(other.size), str(new char[size] {})
	{
		//this->size = other.size;
		//CopyConstrutor должен выполнять DeepCopy (Побитовое копирование),
		//т.е., выделить новую память, и скопировать в нее содержимое другого объекта
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		//---------------------------------------------------------------------------
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other) :size(other.size), str(other.str)
	{
		//MoveConstructor выполняет ShallowCopy (Поверхностое копирование)
		//this->size = other.size;
		//this->str = other.str; //Копируем адрес памяти, принадлежащей другому объекту
		other.size = 0;
		other.str = nullptr; //Зануляем адрес памяти в другом объекте, чтобы эту память НЕ удалил деструктор
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	String& operator=(const String& other)
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
	String& operator=(String&& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		*this = *this + other;
		return *this;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	//				Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	//Левую строку копируем соответственно
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	//Правую строку копируем со смещением вправо на размер левой строки 
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
//#define CONSTRUCTORS_CHECK
//#define MOVE_METHODS_CHECK
#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str1;	//Default constructor
	str1.print();

	String str2(5);	//explicit Single-argument constructor
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = str3;	//CopyConstructor
	str4.print();

	String str5;
	str5.print();
	str5 = str4;		//CopyAssignment
	str5.print();
#endif // CONSTRUCTORS_CHECK

#ifdef MOVE_METHODS_CHECK
	String str1 = "Hello";
	String str2("World");
	//String str3 = str1 + str2; //MoveConstructor
	String str3;
	str3 = str1 + str2;
	//String str3 = str1 + " " + str2;
	////str3.print();
	//cout << str3 << endl;

	/*str1 += str2;
	cout << str1 << endl;
	cout << "Введите строку: "; cin >> str1;
	cout << str1 << endl;*/
#endif // MOVE_METHODS_CHECK

#ifdef CALLING_CONSTRUCTORS
	String str1;			//Default constructor (Конструктор по-умолчанию)
	String str2(55);		//Single-argument constructor (int) (Конструктор с одним параметром)
	String str3 = "Hello";	//Single-argument constructor (const char*) (Конструктор с одним параметром)
	String str4 = str3;		//Copy constructor (Конструктор копирования)
	String str5;
	str5 = str4;	        //Copy assignment
	str5.print();
	String str6();			//Здесь НЕ вызывается никаких конструкторов, и следовательно НЕ создается объект
							//Здесь объявляется функция str6(), которая ничего не возвращет 
	String str7{};			//Явный вызов конструктора по умолчанию
	str7.print();
#endif // CALLING_CONSTRUCTORS

}