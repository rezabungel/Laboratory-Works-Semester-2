// Zadanie 4 Svyatchenko Artem KTSO-03-20.cpp
//Практическая работа №4.Строки.
//Унаследуйте свой класс от базового класса «Строка». Реализуйте работу функций:
//конструкторов, конструктора копий, деструктора, operator=, как в базовом классе, так и в
//наследнике.Добавьте в наследник работу функции, указанной в варианте.

//Вариант 18. 
//Строку мысленно разбить на последовательности по 5 символов. Подсчитать
//количество пятерок символов, для которых среднее количество гласных
//больше среднего для всей строки.

#include <iostream>
using namespace std;

class BaseString
{
protected:
	char* text;
	int len;
public:
	BaseString()//Конструктор.
	{
		//		cout << "Base Constructor 1\n";
		text = nullptr;
		len = 0;
	}
	BaseString(const char* sms)//Конструктор.
	{
		//		cout << "Base Constructor 2\n";
		for (int i = 0;; i++)
		{
			if (sms[i] == '\0')
			{
				len = i;
				break;
			}
		}
		text = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			text[i] = sms[i];
		}
	}
	BaseString(const BaseString& copy)//Копирование.
	{
		//		cout << "Copy constructor\n";
		len = copy.len;
		text = new char[len + 1];
		for (int i = 0; i <= len; i++)
		{
			text[i] = copy.text[i];
		};
	}
	~BaseString()//Деструктор.
	{
		//		cout << "Base Destructor\n";
		if (text != nullptr)
		{
			delete[] text;
			text = nullptr;
		};
		len = 0;
	}
	int Length()//Метод, возвращающий количество символов. 
	{
		return len;
	}
	BaseString& operator=(BaseString& same)
	{
		//		cout << "Base Operator = \n";		
		if (this != &same)
		{
			if (text != nullptr)
			{
				delete[] text;
				text = nullptr;
			};
			len = same.Length();
			text = new char[len + 1];
			for (int i = 0; i <= len; i++)
			{
				text[i] = same.text[i];
			};
		};
		return *this;
	}
	void print()//Метод, который организует вывод информации в консоль.
	{
		cout << "Text=";
		int i = 0;
		while (text[i] != '\0')
		{
			cout << text[i];
			i++;
		};
		cout << "\t len = " << len << endl;
	}
};

class MYString : public BaseString
{
public:
	MYString() :BaseString() {}//Конструктор.
	MYString(const char* sms) :BaseString(sms) {}//Конструктор.
	MYString(const MYString& copy) :BaseString(copy) {}//Копирование.
	~MYString()//Деструктор.
	{
		//		cout << "Base Destructor\n";
		if (text != nullptr)
		{
			delete[] text;
			text = nullptr;
		};
		len = 0;
	}
	int work()//Функция
	{
		int result = 0;
		int count = 0; //Счетчик гласных букв в слове(фразе).
		if (text != nullptr)
		{
			int sred = 0;
			for (int i = 0; i < len; i++)
			{
				//Гласные буквы "A", "E", "I", "O", "U", "Y".
				if (text[i] == 65 || text[i] == 69 || text[i] == 73 || text[i] == 79 || text[i] == 85 || text[i] == 89 || text[i] == 97 || text[i] == 101 || text[i] == 105 || text[i] == 111 || text[i] == 117 || text[i] == 121)
				{
					count = count + 1;
				};
			};
			sred = len / count;
			int k = 0;
			count = 0;
			for (int i = 0; i < len; i++)
			{
				if (text[i] == 65 || text[i] == 69 || text[i] == 73 || text[i] == 79 || text[i] == 85 || text[i] == 89 || text[i] == 97 || text[i] == 101 || text[i] == 105 || text[i] == 111 || text[i] == 117 || text[i] == 121)
				{
					count = count + 1;
				};
				k = k + 1;
				if (k == 5)
				{
					if (count > sred)
					{
						result = result + 1;
					};
					k = 0;
					count = 0;
				};
			};
		};
		return result;
	}
};



int main()
{
	cout << "************************************************************************************\n";
	BaseString A;
	BaseString B("Hello");
	BaseString С("Goodbye");
	BaseString D(B);
	cout << "(Variable B) "; B.print();
	cout << "(Variable C) "; С.print();
	cout << "(Variable D (copy B)) "; D.print();
	cout << "Test operetor= (B = C)" << endl;
	B = С;
	cout << "(Variable B) "; B.print();
	int help = B.Length();
	cout << "Kol-vo simvolov = " << help << endl;

	cout << "************************************************************************************\n";
	MYString A1;
	MYString B1("Morning");
	MYString С1("Night");
	MYString D1(B1);
	cout << "(Variable B1) "; B1.print();
	cout << "(Variable C1) "; С1.print();
	cout << "(Variable D1 (copy B1)) "; D1.print();
	cout << "Test operetor= (B1 = C1)" << endl;
	B = С;
	cout << "(Variable B1) "; B1.print();
	int help1 = B1.Length();
	cout << "Kol-vo simvolov = " << help1 << endl;
	cout << "************************************************************************************\n";
	MYString Q("Easy come, easy go");
	int help2 = Q.work();
	cout << "(Variable Q) "; Q.print();
	cout << "The number of fives of characters for which the average is greater than the average for the entire line = " << help2 << endl;
	cout << "************************************************************************************\n";
}