#include "RHorrace_prog4.h"

//Horrace, Robert CS163

/*
   This .cpp file will hold the implementations
   of the functions in the .h file.
   The functions will be called.
   The BST functions will be recursive.
 */

concept::concept()//concept constructor
{
	name = NULL;//name variable set to NULL
	description = NULL;//description variable set to NULL
	advantage = NULL;//advanatage variable set to NULL
	disadvantage = NULL;//disadvantage variable set to NULL
}

concept::~concept()
{
	if(name)//if name not NULL
	{
		delete [] name;
		name = NULL;

	}
	if(description)//if description not NULL
	{
		delete [] description;
		description = NULL;
	}
	if(advantage)//if advantage not NULL
	{
		delete [] advantage;
		advantage = NULL;
	}
	if(disadvantage)//if disadvantage not NULL
	{
		delete [] disadvantage;
		disadvantage = NULL;
	}
}

void concept::insert(char nm[], char dscrptn[], char advntg[], char dsadvntg[])//inserts variables
{
	name = new char[strlen(nm) + 1];//make new char array
	strcpy(name,nm);//copy variable
	description = new char[strlen(dscrptn) + 1];//make new vhar array
	strcpy(description,dscrptn);//copy variable
	advantage = new char[strlen(advntg) + 1];//make new char array
	strcpy(advantage,advntg);//copy variable
	disadvantage = new char[strlen(dsadvntg) + 1];//make new char array
	strcpy(disadvantage,dsadvntg);//copy variable
}

int concept::check_name(char nm[])//checks if name matches with concept name variable
{
	if(strcmp(name,nm) > 0) return 1;//if nm is lessthan name
	if(strcmp(name,nm) < 0)return -1;//if nm is greater than name
	if(strcmp(name,nm) == 0) return 0;//if the same
}

void concept::get_data(char nm[], char dscrptn[], char advntg[], char dsadvntg[])//gets data from variables
{
	strcpy(nm,name);//copies name
	strcpy(dscrptn,description);//copies description
	strcpy(advntg,advantage);//copies advantage
	strcpy(dsadvntg,disadvantage);//copies disadvantage
}

void concept::display()//displays data
{
	cout << "Name: " << name << endl;//displays name
	cout << "Description: " << description << endl;//displays description
	cout << "Advantage(s): " << advantage << endl;//displays advantage
	cout << "Disavantage(s): " << disadvantage << endl;//displays disadvantage
}

BST::BST()//BST constructor
{
	root = NULL;//root is set to NULL
}
BST::~BST()//BST destructor
{
	if(root)//if not NULL
		remove_all(root);//calls remove all functions
}

int BST::insert(char nm[], char dscrptn[], char advntg[], char dsadvntg[])//insert wrapper function
{
	return insert(root,nm,dscrptn,advntg,dsadvntg);// calls recursive insert function
}

int BST::insert(node *& root, char nm[], char dscrptn[], char advntg[], char dsadvntg[])//inserts data into root
{
	if(!root)//if root is NULL
	{
		root = new node;
		root -> data.insert(nm,dscrptn,advntg,dsadvntg);//calls insert function from concept class
		root -> left = NULL;//set left to NULL
		root -> right = NULL;//set right to NULL
		return 1;//end function
	}
	if(root -> data.check_name(nm) == -1 || root ->data.check_name(nm) == 0)//if greater than or equal to the current root node
		return insert(root -> right,nm,dscrptn,advntg,dsadvntg);//traverse recursively to the right
	if(root -> data.check_name(nm) == 1)//if less than the root node
		return insert(root -> left,nm,dscrptn,advntg,dsadvntg);//traverse recursively to the left
}

int BST::retrieve(char nm[])//retrieve wrapper function
{
	return retrieve(root, nm);//call recursive retrieve function
}

int BST::retrieve(node *& root, char nm[])//retrievs data from root function
{
	if(!root) return 0;//if NULL
	if(root -> data.check_name(nm) == 0)//if a match
	{
		root -> data.display();//display node
		return 1;
	}
	if(root -> data.check_name(nm) == -1)//if greater than the root
		return retrieve(root -> right, nm);//recursively traverse to the right
	if(root -> data.check_name(nm) == 1)//if less than the root
		return retrieve(root -> left, nm);//recursively traverse to the left
}

int BST::remove_match(char nm[])//remove_match wrapper functions
{
	return remove_match(root, nm);//call recursive remove_match function
}

int BST::remove_match(node *& root, char nm[])//remove_match from BST function
{
	char name[SIZE];//temp name
	char description[SIZE];//temp description
	char advantage[SIZE];//temp advantage
	char disadvantage[SIZE];//temp disadvantage
	if(!root) return 0;//if NULL
	if(root -> data.check_name(nm) == 0)//if a match
	{
		node * current = root;
		node * previous = root;
		//IN ORDER SUCCESSION
		if(root -> right && !root -> right -> left)
		{
			current = current -> right;
			previous -> right = current -> right;
			current -> data.get_data(name,description,advantage,disadvantage);//get data
			root -> data.insert(name,description,advantage,disadvantage);//insert data
			delete current;
			return 1;
		}
		else if(root -> right && root -> right -> left)//if right and right -> left exists
		{
			current = current -> right;
			while(current -> left)
			{
				previous = current;
				current = current -> left;
			}
			if(current -> right)
				previous -> left = current -> right;
			current -> data.get_data(name,description,advantage,disadvantage);
			root -> data.insert(name,description,advantage,disadvantage);
			delete current;
			return 1;
		}
		else if(!root -> left && root -> right)//if there is no left but a right
		{
			current = root -> right;
			delete root;
			root = current;
			return 1;
		}
		else if(root -> left && !root -> right)//if there is no right but a left
		{
			current = root -> left;
			delete root;
			root = current;
			return 1;
		}
		else if(!root -> left && !root -> right)//if left and right don't exist
		{
			delete root;
			root = NULL;
			return 1;
		}
	}
	if(root -> data.check_name(nm) == -1)//if greater than root
		return remove_match(root -> right, nm);//recursively traverse to the right
	if(root -> data.check_name(nm) == 1)//if less than root
		return remove_match(root -> left, nm);//recursively travers to the left
}

int BST::remove_all()//remove all wrapper function
{
	return remove_all(root);//call recursive remove all function
}

int BST::remove_all(node *& root)//remove all nodes function
{
	if(!root) return 0;//if NULL
	if(remove_all(root -> left)){}//recursively travers to the left
	if(remove_all(root -> right)){}//recursively traverse to the right
	delete root;//delete node
	root = NULL;//set it to NULL
	return 1;//end function
}

int BST::display()//display wrapper function
{
	return display(root);//call recursive display function
}

int BST::display(node * root)//display nodes alphabetically
{
	if(!root) return 0;//if NULL
	if(display(root -> left)){}//recursively traverse to the left
	root -> data.display();//display node
	if(display(root -> right)){}//recursively traverse to the right
	return 1;//end function
}


