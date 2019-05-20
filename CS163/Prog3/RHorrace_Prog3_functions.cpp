#include "RHorrace_prog3.h"

//Horrace, Robert CS163
/*
   This program is designed to hold the functions of the classes.
   By using the functions, the program will make a LLL.
   The program, using a hash table, will display the nodes depending
   on name, date, content, or views.
 */

post::post()//post contstructor
{
	name = NULL;
	date = NULL;
	content = NULL;
	views = NULL;
}

post::~post()//post destructor
{
	if(name)
	{
		delete [] name;
		name = NULL;
	}
	if(date)
	{
		delete [] date;
		date = NULL;
	}
	if(content)
	{
		delete [] content;
		content = NULL;
	}
	if(views)
	{
		delete [] views;
		views = NULL;
	}
}

void post::insert(char nm[],char dt[],char cntnt[],char vws[])//inserts variables into post
{
	name = new char[strlen(nm) + 1];
	strcpy(name,nm);
	date = new char[strlen(dt) +1];
	strcpy(date,dt);
	content = new char[strlen(cntnt) + 1];
	strcpy(content,cntnt);
	views = new char[strlen(vws) + 1];
	strcpy(views,vws);
}

int post::check_name(char key[])//checks for name
{
	if(strcmp(key,name) == 0)//if the key and the name is the same
		return 1;
	else
		return 0;
}

int post::check_date(char key[])//checks for date
{
	if(strcmp(key,date) == 0)//if they're the same
		return 1;
	else
		return 0;
}

int post::check_content(char key[])//checks for content
{
	if(strcmp(key,content) == 0)//if they're the same
		return 1;
	else
		return 0;
}

int post::check_view(char key[])//checks for views
{
	if(strcmp(key,views) == 0)//if they're the same
		return 1;
	else
		return 0;
}

void post::display()//displays post
{
	cout << "Posted by: " << name << endl;
	cout << "Posted on: " << date << endl;
	cout << "Contains: " << content << endl;
	cout << "Amount of views: " << views << endl;
	cout << endl << endl << endl << endl;
}

list::list()//list constructor
{
	head = NULL;
}

list::~list()//list destructor
{
	if(head)//if head isn't NULL
	{
		node * current = head;
		while(current -> next)// traverses if current -> next isn't NULL
		{
			current = current -> next;
			delete head;
			head = current;
		}
		delete head;
		head = NULL;
	}
}

void list::insert(char nm[],char dt[], char cntnt[], char vws[])//inserts data into a node
{
	if(!head)//if head is NULL
	{
		head = new node;
		head -> news.insert(nm,dt,cntnt,vws);//inserts data into node
		head -> next = NULL;
	}
	else//if head isn't NULL
	{
		node * current = head;
		while(current -> next)//travers to end of list
		{
			current = current -> next;
		}
		current -> next = new node;
		current = current -> next;
		current -> news.insert(nm,dt,cntnt,vws);//inserts data into node
		current -> next = NULL;
	}
}


void list::display()//dusplays node
{
	if(!head)//if head is NULL
		cout << "There are no posts." << endl;
	else
	{
		node * current = head;
		while(current)//traverses list
		{
			current -> news.display();//displays node
			current = current -> next;
		}
	}
}

table::table(int size)//table constructor
{
	hash_table_size = size;
	hash_table = new node * [size];//make array of pointers
	for(int i = 0;i < size; ++i)
	{
		*(hash_table + i) = NULL;
	}
}

table::~table()//table destructor
{
	node * current = NULL;
	for(int i = 0; i < hash_table_size; ++i)
	{
		if(*(hash_table + i))//if hash_table index isn't NULL
		{
			current = *(hash_table + i);
			while(current -> next)//travers if current -> next isn't NULL
			{
				current = current -> next;
				delete *(hash_table + i);//delete node
				*(hash_table + i) = current;
			}
		}
	}
	hash_table_size = 0;
}

int table::hash(char key[])//hash function
{
	int len = strlen(key);
	int value = 0;
	for(int i = 0; i < len; ++i)
	{
		value += key[i];
	}
	return value % hash_table_size;//returns mod value
}

void table::insert(char * value, char name[], char date[], char content[], char views[])//inserts into hash table
{
	int val = hash(value);//hash function call
	if(*(hash_table + val) == NULL)//if hash table index is NULL
	{
		*(hash_table + val) = new node;
		(*(hash_table + val)) -> news.insert(name,date,content,views);//inserts data in hash table
		(*(hash_table + val)) -> next = NULL;
		return;
	}	
	else
	{
		node * temp = new node;
		temp -> news.insert(name,date,content,views);//inserts data into hash table
		temp -> next = *(hash_table + val);
		*(hash_table + val) = temp;
		return;
	}
}

int table::search(char search[], char key[])//searchs for node by key
{
	int val = hash(key);//hash function
	int k = 0;//for matches
	int l = 0;//for amount of matches
	if(*(hash_table + val) == NULL)//if hash table index is NULL
		return 0;
	else
	{
		node * current = *(hash_table + val);
		while(current)
		{
			if(search[0] == 'n')//if search by name
			{
				k = current -> news.check_name(key);//checks for name
				if(k == 1)//if a match
				{
					current -> news.display();//displays node
				}
				l += k;
			}
			else if(search[0] == 'd')//if search by date
			{
				k = current  -> news.check_date(key);//checks date
				if(k == 1)//if a match
				{
					current -> news.display();//displays node
				}
				l += k;
			}
			else if(search[0] == 'c')//if search by content
			{
				k = current -> news.check_content(key);//checks content
				if(k == 1)//if a match
				{
					current -> news.display();//displays node
				}
				l += k;
			}
			else if(search[0] == 'v')//if search by view
			{
				k = current -> news.check_view(key);//checks view
				if(k == 1)//if a match
				{
					current -> news.display();//displays node
				}
				l += k;
			}
			current = current -> next;//traverse traverse
		}
		if(l == 0)//if no matches
			return 0;
		else
			return 1;
	}
} 
