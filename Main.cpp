/*
 Choy, Oscar
 CS A200
 March 7, 2016

 Lab #6
 
 This file will be used to test the functions of the BST implementation file "BST.c".
*/

#include "BST.h"

#include <iostream>
#include <fstream>
using namespace std;

void processTree(BST&,char fileName[]);

void testTree(const BST& bst);

int main()
{
	cout << "TESTING: int_1 BST\n\n";
	BST int1BST;
	char fileNameInt1[] = "data_int_1.txt";
	processTree(int1BST,fileNameInt1);
	testTree(int1BST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: int_2 BST\n\n";
	BST int2BST;
	char fileNameInt2[] = "data_int_2.txt";
	processTree(int2BST,fileNameInt2);
	testTree(int2BST);

	cout << "\n\n---------------------------------------------------\n";
	cout << "TESTING: Deleting tree...\n\n";
	int1BST.destroyTree();
	testTree(int1BST);

	cout << endl << endl;
	system("Pause");
	return 0;
}

void processTree(BST& bst, char fileName[])
{
	ifstream infile;
	infile.open(fileName);

	if(!infile)
        cerr << "Cannot open the input file." << endl;
	else
	{
		int data;	
		infile >> data;
		
		while (data != -999)
        {
			 bst.insert(data); 	
			 infile >> data;	
        }

		infile.clear(); //reset eof for next input
     }

     infile.close();
}

void testTree(const BST& bst)
{
	//TEST: inorder traversal (recursive)
	cout << "Inorder traversal (recursive):\n      ";
	bst.recursiveInorder();

	//TEST: inorder traversal (non-recursive)
	cout << "\nInorder traversal (non-recursive):\n      ";
	bst.nonRecursiveInorder();

	//TEST: preorder traversal (non-recursive)
	cout << "\nPreorder traversal (non-recursive):\n      ";
	bst.nonRecursivePreorder();
	
	//TEST: postorder traversal (non-recursive)
	cout << "\nPostorder traversal (non-recursive):\n      ";
	bst.nonRecursivePostorder();

	//TEST: totalNodes
	cout << "\nTotal nodes: " << bst.totalNodes();
}
