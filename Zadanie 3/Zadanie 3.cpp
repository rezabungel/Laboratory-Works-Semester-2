// Zadanie 3 Svyatchenko Artem KTSO-03-20.cpp
/*Практическая работа №3.Множественное наследование
Необходимо реализовать указанную схему наследования.В схеме «0» А1 –
родитель для классов B1, B2. (Моя схема-вариант 18)
1 Каждый класс содержит защищённую переменную.Например: A1
содержит переменную a1, B1 – b1, C2 – c2 и т.п.Каждый класс имеет
конструктор, присваивающий этой переменной некое значение.
Конструкторы производных классов должны вызывать конструкторы
базовых классов и передавать туда параметры.
2 В базовых классах реализовать функцию print(), которая выводит на
консоль имя класса, из которого она вызвана.В производных классах
переопределять её, чтобы она выводила корректный результат.
Например:
A1 a;
a.print(); = > “A1”
B1 b;
b.print(); = > “B1”
3 Написать функцию show(), которая выводит все доступные для этого
класса переменные.Например, в классе B1 доступны локальные
переменные класса B1 и некоторые переменные из родительского
класса A1.Переопределить её в производных классах.
A1 a;
a.show(); = > только переменные в A1
B1 b;
b.show(); = > переменные из B1 и A1*/

#include <iostream>
using namespace std;

class A1
{
protected:
	int a1;
public:
	A1(int a = 0)
	{
		cout << "\nClass A1 constructor";
		a1 = a;
	}
	void print()
	{
		cout << "\nVariable of A1 class";
	}
	void show()
	{
		cout << "\na1=" << a1;
	}

};

class B1 : virtual public A1
{
protected:
	int    b1;
public:
	B1(int bValue = 0, int aValue = 0) : A1(aValue)
	{
		cout << "\nClass B1 constructor";
		b1 = bValue;
	}
	void print()
	{
		cout << "\nVariable of B1 class";
	}
	void show()
	{
		cout << "\nb1=" << b1 << ", a1=" << a1;
	}
};

class B2 : virtual public A1
{
protected:
	int    b2;
public:
	B2(int bValue = 0, int aValue = 0) : A1(aValue)
	{
		cout << "\nClass B2 constructor";
		b2 = bValue;
	}
	void print()
	{
		cout << "\nVariable of B2 class";
	}
	void show()
	{
		cout << "\nb2=" << b2 << ", a1=" << a1;
	}
};

class B3 : virtual public A1
{
protected:
	int    b3;
public:
	B3(int bValue = 0, int aValue = 0) : A1(aValue)
	{
		cout << "\nClass B3 constructor";
		b3 = bValue;
	}
	void print()
	{
		cout << "\nVariable of B3 class";
	}
	void show()
	{
		cout << "\nb3=" << b3 << ", a1=" << a1;
	}
};

class C1 : virtual public B1, virtual public B2, virtual public B3
{
protected:
	int    c1;
public:
	C1(int cValue = 0, int b1Value = 0, int b2Value = 0, int b3Value = 0, int aValue = 0) : B1(b1Value, aValue), B2(b2Value, aValue), B3(b3Value, aValue), A1(aValue)
	{
		cout << "\nClass C1 constructor";
		c1 = cValue;
	}
	void print()
	{
		cout << "\nVariable of C1 class";
	}
	void show()
	{
		cout << "\nc1=" << c1 << ", b1=" << b1 << ", b2=" << b2 << ", b3=" << b3 << ", a1=" << a1;
	}
};

class C2 : virtual public B1, virtual public B2, virtual public B3
{
protected:
	int    c2;
public:
	C2(int cValue = 0, int b1Value = 0, int b2Value = 0, int b3Value = 0, int aValue = 0) : B1(b1Value, aValue), B2(b2Value, aValue), B3(b3Value, aValue), A1(aValue)
	{
		cout << "\nClass C2 constructor";
		c2 = cValue;
	}
	void print()
	{
		cout << "\nVariable of C2 class";
	}
	void show()
	{
		cout << "\nc2=" << c2 << ", b1=" << b1 << ", b2=" << b2 << ", b3=" << b3 << ", a1=" << a1;
	}
};

class C3 : virtual public B1, virtual public B2, virtual public B3
{
protected:
	int    c3;
public:
	C3(int cValue = 0, int b1Value = 0, int b2Value = 0, int b3Value = 0, int aValue = 0) : B1(b1Value, aValue), B2(b2Value, aValue), B3(b3Value, aValue), A1(aValue)
	{
		cout << "\nClass C3 constructor";
		c3 = cValue;
	}
	void print()
	{
		cout << "\nVariable of C3 class";
	}
	void show()
	{
		cout << "\nc3=" << c3 << ", b1=" << b1 << ", b2=" << b2 << ", b3=" << b3 << ", a1=" << a1;
	}
};



int main()
{
	cout << "\n\n*****************************************************************************" << endl;
	A1 Q;
	B1 QQ;
	B2 QQQ;
	B3 QQQQ;
	C1 QQQQQ;
	C2 QQQQQQ;
	C3 QQQQQQQ;
	cout << "\n\n*****************************************************************************" << endl;
	Q.print();
	QQ.print();
	QQQ.print();
	QQQQ.print();
	QQQQQ.print();
	QQQQQQ.print();
	QQQQQQQ.print();
	cout << "\n\n*****************************************************************************" << endl;
	Q.show();
	QQ.show();
	QQQ.show();
	QQQQ.show();
	QQQQQ.show();
	QQQQQQ.show();
	QQQQQQQ.show();
	cout << "\n\n*****************************************************************************" << endl;
	A1 P(10);
	B1 PP(5, 15);
	B2 PPP(6, 20);
	B3 PPPP(7, 25);
	C1 PPPPP(1, 2, 3, 4, 10000);
	C2 PPPPPP(2000, 11, 12, 13, 14);
	C3 PPPPPPP(3000, 91, 92, 93, 94);
	cout << "\n\n*****************************************************************************" << endl;
	P.print();
	PP.print();
	PPP.print();
	PPPP.print();
	PPPPP.print();
	PPPPPP.print();
	PPPPPPP.print();
	cout << "\n\n*****************************************************************************" << endl;
	P.show();
	PP.show();
	PPP.show();
	PPPP.show();
	PPPPP.show();
	PPPPPP.show();
	PPPPPPP.show();
	cout << "\n\n*****************************************************************************" << endl;
}