

#ifndef PROJEKT_HEAP_H
#define PROJEKT_HEAP_H

class Heap {
public:
    void push(int x);

    void pop();

    void remove_by_value(int x);

    void remove_at(int index);

    int search_by_value(int x);

    void read_from_file(string file);

    void print();

    int get_size();


};

#endif //PROJEKT_HEAP_H
