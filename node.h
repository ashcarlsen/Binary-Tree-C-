#ifndef NODE_H
#define NODE_H
#include <iostream>
class Node {		//class 
public: 		//public values
	int value;
	Node* left;
	Node* right;
	Node(int number)		//Constructor
	{
		value = number;
		left = nullptr;
		right = nullptr;
	}
};

#endif