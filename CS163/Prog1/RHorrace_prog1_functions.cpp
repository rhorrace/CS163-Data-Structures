#include "RHorrace_prog1_list.h"

using namespace std;

//Horrace, Robert
/*
   This program is designed for the functions listed
   in the list.h file and to be used in the main program.
   All functions will be used.
 */

candidate::candidate()//candidate class constructor
{
	name = NULL;//name
	views = NULL;//major views
	polls = 0;//poll rank
	thoughts = NULL;//opinion of becoming president
}
candidate::~candidate()//candidate class destructor
{
	if(name != NULL)//if name isn't NULL
	{
		delete name;//delete name
		name = NULL;//name is NULL
	}
	if(views != NULL)//if views isn't NULL
	{
		delete views;//delete views
		views = NULL;//views is NULL
	}
	if(polls != 0)//if polls isn't 0
	{
		polls = 0;//polls is 0
	}
	if(thoughts != NULL)//if thought isn't NULL
	{
		delete thoughts;//delete thoughts
		thoughts = NULL;//thoughts is NULL
	}
}
void candidate::get_info(char nm[SIZE], char pnt[VIEW], int & pll, char thght[VIEW])//inserts info
{
	name = new char[strlen(nm)+1];
	strcpy(name, nm);//copies name in DAA
	views = new char[strlen(pnt) + 1];
	strcpy(views, pnt);//copies major views in DAA
	polls = pll;//copis poll rank
	thoughts = new char[strlen(thght)+1];
	strcpy(thoughts,thght);//copies opinion in DAA
}
void candidate::update_polls(int & plls)//updates poll rank
{
	polls = plls;//copies poll rank
}
void candidate::display()//displays candidate
{
	cout << "Name: " << name << endl;
	cout << "Views: " << views << endl;
	cout << "Poll rank: #" << polls << endl;
	cout << "Thoughts: " << thoughts << endl;
}
party::party()//constructor for party class
{
	prty = NULL;//prty is NULL
}
party::~party()//destructor for party class
{
	if(prty != NULL)//if prty isn't NULL
	{
		delete prty;
		prty = NULL;//party is NULL
	}
}
void party::insert_party(char pltc[SIZE])//inserts party
{
	prty = new char[strlen(pltc) + 1];
	strcpy(prty,pltc);//copies party variable
}
void party::copy(char pltc[SIZE])
{
	strcpy(pltc,prty);
}
void party::display()//displays party name
{
	cout << prty;
}
candilist::candilist()//constructor for candilist class
{
	head = NULL;//head is NULL
}
candilist::~candilist()//destructor for candilist class
{
	candinode * current = head;
	if(head != NULL)//if head isn't NULL
	{
		while(current != NULL)
		{
			current = current -> next;
			delete head;
			head = current;
		}
		head = NULL;
	}
}
void candilist::add(char nm[SIZE],char pnt[VIEW], int & pll, char thght[VIEW])//add node function
{
	candinode * temp = NULL;
	temp = new candinode;
	temp -> data.get_info(nm, pnt, pll, thght);//call get info function
	temp -> next = NULL;//next is NULL
	if(head == NULL)//if current is NULL
	{
		head = temp;
		head -> next = NULL;
	}
	else if(head != NULL)
	{
		candinode * current = head;//current
		while(current -> next != NULL)
		{
			current = current  -> next;
		}
		current -> next = temp;
		current = current -> next;
		current -> next = NULL;
	}
}
void candilist::display()//displays candilist
{
	candinode * current = head;//current is head
	while(current)
	{
		current -> data.display();
		current = current -> next;
	}
}
partylist::partylist()//partylist constructor
{
	head = NULL;
}
partylist::~partylist()//partylist destructor
{
	partynode * current = head;
	if(head != NULL)//if head isn't NULL
	{
		while(current != NULL)
		{
			current = current -> next;
			delete head;
			head = current;
		}
		head = NULL;
	}
}
void partylist::add_party(char pltc[SIZE])//adds party name into data
{
	partynode * temp = NULL;
	partynode * current = head;//current
	temp = new partynode;
	temp -> data.insert_party(pltc);//call get info function
	temp -> next = NULL;//next is NULL
	if(head == NULL)//if current is NULL
	{
		head = temp;
		head -> next = NULL;
	}
	else if(head != NULL)
	{
		while(current -> next != NULL)
		{
			current = current  -> next;
		}
		current -> next = temp;
		current = current -> next;
		current -> next = NULL;
	}

}
void partylist::get_party(char pltc[SIZE])
{
	partynode * current = head;
	current -> data.copy(pltc);
}
void partylist::add_candidate(char political[SIZE], char nm[SIZE],char pnt[VIEW], int & pll, char thght[VIEW])//adds candidate in a node
{
	char tempo[SIZE];
	partynode * current = head;
	while(current)
	{
		get_party(tempo);
		if(strcmp(political, tempo) == 0)
		{
			current -> list -> add(nm,pnt,pll,thght);
		}
		else if(strcmp(political, tempo) != 0)
			current = current -> next;
	}
}
void partylist::display()
{
}






