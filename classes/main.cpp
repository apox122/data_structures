#include <iostream>
#include <Windows.h>
#include "List.cpp"
#include <chrono>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Heap.cpp"
#include "DynamicArray.cpp"
#include "RedBlackTree.cpp"


List list;
Heap heap;
DynamicArray dynamicArray;
RedBlackTree tree;

int setValue();

int setIndex();

void menu();

void menuList();

void menuHeap();

void menuArray();

void menuColorTree();

void countTimeArray();

int loop();

string fileName();

int main() {
    menu();
    return loop();
}

int loop() {
    while (true) {
        char option = getchar();
        switch (option) {
            case '1':
                menuList();
                break;
            case '2':
                menuArray();
                break;
            case '3':
                menuHeap();
                break;
            case '4':
                menuColorTree();
                break;
            case '5':
                system("exit");
                return 0;
        }
    }
}

void menu() {
    char *menu[5];
    menu[0] = "\n1. Lista";
    menu[1] = "2. Tablica";
    menu[2] = "3. Kopiec";
    menu[3] = "4. Drzewo cz-cz";
    menu[4] = "5. Wyjdz";
    cout << "-----MENU GLOWNE-----";
    for (int i = 0; i < 5; ++i) {
        cout << menu[i];
        cout << "\n";
    }
}

void menuList() {
    char *menuList[10];
    menuList[0] = "1. Wstaw na poczatke listy";
    menuList[1] = "2. Wstaw na koniec ";
    menuList[2] = "3. Wstaw w dowolne miejsce";
    menuList[3] = "4. Usun z poczatku";
    menuList[4] = "5. Usun z konca";
    menuList[5] = "6. Usun podana wartosc";
    menuList[6] = "7. Usun z dowolnej pozycji";
    menuList[7] = "8. Wydrukuj cala liste";
    menuList[8] = "9. Wyszukaj wartosc";
    menuList[9] = "0. Wroc do poprzedniej strony";
    menuList[10] = "R. Wczytaj z pliku";
    cout << "-----Lista-----\n";
    for (int i = 0; i <= 10; ++i) {
        cout << menuList[i];
        cout << "\n";
    }
    getchar();
    char option = getchar();
    switch (option) {
        case '1':
            list.push_front(setValue());
            break;
        case '2':
            list.push_back(setValue());
            break;
        case '3':
            list.insert_at(setValue(), setIndex());
            break;
        case '4':
            list.pop_front();
            break;
        case '5':
            list.pop_back();
            break;
        case '6':
            list.remove_by_value(setValue());
            break;
        case '7':
            list.remove_at(setIndex() - 1);
            break;
        case '8':
            list.print();
            break;
        case '9':
            list.search_by_value(setValue());
            break;
        case 'R':
            list.read_from_file(fileName());
            break;
        case '0':
            main();
            break;
    }
    menu();
}

void menuHeap() {
    char *menuHeap[10];
    menuHeap[0] = "1. Wstaw do kopca";
    menuHeap[1] = "2. Usun z korzenia";
    menuHeap[2] = "3. Usun podana wartosc";
    menuHeap[3] = "4. Wydrukuj caly kopiec";
    menuHeap[4] = "5. Wyszukaj wartosc";
    menuHeap[5] = "R. Wczytaj z pliku";
    menuHeap[6] = "0. Wroc do poprzedniej strony";
    cout << "-----KOPIEC-----\n";
    for (int i = 0; i <= 6; ++i) {
        cout << menuHeap[i];
        cout << "\n";
    }
    getchar();
    char option = getchar();
    switch (option) {
        case '1':
            heap.push(setValue());
            break;
        case '2':
            heap.pop();
            break;
        case '3':
            heap.remove_by_value(setValue());
            break;
        case '4':
            heap.print();
            break;
        case '5':
            heap.search_by_value(setValue());
            break;
        case 'R':
            heap.read_from_file(fileName());
            break;
        case '0':
            main();
            break;
    }
    menu();
}

void menuArray() {
    char *menuArray[10];
    menuArray[0] = "1. Wstaw na poczatek tablicy";
    menuArray[1] = "2. Wstaw na koniec ";
    menuArray[2] = "3. Wstaw w dowolne miejsce";
    menuArray[3] = "4. Usun z poczatku";
    menuArray[4] = "5. Usun z konca";
    menuArray[5] = "6. Usun podana wartosc";
    menuArray[6] = "7. Usun z dowolnej pozycji";
    menuArray[7] = "8. Wydrukuj cala tablice";
    menuArray[8] = "9. Wyszukaj wartosc";
    menuArray[9] = "0. Wroc do poprzedniej strony";
    menuArray[10] = "R. Wczytaj z pliku";
    cout << "-----TABLICA-----\n";
    for (int i = 0; i <= 10; ++i) {
        cout << menuArray[i];
        cout << "\n";
    }
    getchar();
    char option = getchar();
    switch (option) {
        case '1':
            dynamicArray.push_front(setValue());
            break;
        case '2':
            dynamicArray.push_back(setValue());
            break;
        case '3':
            dynamicArray.insert_at(setIndex(), setValue());
            break;
        case '4':
            dynamicArray.pop_front();
            break;
        case '5':
            dynamicArray.pop_back();
            break;
        case '6':
            dynamicArray.remove_by_value(setValue());
            break;
        case '7':
            dynamicArray.remove_at(setIndex() - 1);
            break;
        case '8':
            dynamicArray.print();
            break;
        case '9':
            dynamicArray.search_by_value(setValue());
            break;
        case 'R':
            dynamicArray.read_from_file(fileName());
            break;
        case '0':
            main();
            break;
    }
    menu();
}

void menuColorTree() {
    char *menuTree[10];
    menuTree[0] = "1. Wstaw do drzewa";
    menuTree[1] = "2. Usun korzenia";
    menuTree[2] = "3. Usun wartosc";
    menuTree[3] = "4. Wydrukuj drzewo";
    menuTree[4] = "5. Wyszukaj wartosc";
    menuTree[5] = "0. Wroc do poprzedniej strony";
    menuTree[6] = "R. Wczytaj z pliku";
    cout << "-----Drzewo_Cz_Cz-----\n";
    for (int i = 0; i <= 5; ++i) {
        cout << menuTree[i];
        cout << "\n";
    }
    getchar();
    char option = getchar();
    switch (option) {
        case '1':
            tree.push(setValue());
            break;
        case '2':
            tree.pop();
            break;
        case '3':
            tree.deleteNode(setValue());
            break;
        case '4':
            tree.printTree();
            break;
        case '5':
            tree.search(setValue());
            break;
        case 'R':
            tree.read_from_file(fileName());
            break;
        case '0':
            main();
            break;
    }
    menu();
}

string fileName() {
    cout << "Podaj nazwe pliku [value.txt]\n";
    string filename;
    cin >> filename;
    return filename;
}

int setValue() {
    cout << "Podaj wartosc do wykonania operacji: \n";
    int a;
    cin >> a;
    return a;
}

int setIndex() {
    cout << "Podaj index: ";
    int a;
    cin >> a;
    return a;
}

void countTimeArray() {
    long avgTime = 0;
    LARGE_INTEGER start, end, freq;
    QueryPerformanceFrequency(&freq);
    srand(time(NULL));
    tree.read_from_file("C:\\Users\\apox1\\CLionProjects\\projekt\\dataFiles\\data.txt");
    for (int i = 0; i < 200; ++i) {
        int randomInt = rand() % 5000;
        int randomInt2 = rand() % 10000;
        QueryPerformanceCounter(&start);
        tree.pop();
        QueryPerformanceCounter(&end);
        double duration = (double) (end.QuadPart - start.QuadPart) / (double) freq.QuadPart;
        avgTime += duration * 1000000000;
    }
    auto avgTimeInNs = avgTime / 200;
    ofstream outFile("C:\\Users\\apox1\\CLionProjects\\projekt\\dataFiles\\file.txt", ios::app);
    if (outFile.is_open()) {
        outFile << avgTimeInNs << " ns" << std::endl;
        outFile.close();
        cout << "Average time saved to file: file.txt" << endl;
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
    cout << "Average time: " << avgTimeInNs << " ns" << endl;

}

