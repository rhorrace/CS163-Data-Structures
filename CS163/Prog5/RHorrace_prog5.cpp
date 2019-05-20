#include "RHorrace_prog5.h"

//Horrace, Robert CS163
/*
	This program is designed to hold the main 
	function and calls the functions from the 
	.h file.
	The functions used in this program will call 
	the functions in the .h file.
	The client will not know what is happening 
	behind the scenes.
*/
void insert_friend(graph & grph);//inserts friend(s)
void insert_event(graph & grph);//inserts event(s)
void display(graph grph);//displays whatever the user wants to display
int main()
{
	graph my_graph;//table object
	cout << "Welcome." << endl << endl;//welcomes user
	cout << "Enter all events in chronological order!" << endl;//warns user to insert all events in chronologival order
	insert_friend(my_graph);//calls insert friend function
	insert_event(my_graph);//calls insert event function
	display(my_graph);//calls display function
	return 0;
}

void insert_friend(graph & grph)//inserts friend(s)
{
	char name[SIZE];//name variable
	char affair[SIZE];//event variable
	char date[SIZE];//date variable
	int amnt = 0;//for inserting friend
	int friends = 0;//amount of friends
	char response;
	cout << "How many friends do you want to enter(ex. 2, no more than 100):";//enter a number less than 100
	cin >> friends;
	cin.ignore(100,'\n');
	while(amnt < friends)//while counting amount is less than friend amount
	{
		cout << "Enter friend's name:";//enter friend name
		cin.get(name,SIZE,'\n');
		cin.ignore(100,'\n');
		name[0] = toupper(name[0]);
		for(int i = 0;i<strlen(name);++i)
		{
			if(isspace(name[i]))
				name[i+1] = toupper(name[i+1]);
		}
		grph.insert_adjacent(name);//calls insert adjacenct function
		++amnt;//adds 1 to amnt
	}

}

void insert_event(graph & grph)//inserts event(s)
{
	int a, b = 0;//
	char friend1[SIZE];//friend for event
	char friend2[SIZE];//friend that shares event
	char event[SIZE];//event
	char date[SIZE];//date
	char response;//response variable
	do{
		cout << "Add an event for a friend?(Y/N):";//yes or no
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
	}while(response != 'Y' && response != 'N');//repeats if not Y and not N
	if(response == 'Y')//if user says yes
	{
		do{
			cout << "Enter friend you want to add an event for:";//enter name of friend
			cin.get(friend1,SIZE,'\n');
			cin.ignore(100,'\n');
			friend1[0] = toupper(friend1[0]);
			for(int i = 0;i<strlen(friend1);++i)
			{
				if(isspace(friend1[i]))
					friend1[i+1] = toupper(friend1[i+1]);
			}
			cout << "Enter friend's event(ex. Went to party):";//enter event of friend
			cin.get(event,SIZE,'\n');
			cin.ignore(100,'\n'); 
			cout << "Enter date of event(ex. 01/23/1996):";//enter date of event
			cin.get(date,SIZE,'\n');
			cin.ignore(100,'\n');
			do{
				cout << "Is there a friend that shares the event?(Y/N):";//yes or no
				cin >> response;
				cin.ignore(100,'\n');
				response = toupper(response);
			}while(response != 'Y' && response != 'N');//repeat if not Y and not N
			if(response == 'N')//if no
			{
				a = grph.insert_edge_no_friend(friend1,event,date);//inserts event without connecting a friend
				if(a == 0)//if friend doesn't exist
					cout << "Friend doesn't exist." << endl;
				if(a == 1)//if he/she exists
					cout << "Done." << endl;
			}
			if(response == 'Y')//if yes
			{
				cout << "Enter other friend who shares the event:";//enter other friend
				cin.get(friend2,SIZE,'\n');
				cin.ignore(100,'\n');
				friend2[0] = toupper(friend2[0]);
				for(int i = 0;i<strlen(friend2);++i)
				{
					if(isspace(friend2[i]))
						friend2[i+1] = toupper(friend2[i+1]);
				}
				a = grph.insert_edge(friend1,friend2,event,date);//calls insert edge function
				b = grph.insert_edge(friend2,friend1,event,date);//calls functions again but for other friend
				if(a == 0 || b == 0)//if either one doesn't exist
					cout << "At least one of these friends doesn't exist in the database." << endl;
				else//if successful
					cout << "done." << endl;
			}
			do{
				cout << "Another event?(Y/N):";//enter another event
				cin >> response;
				cin.ignore(100,'\n');
				response = toupper(response);
			}while(response != 'Y' && response != 'N');//repeat question if not Y and not N
		}while(response == 'Y');//repeats completely if yes
	}
}
void display(graph grph)//displas whatever user wants to display
{
	char name[SIZE];//name variable
	char event[SIZE];//event variable
	char date[SIZE];//date variable
	char response;//response variable
	do{
		cout << "Display events of one person?(Y/N):";//yes or no
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
	}while(response == 'Y' && response != 'N');//repeats if not Y and not N
	if(response == 'Y')//if yes
	{
		cout << "Enter name of friend:";//enter friend name
		cin.get(name,SIZE,'\n');
		cin.ignore(100,'\n');
		name[0] = toupper(name[0]);
		for(int i = 0; i<strlen(name); ++i)
		{
			if(isspace(name[i]))
				name[i+1] = toupper(name[i+1]);
		}
		grph.display_person(name);//displays person and his/her events chronologically
	}
	do{
		cout << "Display people who went to the same event on a certain date?(Y/N):";//yes or no
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
	}while(response != 'Y' && response != 'N');
	if(response == 'Y')
	{
		cout << "Enter event:";
		cin.get(event,SIZE,'\n');
		cin.ignore(100,'\n');
		cout << "Enter date of the event:";
		cin.get(date,SIZE,'\n');
		cin.ignore(100,'\n');
		grph.display_vertices(event,date);//displays people at a certain event
	}
	do{
		cout << "Display all friends and their events?(Y/N):";//displays all people ad their events
		cin >> response;
		cin.ignore(100,'\n');
		response = toupper(response);
	}while(response != 'Y' && response != 'N');
	if(response == 'Y')
		grph.display_all();//calls display all function
}
