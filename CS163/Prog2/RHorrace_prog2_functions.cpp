#include "RHorrace_prog2.h"
//Horrace, Robert CS163

/*
   This program is designed to hold
   the functions of the ADTs.
   Each and every function will be called.
 */

product::product()//product constructor
{
	name = NULL;
	description = NULL;
	barcode = NULL;
	maker = NULL;
	quantity = 0;
}

product::~product()//product destructor
{
	if(name != NULL)//if name isn't NULL
	{
		delete [] name;
		name = NULL;
	}
	if(description != NULL)//if description isn't NULL
	{
		delete [] description;
		description = NULL;
	}
	if(barcode != NULL)//if barcode isn't NULL
	{
		delete [] barcode;
		barcode = NULL;
	}
	if(maker != NULL)//if maker isn't NULL
	{
		delete [] maker;
		maker = NULL;
	}
	if(quantity != 0)//if quantity isn't 0
	{
		quantity = 0;
	}
}

void product::insert(char nm[], char des[],char brcd[], char mkr[], int & qty)//inserts data into class
{
	name = new char[strlen(nm)+1];
	strcpy(name,nm);
	description = new char[strlen(des)+1];
	strcpy(description,des);
	barcode = new char[strlen(brcd)+1];
	strcpy(barcode,brcd);
	maker = new char[strlen(mkr)+1];
	strcpy(maker,mkr);
	quantity = qty;

}

void product::get_name(char nm[])//gets name from product
{
	strcpy(nm,name);
}

void product::get_data(char nm[], int & qty)//gets data from product
{
	strcpy(nm,name);
	qty = quantity;
}

void product::get_data(char des[], char brcd[], char mkr[])//gets description, barcode, and maker from product
{
	strcpy(des,description);
	strcpy(brcd,barcode);
	strcpy(mkr,maker);
}

void product::update_stock(int & num)//subtracts the amount from the stock amount
{
	quantity -= num;
}

void product::display()//displays all data of product
{
	cout << "Product: " << name << endl;
	cout << "Description: " << description << endl;
	cout << "Barcode: " << barcode << endl;
	cout << "Made by: " << maker << endl;
	if(quantity > 0)
		cout << "Amount: " << quantity << endl;//if there is still product
	else if(quantity <= 0)//if amount is less than or equal to 0
		cout << "OUT OF STOCK" << endl;
}

warehouse::warehouse()//warehouse constructor
{
	head = NULL;
}

warehouse::~warehouse()//warehouse destructor
{
	node * current = head;
	if(head)//if head isn't NULL
	{
		while(current)
		{
			current = current -> next;
			delete head;
			head = current;
		}
		head = NULL;
	}
}

void warehouse::insert()//inserts data into node
{
	fin.open("product.txt");//opens txt file
	if(fin)//if conneted to file
	{
		while(fin.peek() != '\n')
		{
			char nm[SIZE];
			char des[SIZE];
			char brcd[SIZE];
			char mkr[SIZE];
			int qnty;
			fin.get(nm,SIZE,';');//for name
			fin.ignore(100, ';');
			fin.get(des,SIZE,';');//for description
			fin.ignore(100, ';');
			fin.get(brcd,SIZE,';');//for barcode
			fin.ignore(100, ';');
			fin >> qnty;//for quantity
			fin.ignore(100, ';');
			fin.get(mkr,SIZE,'\n');//for maker
			fin.ignore(100,'\n');

			insert_node(nm,des,brcd,mkr,qnty);//inserts data into node
		}
	}
	fin.close();//closes file
}

void warehouse::insert_node(char nm[], char des[],char brcd[], char mkr[], int & qty)//inserts data into node
{

	if(!head)//if head is NULL
	{
		head = new node;
		head -> data.insert(nm,des,brcd,mkr,qty);//inserts data
		head -> next = NULL;
	}
	else
	{
		node * current = head;
		while(current -> next != NULL)
		{
			current = current -> next;//traverse!!!! traverse!!!!
		}
		current -> next = new node;
		current = current->next;
		current -> data.insert(nm,des,brcd,mkr,qty);//inserts data
		current->next = NULL;
	}
}

void warehouse::get_prdct(char nm[] ,char des[],char brcd[],char mkr[])//gets product data
{
	char name[SIZE];
	if(head)
	{
		node * current = head;
		while(current)
		{
			current -> data.get_name(name);
			if(strcmp(nm,name) == 0)//if product names are the same
				current -> data.get_data(des,brcd,mkr);//gets data
			current = current -> next;
		}
	}
}

void warehouse::update_amount(char nm[], int & num)//updates the stock amount in node
{
	char name[SIZE];
	if(head)
	{
		node * current = head;
		while(current)
		{
			current -> data.get_name(name);//gets name
			if(strcmp(nm,name) == 0)//if the same
				current -> data.update_stock(num);//updates stock amount
			current = current -> next;
		}
	}
}

void warehouse::display()
{
	node * current = head;
	if(head)
	{
		while(current)
		{	
			current -> data.display();//displays the node
			current = current -> next;
		}
	}
}

stack::stack()//stack constructor
{
	s_head = NULL;
}
stack::~stack()//stack destructor
{
	node * current = s_head;
	if(s_head)//if head isn't NULL
	{
		while(current)
		{
			current = current -> next;
			delete s_head;
			s_head = current;
		}
		s_head = NULL;
	}
}
void stack::push(char nm[],char des[],char brcd[],char mkr[], int & qty)//adds node to stack
{	
	if(!s_head)
	{
		s_head = new node;
		s_head -> data.insert(nm,des,brcd,mkr,qty);//inserts data into node
		s_head -> next = NULL;
	}
	else
	{
		node * temp = NULL;
		temp = new node;
		temp -> data.insert(nm,des,brcd,mkr,qty);//inserts data into node
		temp -> next = s_head;
		s_head = temp;

	}
}
int stack::pop()//removes from top of stack
{
	if(!s_head)//if head is NULL
		return 0;
	else if(s_head)//if head isn't NULL
	{
		node * temp = s_head;
		temp = temp -> next;
		delete s_head;
		s_head = temp;
		return 1;
	}
}

int stack::peek()//peeks at top of stack
{
	if(!s_head)
		return 0;
	else if(s_head)
	{
		s_head ->data.display();//displays node
	}
}

queue::queue()//queue constructor
{
	rear = NULL;
}

queue::~queue()//queue destructor
{
	if(rear)//if rear isn't NULL
	{
		stacknode * temp = rear -> next;
		rear -> next = NULL;
		rear = temp;
		while(rear)
		{
			temp = temp -> next;
			delete rear;
			rear = temp;
			if(rear -> next == NULL)
			{
				delete temp;
				rear = NULL;
			}
		}
	}
}

void queue::enqueue()//adds to queue
{
	if(!rear)
	{
		rear = new stacknode;
		rear -> next = rear;
	}
	else if(rear)
	{
		stacknode * current = rear -> next;
		rear -> next = new stacknode;
		rear = rear -> next;
		rear -> next = current;
		
	}
}

int queue::dequeue()removes from queue
{
	if(!rear)
		return 0;
	else
	{
		stacknode * current = rear -> next;
		stacknode * temp = current;
		current = current -> next;
		delete temp;
		temp = current;
		rear -> next = temp;
	}
}

