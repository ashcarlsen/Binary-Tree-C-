#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "tree.h"
/********************************************************************************
*
*	Name: main
*
*	Function: create a binary tree with insertion from an input file and output 
*			  to a command line output file
*
*	Inputs: argc being the number of command line args and argv being a string array
*
*	Outputs: none
*
**********************************************************************************
*
*Begin
*	define variables
*	try
*		if not right ammount of command line args 	
*			then throw the number of args
*		create string variables based on command line file args
*		open the input file
*		if the file doesn't open
*			throw the file name
*		while the file isn't at it's end
*			read in the operator and value
*			if the operator is an a
*				add that value to the tree
*			else if the operator is a d
*				delete that value from the tree
*			else
*				throw the operator
*		EndLoop
*	catch int
*		print error for number of args passed in
*	catch string
*		print error of file name that failed to open
*	catch char
*		print error for the wrong operator in input file
*	output the binary tree to the output file
*End
********************************************************************************/
int main(int argc, char* argv[])
{
	Tree binaryTree;	//define variables
	char validOperator = '\0';
	int insertValue = 0;
	std::string command1, command2;
	try 			//try
	{
		//if not right ammount of command line args
		if(argc != 3)
		{
			//throw the number of args
			throw argc;
		}
		//create string variables based on command line file args
		command1 = argv[1];
		command2 = argv[2];
		std::ifstream inputFile;
		//open the input file
		inputFile.open(command1, std::ios::in);
		//if the file doesn't open
		if (!inputFile.is_open())
		{
			//throw the file name
			throw command1;
		}
		//while the file isn't at its end
		while (!inputFile.eof())
		{
			//read the operator and value
			inputFile >> validOperator;
			inputFile >> insertValue;
			//if the operator is an a 
			if (validOperator == 'a')
			{
				//add that value to the tree
				binaryTree.newNode(insertValue);
			}
			//else if the operator is a d
			else if (validOperator == 'd')
			{
				//delete that value from the node
				binaryTree.deleteNode(insertValue);
			}
			//else
			else 
			{
				//throw the operator
				throw validOperator;
			}
		}//EndLoop
	}
	catch (int e)		//catch int
	{
		//print error on how many command line args there is
		std::cout << "\033[1;31mInvalid number of command line arguments: \033[1;31m" << "\033[1;33m" << argc << "\033[1;33m" << std::endl;
		exit(1);
	}
	catch (std::string e)	//catch string
	{
		//print error of file that didn't open
		std::cout << "\"" << e << "\"" << " did not open." << std::endl;
		exit(1);
	}
	catch (char e)	//catch char
	{ 
	//print error of invalid operator in input file
		std::cout << "Invalid operator: " << e << std::endl;
		exit(1);
	}
	//output tree to the output file
	binaryTree.outputTree(binaryTree.root, command2);
	return 0;	//End
}