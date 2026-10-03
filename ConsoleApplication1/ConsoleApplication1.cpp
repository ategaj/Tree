#include <iostream>
#include "tree.h"

int main()
{
	tree a;
	a.insert(2);
	a.insert(1);
	a.insert(5);
	a.insert(3);
	a.insert(4);
	a.insert(12);
	a.insert(0);
	a.insert(7);
	a.insert(8);
	a.insert(10);
	a.insert(3);
	a.print();
}

