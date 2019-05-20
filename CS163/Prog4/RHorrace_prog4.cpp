#include "RHorrace_prog4.h"

//Horrace, Robert CS163

/*
   This.cpp file is the main function.
   It will be the only thing the client will see.
   The program will have functions that calls the 
   functions in the .h file.
 */
int insert(BST & a_bst);//insert function
int retrieve(BST & a_bst);//retrieve(search) function
int remove_match(BST & a_bst);//remove match function
int display(BST & a_bst);//display function
int main()
{
	BST bst;//BST object
	if(insert(bst) == 1){}//call insert function
	if(retrieve(bst) == 0){}//call retrieve function
	if(display(bst) == 0){}//call display function
	cout << endl << endl << endl;
	if(remove_match(bst) == 0){}//call remove match fucntion
	if(display(bst) == 0){}//call display function
	cout << "Farewell." << endl;//bid farewell
	return 0;
}
int insert(BST & a_bst)//insert function
{
	int a = 0;
	//temp variables for concepts
	char name[SIZE];
	char description[SIZE];
	char advantage[SIZE];
	char disadvantage[SIZE];
	char temp;//response variable
	do{
		cout << "Enter concept name:";
		cin.get(name,SIZE,'\n');
		cin.ignore(100,'\n');
		cout << "Enter description:";
		cin.get(description,SIZE,'\n');
		cin.ignore(100,'\n');
		cout << "Enter Advantage(s):";
		cin.get(advantage,SIZE,'\n');
		cin.ignore(100,'\n');
		cout << "Enter disadvantage(s):";
		cin.get(disadvantage,SIZE,'\n');
		cin.ignore(100,'\n');
		a = a_bst.insert(name,description,advantage,disadvantage);//call insert function from BST class
		do{
			cout << "Insert another concept?(Y/N):";
			cin >> temp;
			cin.ignore(100,'\n');
			temp = toupper(temp);
		}while(temp != 'Y' && temp != 'N');
	}while(temp == 'Y');//repeats if the user says yes
	return a;
}
int retrieve(BST & a_bst)//retrieve(search) function
{
	char temp;//response variable
	char name[SIZE];//what they want to search for variable
	do{
	cout << "Search for a certain concept?(Y/N):";
	cin >> temp;
	cin.ignore(100,'\n');
	temp = toupper(temp);
	}while(temp != 'Y' && temp != 'N');
	while(temp == 'Y')//loops if they want to search again
	{
		cout << "Enter concept you want to search for:";
		cin.get(name,SIZE,'\n');
		cin.ignore(100,'\n');
		if(a_bst.retrieve(name) == 0)//calls function
			cout << "Sorry, We have no concepts matching that name." << endl;//if not found
		do{
		cout << "Search again?(Y/N):";
		cin >> temp;
		cin.ignore(100,'\n');
		temp = toupper(temp);
		}while(temp != 'Y' && temp != 'N');
	}
	return 1;
}
int remove_match(BST & a_bst)//remove match function
{
	char temp;//response variable
	char name[SIZE];//what they want to remove function
	int a = 0;
	do{
	cout << "Remove a concept?(Y/N):";
	cin >> temp;
	cin.ignore(100,'\n');
	temp = toupper(temp);
	}while(temp != 'Y' && temp != 'N');
	while(temp == 'Y')//loops if user wants to remove another concept
	{
		cout << "Enter concept you want to remove:";
		cin.get(name,SIZE,'\n');
		cin.ignore(100,'\n');
		a = a_bst.remove_match(name);//calls remove match functon from BST class
		if(a == 0)//if not found
			cout << "No concept found." << endl;
		if(a == 1)//if found and removed
			cout << "Removed." << endl;
		do{
			cout << "Remove another concept?(Y/N):";
			cin >> temp;
			cin.ignore(100,'\n');
			temp = toupper(temp);
		}while(temp != 'Y' && temp != 'N');
	}
	return 0;
}
int display(BST & a_bst)//display function
{
	int a = 0;
	char temp;
	do{
	cout << "Display all?(Y/N):";
	cin >> temp;
	cin.ignore(100,'\n');
	temp = toupper(temp);
	}while(temp != 'Y' && temp != 'N');
	if(temp == 'Y')//if user says yes
	{
		cout << endl;
		a = a_bst.display();//calls display function from BST class
		if(a == 0)//if nothing to display
		{
			cout << "There are currently no concepts to display." << endl;
			return 0;
		}
		cout << endl;
	}
}
