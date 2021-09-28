# Laboratory-Works-Semester-2

## Practical Assignment № 1. Working with Sequential Containers.
### Zadanie 1.1 

[Task in code](./Zadanie%201.1/Zadanie%201.1.cpp)

<details>
    <summary>Input</summary>
    No input is required.
</details>

<details>
    <summary>Output</summary>   
    
    Pokazyvayu, chto konstruktor, metod print, settery i gettery rabotayut.

    Vector(0 ; 0)
    Vector(10 ; 0)
    Vector(30 ; 35)
    Zadayu vektory A novyye znacheniya.
    Vector(9 ; 8)
    Poluchayu koordinaty vektorov.
    x1=10 value coordinate X vector B
    y1=35 value coordinate Y vector C

    Perekhozhu k vypolneniyu zadaniya - pereopredeleniyu operatsiy.
    Vector C:
    Vector(30 ; 35)

    Proyektsiya vectora C na os' abstsiss=30
    Proyektsiya vectora C na os' ordinat=35

    Vector osi l:
    Vector(28 ; 7)
    Proyektsiya vectora C na vector l=38

</details>

### Zadanie 1.2

[Task in code](./Zadanie%201.2/Zadanie%201.2.cpp)

<details>
    <summary>Input</summary>
    The following input was entered to obtain such an output:
    
    5   
    70

</details>

<details>
    <summary>Output</summary>   

    Pereopredelonnyye operatsii.
    !- proketsiya na os' abstsiss; ~ -proketsiya na os' ordinat; && - proyektsiya na drugoy vektor.
    Vector C:
    Vector(30 ; 35)

    Proyektsiya vectora C na os' abstsiss=30
    Proyektsiya vectora C na os' ordinat=35

    Vector osi l:
    Vector(28 ; 7)
    Proyektsiya vectora C na vector l=37.593


    Perehodim k deleniyu veshchestvennykh chisel na vektor.
    Vvedite chislo. Chislo razdelit'sya na etot Vektor   (C/m = {Cx/m, Cy/m}). m=5
    Rezul'tat deleniya vektora na veshchestvennoye chislo:
    Vector(6 ; 7)



    Po zadaniyu trebuyetsya organizovat' deleniye veshchestvennogo chisla na vektor v kachestve druzhestvennoy funktsii dlya klassa naslednika.
    Ya sozdal naslednik klassa Vector. V naslednike realizoval konstruktory, pereopredelil metod print i dobavil druzhestvennuyu funktsiyu deleniye veshchestvennogo chisla na vektor.Pokazyvayu, chto konstruktor, metod print, settery i gettery rabotayut dlya naslednika klassa.

    SecondVector(0 ; 0)
    SecondVector(10 ; 0)
    SecondVector(30 ; 35)
    Zadadim vektory A novyye znacheniya.
    SecondVector(9 ; 8)
    Poluchayu koordinaty vektorov.
    x1=10 value coordinate X vector B
    y1=35 value coordinate Y vector AS
    Konstruktor, metod print, gettery i settery dlya naslednika rabotayut pravil'no.

    SecondVector AS:
    SecondVector(30 ; 35)
    Vvedite chislo. Vektor razdelit'sya na eto chislo (d / AS = {d/ASx, d/ASy}). d=70
    Rezul'tat deleniya vektora na veshchestvennoye chislo:
    SecondVector(2.33333 ; 2)

</details>

## Practical Assignment № 2. Arrays.
### Zadanie 2

[Task in code](./Zadanie%202/Zadanie%202.cpp)

<details>
    <summary>Input</summary>
    The following input was entered to obtain such an output:
    
    10
    0
    1
    100
    8
</details>

<details>
    <summary>Output</summary>   

    HelpMassiv={7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21}

    MyArray constructor 1
    RandomMassiv is working
    Massiv 1
    MyArr, size: 100, values: {8, 50, 74, 59, 31, 73, 45, 79, 24, 10, 41, 66, 93, 43, 88, 4, 28, 30, 41, 13, 4, 70, 10, 58, 61, 34, 100, 79, 17, 36, 98, 27, 13, 68, 11, 34, 80, 50, 80, 22, 68, 73, 94, 37, 86, 46, 29, 92, 95, 58, 2, 54, 9, 45, 69, 91, 25, 97, 31, 4, 23, 67, 50, 25, 2, 54, 78, 9, 29, 34, 99, 82, 36, 14, 66, 15, 64, 37, 26, 70, 16, 95, 30, 2, 18, 96, 6, 5, 52, 99, 89, 24, 6, 83, 53, 67, 17, 38, 39, 45}

    MyArray constructor 2
    Massiv 2
    MyArr, size: 15, values: {7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21}

    MyArray constructor 1
    RandomMassiv is working
    Massiv 3
    MyArr, size: 100, values: {2, 98, 72, 29, 38, 59, 78, 98, 95, 5, 10, 32, 46, 76, 36, 99, 43, 100, 69, 13, 61, 58, 95, 9, 96, 69, 14, 31, 7, 63, 43, 66, 83, 53, 68, 22, 96, 13, 72, 2, 91, 32, 39, 58, 17, 91, 41, 80, 36, 7, 73, 99, 96, 20, 55, 24, 90, 61, 6, 27, 24, 7, 14, 71, 39, 95, 21, 45, 67, 35, 27, 95, 64, 39, 45, 91, 51, 60, 24, 48, 86, 18, 73, 40, 48, 86, 97, 86, 24, 21, 45, 69, 36, 16, 26, 35, 43, 12, 80, 53}

    Test 'operetor=' massiv 3 in massiv 1
    operator =
    Massiv 1 posle testa 'operatora='
    MyArr, size: 100, values: {2, 98, 72, 29, 38, 59, 78, 98, 95, 5, 10, 32, 46, 76, 36, 99, 43, 100, 69, 13, 61, 58, 95, 9, 96, 69, 14, 31, 7, 63, 43, 66, 83, 53, 68, 22, 96, 13, 72, 2, 91, 32, 39, 58, 17, 91, 41, 80, 36, 7, 73, 99, 96, 20, 55, 24, 90, 61, 6, 27, 24, 7, 14, 71, 39, 95, 21, 45, 67, 35, 27, 95, 64, 39, 45, 91, 51, 60, 24, 48, 86, 18, 73, 40, 48, 86, 97, 86, 24, 21, 45, 69, 36, 16, 26, 35, 43, 12, 80, 53}

    Test 'operetor[]'
    operator []
    abs=2 Result of checking 'operator[]'

    Copy Massiv 2 in Massiv 4
    Copy constructor
    Massiv 4
    MyArr, size: 15, values: {7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21}



    HelpMassiv2={4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}

    MyArray constructor 1
    RandomMassiv is working
    MassivChild1
    MyArrChild, size: 100, values: {45, 96, 19, 97, 93, 16, 92, 34, 70, 98, 54, 48, 26, 11, 63, 12, 9, 78, 62, 26, 36, 69, 96, 77, 68, 40, 75, 32, 57, 2, 73, 61, 95, 85, 56, 90, 8, 16, 94, 70, 81, 56, 56, 7, 64, 3, 77, 9, 50, 32, 45, 39, 9, 98, 52, 50, 4, 32, 32, 15, 20, 76, 10, 81, 30, 24, 55, 61, 38, 46, 18, 26, 1, 57, 65, 98, 49, 5, 51, 51, 77, 13, 55, 98, 5, 82, 49, 66, 79, 100, 10, 30, 54, 84, 48, 8, 74, 23, 6, 77}

    MyArray constructor 2
    MassivChild2
    MyArrChild, size: 15, values: {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}

    Test 'IndexOf'
    Vvedite znacheniye elementa. Znacheniye elementa=10

    IndexOf working
    MassivChild2[6]=10

    Test 'RemoveAt'
    Vvedite indexRemove. IndexRemove=0

    RemoveAt working
    MassivChild2
    MyArrChild, size: 14, values: {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}

    Test 'InsertAt'
    Vvedite indexInsert. IndexInsert=1
    Vvedite chislo kotoroye khodite vstavit' v massiv. Chislo=100

    InsertAt working
    MassivChild2
    MyArrChild, size: 15, values: {5, 100, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}



    Napomnim MassivChild1
    MyArrChild, size: 100, values: {45, 96, 19, 97, 93, 16, 92, 34, 70, 98, 54, 48, 26, 11, 63, 12, 9, 78, 62, 26, 36, 69, 96, 77, 68, 40, 75, 32, 57, 2, 73, 61, 95, 85, 56, 90, 8, 16, 94, 70, 81, 56, 56, 7, 64, 3, 77, 9, 50, 32, 45, 39, 9, 98, 52, 50, 4, 32, 32, 15, 20, 76, 10, 81, 30, 24, 55, 61, 38, 46, 18, 26, 1, 57, 65, 98, 49, 5, 51, 51, 77, 13, 55, 98, 5, 82, 49, 66, 79, 100, 10, 30, 54, 84, 48, 8, 74, 23, 6, 77}

    MyArray constructor 3

    IndeksBolsheDvukh working
    MyArray constructor 3
    operator =
    MyArrayChild destructor
    MyArray destructor
    Massiv indeksov elementy kotorogo vstrechayutsya bol'she dvukh raz:
    MyArrChild, size: 21, values: {9, 53, 75, 83, 12, 19, 71, 16, 47, 52, 23, 46, 80, 99, 27, 49, 57, 58, 34, 41, 42}



    MyArray constructor 1
    SortZapolneniye is working
    MassivSorted1
    MySortedArray, size: 100, values: {1, 3, 4, 4, 6, 7, 7, 9, 10, 10, 10, 11, 13, 13, 15, 17, 18, 19, 19, 22, 23, 24, 24, 24, 25, 28, 32, 33, 35, 37, 39, 41, 46, 51, 51, 56, 56, 56, 58, 58, 65, 66, 67, 69, 70, 70, 71, 74, 74, 76, 78, 79, 80, 81, 84, 85, 85, 86, 88, 88, 90, 92, 92, 96, 98, 99, 99, 101, 103, 105, 109, 109, 112, 114, 115, 116, 119, 119, 121, 122, 123, 123, 125, 126, 126, 127, 131, 137, 139, 144, 145, 146, 147, 151, 151, 152, 153, 155, 158, 159}

    MyArray constructor 1

    MyArray constructor 1
    IndeksBolsheDvukh working
    operator =
    MySortedArray destructor
    MyArrayChild destructor
    MyArray destructor
    Massiv indeksov elementy kotorogo vstrechayutsya bol'she dvukh raz:
    MySortedArray, size: 9, values: {8, 9, 10, 21, 22, 23, 35, 36, 37}

    Kakoy element vy khotite vstavit' v massiv (otsortirovannost' sokhranitsya)?
    x=8

    push working
    Massiv posle togo kak my vstavili tuda element:
    MySortedArray, size: 100, values: {1, 3, 4, 4, 6, 7, 7, 8, 9, 10, 10, 10, 11, 13, 13, 15, 17, 18, 19, 19, 22, 23, 24, 24, 24, 25, 28, 32, 33, 35, 37, 39, 41, 46, 51, 51, 56, 56, 56, 58, 58, 65, 66, 67, 69, 70, 70, 71, 74, 74, 76, 78, 79, 80, 81, 84, 85, 85, 86, 88, 88, 90, 92, 92, 96, 98, 99, 99, 101, 103, 105, 109, 109, 112, 114, 115, 116, 119, 119, 121, 122, 123, 123, 125, 126, 126, 127, 131, 137, 139, 144, 145, 146, 147, 151, 151, 152, 153, 155, 158}
    MySortedArray destructor
    MyArrayChild destructor
    MyArray destructor
    MySortedArray destructor
    MyArrayChild destructor
    MyArray destructor
    MyArrayChild destructor
    MyArray destructor
    MyArrayChild destructor
    MyArray destructor
    MyArrayChild destructor
    MyArray destructor
    MyArray destructor
    MyArray destructor
    MyArray destructor
    MyArray destructor

</details>

## Practical Assignment № 3. Multiple Inheritance.
### Zadanie 3

[Task in code](./Zadanie%203/Zadanie%203.cpp)

<details>
    <summary>Input</summary>
    No input is required.
</details>

<details>
    <summary>Output</summary>   
    
    *****************************************************************************

    Class A1 constructor
    Class A1 constructor
    Class B1 constructor
    Class A1 constructor
    Class B2 constructor
    Class A1 constructor
    Class B3 constructor
    Class A1 constructor
    Class B1 constructor
    Class B2 constructor
    Class B3 constructor
    Class C1 constructor
    Class A1 constructor
    Class B1 constructor
    Class B2 constructor
    Class B3 constructor
    Class C2 constructor
    Class A1 constructor
    Class B1 constructor
    Class B2 constructor
    Class B3 constructor
    Class C3 constructor

    *****************************************************************************

    Variable of A1 class
    Variable of B1 class
    Variable of B2 class
    Variable of B3 class
    Variable of C1 class
    Variable of C2 class
    Variable of C3 class

    *****************************************************************************

    a1=0
    b1=0, a1=0
    b2=0, a1=0
    b3=0, a1=0
    c1=0, b1=0, b2=0, b3=0, a1=0
    c2=0, b1=0, b2=0, b3=0, a1=0
    c3=0, b1=0, b2=0, b3=0, a1=0

    *****************************************************************************

    Class A1 constructor
    Class A1 constructor
    Class B1 constructor
    Class A1 constructor
    Class B2 constructor
    Class A1 constructor
    Class B3 constructor
    Class A1 constructor
    Class B1 constructor
    Class B2 constructor
    Class B3 constructor
    Class C1 constructor
    Class A1 constructor
    Class B1 constructor
    Class B2 constructor
    Class B3 constructor
    Class C2 constructor
    Class A1 constructor
    Class B1 constructor
    Class B2 constructor
    Class B3 constructor
    Class C3 constructor

    *****************************************************************************

    Variable of A1 class
    Variable of B1 class
    Variable of B2 class
    Variable of B3 class
    Variable of C1 class
    Variable of C2 class
    Variable of C3 class

    *****************************************************************************

    a1=10
    b1=5, a1=15
    b2=6, a1=20
    b3=7, a1=25
    c1=1, b1=2, b2=3, b3=4, a1=10000
    c2=2000, b1=11, b2=12, b3=13, a1=14
    c3=3000, b1=91, b2=92, b3=93, a1=94

    *****************************************************************************
</details>

## Practical Assignment № 4. Strings.
### Zadanie 4

[Task in code](./Zadanie%204/Zadanie%204.cpp)

<details>
    <summary>Input</summary>
    No input is required.
</details>

<details>
    <summary>Output</summary>   

    ************************************************************************************
    (Variable B) Text=Hello	 len = 5
    (Variable C) Text=Goodbye	 len = 7
    (Variable D (copy B)) Text=Hello	 len = 5
    Test operetor= (B = C)
    (Variable B) Text=Goodbye	 len = 7
    Kol-vo simvolov = 7
    ************************************************************************************
    (Variable B1) Text=Morning	 len = 7
    (Variable C1) Text=Night	 len = 5
    (Variable D1 (copy B1)) Text=Morning	 len = 7
    Test operetor= (B1 = C1)
    (Variable B1) Text=Morning	 len = 7
    Kol-vo simvolov = 7
    ************************************************************************************
    (Variable Q) Text=Easy come, easy go	 len = 18
    The number of fives of characters for which the average is greater than the average for the entire line = 2
    ************************************************************************************

</details>

## Practical Assignment № 5. Matrices.
### Zadanie 5

[Task in code](./Zadanie%205/Zadanie%205.cpp)

<details>
    <summary>Input</summary>
    No input is required.
</details>

<details>
    <summary>Output</summary>   

    Exception has been caught: WrongSizeException: Non-positive size of matrix.
    ****************************************************
    Print matrix
    42 68 35 1 70
    25 79 59 63 65
    ****************************************************
    Print matrix
    42 68 35 1 70
    25 79 59 63 65
    ****************************************************
    Print matrix
    6 46 82 28 62
    92 96 43 28 37
    92 5 3 54 93
    83 22 17 19 96
    48 27 72 39 70
    ****************************************************
    Print matrix
    6 46 82 28 62
    92 96 43 28 37
    92 5 3 54 93
    83 22 17 19 96
    48 27 72 39 70
    ****************************************************
    Print matrix
    6 46 82 28 62
    92 5 3 54 93
    83 22 17 19 96
    ****************************************************
    Exception has been caught: IndexOutOfBoundsException: Obrashcheniye k nesushchestvuyushchemu indeksu.
    ****************************************************
    Exception has been caught: IndexOutOfBoundsException: Obrashcheniye k nesushchestvuyushchemu indeksu.
    ****************************************************
    Sokhranim matritsu B v fayl.
    Print matrix
    6 46 82 28 62
    92 96 43 28 37
    92 5 3 54 93
    83 22 17 19 96
    48 27 72 39 70

    The file is open.
    Data has been successfully written to file.
    The file is closed.
    ****************************************************
    Prochitayem dannyye iz fayla.
    The file is open.
    Reading...
    The file is closed.

    ***************************************************************
    Print matrix
    6 46 82 28 62
    92 96 43 28 37
    92 5 3 54 93
    83 22 17 19 96
    48 27 72 39 70
    Rezul'tat sovpadayet s tem, chto my zapisyvali v fayl.
    ****************************************************

</details>

## Practical Assignment № 7. Sorting Algorithms.
### Zadanie 7

[Task in code](./Zadanie%207/Zadanie%207.cpp)

<details>
    <summary>Input</summary>
    The following input was entered to obtain such an output:
    
    10
</details>

<details>
    <summary>Output</summary>   

    Enter the size of the array: 10
    ***************************************************************************************************
    !CountingSort!
    41      467     334     500     169     724     478     358     962     464
    41      169     334     358     464     467     478     500     724     962
    ***************************************************************************************************
    !MergeSort!
    41      467     334     500     169     724     478     358     962     464
    41      169     334     358     464     467     478     500     724     962
    ***************************************************************************************************
    !Test: save array to file!
    The file is open.
    Data has been successfully written to file.
    The file is closed.
    ***************************************************************************************************
    ***************************************************************************************************
    !Test: take size array from file!
    The answer must be = 10
    The file is open.
    We count the number of elements...
    size = 10
    The file is closed.
    ***************************************************************************************************
    ***************************************************************************************************
    !Test: take data array from file!
    The file is open.
    We count the number of elements...
    size = 10
    The file is closed.
    ***************************************************************************************************
    The file is open.
    Reading...
    The file is closed.
    ***************************************************************************************************
    41      467     334     500     169     724     478     358     962     464
    ***************************************************************************************************



    Okay. Let's compare the running time of sorting algorithms on different arrays.



    ***************************************************************************************************
    The file is open.
    Data has been successfully written to file.
    The file is closed.
    ***************************************************************************************************
    The file is open.
    Data has been successfully written to file.
    The file is closed.
    ***************************************************************************************************
    The file is open.
    Data has been successfully written to file.
    The file is closed.
    ***************************************************************************************************
    ***************************************************************************************************
    !File 1!
    ***************************************************************************************************
    !CountingSort!
    The file is open.
    Reading...
    The file is closed.
    ***************************************************************************************************
    0.003
    ---------------------------------------------------------------------------------------------------
    !MergeSort!
    The file is open.
    Reading...
    The file is closed.
    ***************************************************************************************************
    0.039
    ***************************************************************************************************
    !File 2!
    ***************************************************************************************************
    !CountingSort!
    The file is open.
    Reading...
    The file is closed.
    ***************************************************************************************************
    0.002
    ---------------------------------------------------------------------------------------------------
    !MergeSort!
    The file is open.
    Reading...
    The file is closed.
    ***************************************************************************************************
    0.037
    ***************************************************************************************************
    !File 3!
    ***************************************************************************************************
    !CountingSort!
    The file is open.
    Reading...
    The file is closed.
    ***************************************************************************************************
    0.002
    ---------------------------------------------------------------------------------------------------
    !MergeSort!
    The file is open.
    Reading...
    The file is closed.
    ***************************************************************************************************
    0.047
    ***************************************************************************************************

</details>