#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

//Horrace, Robert CS163
/*
   This program is designed for the table ADT.
   This program will be a hashtable.
   This .h file will be used.
 */
using namespace std;
const int SIZE = 50;//SIZE value
class post//post class
{
	public:
		post();//post constructor
		~post();//post destructor
		void insert(char nm[],char dt[],char cntnt[],char vws[]);//inserts into class
		int check_name(char key[]);//checks name
		int check_date(char key[]);//checks date
		int check_content(char key[]);//checks content
		int check_view(char key[]);//checks view
		void display();//displays variables
	private:
		char * name;//name variable
		char * date;//date variable
		char * content;//content variable
		char * views;//views variable
};

struct node//node struct for LLL
{
	post news;//post object
	node * next;//for traversing
};
class list//LLL class
{
	public:
		list();//list constructor
		~list();//list destructor
		void insert(char nm[],char dt[],char cntnt[],char vws[]);//inserts into a node
		void display();//displays node(s)
	private:
		node * head;//node variable
};
class table//table class
{
	public:
		table(int size = 100);//table constructor
		~table();//table destructor
		int hash(char key[]);//hash function
		void insert(char * value, char name[], char date[], char content[], char views[]);//inserts into hash table
		int search(char search[], char key[]);//searches for node in hash table
	private:
		node ** hash_table;//node for hash table
		int hash_table_size;//for size of hash table
};
