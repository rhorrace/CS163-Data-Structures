#include "RHorrace_prog5.h"

//Horrace, Robert CS163
/*
	This program is designed for the
	implementations of the functions.
	This will have the constructors, destructors,
	and all functions in the .h file
	All functions will be used.
*/
person::person()//person constructor
{
	name = NULL;
}

person::~person()//person destructor
{
	if(name)//if it exists
	{
		delete [] name;
		name = NULL;
	}
}

void person::insert(char nm[])//inserts person functions
{
	name = new char[strlen(nm) +1];
	strcpy(name,nm);
}

int person::compare_name(char nm[])//compare name function
{
	if(name)//if it exists
	{
		if(strcmp(name,nm) == 0) return 1;//if a match
		else //if not match
			return 0;
	}
	return 0;//if name is NULL
}

void person::display()//display person function
{
	cout << endl << "Friend: " << name << endl;
}

graph::graph(int size)//graph constructor
{
	adjacency_list = new vertex[size];//sets vertec object into array of vertices
	for(int i = 0; i < size; ++ i)//sets all vertices and head pointers to NULL
	{
		(adjacency_list + i) -> head = NULL;
		(adjacency_list + i) -> prsn = NULL;
	}
	list_size = size;//sets list_size equal to 100
}

graph::~graph()//graph destructor
{
	delete [] adjacency_list;//delets array
	adjacency_list = NULL;//sets vertex to NULL
	list_size = 0;//makes list size to 0
	/*	for(int i = 0; i < SIZE; ++i)
		{
		if((adjacency_list + i) -> head)
		{
		delete (adjacency + i) -> head; 
		(adjacency_list + i) -> head = NULL;
		}
		if((adjacency_list + i) -> prsn)
		{
		delete (adjacency + i) -> prsn;
		(adjacency_list + i) -> prsn = NULL
		}
		}
	 */
}

int graph::insert_adjacent(char nm[])//inserts adjacentfunction
{
	int index = 0;//temp counter
	while(index < list_size)//go through list until full
	{
		if(!(adjacency_list + index) -> prsn)//if NULL
		{
			(adjacency_list + index) -> prsn = new person;
			(adjacency_list + index) -> prsn -> insert(nm);
			return 1;
		}
		++index;//adds one to index
	}
	return 0;//if full
}

int graph::insert_edge(char nm1[], char nm2[], char affr[], char dt[])//inserts edge function
{
	int start = find_location(nm1);//finds friend 1
	int attach = find_location(nm2);//finds friend 2
	if(start == -1 || attach == -1) return 0;//if one of them doesn't exist
	if(start >= 0 && attach >= 0)//if exist
	{
		if(!(adjacency_list + start) -> head)//if NULL
		{
			(adjacency_list + start) -> head= new node;
			(adjacency_list + start) -> head -> event = new char[strlen(affr) + 1];
			strcpy((adjacency_list + start)-> head -> event,affr);
			(adjacency_list + start) -> head -> date = new char[strlen(dt) + 1];
			strcpy((adjacency_list + start) -> head -> date,dt);
			(adjacency_list + start) -> head -> adjacent = (adjacency_list + attach);
			(adjacency_list + start) -> head -> next = NULL;
			(adjacency_list + start) -> tail = (adjacency_list + start) -> head;
			return 1;//if successful
		}
		//if head exists
		(adjacency_list + start) -> tail = new node;
		(adjacency_list + start) -> tail -> event = new char[strlen(affr) + 1];
		strcpy((adjacency_list + start) -> tail -> event,affr);
		(adjacency_list + start) -> tail -> date = new char[strlen(dt) + 1];
		strcpy((adjacency_list + start) -> tail -> date,dt);
		(adjacency_list + start) -> tail -> adjacent = (adjacency_list + attach);
		(adjacency_list + start) -> tail -> next = NULL;
		return 1;//if successful
	}
	return 0;//if not successful
}


int graph::insert_edge_no_friend(char nm1[], char affr[], char dt[])//inserts edge without connecting another friend functions
{
	int find = find_location(nm1);//finds location of friend
	if(find == -1) return 0;//if doesn't exist
	if(find >= 0)
	{
		if(!(adjacency_list + find) -> head)//if head is NULL
		{
			(adjacency_list + find) -> head= new node;
			(adjacency_list + find) -> head -> event = new char[strlen(affr) + 1];
			strcpy((adjacency_list + find)-> head -> event,affr);
			(adjacency_list + find) -> head -> date = new char[strlen(dt) + 1];
			strcpy((adjacency_list + find) -> head -> date,dt);
			(adjacency_list + find) -> head -> adjacent = NULL;
			(adjacency_list + find) -> head -> next = NULL;
			(adjacency_list + find) -> tail = (adjacency_list + find) -> head;
			return 1;//if successful
		}
	//if head isn't NULL
		(adjacency_list + find) -> tail = new node;
		(adjacency_list + find) -> tail -> event = new char[strlen(affr) + 1];
		strcpy((adjacency_list + find) -> tail -> event,affr);
		(adjacency_list + find) -> tail -> date = new char[strlen(dt) + 1];
		strcpy((adjacency_list + find) -> tail -> date,dt);
		(adjacency_list + find) -> tail -> adjacent = NULL;
		(adjacency_list + find) -> tail -> next = NULL;
		return 1;//if successful
	}
	return 0;//if not successful
}

int graph::find_location(char nm[])//find friend function
{
	if(!(adjacency_list + 0) -> prsn) return -1;//if first index is NULL
	int a = 0;
	for(int i = 0; i < list_size; ++ i)//checks each index
	{
		a = (adjacency_list + i) -> prsn -> compare_name(nm);//compares name with the vertex
		if(a == 1)//if found
			return i;
	}
	return -1;//if not successful
}

int graph::display_person(char nm[])//display person functions
{
	int a = find_location(nm);//finds person
	if(a != -1)//if found
	{
		(adjacency_list + a) -> prsn -> display();//display person
		cout << endl << endl;
		return display_person((adjacency_list + a) -> head);//calls recursive functions
	}
}

int graph::display_person(node * list)//display person recursive functions
{
	if(!list) return 0;//if doesn't exist
	cout << "Event: " << list -> event << endl;
	cout << "Date: " << list -> date << endl << endl;
	if(list -> next) display_person(list -> next);//traverse to next node
	return 1;
}

int graph::display_vertices(char affr[], char dt[])
{
	int i = 0;
	if(!(adjacency_list + 0)) return 0;//if first vertex doesn't exist
	cout << "People who went to this event:" << endl;
	while(display_vertices((adjacency_list + i) -> head, affr, dt, i) != 0 && (adjacency_list + i)) ++i;//displays each person at a certain event
	return i;
}

int graph::display_vertices(node * list, char affr[], char dt[],int i)
{
	int a = 0;
	if(!list) return 0;//if NULL
	if(strcmp(affr,list -> event) == 0 && strcmp(dt, list -> date) == 0)
	{
		if(list -> adjacent)//if adjacent exists
		{
			list -> adjacent -> prsn -> display();//display person
			/*			display_vertices(list -> adjacent -> head,affr,dt,i);
						return i;
			 */
		}	
		else return display_vertices(list -> next, affr, dt, i);//go to next node
	}
}

int graph::display_all()//displays every person and heir events
{
	int i = 0;
	while((adjacency_list + i))//while the vertex exists
	{
		display_all((adjacency_list + i));// display all
		++i;//add 1
	}
	return 1;
}

int graph::display_all(vertex * friends)//display all function
{
	friends -> prsn -> display();//display friend
	return display_events(friends);//calls display event functions
}

int graph::display_events(vertex * friends)//display events wrapper functions
{
	return display_events(friends -> head);//call recursive functions
}

int graph::display_events(node * list)//display events recursive function
{
	if(!list) return 0;//if NULL
	cout << "Event: " << list -> event << endl;
	cout << "Date: " << list -> date << endl;
	return display_events(list -> next);//go to next node
}
