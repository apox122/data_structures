#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

class Heap {
private:
    int* heap;
    int size;
    int capacity;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void heapifyUp(int i) {
        while (i != 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < size && heap[l] > heap[largest]) {
            largest = l;
        }
        if (r < size && heap[r] > heap[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
    void resize(int newCapacity) {
        int* newHeapArray = new int[newCapacity]; // alokuj nową tablicę

        for (int i = 0; i < size; i++) {
            newHeapArray[i] = heap[i];
        }

        delete[] heap; // zwolnij starą tablicę
        heap = newHeapArray; // ustaw wskaźnik na nową tablicę
        capacity = newCapacity; // zaktualizuj pojemność
    }

public:
    Heap() {
        this->heap = new int[capacity];
        this->size = 0;
        this->capacity = capacity;
    }

    ~Heap() {
        delete[] heap;
    }

    void push(int x) {
        if (size >= capacity) {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        heap[size] = x;
        heapifyUp(size);
        size++;
    }

    int pop() {
        if (size == 0) {
            return -1;
        }

        int maxValue = heap[0];

        heap[0] = heap[size - 1];
        size--;

        heapifyDown(0);

        return maxValue;
    }

    void remove_by_value(int value) {
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {
                heap[i] = heap[size - 1];
                size--;

                heapifyUp(i);
                heapifyDown(i);

                return;
            }
        }
    }

    void remove_at(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        heap[index] = heap[size - 1];
        delete &heap[size - 1];
        size--;
        if (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            heapifyUp(index);
        } else {
            heapifyDown(index);
        }
    }
    int search_by_value(int x) {
        for (int i = 0; i < size; i++) {
            if (heap[i] == x) {
                cout<<"Jest"<<endl;
                return 1;
            }
        }
        cout<<"Nie ma"<<endl;
        return 0;
    }

    void read_from_file(string filename) {
        ifstream file(filename);

        if (!file) {
            throw runtime_error("Cannot open file");
        }

        int x;
        while (file >> x) {
            push(x);
        }

        file.close();
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};