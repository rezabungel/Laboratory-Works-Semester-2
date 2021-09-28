// Zadanie 1.2 Svyatchenko Artem KTSO-03-20.cpp
/*Практическая работа №1. Работа с последовательными контейнерами.
Задание 1.2
Постройте наследник класса C из задания 1.1. Введите в него дружественные функции,
перегружающие недостающие комбинации расположения операндов в операциях из задания 1.1.
Для определенности в таблице 1.2 представлены операции, которые необходимо реализовать с
помощью дружественных функций.
Примечание: например, в задании 1.1 требовалось перегрузить операцию
умножения комплексного числа на действительное: z = w * x: здесь z, w –
комплексные числа, x – действительное число. В задании 1.2 нужно ввести
функции для перегрузки операций так, чтобы заработала операция z = x * w.*/

/*Вариант 18
Класс С: Вектор (2 компоненты)
Реализуемая операция: Бинарная операция деления вещественного числа на
вектор: каждая компонента вектора – это частное от деление числа на её
первоначальное значение: a / V = {a/Vx, a/Vy}.
*/

//В задании подразумевается наличие бинарной операции деления вектора на вещественное число, которое будет введено сейчас, т.к. в задании 1.1 об этом не говорилось.

#include<iostream>
#include<math.h>
using namespace std;

class Vector
{
protected: //Закрываем доступ извне, но даем доступ наследнику.
	double coordinateX;
	double coordinateY;
public:
	//Конструкторы.
	Vector()//По-умолчанию создается вектор с координатами (0:0).
	{
		coordinateX = 0;
		coordinateY = 0;
	}
	Vector(double CoordinateX)//Создаем вектор, с заданной первой координатой и второй координатой равной 0.
	{
		coordinateX = CoordinateX;
		coordinateY = 0;
	}
	Vector(double CoordinateX, double CoordinateY)//Создаем вектор, с заданной первой и второй координатами.
	{
		coordinateX = CoordinateX;
		coordinateY = CoordinateY;
	}
	//Операция вывода вектора.
	virtual void print()
	{
		cout << "\nVector(" << coordinateX << " ; " << coordinateY << ")";
	}
	//Сеттеры. (Запись данных извне).
	void setCoordinateX(double value) //Запись в координату X.
	{
		coordinateX = value;
	}
	void setCoordinateY(double value) //Запись в координату Y.
	{
		coordinateY = value;
	}
	//Геттеры. (Считать данные извне).
	double getCoordinateX() //Считывание координаты X.
	{
		return coordinateX;
	}
	double getCoordinateY() //Считывание координаты Y.
	{
		return coordinateY;
	}
	friend double modylvectora(const Vector& vec);//Этот метод будет находить длину вектора.
	friend double SkalyarnoyeProizvedeniye(const Vector& vec1, const Vector& vec2);//Этот метод будет находить скалярное произведение двух векторов.
	//Переорпеделение операций.
	//Перегрузка унарного оператора ! (логическое отрицание, НЕ), который будет выдавать прокцию на ось абсцисс.
	double operator!()
	{//Проекция вектора на ось абсцисс это просто его координата X.
		double res = coordinateX;//Вычисление проекции.
		return res;
	}
	//Перегрузка унарного оператора ~ (побитовая инверсия), который будет выдавать прокцию на ось абсцисс.
	double operator~()
	{//Проекция вектора на ось ординат это просто его координата Y.
		double res = coordinateY;//Вычисление проекции.
		return res;
	}
	//Перегрузка бинарного оператора && (Логическое умножение, И), который будет выдавать прокцию одного вектора на другой.
	double operator&&(const Vector& os)//Вектор оси будем передавать по константной ссылке. Передача по ссылке отключит копирование, а константа запретит изменения.
	{
		double res;
		double DlinaVectoraOsi = modylvectora(os);//Длина вектора оси.
		//res = (coordinateX * os.coordinateX + coordinateY * os.coordinateY) / DlinaVectoraOsi;//Вычисление проекции.
		Vector help(coordinateX, coordinateY);//Этот вектор нужен для передачи вектора С в функцию скалярного произведения. 
		res = SkalyarnoyeProizvedeniye(help, os) / DlinaVectoraOsi;
		return res;
	}
	//Перегрузка бинарной операции деления вектора на вещественное число.
	Vector operator/(const double& a)
	{
		Vector Res;
		Res.coordinateX = coordinateX / a;
		Res.coordinateY = coordinateY / a;
		return Res;
	}
};

class SecondVector : public Vector //Производный класс.
{
public:
	//Конструкторы для производного класса                        
	SecondVector() :Vector() {}
	SecondVector(double CoordinateX) : Vector(CoordinateX) {}
	SecondVector(double CoordinateX, double CoordinateY) : Vector(CoordinateX, CoordinateY) {}
	virtual void print()//Переобозначили метод print для произвольного класса.
	{
		cout << "\nSecondVector(" << coordinateX << " ; " << coordinateY << ")";
	}
	friend SecondVector operator/(const double& a, const SecondVector& QQ);
};

SecondVector operator/(const double& a, const SecondVector& QQ)
{
	SecondVector Res;
	Res.coordinateX = a / QQ.coordinateX;
	Res.coordinateY = a / QQ.coordinateY;
	return Res;
};
double modylvectora(const Vector& vec)//Этот метод будет находить длину вектора.
{
	double res;
	res = sqrt(vec.coordinateX * vec.coordinateX + vec.coordinateY * vec.coordinateY);//Длина вектора.
	return res;
}
double SkalyarnoyeProizvedeniye(const Vector& vec1, const Vector& vec2)//Этот метод будет находить скалярное произведение двух векторов.
{
	double res;
	res = vec1.coordinateX * vec2.coordinateX + vec1.coordinateY * vec2.coordinateY;
	return res;
}



int main()
{	//Чтобы невозникло проблем с работой вещественных и целочисленных данных, наш вектор теперь будет не челосисленный, а вещественный.
	//Показываю, что конструктор, метод print, сеттеры и геттеры  работают для класса Vector в задании 1.1.
	cout << "Pereopredelonnyye operatsii.\n";
	cout << "!- proketsiya na os' abstsiss; ~ -proketsiya na os' ordinat; && - proyektsiya na drugoy vektor.\n";//Подробнее о смысле проекции см в задании 1.1.
	Vector C(30, 35); //Будет создан вектор с координатами (30;35). 
	cout << "Vector C:"; //Вывожу вектор в консоль, для того, чтобы увидеть чему равны координаты.
	C.print();
	cout << "\n"; //Пропускаю строчку в консоле для наглядности.
	//Прокция вектора на ось абсцисс.
	double proyektsiyaX = !C;
	cout << "\nProyektsiya vectora C na os' abstsiss=" << proyektsiyaX;
	//Прокция вектора на ось ординат.
	double proyektsiyaY = ~C;
	cout << "\nProyektsiya vectora C na os' ordinat=" << proyektsiyaY;
	cout << "\n"; //Пропускаю строчку в консоле для наглядности.
	//Проекция одного вектора на другой, который будет являться осью.
	Vector l(28, 7);//Вектор ось.
	cout << "\nVector osi l:";
	l.print(); //Вывод вектора l.
	double proyektsiya = C && l;
	cout << "\nProyektsiya vectora C na vector l=" << proyektsiya;
	cout << "\n\n\nPerehodim k deleniyu veshchestvennykh chisel na vektor."; //Пропускаю строчку в консоле для наглядности
	//Деление вектора на вещественное число.
	double m = 0;
	cout << "\nVvedite chislo. Chislo razdelit'sya na etot Vektor   (C/m = {Cx/m, Cy/m}). m=";
	cin >> m;
	if (m != 0)
	{
		Vector deleniye = C / m;
		cout << "Rezul'tat deleniya vektora na veshchestvennoye chislo:";
		deleniye.print();
	}
	else
	{
		cout << "\nDelit' na 0 nel'zya.";
	}
	cout << "\n\n\n"; //Пропускаю строчи в консоле для наглядности
	cout << "\nPo zadaniyu trebuyetsya organizovat' deleniye veshchestvennogo chisla na vektor v kachestve druzhestvennoy funktsii dlya klassa naslednika.";
	cout << "\nYa sozdal naslednik klassa Vector. V naslednike realizoval konstruktory, pereopredelil metod print i dobavil druzhestvennuyu funktsiyu deleniye veshchestvennogo chisla na vektor.";
	cout << "Pokazyvayu, chto konstruktor, metod print, settery i gettery rabotayut dlya naslednika klassa.\n";
	SecondVector A; //Будет создан вектор с координатами (0;0).
	SecondVector B(10); //Будет создан вектор с координатами (10;0).
	SecondVector AS(30, 35); //Будет создан вектор с координатами (30;35). 
	A.print(); //Вывод вектора A.
	B.print(); //Вывод вектора B.
	AS.print();//Вывод вектора AS.
	cout << "\nZadadim vektory A novyye znacheniya.";
	A.setCoordinateX(9); //Задаем вектору А координату X=8.
	A.setCoordinateY(8); //Задаем вектору А координату Y=9.
	A.print(); //Вывод вектора A с новыми координатами.
	cout << "\nPoluchayu koordinaty vektorov.";
	double x1 = B.getCoordinateX(); //Запись в переменную x1 значение координаты X вектора AS.
	double y1 = AS.getCoordinateY(); //Запись в переменную y1 значение координаты Y вектора AS.
	cout << "\nx1=" << x1 << " value coordinate X vector B"; //Вывод x1.
	cout << "\ny1=" << y1 << " value coordinate Y vector AS"; //Вывод y1.
	cout << "\nKonstruktor, metod print, gettery i settery dlya naslednika rabotayut pravil'no.\n\n";
	double d = 0;
	cout << "SecondVector AS:";
	AS.print();
	cout << "\nVvedite chislo. Vektor razdelit'sya na eto chislo (d / AS = {d/ASx, d/ASy}). d=";
	cin >> d;
	if ((AS.getCoordinateX() != 0) && (AS.getCoordinateY() != 0))
	{
		SecondVector deleniesecond = d / AS;
		cout << "Rezul'tat deleniya vektora na veshchestvennoye chislo:";
		deleniesecond.print();
	}
	else
	{
		cout << "\nV koordinate vektora soderzhit'sya 0, a na 0 delit' nel'zya.";
	}
}