#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node *prev;
};

class List {
private:
    Node *head;
    Node *tail;
    int size;

public:
    List() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~List() {
        while (head != NULL) {
            Node *current_node = head;
            head = head->next;
            delete current_node;
        }
        size = 0;
        tail = NULL;
    }

    void push_front(int value) {
        Node *new_node = new Node();
        new_node->value = value;
        new_node->prev = NULL;
        new_node->next = head;

        if (head != NULL) {
            head->prev = new_node;

        } else {
            tail = new_node;
        }

        head = new_node;
        size++;
    }

    void push_back(int value) {
        Node *new_node = new Node();
        new_node->value = value;
        new_node->next = NULL;
        new_node->prev = tail;

        if (tail != NULL) {
            tail->next = new_node;
        } else {
            head = new_node;
        }

        tail = new_node;
        size++;
    }

    void pop_back() {
        if (tail != NULL) {
            Node *last_node = tail;
            tail = tail->prev;

            if (tail != NULL) {
                tail->next = NULL;
            } else {
                head = NULL;
            }
            delete last_node;
            size--;
        }
    }

    int search_by_value(int value) {
        Node *current_node = head;
        while (current_node != NULL) {
            if (current_node->value == value) {
                cout << "Jest" << endl;
                return 1;
            }
            current_node = current_node->next;
        }
        cout << "Nie ma" << endl;
        return 0;
    }

    void pop_front() {
        if (head != NULL) {
            Node *first_node = head;
            head = head->next;

            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }

            delete first_node;
            size--;
        }
    }

    void remove_by_value(int value) {
        Node *current_node = head;

        while (current_node != NULL) {
            if (current_node->value == value) {
                if (current_node == head) {
                    pop_front();
                } else if (current_node == tail) {
                    pop_back();
                } else {
                    current_node->prev->next = current_node->next;
                    current_node->next->prev = current_node->prev;
                    delete current_node;
                    size--;
                }
                break;
            }
            current_node = current_node->next;
        }
    }

    void insert_at(int value, int index) {
        if (index < 0 || index > size) {
            cout << "Zly index\n";
        }

        if (index == 0) {
            push_front(value);
            return;
        }

        if (index == size) {
            push_back(value);
            return;
        }

        Node *new_node = new Node();
        new_node->value = value;

        Node *current_node = head;
        for (int i = 0; i < index - 1; i++) {
            new_node->prev = current_node;
            new_node->next = current_node->next;
            current_node->next->prev = new_node;
            current_node->next = new_node;
            size++;
        }
    }

    void remove_at(int index) {
        if (index < 0 || index >= size) {
            cout << "Zly index\n";
            return;
        }

        if (index == 0) {
            pop_front();
            return;
        }

        if (index == size - 1) {
            pop_back();
            return;
        }

        Node *current_node = head;
        for (int i = 0; i < index; i++) {
            current_node = current_node->next;
        }

        current_node->prev->next = current_node->next;
        current_node->next->prev = current_node->prev;
        delete current_node;
        size--;
    }

    int get_size() const {
        return size;
    }

    void print() {
        Node *current_node = head;

        while (current_node != nullptr) {
            cout << current_node->value << " ";
            current_node = current_node->next;
        }

        cout << endl;
    }

    void read_from_file(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Nie mozna otworzyc pliku\n" << endl;
            return;
        }
        int value;
        while (file >> value) {
            push_back(value);
        }

        file.close();
    }
};