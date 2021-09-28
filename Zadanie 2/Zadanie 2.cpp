// Zadanie 2 Svyatchenko Artem KTSO-03-20.cpp
/*
A. Вам предоставлен класс MyArrayParent, частично реализующий функции массива
(файл InheritanceArray_empty.cpp). Дополните класс необходимыми функциями:
1. Конструктором копий MyArrayParent (&MyArrayParent v).
2. Оператором =.
3. Оператором [ ] для обращения к элементу по индексу.
4. Конструктором, принимающим и копирующим информацию из существующего массива.

B. В классе MyArrayChild, унаследованном от класса MyArrayParent, необходимо
добавить функции (обратите внимание на то, что можно пользоваться функциями, уже
реализованными в базовом классе):
1. Удаления элемента из произвольного места в массиве RemoveAt().
2. Поиска элемента в массиве по значению IndexOf().
3. Вставки элемента в некоторое место в массиве InsertAt().
4. Добавьте функцию согласно Вашему варианту (см. таблицу 1). Результатом
обработки массива должен быть новый объект класса. Исходный массив не должен меняться.

C. Унаследуйте новый класс MySortedArray от MyArrayChild. Мы предполагаем, что этот
класс содержит упорядоченный массив. Переопределите функции из пункта B.4, имея
ввиду, что массив отсортирован. Переопределите операцию добавления элемента (push)
таким образом, чтобы массив оставался отсортированным при добавлении нового элемента.

Таблица 1. Функции для пунктов B.4 и C.
Вариант 18: Поместить в выходной массив индексы всех элементов, которые встречаются больше двух раз.
*/
#include <iostream>
using namespace std;

class MyArrayParent
{
protected:
	//сколько памяти выделено?
	int capacity;
	//количество элементов - сколько памяти используем
	int count; //Количество-т.е. индекс последнего элемента будет count-1.
	//массив
	double* ptr;
public:
	//конструкторы и деструктор
	MyArrayParent()
	{
		cout << "\nMyArray constructor 1";
		ptr = new double[100];
		capacity = 100;
		count = 0;
	}
	//Пункт А4. Конструктор, принимающий и копирующий информацию из существующего массива. 
	MyArrayParent(double* arr, int len)
	{
		cout << "\nMyArray constructor 2";
		ptr = new double[len];
		capacity = len;
		count = len;
		for (int i = 0; i < count; i++) //Т.к. знак <, то как раз получится, что последний заход будет при значении count-1, т.е. это будет последний индекс.
		{
			ptr[i] = arr[i];
		}
	}
	MyArrayParent(int index) //Конструктор, создающий массив определенной размерности.
	{
		cout << "\nMyArray constructor 3";
		ptr = new double[index];
		capacity = index;
		count = 0;
	}

	//Пункт А1. Конструктор копий.
	MyArrayParent(const MyArrayParent& V)
	{
		cout << "\nCopy constructor";
		//создание копии объекта - в основном, при возвращении результата из функции / передаче параметров в функцию
		capacity = V.capacity;
		count = V.count;
		ptr = new double[capacity];
		for (int i = 0; i < count; i++)
		{
			ptr[i] = V.ptr[i];
		}
	}
	//деструктор
	~MyArrayParent()
	{
		cout << "\nMyArray destructor";
		if (ptr != NULL)
		{
			ptr = NULL;
			delete[] ptr;
		}
	}
	//обращение к полям
	int Capacity() { return capacity; }
	int Size() { return count; }
	void RandomMassiv()
	{
		cout << "\nRandomMassiv is working";
		for (int i = 0; i < capacity; i++)
		{
			ptr[i] = rand() % 100 + 1;             ////////////////Почему не ставим *ptr[i]=...???? (Потому что перегрузили оператор []???)
		}
		count = capacity;
	}
	double& operator[](int index)                  /////////////Проблемы с пониманием использования этой функции.
	{
		cout << "\noperator [] ";
		//перегрузка оператора []
		if (index >= 0 && index <= (count - 1)) //индекс последнего элемента будет count - 1 или можно было написать <count
		{
			return ptr[index];
		}
		throw - 1;
	}
	//Пункт A2. Оператор=
	MyArrayParent& operator=(const MyArrayParent& V) //зачем &????    (возможно тут ошибка. см оператор = еше в 4 лабе, дам должно быть лучше)
	{
		cout << "\noperator = ";
		//оператор =
		//arr1 = arr2 = arr3; где arr_i - объекты нашего класса
		if (this != &V)
		{
			if (V.ptr != nullptr)
			{
				delete[] ptr;
				ptr = nullptr;
			}
			ptr = new double[V.count];
			count = V.count;
			capacity = V.capacity;
			for (int i = 0; i < count; i++)
			{
				ptr[i] = V.ptr[i];
			}
		}
		return*this;
	}

	void print()
	{
		cout << "\nMyArr, size: " << count << ", values: {";
		int i = 0;
		for (i = 0; i < count; i++)
		{
			cout << ptr[i];
			if (i != count - 1)
				cout << ", ";
		}
		cout << "}";
	}
};

class MyArrayChild :public MyArrayParent
{
public:
	//конструкторы и деструктор дочернего класса
	MyArrayChild() : MyArrayParent() {}
	//Пункт А4. Конструкторо, принимающий и копирующий информацию из существующего массива. 
	MyArrayChild(double* arr, int len) : MyArrayParent(arr, len) {}
	MyArrayChild(int index) : MyArrayParent(index) {}
	//деструктор
	~MyArrayChild()
	{
		cout << "\nMyArrayChild destructor";
		if (ptr != NULL)
		{
			ptr = NULL;
			delete[] ptr;
		}

	}

	//Переопределение Print
	void print()
	{
		cout << "\nMyArrChild, size: " << count << ", values: {";
		int i = 0;
		for (i = 0; i < count; i++)
		{
			cout << ptr[i];
			if (i != count - 1)
				cout << ", ";
		}
		cout << "}";
	}

	void RemoveAt(int x)//Удаление элемента из произвольного места в массиве RemoveAt().
	{/*Этот метод удаляет элемент массива, который находится под индексом x. После удаления все элементы правее x смещаются влево. В результате одна ячейка массива освобождает; она
		готова для записи новых значений.*/
		cout << "\nRemoveAt working" << endl;
		if (x >= 0 && x < count)
		{//Такой элемент есть.
			for (int i = x; i < count; i++)
			{
				if (i != (count - 1))
				{
					//Если не последний элемент.
					ptr[i] = ptr[i + 1];
				}
			};
			//Раз не удалили элемент, то размерность не меняется, т.е. capacity = capacity; 
			ptr[count - 1] = 0; //Запись нуля в последний элемент.
			count = count - 1;
			return;
		}
		else
		{//Такого элемента нет.	
			cout << "Element ne nayden." << endl;
			return;
		}
	}

	int IndexOf(double x) //Поиска элемента в массиве по значению IndexOf().
	{ //Метод должен возвращать индекс найденного элемента.
		cout << "\nIndexOf working";
		for (int i = 0; i < count; i++)
		{
			if (ptr[i] == x)
			{
				return i;
			}
		}
		return -1;
	}

	void InsertAt(int x, double& element)//Вставки элемента в некоторое место в массиве InsertAt().
	{/*Метод будет работать так: Если в массиве есть свободное место, то все элементы массива правее x и сам x-овый элемент сместятся вправо, а после смещения на освободившееся место встанет число, которое мы
	 захотели добавить в массив.*/
		cout << "\nInsertAt working" << endl;
		if (count < capacity)
		{//Свободное место в массиве - есть.
			if (x >= 0 && x < count)
			{//Попали в диапазон индексов.
				count = count + 1;
				for (int i = count; i > x; i--)
				{
					ptr[i] = ptr[i - 1];
				}
				ptr[x] = element;
				return;
			}
			else
			{//Нет такого индекса.	
				cout << "Element ne nayden. Takogo indeksa byt' ne mozhet." << endl;
				return;
			}
		}
		else
		{//Нет свободного места в массиве.
			cout << "Massiv zapolnen polnost'yu, nekuda smeshchat'sya." << endl;
			return;
		}
	}


	MyArrayChild IndeksBolsheDvukh()         //Как грамотно закончить *this????? или можно вообще без ничего?
	{
		cout << "\nIndeksBolsheDvukh working";
		MyArrayChild ForHelp(count); //Создаем промежуточный массив, в который будем записывать наши индексы, встречающиеся больше двух раз.
		if (count > 0)
		{//Если в массиве есть значения, т.е. он не пустой.
			int countVstrech;
			double helpIndex;
			for (int i = 0; i < count; i++)
			{
				countVstrech = 1;
				helpIndex = 0;
				for (int k = 0; k < count; k++)
				{
					switch (countVstrech)
					{
					case 1:
						if (ptr[i] == ptr[k])
						{
							if (i != k) //i!=k - проверка на то, что мы не смотрим один и тот же элемент.
							{
								if (i < k) //Если мы найдем элемент, раньше, чем дойдем до k, то значит мы его уже рассматривали, следовательно, дальше этот i - тый элемент рассматривать нет смысла, нужно переходить к следующему.
								{
									helpIndex = k;
									countVstrech = countVstrech + 1;

								}
								else
								{
									//Дальше не нужно проверять
									k = count;
								}
							}
						}
						break;
					case 2://Три повторяющихся элемента.
						if (ptr[i] == ptr[k])
						{
							countVstrech = countVstrech + 1;
							ForHelp.ptr[ForHelp.count] = i;	ForHelp.count = ForHelp.count + 1;
							ForHelp.ptr[ForHelp.count] = helpIndex; ForHelp.count = ForHelp.count + 1;
							ForHelp.ptr[ForHelp.count] = k;	ForHelp.count = ForHelp.count + 1;
						}
						break;
					default://Более трёх повторяющихся элементов.
						if (ptr[i] == ptr[k])
						{
							countVstrech = countVstrech + 1;
							ForHelp.ptr[ForHelp.count] = k; ForHelp.count = ForHelp.count + 1;
						}
						break;
					}
				}
			}
			if (ForHelp.count > 0)
			{
				return ForHelp;
			}
			else
			{
				cout << "Ne udalos' nayti elementy, vstrechayushchikhsya bol'she dvukh raz." << endl;
				return ForHelp;
			}
		}
		else
		{//Массив пустой.
			cout << "Massiv v kotorom my khoteli iskat' elementy, vstrechayushchikhsya bol'she dvukh raz, na samom dele pustoy." << endl;
			return ForHelp;
		}
	}
};

class MySortedArray :public MyArrayChild
{
public:
	//конструкторы и деструктор дочернего класса
	MySortedArray() : MyArrayChild() {}
	~MySortedArray()
	{
		cout << "\nMySortedArray destructor";
		if (ptr != NULL)
		{
			ptr = NULL;
			delete[] ptr;
		}
	}
	//Переопределение Print
	void print()
	{
		cout << "\nMySortedArray, size: " << count << ", values: {";
		int i = 0;
		for (i = 0; i < count; i++)
		{
			cout << ptr[i];
			if (i != count - 1)
				cout << ", ";
		}
		cout << "}";
	}
	void SortZapolneniye()//Заполняет массив случайными числами, а потом сортирует их.
	{
		cout << "\nSortZapolneniye is working";
		for (int i = 0; i < capacity; i++)
		{
			ptr[i] = rand() % 159 + 1;
		}
		count = capacity;
		for (int i = 0; i < count; i++)
		{
			for (int j = count - 1; j > i; j--)
			{
				if (ptr[j - 1] > ptr[j])
				{
					int x = ptr[j - 1];
					ptr[j - 1] = ptr[j];
					ptr[j] = x;
				}
			}
		}
	}
	MySortedArray IndeksBolsheDvukh()
	{
		MySortedArray ForHelp1;
		cout << "\nIndeksBolsheDvukh working";
		if (count > 0) //Проверка на то, пустой ли массив в котором мы будем искать индексы элементов, встречающихся больше двух раз.
		{
			for (int i = 0; i < count; i++)
			{
				int KolichestvoPovtorov = 1;
				for (int k = i + 1; k < count; k++)
				{
					if (ptr[i] == ptr[k])
					{
						KolichestvoPovtorov = KolichestvoPovtorov + 1;
					}
					else
					{
						if (KolichestvoPovtorov >= 3) //Элементы встречаются больше 2х раз, значит нужно запомнить их индексы.
						{
							for (i; i < k; i++)
							{
								ForHelp1.ptr[ForHelp1.count] = i;
								ForHelp1.count = ForHelp1.count + 1;
							}
						}
						k = count;//Заканчиваем второй цикл.
					}
				}
			}
			if (ForHelp1.count > 0)
			{
				return ForHelp1;
			}
			else
			{
				cout << "Ne udalos' nayti elementy, vstrechayushchikhsya bol'she dvukh raz." << endl;
				return ForHelp1;
			}
		}
		else
		{//Массив пустой.
			cout << "Massiv v kotorom my khoteli iskat' elementy, vstrechayushchikhsya bol'she dvukh raz, na samom dele pustoy." << endl;
			return ForHelp1;
		}
	}
	MySortedArray& push(const double& element)//Элемент будет поставлен в нужно место (отсортированность сохранится), но последний элемент замениться предпоследним, в случаи полностью заполненного массива.
	{
		cout << "\npush working";
		for (int i = 0; i < count; i++)
		{
			if (ptr[i] > element)
			{
				for (int k = count - 2; k >= i; k--)//Сдвиг элементов					
				{
					ptr[k + 1] = ptr[k];
				}
				ptr[i] = element;
				i = count; //Конец цикла.
			}
		}
		return *this;
	}
};



int main()
{
	double helpmassiv[15];
	cout << "HelpMassiv={";
	for (int i = 0; i < 15; i++)
	{
		helpmassiv[i] = i + 7;
		cout << helpmassiv[i];
		if (i != 14)
		{
			cout << ", ";
		}
	}
	cout << "}" << endl;

	MyArrayParent Massiv1;//Проверка конструктора 1.
	Massiv1.RandomMassiv();//Заполним массив1 случайными числами.
	cout << "\nMassiv 1"; Massiv1.print();//Выведем массив1.
	cout << endl;

	MyArrayParent Massiv2(helpmassiv, 15);//Проверка конструктора 2.
	cout << "\nMassiv 2"; Massiv2.print();//Выведем массив2.
	cout << endl;

	MyArrayParent Massiv3;//Этот масcив будем присваивать в 1ый.
	Massiv3.RandomMassiv();
	cout << "\nMassiv 3"; Massiv3.print();//Выведем массив3.
	cout << endl;

	cout << "\nTest 'operetor=' massiv 3 in massiv 1";
	Massiv1 = Massiv3;
	cout << "\nMassiv 1 posle testa 'operatora=' "; Massiv1.print(); cout << endl;

	cout << "\nTest 'operetor[]'";
	double abc = 0;
	abc = Massiv1[0];
	cout << "\nabs=" << abc << " Result of checking 'operator[]'" << endl;

	cout << "\nCopy Massiv 2 in Massiv 4";
	MyArrayParent Massiv4(Massiv2);
	cout << "\nMassiv 4"; Massiv4.print(); cout << endl << endl << endl << endl;

	double helpmassiv2[15];
	cout << "HelpMassiv2={";
	for (int i = 0; i < 15; i++)
	{
		helpmassiv2[i] = i + 4;
		cout << helpmassiv2[i];
		if (i != 14)
		{
			cout << ", ";
		}
	}
	cout << "}" << endl;

	MyArrayChild MassivChild1;//Проверка конструктора 1 для дочернего класса MyArrayChild.
	MassivChild1.RandomMassiv();//Заполним массивChild1 случайными числами.
	cout << "\nMassivChild1"; MassivChild1.print();//Выведем массивChild1.
	cout << endl;

	MyArrayChild MassivChild2(helpmassiv2, 15);//Проверка конструктора 2 для дочернего класса MyArrayChild.
	cout << "\nMassivChild2"; MassivChild2.print();//Выведем массивChild2.
	cout << endl;

	cout << "\nTest 'IndexOf'" << endl;
	double Element = 0;
	int index = 0;
	cout << "Vvedite znacheniye elementa. Znacheniye elementa="; cin >> Element;
	index = MassivChild2.IndexOf(Element);
	if (index != -1)
	{
		cout << "\nMassivChild2[" << index << "]=" << Element << endl;;
	}
	else
	{
		cout << "\nZnacheniye elementa=" << Element << " ne nayden v MassivChild2" << endl;
	};

	cout << "\nTest 'RemoveAt'" << endl;
	int indexRemove = 0;
	cout << "Vvedite indexRemove. IndexRemove="; cin >> indexRemove;
	MassivChild2.RemoveAt(indexRemove);
	cout << "MassivChild2"; MassivChild2.print();//Выведем MassivChild1.
	cout << endl;

	cout << "\nTest 'InsertAt'" << endl;
	int indexInsert = 0; double chislo = 0;
	cout << "Vvedite indexInsert. IndexInsert="; cin >> indexInsert;
	cout << "Vvedite chislo kotoroye khodite vstavit' v massiv. Chislo="; cin >> chislo;
	MassivChild2.InsertAt(indexInsert, chislo);
	cout << "MassivChild2"; MassivChild2.print();//Выведем MassivChild1.
	cout << endl << endl << endl;

	cout << "\nNapomnim MassivChild1"; MassivChild1.print();//Выведем массивChild1.
	cout << endl;
	//Для пункта B4 нам понадобится массив, такой же размерности, как и исходный массив. (Индексы будем искать из MassivChild1, предполагая, что мы не знаем его размерность).
	MyArrayChild MassivIndexovBolisheDvukh(MassivChild1.Size()); cout << endl;
	//Индексы элементов, которые встречаются больше двух, будем искать в массиве MassivChild1.
	MassivIndexovBolisheDvukh = MassivChild1.IndeksBolsheDvukh();
	cout << "\nMassiv indeksov elementy kotorogo vstrechayutsya bol'she dvukh raz:";
	MassivIndexovBolisheDvukh.print(); cout << endl << endl << endl;

	//Пункт С.
	MySortedArray MassivSorted1;//Проверка конструктора 1 для дочернего класса MySortedArray.
	MassivSorted1.SortZapolneniye();//Заполним MassivSorted1 случайными числами и отсортируем его.
	cout << "\nMassivSorted1"; MassivSorted1.print();//Выведем MassivSorted1.
	cout << endl;
	//Для пункта C4 нам понадобится массив, такой же размерности, как и исходный массив. (Индексы будем искать из MassivSorted1; массивы обладают одинаковой размерностью).
	MySortedArray MassivSortedIndexovBolisheDvukh; cout << endl;
	//Индексы элементов, которые встречаются больше двух, будем искать в массиве MassivSorted1.
	MassivSortedIndexovBolisheDvukh = MassivSorted1.IndeksBolsheDvukh();
	cout << "\nMassiv indeksov elementy kotorogo vstrechayutsya bol'she dvukh raz:";
	MassivSortedIndexovBolisheDvukh.print(); cout << endl;
	cout << "\nKakoy element vy khotite vstavit' v massiv (otsortirovannost' sokhranitsya)?" << endl;
	double x = 0;
	cout << "x=", cin >> x;
	MassivSorted1.push(x);
	cout << "\nMassiv posle togo kak my vstavili tuda element:";
	MassivSorted1.print();
	return 0;
}