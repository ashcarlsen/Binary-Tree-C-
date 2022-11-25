#ifndef TREE_H
#define TREE_H
#include "node.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
class Tree {		//class
public:					//public members
	Node* root;
	Tree()				//consructor
	{
		root = nullptr;
	}
	~Tree()
	{
		deconstruct(root);
	}
	void deconstruct(Node* n);
	void newNode(int value);	//methods
	void deleteNode(int number);
	void outputTree(Node* root, std::string);
	void outputNode(Node* n, std::ofstream& file);
};

#endif