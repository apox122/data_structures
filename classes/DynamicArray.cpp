#include <iostream>
#include <fstream>

using namespace std;

class DynamicArray {
private:
    int *arr;
    int size;
    int capacity;

public:
    DynamicArray() {
        size = 0;
        capacity = 1;
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void push_back(int x) {
        if (size == capacity) {
            capacity *= 2;
            int *new_arr = new int[capacity];
            for (int i = 0; i < size; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
        arr[size] = x;
        size++;
    }

    void push_front(int x) {
        if (size == capacity) {
            capacity *= 2;
        }
        int *new_arr = new int[capacity];
        new_arr[0] = x;
        for (int i = 0; i < size; i++) {
            new_arr[i + 1] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        size++;
    }

    void pop_back() {
        if (size == 0) {
            return;
        }
        delete &arr[size - 1];
        size--;
    }

    void pop_front() {
        if (size == 0) {
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    void remove_by_value(int x) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == x) {
                for (int j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--;
                break;
            }
        }
    }

    void insert_at(int index, int x) {
        if (index < 0 || index > size) {
            cout << "Zly indeks\n";
            return;
        }
        if (size == capacity) {
            capacity *= 2;
            int *new_arr = new int[capacity];
            for (int i = 0; i < index; i++) {
                new_arr[i] = arr[i];
            }
            new_arr[index] = x;
            for (int i = index; i < size; i++) {
                new_arr[i + 1] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        } else {
            for (int i = size - 1; i >= index; i--) {
                arr[i + 1] = arr[i];
            }
            arr[index] = x;
        }
        size++;
    }

    void remove_at(int index) {
        if (index < 0 || index >= size) {
            cout <<"Zly indeks\n";
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    int search_by_value(int x) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == x) {
                cout << "Jest" << endl;
                return i;
            }
        }
        cout << "Nie ma" << endl;
        return -1;
    }

    void read_from_file(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Zla nazwa pliku\n" << endl;
            return;
        }
        int x;
        while (file >> x) {
            push_back(x);
        }
        file.close();
    }

    int get_size() {
        return size;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};