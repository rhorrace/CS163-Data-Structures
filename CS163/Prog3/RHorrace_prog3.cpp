#include "RHorrace_prog3.h"

//Horrace, Robert CS163
/*
   This program is the main.
   This program will test the ADTs and see if they work.
   This is also the program for main functions.
 */
void insert(table & a_hash, list & a_list);//inserts variables
void search(table b_hash);//searches
int main()
{
	char response;
	table my_hash;//table object
	list my_list;//list object
	cout << "Welcome to the poster." << endl;//Welcomes user
	cout << "Currently, there are no posts." << endl;//There are no nodes
	do{
		insert(my_hash,my_list);//call insert function
		search(my_hash);//calls search function
		do{
			cout << "Display All?(Y/N):";
			cin >> response;
			cin.ignore(100,'\n');
			response = toupper(response);
		}while(response != 'Y' && response != 'N');//repeats if not yes or no
		if(response == 'Y')//if yes
			my_list.display();//displays all posts
		do{
			cout << "Enter another post?(Y/N):";
			cin >> response;
			cin.ignore(100,'\n');
			response = toupper(response);
		}while(response != 'N' && response != 'Y');//repeats if not yes or no
	}while(response == 'Y');//repeats if yes
	cout << "Farewell." << endl;//farewell to user
	return 0;
}

void insert(table & a_hash, list & a_list)//inserts
{
	char name[SIZE];//person who posted post
	char date[SIZE];//date of post
	char content[SIZE];//content of post
	char views[SIZE];//views of post
	cout << "Enter the name of the person who posted the post(ex. John Smith): ";
	cin.get(name,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "Enter the date it was posted(ex. 11/16/1995): ";
	cin.get(date,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "Enter one word to describe the content(ex. content): ";
	cin.get(content,SIZE,'\n');
	cin.ignore(100,'\n');
	cout << "enter the amount of views of the post(ex. 9000): ";
	cin.get(views,SIZE,'\n');
	cin.ignore(100,'\n');
	a_list.insert(name,date,content,views);//insets into LLL
	a_hash.insert(name,name,date,content,views);//inserts to table depending on name
	a_hash.insert(date,name,date,content,views);//inserts to table depending on date
	a_hash.insert(content,name,date,content,views);//inserts to table depending on content
	a_hash.insert(views,name,date,content,views);//inserts to table depending on views
}

void search(table b_hash)//search function
{
	int srch = 0;
	char temp;
	char search[SIZE];
	char name[SIZE];
	do{
		cout << "Search for a post?(Y/N):";
		cin >> temp;
		cin.ignore(100,'\n');
		temp = toupper(temp);
	}while(temp != 'Y' && temp != 'N');//repeats if no yes or no
	if(temp == 'Y')//if yes
	{
		do{
			cout << "Search by name,date,content, or views?:";
			cin.get(search,SIZE,'\n');
			cin.ignore(100,'\n');
			for(int i = 0; i < strlen(search); ++i)
			{
				search[i] = tolower(search[i]);//lowers cases all indeces
			}
		}while(search[0] != 'n' && search [0] != 'd' && search[0] != 'c' && search[0] != 'v');	//repeats if foirst index isn't a n,d,c, or v	
		cout << "Enter name,date,content, or view depending on what you are searching for(ex. if you chose name, enter a name):";
		cin.get(name,SIZE,'\n');
		cin.ignore(100,'\n');
		srch = b_hash.search(search,name);//searches hash table depending on search by and search value
		if(srch == 0)//if there are no posts matching the search value
		{
			cout << "No posts have what you entered." << endl;
		}
	}
	if(temp == 'N')//if no
		return;
}
