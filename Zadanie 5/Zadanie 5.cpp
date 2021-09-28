// Zadanie 5 Svyatchenko Artem KTSO-03-20.cpp
// Практическая работа №5.Матрицы.
/*
1. Унаследуйте класс от базового класса Многомерный массив. Убедитесь,
что в родительском классе верно выделяется и освобождается память под
многомерный массив. В производном классе напишите метод заполнения массива
произвольным нетривиальным образом. Введите метод, который решает задачу, указанную
в варианте, и возвращает из неё результат (входная матрица остаётся неизменной,
на выходе должен быть новый массив или число).
2. Введите систему исключений, указанную на рисунке 1. Встройте собственный тип исключения,
которое может возникнуть при решении задачи из Вашего варианта, в общую структуру наследования.
Продемонстрируйте обработку исключений с помощью операторов try – throw – catch
(исключения генерируются в методах класса Матрица, обрабатываются – в main).
************************************************************************************************
Рисунок 1 Схема наследования классов - исключений
Здесь Exception – базовый класс для исключений, которые могут
произойти в классе Матрица.
IndexOutOfBounds – выход за границы массива.
WrongDimensionsException – участие в одной операции операндов(в
основном, матриц) неправильных размеров(например, сложение
матриц, размеры которых отличаются).
WrongSizeException – использование ошибочных значений при
создании объектов класса Матрица.
************************************************************************************************
3. Сохраните результат обработки нескольких матриц в файл, извлеките результаты из файла,
выведите их в консоль. Продемонстрируйте, что результаты, которые записывались в файл,
и прочитанные из файла данные не отличаются.
4. Введите конструкторы и методы для чтения матрицы произвольного размера из файла.
5. Преобразуйте классы многомерных массивов к шаблонам классов.

Вариант 18.
Удалить из матрицы все строки и столбцы, среднее арифметическое которых большие некоторого параметра border.
*/

#include <iostream>
#include <fstream> //библиотека для работы с файлами.
#include <string> 
using namespace std;



class Exception : public exception
{
protected:
	//сообщение об ошибке
	char* str;
public:
	Exception(const char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy_s(str, strlen(s) + 1, s);
	}
	Exception(const Exception& e)
	{
		str = new char[strlen(e.str) + 1];
		strcpy_s(str, strlen(e.str) + 1, e.str);
	}

	~Exception()
	{
		delete[] str;
	}
	virtual void print()//Для каждого класса будет своя конкретная функция вывода.
	{
		cout << "Exception: " << str << endl;
	}
};

class IndexOutOfBoundsException :public Exception
{
public:
	IndexOutOfBoundsException(const char* s) : Exception(s) {};
	IndexOutOfBoundsException(const IndexOutOfBoundsException& e) :Exception(e) {};
	virtual void print()
	{
		cout << "IndexOutOfBoundsException: " << str << endl;
	}
};
class WrongDimensionsException :public Exception
{
public:
	WrongDimensionsException(const char* s) : Exception(s) {};
	WrongDimensionsException(const WrongDimensionsException& e) :Exception(e) {};
	virtual void print()
	{
		cout << "WrongDimensionsException: " << str << endl;
	}
};
class WrongSizeException : public WrongDimensionsException
{
public:
	WrongSizeException(const char* s) : WrongDimensionsException(s) {};
	WrongSizeException(const WrongSizeException& e) :WrongDimensionsException(e) {};
	virtual void print()
	{
		cout << "WrongSizeException: " << str << endl;
	}
};

template<typename T> //Шаблоны классов.
class BaseMatrix
{
protected:
	T** ptr;
	int height;
	int width;
public:
	BaseMatrix(int Height = 2, int Width = 2)//Конструктор.
	{
		if (Height <= 0 || Width <= 0)
		{
			throw WrongSizeException("Non-positive size of matrix.");
		}
		height = Height;
		width = Width;
		ptr = new T * [height];
		for (int i = 0; i < height; i++)
		{
			ptr[i] = new T[width];
		}
	}
	BaseMatrix(const BaseMatrix<T>& copy)//Копирование.
	{
		height = copy.height;
		width = copy.width;
		ptr = new T * [height];
		for (int i = 0; i < height; i++)
		{
			ptr[i] = new T[width];
			for (int j = 0; j < width; j++)
			{
				ptr[i][j] = copy.ptr[i][j];
			}
		}
	}
	BaseMatrix(string filename)//Конструктор, создающий матрицу, прочитанную из файла.
	{
		ifstream fin;
		fin.open(filename); //открываем файл.

		if (!fin.is_open()) //проверка на то, смогли ли мы открыть наш файл.
		{
			cout << "File open error." << endl;
			cout << "***************************************************************" << endl;
		}
		else
		{
			cout << "The file is open." << endl;
			cout << "Reading..." << endl;
			char ch;
			while (!fin.eof())
			{
				fin.get(ch);
				if (ch == '\n')
				{
					height = height + 1;
				}
			};
			height = height - 1;
			ch = ' ';
			fin.close(); //закрываем файл.
			fin.open(filename); //открываем файл.
			while (!fin.eof() && ch != '\n')
			{
				fin.get(ch);
				if (ch == ' ')
				{
					width = width + 1;
				}
			};
			ptr = new T * [height];
			for (int i = 0; i < height; i++)
			{
				ptr[i] = new T[width];
			};
			fin.close(); //закрываем файл.
			fin.open(filename); //открываем файл.
			int index_line = 0;
			int index_stolb = 0;
			string str;
			while (!fin.eof()) //Цикл работает до тех пор, пока не дойдет до конца файла.
			{
				str = "	";
				fin >> str;//считывает данные до пробела.
				T help;
				help = atof(str.c_str());//преобразование к числу.
				ptr[index_line][index_stolb] = help;
				index_stolb = index_stolb + 1;
				if (index_stolb == width)
				{
					index_stolb = 0;
					index_line = index_line + 1;
					if (index_line == height)
					{
						break;
					}
				}
			};
		};
		cout << "The file is closed." << endl << endl;
		fin.close(); //закрываем файл.
		cout << "***************************************************************" << endl;
	}
	~BaseMatrix()//Деструктор.
	{
		if (ptr != nullptr)
		{
			for (int i = 0; i < height; i++)
				delete[] ptr[i];
			delete[] ptr;
			ptr = nullptr;
		}
		height = 0;
		width = 0;
	}
	void print()//Вывод массива.
	{
		cout << "Print matrix" << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << ptr[i][j] << " ";
			cout << "\n";
		}
	}
	void Zapolneniye()//Заполнение массива случайными числами.
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				ptr[i][j] = rand() % 100 + 1;
			}
		}
	}
	void tochechnoye_zapolneniye(int i, int j, T number)//Заполнение конкретных ячеек массива.
	{
		if (i >= height || j >= width || i < 0 || j < 0)
		{
			throw IndexOutOfBoundsException("Obrashcheniye k nesushchestvuyushchemu indeksu.");
		}
		ptr[i][j] = number;
	}

	T tochechnoye_reading(int i, int j)//Чтение конкретных ячеек массива.
	{
		if (i >= height || j >= width || i < 0 || j < 0)
		{
			throw IndexOutOfBoundsException("Obrashcheniye k nesushchestvuyushchemu indeksu.");
		}
		T a = ptr[i][j];
		return	a;
	}
	void const Save(string filename)//Сохранение матрицы в файл.
	{
		ofstream fout;
		fout.open(filename);
		if (!fout.is_open()) //Проверка на то, смогли ли мы открыть наш файл.
		{
			cout << "File open error." << endl;
		}
		else
		{
			cout << "The file is open." << endl;
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					fout << ptr[i][j] << " ";
				}
				fout << endl;
			}
			cout << "Data has been successfully written to file." << endl;
		};
		fout.close(); //закрываем файл.
		cout << "The file is closed." << endl;
		cout << "****************************************************" << endl;
	}
};

template<typename T> //Шаблоны классов.
class MyMatrix :public BaseMatrix<T>
{
protected:
	using BaseMatrix<T> ::ptr;
	using BaseMatrix<T> ::height;
	using BaseMatrix<T> ::width;
public:
	MyMatrix(int Height = 2, int Width = 2) :BaseMatrix<T>(Height, Width) {}//Конструктор.
	MyMatrix(const MyMatrix& copy) :BaseMatrix<T>(copy) {}//Копирования.
	MyMatrix(string filename) :BaseMatrix<T>(filename) {}//Конструктор, создающий матрицу, прочитанную из файла.
	~MyMatrix()//Деструктор.
	{
		if (ptr != nullptr)
		{
			for (int i = 0; i < height; i++)
				delete[] ptr[i];
			delete[] ptr;
			ptr = nullptr;
		}
		height = 0;
		width = 0;
	}
	MyMatrix<T> Work(int border = 0)//Функция из задания.
	{
		int Help_height = height;
		int Help_width = width;
		T ForHelp[100][100];
		int count = 0;
		for (int i = 0; i < height; i++)
		{
			T sum = 0;
			for (int j = 0; j < width; j++)
			{
				sum = sum + ptr[i][j];
			}
			sum = sum / width;//Среднее арифметическое.
			if (sum <= border)
			{
				for (int k = 0; k < width; k++)
				{
					ForHelp[count][k] = ptr[i][k];
				}
				count = count + 1;
			}
		}
		Help_height = count;
		MyMatrix<T> result(Help_height, Help_width);
		for (int i = 0; i < Help_height; i++)
		{
			for (int j = 0; j < Help_width; j++)
			{
				try//Использование исключений в собственной функции.
				{
					result.tochechnoye_zapolneniye(i, j, ForHelp[i][j]);
				}
				catch (IndexOutOfBoundsException e)
				{
					cout << "Exception has been caught: "; e.print();
				}
			}
		}
		return result;
	}
};



int main()
{
	try//Тест: WrongSizeException.
	{
		BaseMatrix<double> Wrong(-2, 0);
	}
	catch (WrongSizeException e)
	{
		cout << "Exception has been caught: "; e.print();
	}
	cout << "****************************************************" << endl;
	BaseMatrix<double> A(2, 5);
	A.Zapolneniye();
	A.print();
	cout << "****************************************************" << endl;
	BaseMatrix<double> C(A);//Копирование.
	C.print();
	cout << "****************************************************" << endl;
	MyMatrix<double> B(5, 5);
	B.Zapolneniye();
	B.print();
	cout << "****************************************************" << endl;
	MyMatrix<double> D(B);//Копирование.
	D.print();
	cout << "****************************************************" << endl;
	MyMatrix<double> TestWork(B.Work(50));
	TestWork.print();
	cout << "****************************************************" << endl;
	double for_reading = 0;
	try //Тест: IndexOutOfBoundsException.
	{
		for_reading = B.tochechnoye_reading(-1, 0);
		cout << "for_reading=" << for_reading << endl;
	}
	catch (IndexOutOfBoundsException e)
	{
		cout << "Exception has been caught: "; e.print();
	}
	cout << "****************************************************" << endl;
	try //Тест: IndexOutOfBoundsException.
	{
		B.tochechnoye_zapolneniye(1, -1, 1);
		B.print();
	}
	catch (IndexOutOfBoundsException e)
	{
		cout << "Exception has been caught: "; e.print();
	}
	cout << "****************************************************" << endl;
	cout << "Sokhranim matritsu B v fayl." << endl;
	B.print(); cout << endl;
	B.Save("Result_Matrix.txt");

	cout << "Prochitayem dannyye iz fayla." << endl;
	MyMatrix<double> QQQ("Result_Matrix.txt");
	QQQ.print();
	cout << "Rezul'tat sovpadayet s tem, chto my zapisyvali v fayl." << endl;
	cout << "****************************************************" << endl;
}