// Zadanie 7 Svyatchenko Artem KTSO-03-20.cpp

/*
1 Написать шаблон функции, сортирующей массив указанным способом. Прочесть
массив из файла, отсортировать его, записать отсортированный массив в новый
файл.
2 Продемонстрировать работу функции на 3 массивах: упорядоченном в прямом
порядке, в обратном порядке и неупорядоченном(в случайном порядке). Размеры
массивов должны быть не менее 10 000 элементов.
3 Ввести замеры скорости работы реализации каждого алгоритма либо в виде
количества обменов и количества сравнений, либо по затраченному времени.

Функция:
1 Сортировка подсчётом.
2 Сортировка слиянием.
*/

#include <iostream>
#include <fstream> //библиотека для работы с файлами.
#include <string>
#include <time.h>
using namespace std;

void FillArray(int a[], const int size)//заполнение массива.
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 1000;
	}
}

void PrintArray(int a[], const int size)//вывод массива.
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int TakeSizeArrayFromFile(string filename)//Считаем количество элементов в файле.
{
	int size = 0;
	ifstream fin;
	fin.open(filename); //открываем файл.
	if (!fin.is_open()) //проверка на то, смогли ли мы открыть наш файл.
	{
		cout << "File open error." << endl;
		cout << "***************************************************************************************************\n";
	}
	else
	{
		cout << "The file is open." << endl;
		cout << "We count the number of elements..." << endl;
		char ch;
		while (!fin.eof())
		{
			fin.get(ch);
			if (ch == ' ')
			{
				size = size + 1;
			}
		}
		size = size - 1;
	}
	cout << "size = " << size << endl;
	cout << "The file is closed." << endl;
	fin.close(); //закрываем файл.
	cout << "***************************************************************************************************\n";
	return size;
}

void TakeDataArrayFromFile(string filename, int a[], int size)//Взятие массива из файла (Перед этим, нужно создать массив, размер которого мы получим из функции TakeSizeArrayFromFile). 
{
	ifstream fin;
	fin.open(filename); //открываем файл.
	if (!fin.is_open()) //проверка на то, смогли ли мы открыть наш файл.
	{
		cout << "File open error." << endl;
		cout << "***************************************************************************************************\n";
	}
	else
	{
		cout << "The file is open." << endl;
		cout << "Reading..." << endl;
		int index = 0;
		string str;
		while (!fin.eof()) //Цикл работает до тех пор, пока не дойдет до конца файла.
		{
			str = "	";
			fin >> str;//считывает данные до пробела.
			int help;
			help = atof(str.c_str());//преобразование к числу.
			a[index] = help;
			index = index + 1;
			if (index == size)
			{
				break;
			}
		}
	}
	cout << "The file is closed." << endl;
	fin.close(); //закрываем файл.
	cout << "***************************************************************************************************\n";
}

void SaveArrayInFile(string filename, int a[], const int size)//Сохранение массива в файл.
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
		for (int i = 0; i < size; i++)
		{
			fout << a[i] << " ";
		}
		cout << "Data has been successfully written to file." << endl;
	};
	fout.close(); //закрываем файл.
	cout << "The file is closed." << endl;
	cout << "***************************************************************************************************\n";
}


//template<typename T>


/*Сортировка подсчётом*/
void CountingSort(int a[], int size) //Неприменим для сортировки вещественных чисел и для сортировки очень больших чисел. Сортировать массив можно, если его числа находятся в диапазоне от 0 до ...(так далее, положительные числа).
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	max = max + 1;//Учитываем то, что индексы начинаются с 0.
	int* counter = new int[max];

	for (int i = 0; i < max; i++)//инициализация массива счетчиков.
	{
		counter[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		counter[a[i]] = counter[a[i]] + 1;
	}
	int j = 0;
	for (int i = 0; i < max; i++)
	{
		while (counter[i] != 0)
		{
			a[j] = i;
			counter[i] = counter[i] - 1;
			j = j + 1;
		}
	}
	delete[] counter;
}

/*Сортировка слиянием
//Это пример реализации сортировки слиянием с помощью шаблона. Т.к. Сортировка подсчетом только для int, то применять шаблон к ней нельзя, так как может возникнуть ситуация, когда мы заходим реализовать ее через тип dauble.
template<typename T>
void MergeSort(T a[], int size)
{
	if (size < 2)
	{
		return;
	};
	MergeSort(a, size / 2);
	MergeSort(&a[size / 2], size - (size / 2));
	T* buf = new T[size];
	int idbuf = 0, idl = 0, idr = size / 2;
	while ((idl < size / 2) && (idr < size))
	{
		if (a[idl] < a[idr])
		{
			buf[idbuf++] = a[idl++];
		}
		else
		{
			buf[idbuf++] = a[idr++];
		}
	}
	while (idl < size / 2)
	{
		buf[idbuf++] = a[idl++];
	}
	while (idr < size)
	{
		buf[idbuf++] = a[idr++];
	}
	for (idl = 0; idl < size; idl++)
	{
		a[idl] = buf[idl];
	}
	delete[] buf;
}
*/

/*Сортировка слиянием*/
void MergeSort(int a[], int size)
{
	if (size < 2)
	{
		return;
	};
	MergeSort(a, size / 2);
	MergeSort(&a[size / 2], size - (size / 2));
	int* buf = new int[size];
	int idbuf = 0, idl = 0, idr = size / 2;
	while ((idl < size / 2) && (idr < size))
	{
		if (a[idl] < a[idr])
		{
			buf[idbuf++] = a[idl++];
		}
		else
		{
			buf[idbuf++] = a[idr++];
		}
	}
	while (idl < size / 2)
	{
		buf[idbuf++] = a[idl++];
	}
	while (idr < size)
	{
		buf[idbuf++] = a[idr++];
	}
	for (idl = 0; idl < size; idl++)
	{
		a[idl] = buf[idl];
	}
	delete[] buf;
}



int main()
{
	int size_array = 10;
	cout << "Enter the size of the array: "; cin >> size_array;
	if (size_array <= 0)
	{
		cout << "\nInvalid value for array size = " << size_array << endl;
		size_array = 10;
		cout << "Array size value = " << size_array << endl;
	}
	int* array_for_sort = new int[size_array];
	FillArray(array_for_sort, size_array);
	cout << "***************************************************************************************************\n";
	cout << "!CountingSort!" << endl;
	int* array_for_CountingSort = new int[size_array];
	for (int i = 0; i < size_array; i++)
	{
		array_for_CountingSort[i] = array_for_sort[i];
	}
	PrintArray(array_for_CountingSort, size_array);
	CountingSort(array_for_CountingSort, size_array);
	PrintArray(array_for_CountingSort, size_array);
	cout << "***************************************************************************************************\n";
	cout << "!MergeSort!" << endl;
	int* array_for_MergeSort = new int[size_array];
	for (int i = 0; i < size_array; i++)
	{
		array_for_MergeSort[i] = array_for_sort[i];
	}
	PrintArray(array_for_MergeSort, size_array);
	CountingSort(array_for_MergeSort, size_array);
	PrintArray(array_for_MergeSort, size_array);
	cout << "***************************************************************************************************\n";
	cout << "!Test: save array to file!" << endl;
	SaveArrayInFile("Test save array to file.txt", array_for_sort, size_array);
	cout << "***************************************************************************************************\n";
	cout << "!Test: take size array from file!" << endl;
	cout << "The answer must be = " << size_array << endl;
	int test_size;
	test_size = TakeSizeArrayFromFile("Test save array to file.txt");
	cout << "***************************************************************************************************\n";
	cout << "!Test: take data array from file!" << endl;
	test_size = 0;
	int* array_from_data_from_file = new int[test_size = TakeSizeArrayFromFile("Test save array to file.txt")];
	TakeDataArrayFromFile("Test save array to file.txt", array_from_data_from_file, test_size);
	PrintArray(array_from_data_from_file, test_size);
	cout << "***************************************************************************************************\n";
	cout << endl << endl << endl;
	cout << "Okay. Let's compare the running time of sorting algorithms on different arrays." << endl;
	cout << endl << endl << endl;
	cout << "***************************************************************************************************\n";
	//У нас три файла, в которых хранятся массивы на 100000 элементов.
	//Файл 1: элементы отсортированы по возрастанию.
	//Файл 2: элементы отсортированы по убыванию.
	//Файл 3: элементы не отсортированы.
	const int size = 100000;
	int array_from_file[size];
	for (int i = 0; i < size; i++)
	{
		array_from_file[i] = i;
	}
	SaveArrayInFile("File 1.txt", array_from_file, size);
	for (int i = 0; i < size; i++)
	{
		array_from_file[i] = size - i;
	}
	SaveArrayInFile("File 2.txt", array_from_file, size);
	FillArray(array_from_file, size);
	SaveArrayInFile("File 3.txt", array_from_file, size);
	time_t time1, time2;

	cout << "***************************************************************************************************\n";
	cout << "!File 1!" << endl;
	cout << "***************************************************************************************************\n";
	cout << "!CountingSort!" << endl;
	int array1[size];
	TakeDataArrayFromFile("File 1.txt", array1, size);
	time1 = clock();
	CountingSort(array1, size);
	time2 = clock();
	cout << double(time2 - time1) / CLOCKS_PER_SEC << endl;

	cout << "---------------------------------------------------------------------------------------------------\n";
	cout << "!MergeSort!" << endl;
	TakeDataArrayFromFile("File 1.txt", array1, size);
	time1 = clock();
	MergeSort(array1, size);
	time2 = clock();
	cout << double(time2 - time1) / CLOCKS_PER_SEC << endl;

	cout << "***************************************************************************************************\n";
	cout << "!File 2!" << endl;
	cout << "***************************************************************************************************\n";
	cout << "!CountingSort!" << endl;
	TakeDataArrayFromFile("File 2.txt", array1, size);
	time1 = clock();
	CountingSort(array1, size);
	time2 = clock();
	cout << double(time2 - time1) / CLOCKS_PER_SEC << endl;
	cout << "---------------------------------------------------------------------------------------------------\n";
	cout << "!MergeSort!" << endl;
	TakeDataArrayFromFile("File 2.txt", array1, size);
	time1 = clock();
	MergeSort(array1, size);
	time2 = clock();
	cout << double(time2 - time1) / CLOCKS_PER_SEC << endl;

	cout << "***************************************************************************************************\n";
	cout << "!File 3!" << endl;
	cout << "***************************************************************************************************\n";
	cout << "!CountingSort!" << endl;
	TakeDataArrayFromFile("File 3.txt", array1, size);
	time1 = clock();
	CountingSort(array1, size);
	time2 = clock();
	cout << double(time2 - time1) / CLOCKS_PER_SEC << endl;
	cout << "---------------------------------------------------------------------------------------------------\n";
	cout << "!MergeSort!" << endl;
	TakeDataArrayFromFile("File 3.txt", array1, size);
	time1 = clock();
	MergeSort(array1, size);
	time2 = clock();
	cout << double(time2 - time1) / CLOCKS_PER_SEC << endl;
	cout << "***************************************************************************************************\n";
	delete[] array_for_sort;
	delete[] array_for_CountingSort;
	delete[] array_for_MergeSort;
	delete[] array_from_data_from_file;
	return 0;
}