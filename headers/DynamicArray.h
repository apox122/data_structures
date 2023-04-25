//
// Created by apox1 on 03.04.2023.
//

#ifndef PROJEKT_DYNAMICARRAY_H
#define PROJEKT_DYNAMICARRAY_H


class DynamicArray {

    void push_back(int x);

    void push_front(int x);

    void pop_back();

    void pop_front();

    void remove_by_value(int x);

    void insert_at(int index, int x);

    void remove_at(int index);
    void search_by_value(int x);

    int get_size();

    void print();
};


#endif //PROJEKT_DYNAMICARRAY_H
