#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class tree
{
private:
    struct Koren
    {
        char data;
        Koren* left;
        Koren* right;

        Koren(char value) {
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };
    Koren* root = nullptr;

    Koren* insertKoren(Koren* koren, char value) {
        if (koren == nullptr) {
            return new Koren(value);
        }

        if (value < koren->data) {
            koren->left = insertKoren(koren->left, value);
        }
        else if (value > koren->data) {
            koren->right = insertKoren(koren->right, value);
        }
        return koren;
    }

    void printTree(Koren* koren, int level) {
        if (koren == nullptr) {
            return;
        }
        printTree(koren->left, level + 1);
        cout << koren->data;
        printTree(koren->right, level + 1);
    }

    int countNodes(Koren* koren, int level = 0) {
        if (koren == nullptr) return 0;
        return 1 + countNodes(koren->left) + countNodes(koren->right);
    }

    bool find(Koren* koren, char value) {
        if (koren == nullptr) return false;
        if (koren->data == value) return true;
        if (value < koren->data) return find(koren->left, value);
        return find(koren->right, value);
    }

    Koren* findMin(Koren* koren) {
        if (koren == nullptr) return nullptr;
        while (koren->left != nullptr) {
            koren = koren->left;
        }
        return koren;
    }

    void clear(Koren* koren) {
        if (koren == nullptr) return;
        clear(koren->left);
        clear(koren->right);
        delete koren;
    }

public:
    tree() {
        root = nullptr;
    }

    ~tree() {
        clear(root);
    }

    void insert(char value) {
        root = insertKoren(root, value);
    }

    void print() {
        printTree(root, 0);
        cout << endl;
    }

    int count() {
        return countNodes(root);
    }

    bool contains(char value) {
        return find(root, value);
    }

    char min() {
        Koren* m = findMin(root);
        if (m == nullptr) return '\0';
        return m->data;
    }

    bool empty() {
        return root == nullptr;
    }
};