
#ifndef PROJEKT_LIST_H
#define PROJEKT_LIST_H

class List {

public:
    List();

    void push_back(int x);

    void push_front(int x);

    void pop_back();

    void pop_front();

    void remove_by_value(int x);

    int search_by_value(int x)

    void insert_at(int index, int x);

    int get_size();

    void print();

    void read_from_file(string filename);
};


#endif //PROJEKT_LIST_H
