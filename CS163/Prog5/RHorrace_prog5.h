#include <iostream>
#include <cctype>
#include <cstring>

//Horrace, Robert CS163
/*
	This program is designed to be the .h file.
	This will contain the graph table ADT 
	including the structs and other classes.
	All functions, classes, and structs will
	be used.
*/
using namespace std;

const int SIZE = 100;//for arrays

class person//for friends
{
	public:
		person();//constructor
		~person();//destructor
		void insert(char nm[]);//inserts data in class
		int compare_name(char nm[]);
		void display();//displays variables
	private:
		char * name;//name pointer
};

struct vertex//struct for friends
{
	person * prsn;//person object
	struct node * head;//head pointer for events
	node * tail;//tail pointer for events
};

struct node//strcut for connecting vertices with events
{
	char * event;//event pointer
	char * date;//date pointer
	vertex * adjacent;//adjacenct pointer
	node * next;//next pointer
};

class graph//ADT
{
	public:
		graph(int size = 100);//constructor
		~graph();//destructor
		int insert_adjacent(char nm[]);//inserts friend into vertices
		int insert_edge(char nm1[],char nm2[], char affr[], char dt[]);//inserts events and connects vertices
		int insert_edge_no_friend(char nm1[], char affr[], char dt[]);//inserts events without connecting vertices
		int find_location(char nm[]);//finds vertex
		int display_person(char nm[]);//displays person and events wrapper functions
		int display_vertices(char affr[], char dt[]);//displays vertices wrapper functions
		int display_all();//display all wrapper functions
	private:
		int display_person(node * list);//display person recursive functions
		int display_vertices(node * list, char affr[], char dt[],int i);//display vertices recursive function
		int display_all(vertex * friends);//display all recursive function
		int display_events(vertex * friends);//display events wrapper function
		int display_events(node * list);//display events recursive function
		vertex * adjacency_list;//vertex pointer
		int list_size;//size of list

};
