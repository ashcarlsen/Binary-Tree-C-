#include "tree.h"

/********************************************************************************
*
*	Name: newNode
*
*	Function: takes in a value and create a Node to add to the binary tree
*
*	Inputs: an int value
*
*	Outputs: none
*
**********************************************************************************
*
*Begin
*	create a new Node
*	create a pointer that starts at the root
*	if tree is empty
*		start the tree with the new Node
*	while compare isn't the nullptr
*		if our node is less than the comparing node and the compare has an empty left spot
*			set the left spot to our new node
*			set compare to the nullptr
*		else if our node is less than the comparing node 
*			set compare to it's left subnode
*		else if our node is greater than the comparing node and the compare has an empty right 
*			set the right spot to our new node
*			set compare to the nullptr
*		else if our node is greater than the comparing node
*			set compare to its right subnode
*		else if compares value is the same as our value
*			delete our new node
*			set compare to nullptr
*	EndLoop
*End
********************************************************************************/

void Tree::newNode(int value)
{
	//create a new Node
	Node* p = new Node(value);
	//create a pointer that starts at the root
	Node* compare = root;
	//if the tree is empty 
	if (compare == nullptr)
	{
		//start the tree with the new Node
		root = p;
	}
	//while compare node isn't the nullptr
	while (compare != nullptr)
	{
		//if our node is less than the comparing node and the compare has an empty left spot
		if (p->value < compare->value && compare->left == nullptr)
		{
			//set the left spot to our new node
			compare->left = p;
			//set compare to the nullptr
			compare = nullptr;
		}
		//else if our node is less than the comparing node
		else if (p->value < compare->value)
		{
			//set compare to its left subnode
			compare = compare->left;
		}
		//else if our node is greater than the comparing node and the compare has an empty right
		else if (p->value > compare->value && compare->right == nullptr)
		{
			//set the right subnode to our new node
			compare->right = p;
			//set compare to the nullptr
			compare = nullptr;
		}
		//else if our node is greater than the comparing node
		else if (p->value > compare->value)
		{
			//set compare to its right subnode
			compare = compare->right;
		}
		//else if compares value is the same as our value
		else if (p->value == compare->value)
		{
			//delete our new node
			delete p;
			//set compare to the nullptr
			compare = nullptr;
		}
	}	//EndLoop
}	//End

/*******************************************************************
*
*	Name: deleteNode
*
*	Function: take a value and delete it from a binary tree object
*
*	Inputs: and int number
*
*	Outputs: none
*
*********************************************************************
*
*Begin
*	define pointers
*	forloop that finds the node that needs to be deleted
*		if the number is less than our value
*			move previous to current
*			move current to its left subnode
*			check if current is null
*		else if the number is more than our value
*			move previous to current
*			move current to its right subnode
*			check if current is null
*	EndLoop when current points to the node with value to be deleted
*	if current has no subnodes on either side
*		see if previous is on the right or left
*		set the resulting pointer to null
*		delete current
*	else if current has only a subnode on the right
*		see if previous is on the right or left
*		set the resulting pointer to currents right
*		delete current
*	else if current has only a subnode on the left
*		see if previous is on the right or left
*		set the resulting pointer to currents left
*		delete current
*	else if current has subnodes on both sides
*		create two more pointers
*		set a pointer to the left subnode
*		set a previousfinder node to the current node to be deleted
*		Loop while the finder has a node to its right side
*			set previous to finder
*			set finder equal to its right subnode
*		EndLoop when hit a spot with no more right subnodes	
*		set currents value to our finders value
*		if finder has a left subnode 
*			set previous right pointer to the left subnode
*		else
*			set it null
*		delete finder
*End
**************************************************************************/

void Tree::deleteNode(int number)
{
	//define pointers
	Node* current = root;
	Node* previous = nullptr;
	//forloop that finds the node that needs to be deleted
	if(current == nullptr)
	{
		return;
	}
	for(;current->value != number;)
	{
		//if the number is less than our value
		if(number < current->value)
		{
			//move previous to current
			previous = current;
			//move current to its left subnode
			current = current->left;
			//check if current is null
			if(current == nullptr)
			{
				return;
			}
		}
		//else if the number is more than our value
		else if(number > current->value)
		{
			//move previous to current
			previous = current;
			//move current to its right subnode
			current = current->right;
			//check if current is null
			if(current == nullptr)
			{
				return;
			}
		}
	} //EndLoop when current points to the node with value to be deleted
	//if current has no subnodes on either side
	if(current->left == nullptr && current->right == nullptr)
	{
		//see if previous is on the right or left
		//set the resulting pointer to null
		if(previous->value < current->value)
		{
			previous->right = nullptr;
		}
		else if(previous->value > current->value)
		{
			previous->left = nullptr;
		}
		//delete current
		delete current;
	}
	//else if current has only a subnode on the right
	else if(current->left == nullptr && current->right != nullptr)
	{
		//see if previous is on the right or left
		//set the resulting pointer to currents right
		if(previous->value < current->value)
		{
			previous->right = current->right;
		}
		else
		{
			previous->left = current-> right;
		}
		//delete current
		delete current;
	}
	//else if current has only a subnode on the left
	else if(current->right == nullptr && current->left != nullptr)
	{
		//see if previous is on the right or left
		//set the resulting pointer to currents left
		if(previous->value < current->value)
		{
			previous->right = current->left;
		}
		else
		{
			previous->left = current->left;
		}
		//delete current
		delete current;
	}
	//else if current has subnodes on both sides
	else if(current->right != nullptr && current->left != nullptr)
	{
		//create two more pointers
		//set a pointer to the left subnode
		Node* finder = current->left;
		//set a previousfinder node to the current node to be deleted
		Node* prevfinder = current;
		//Loop while the finder has a node to its right side
		while(finder->right != nullptr)
		{
			//set previous to finder
			prevfinder = finder;
			//set finder equal to its right subnode
			finder = finder->right;
		} //EndLoop when hit a spot with no more right subnodes	
		//set currents value to our finders value
		current->value = finder->value;
		//if finder has a left subnode 
		if(finder->left != nullptr)
		{
			//set previous right pointer to the left subnode
			prevfinder->right = finder->left;
		}
		//else
		else
		{
			//set it null
			prevfinder->right = nullptr;
		}
		//delete finder
		delete finder;
	}
	
}	//End

/******************************************************************************************
*
*	Name: deconstruct
*
*	Function: used to delete the memory of a node and all of it's subtrees recursively
*	
*	Inputs: a node * 
*
*	Outputs: none
*
*******************************************************************************************
*
*Begin
*	if n isn't null
*		deconstruct the left subtree
*		deconstruct the right subtree
*		delete the memory of n
*End 
******************************************************************************************/

void Tree::deconstruct(Node* n)
{
	if(n!= nullptr)	//I'm not even gonna transfer those 5 lines of pseudo code because its 
	{				//pretty explanatory of what's going on here. Like really not a hard concept
					// and now I just wrote 3 lines of absolute BS pseudo code just for the memes
	deconstruct(n->left);	//Never gonna give you up
	deconstruct(n->right);	//Never gonna let you down
	delete n;				//Never gonna run around and desert you
	}
}

/*******************************************************************************************
*
*	Name: outputTree
*
*	Function: outputs a binary tree object to an output file who's name is passed in
*	
*	Inputs: a Node* that is the root of the tree and a string name
*
*	Outputs: none
*
*******************************************************************************************
*
*Begin
*	create an output stream
*	open the file for output
*	if the file doesn't open
*		print an error
*		exit the program
*	if root isn't null
*		run the outputNode function on the root
*	close the file
*End 
*******************************************************************************************/

void Tree::outputTree(Node* root, std::string name)
{
	std::ofstream file;
	file.open(name, std::ios::out);
	if(!file.is_open())
	{
		std::cout << "Failed to open output file." << std::endl;
		exit(1);
	}
	if(root != nullptr)
	{
		outputNode(root, file);
	}
	file.close();
}

/**************************************************************************************
*
*	Name: outputNode
*
*	Function: output the left subnode then the node itself then the right subnode
*			  uses recursion to output in ascending order
*		
*	Inputs: a Node * n and an output stream
*
*	Outputs: none
*
***************************************************************************************
*
*Begin
*	if n isnt null
*		output the left subnode
*		send the value and log base 10 to the output file
*		output the right subnode
*End	
*************************************************************************************/

void Tree::outputNode(Node* n, std::ofstream& outfile)
{
	//if n isn't null
	if(n != nullptr)
	{
		//output the left subnode
	outputNode(n->left, outfile);
	//send the value and log base 10 to the output file
	outfile << n->value << '\t' << std::setprecision(5) << log10(n->value) << std::endl;
	//output the right subnode
	outputNode(n->right, outfile);
	}
}