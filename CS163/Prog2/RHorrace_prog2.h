#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
//Horrace, Robert CS 162
/*
   This program is a .h file.
   This .h file will hold three data types.
   One ADT will be an ordered linked list 
   for the products in the warehouse.
   One ADT will be a stack that will act as an order of products.
   The last ADT will be a queue of stacks.
 */
using namespace std;
const int SIZE = 50;
class product//class for product info
{
	public:
		product();//constructor
		~product();//destructor
		void insert(char nm[], char des[],char brcd[], char mkr[], int & qty);//inserts info
		void get_name(char nm[]);//gets name
		void get_data(char nm[], int & qty);//gets name and amount 
		void get_data(char des[], char brcd[], char mkr[]);//gets description, barcode, maker
		void update_stock(int & num);//updates amount in stock
		void display();//displays info
	private:
		char * name;//name var
		char * description;//description var
		char * barcode;//barcode var
		char * maker;//maker var
		int quantity;//quantity var
};

struct node//node struct
{
	product data;//product obj.
	node * next;//for traversal
};

class warehouse//class for OLL
{
	public:
		warehouse();//constructor
		~warehouse();//destructor
		void insert();//inserts nodes into list
		void insert_node(char nm[], char des[],char brcd[], char mkr[], int & qty);//inserts info
		void get_prdct(char nm[],char des[], char brcd[], char mkr[]);//gets product values
		void update_amount(char nm[], int & num);//updates stock
		void display();//displays the products
	private:
		ifstream fin;//file var
		node * head;//head pointer for node
};

class stack//stack class
{
	public:
		stack();//constructor
		~stack();//destructor
		void push(char nm[],char des[],char brcd[],char mkr[], int & qty);//adds node to stack
		int pop();//removes from stack
		int peek();//peeks at the top(first node) of the stack
	private:
		node * s_head;//head pointer for node
};

struct stacknode//node for stacks
{
	stack data;//strack obj
	stacknode * next;//for traversal
};

class queue//queue class
{
	public:
		queue();//constructor
		~queue();//destructor
		void enqueue();//adds to queue
		int dequeue();//removes from queue
	private:
		stacknode * rear;//stacknode pointer
};
