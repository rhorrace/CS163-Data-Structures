#include <iostream>
#include <cctype>
#include <cstring>

//Horrace, Robert CS163

/*
   This .h file is for program 4.
   This will hold the functions for the
   the table ADT, which is a BST.
   By using BSTs, concepts will be sorted.
 */

using namespace std;

const int SIZE = 100;//constant integer variable

class concept//concept class for node struct
{
	public:
		concept();//constructor
		~concept();//destructor
		void insert(char nm[], char dscrptn[], char advntg[], char dsadvntg[]);//insert function
		int check_name(char nm[]);//check name function
		void get_data(char nm[], char dscrptn[], char advntg[], char dsadvntg[]);//gets data function
		void display();//display function
	private:
		char * name;//name pointer
		char * description;//description pointer
		char * advantage;//advantage pointer
		char * disadvantage;//disadvantage pointer
};
struct node//node for BST
{
concept data;//concept object
node * left;//for left side
node * right;//for right side
};

class BST//binary search tree class
{
	public:
		BST();//constructor
		~BST();//destructor
		int insert(char nm[], char dscrptn[], char advntg[], char dsadvntg[]);//insert wrapper function
		int insert(node *& root, char nm[], char dscrptn[], char advntg[], char dsadvntg[]);//recursive insert function
		int retrieve(char nm[]);//retrieve wrapper function
		int retrieve(node *& root, char nm[]);//recursive retrieve function
		int remove_match(char nm[]);//remove fucnction if there is a match
		int remove_match(node *& root, char nm[]);//half recursive, haf iterative remove function if there is a match
		int remove_all();//remove all wrapper function
		int remove_all(node *& root);//recursive remove all function
		int display();//display all wrapper function
		int display(node * root);//recursive display all function(alphabetically sorted)
	private:
	node * root;//node variable for BST
};
