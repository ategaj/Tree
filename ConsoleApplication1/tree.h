#pragma once
#include <iostream>
using namespace std;
class tree
{
private:
	struct Koren
	{
		int data;
		Koren* left;
		Koren* right;
		
		Koren(int value) {
			data = value;
			left = nullptr;
			right = nullptr;
		}

	};
	Koren* root = nullptr;

	Koren* insertKoren(Koren* koren, int value) {
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
		for (int i = 0; i < level; i++) {
			cout << "   ";
		}
		cout << koren->data << endl;
		printTree (koren->right, level + 1);
		
		printTree (koren->left, level + 1);
		
	}
public:
	tree() {
		root = nullptr;
	}

	void insert(int value) {
		root = insertKoren(root, value);
	}

	void print() {
		printTree(root, 0);
		cout << endl;
	}


	
};

