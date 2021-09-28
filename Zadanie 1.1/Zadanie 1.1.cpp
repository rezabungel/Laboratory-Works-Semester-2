// Zadanie 1.1 Svyatchenko Artem KTSO-03-20.cpp
/*Практическая работа №1. Работа с последовательными контейнерами.
Задание 1.1
Постройте класс C, указанный в варианте (таблица 1.1). Поля должны
быть закрытыми.Введите необходимый набор конструкторов и деструктор
(при необходимости).Введите для него перегрузку операций, указанных в
варианте, с помощью компонентных функций.Продемонстрируйте работу
построенных операций в функции main.*/

/*Вариант 18
Класс С: Вектор (2 компоненты)
Реализуемая операция: Унарная операция проекции на ось абсцисс, унарная операция проекции на ось ординат, бинарная операция проекции на произвольную ось.
*/

#include<iostream>
#include<math.h>
using namespace std;

class Vector
{
private:
	int coordinateX;
	int coordinateY;
public:
	//Конструкторы.
	Vector()//По-умолчанию создается вектор с координатами (0:0).
	{
		coordinateX = 0;
		coordinateY = 0;
	}
	Vector(int CoordinateX)//Создаем вектор, с заданной первой координатой и второй координатой равной 0.
	{
		coordinateX = CoordinateX;
		coordinateY = 0;
	}
	Vector(int CoordinateX, int CoordinateY)//Создаем вектор, с заданной первой и второй координатами.
	{
		coordinateX = CoordinateX;
		coordinateY = CoordinateY;
	}
	//Операция вывода вектора.
	void print()
	{
		cout << "\nVector(" << coordinateX << " ; " << coordinateY << ")";
	}
	//Сеттеры. (Запись данных извне).
	void setCoordinateX(int value) //Запись в координату X.
	{
		coordinateX = value;
	}
	void setCoordinateY(int value) //Запись в координату Y.
	{
		coordinateY = value;
	}
	//Геттеры. (Считать данные извне).
	int getCoordinateX() //Считывание координаты X.
	{
		return coordinateX;
	}
	int getCoordinateY() //Считывание координаты Y.
	{
		return coordinateY;
	}
	friend int modylvectora(const Vector& vec);//Этот метод будет находить длину вектора.
	friend int SkalyarnoyeProizvedeniye(const Vector& vec1, const Vector& vec2);//Этот метод будет находить скалярное произведение двух векторов.
		//Переорпеделение операций.
		//Перегрузка унарного оператора ! (логическое отрицание, НЕ), который будет выдавать прокцию на ось абсцисс.
	int operator!()
	{//Проекция вектора на ось абсцисс это просто его координата X.
		int res = coordinateX;//Вычисление проекции.
		return res;
	}
	//Перегрузка унарного оператора ~ (побитовая инверсия), который будет выдавать прокцию на ось абсцисс.
	int operator~()
	{//Проекция вектора на ось ординат это просто его координата Y.
		int res = coordinateY;//Вычисление проекции.
		return res;
	}
	//Перегрузка бинарного оператора && (Логическое умножение, И), который будет выдавать прокцию одного вектора на другой.
	int operator&&(const Vector& os)//Вектор оси будем передавать по константной ссылке. Передача по ссылке отключит копирование, а константа запретит изменения.
	{
		int res;
		int DlinaVectoraOsi = modylvectora(os);//Длина вектора оси.
		//res = (coordinateX * os.coordinateX + coordinateY * os.coordinateY) / DlinaVectoraOsi;//Вычисление проекции.
		Vector help(coordinateX, coordinateY);//Этот вектор нужен для передачи вектора С в функцию скалярного произведения. 
		res = SkalyarnoyeProizvedeniye(help, os) / DlinaVectoraOsi;
		return res;
	}
};
int modylvectora(const Vector& vec)//Этот метод будет находить длину вектора.
{
	int res;
	res = sqrt(vec.coordinateX * vec.coordinateX + vec.coordinateY * vec.coordinateY);//Длина вектора.
	return res;
}
int SkalyarnoyeProizvedeniye(const Vector& vec1, const Vector& vec2)//Этот метод будет находить скалярное произведение двух векторов.
{
	int res;
	res = vec1.coordinateX * vec2.coordinateX + vec1.coordinateY * vec2.coordinateY;
	return res;
}



int main()
{
	//Показываю, что конструктор, метод print, сеттеры и геттеры работают.
	cout << "Pokazyvayu, chto konstruktor, metod print, settery i gettery rabotayut.\n";
	Vector A; //Будет создан вектор с координатами (0;0).
	Vector B(10); //Будет создан вектор с координатами (10;0).
	Vector C(30, 35); //Будет создан вектор с координатами (30;35). 
	A.print(); //Вывод вектора A.
	B.print(); //Вывод вектора B.
	C.print(); //Вывод вектора C.
	cout << "\nZadayu vektory A novyye znacheniya.";
	A.setCoordinateX(9); //Задаем вектору А координату X=8.
	A.setCoordinateY(8); //Задаем вектору А координату Y=9.
	A.print(); //Вывод вектора A с новыми координатами.
	cout << "\nPoluchayu koordinaty vektorov.";
	int x1 = B.getCoordinateX(); //Запись в переменную x1 значение координаты X вектора B.
	int y1 = C.getCoordinateY(); //Запись в переменную y1 значение координаты Y вектора C.
	cout << "\nx1=" << x1 << " value coordinate X vector B"; //Вывод x1.
	cout << "\ny1=" << y1 << " value coordinate Y vector C"; //Вывод y1.
	cout << "\n"; //Пропускаю строчку в консоле для наглядности.
	cout << "\n"; //Пропускаю строчку в консоле для наглядности.

	cout << "Perekhozhu k vypolneniyu zadaniya - pereopredeleniyu operatsiy.";
	/*Проекция вектора AB на ось называется число, равное длине вектора A'B' (A' и B'- проекции точек A и B на ось)
	взятое со знак + если угол между вектором AB и осью острый и со знаком - если угол тупой.
	Также можно обойтись и без угла. Достаточно только салярное произведение разделить на длину вектора оси.*/
	cout << "\n"; //Пропускаю строчку в консоле для наглядности.
	cout << "Vector C:"; //Напоминаю чему равен вектор С.
	C.print();
	cout << "\n"; //Пропускаю строчку в консоле для наглядности.

	//Прокция вектора на ось абсцисс.
	int proyektsiyaX = !C;
	cout << "\nProyektsiya vectora C na os' abstsiss=" << proyektsiyaX;

	//Прокция вектора на ось ординат.
	int proyektsiyaY = ~C;
	cout << "\nProyektsiya vectora C na os' ordinat=" << proyektsiyaY;
	cout << "\n"; //Пропускаю строчку в консоле для наглядности.

	//Проекция одного вектора на другой, который будет являться осью.
	Vector l(28, 7);//Вектор ось.
	cout << "\nVector osi l:";
	l.print(); //Вывод вектора l.
	int proyektsiya = C && l;
	cout << "\nProyektsiya vectora C na vector l=" << proyektsiya;
	cout << "\n"; //Пропускаю строчку в консоле для наглядности.
}