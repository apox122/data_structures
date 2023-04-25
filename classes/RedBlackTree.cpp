
#include <iostream>
#include <fstream>

using namespace std;

struct Node2 {
    int value;
    Node2 *parent;
    Node2 *left;
    Node2 *right;
    int color;
};

typedef Node2 *NodePtr;

class RedBlackTree {
private:
    NodePtr root;
    NodePtr SENTINEL;

    void preOrderHelper(NodePtr node) {
        if (node != SENTINEL) {
            cout << node->value << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }

    void inOrderHelper(NodePtr node) {
        if (node != SENTINEL) {
            inOrderHelper(node->left);
            cout << node->value << " ";
            inOrderHelper(node->right);
        }
    }


    void postOrderHelper(NodePtr node) {
        if (node != SENTINEL) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            cout << node->value << " ";
        }
    }

    NodePtr searchTreeHelper(NodePtr node, int key) {
        if (node == SENTINEL || key == node->value) {
            return node;
        }

        if (key < node->value) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }

    void deleteFix(NodePtr x) {
        NodePtr s;
        while (x != root && x->color == 0) {
            if (x == x->parent->left) {
                s = x->parent->right;
                if (s->color == 1) {
                    s->color = 0;
                    x->parent->color = 1;
                    leftRotate(x->parent);
                    s = x->parent->right;
                }

                if (s->left->color == 0 && s->right->color == 0) {
                    s->color = 1;
                    x = x->parent;
                } else {
                    if (s->right->color == 0) {
                        s->left->color = 0;
                        s->color = 1;
                        rightRotate(s);
                        s = x->parent->right;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->right->color = 0;
                    leftRotate(x->parent);
                    x = root;
                }
            } else {
                s = x->parent->left;
                if (s->color == 1) {
                    s->color = 0;
                    x->parent->color = 1;
                    rightRotate(x->parent);
                    s = x->parent->left;
                }

                if (s->right->color == 0 && s->right->color == 0) {
                    s->color = 1;
                    x = x->parent;
                } else {
                    if (s->left->color == 0) {
                        s->right->color = 0;
                        s->color = 1;
                        leftRotate(s);
                        s = x->parent->left;
                    }

                    s->color = x->parent->color;
                    x->parent->color = 0;
                    s->left->color = 0;
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = 0;
    }

    void rbTransplant(NodePtr u, NodePtr v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteNodeHelper(NodePtr node, int key) {
        NodePtr z = SENTINEL;
        NodePtr x, y;
        while (node != SENTINEL) {
            if (node->value == key) {
                z = node;
            }

            if (node->value <= key) {
                node = node->right;
            } else {
                node = node->left;
            }
        }

        if (z == SENTINEL) {
            return;
        }

        y = z;
        int y_original_color = y->color;
        if (z->left == SENTINEL) {
            x = z->right;
            rbTransplant(z, z->right);
        } else if (z->right == SENTINEL) {
            x = z->left;
            rbTransplant(z, z->left);
        } else {
            y = minimum(z->right);
            y_original_color = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                rbTransplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            rbTransplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (y_original_color == 0) {
            deleteFix(x);
        }
    }

    void insertFix(NodePtr k) {
        NodePtr u;
        while (k->parent->color == 1) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    leftRotate(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right;

                if (u->color == 1) {
                    u->color = 0;
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = 0;
                    k->parent->parent->color = 1;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = 0;
    }

    void printHelper(NodePtr root, string indent, bool last) {
        if (root != SENTINEL) {
            cout << indent;
            if (last) {
                cout << "R--";
                indent += "   ";
            } else {
                cout << "L--";
                indent += "|  ";
            }

            string sColor = root->color ? "R" : "B";
            cout << root->value << "(" << sColor << ")" << endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

public:
    RedBlackTree() {
        SENTINEL = new Node2;
        SENTINEL->color = 0;
        SENTINEL->left = nullptr;
        SENTINEL->right = nullptr;
        root = SENTINEL;
    }


    void search(int k) {
        NodePtr result = searchTreeHelper(this->root, k);

        if (result != SENTINEL && result->value == k) {
            cout << "Jest" << endl;
            return;
        } else {
            cout << "Nie ma" << endl;
            return;
        }
    }

    NodePtr minimum(NodePtr node) {
        while (node->left != SENTINEL) {
            node = node->left;
        }
        return node;
    }

    void leftRotate(NodePtr x) {
        NodePtr y = x->right;
        x->right = y->left;
        if (y->left != SENTINEL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(NodePtr x) {
        NodePtr y = x->left;
        x->left = y->right;
        if (y->right != SENTINEL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    // Inserting a node
    void push(int key) {
        NodePtr node = new Node2;
        node->parent = nullptr;
        node->value = key;
        node->left = SENTINEL;
        node->right = SENTINEL;
        node->color = 1;

        NodePtr y = nullptr;
        NodePtr x = this->root;

        while (x != SENTINEL) {
            y = x;
            if (node->value < x->value) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->value < y->value) {
            y->left = node;
        } else {
            y->right = node;
        }

        if (node->parent == nullptr) {
            node->color = 0;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        insertFix(node);
    }

    NodePtr getRoot() {
        return this->root;
    }

    void pop() {
        deleteNode(getRoot()->value);
    }

    void deleteNode(int data) {
        deleteNodeHelper(this->root, data);
    }

    void printTree() {
        if (root) {
            printHelper(this->root, "", true);
        }
    }

    void read_from_file(const std::string &file) {
        ifstream input_file(file);

        if (!input_file) {
            cout << "Error opening file " << file << endl;
            return;
        }
        int val;
        while (input_file >> val) {
            push(val);
        }
        input_file.close();
    }

    void inorderTraversal(Node2 *node) {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }
};
