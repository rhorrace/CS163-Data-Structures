p

p
#include "RHorrace_prog2.h"
//Horrace, Robert CS163

/*
   This program is designed for the client.
   It will allow the client to put in an order
   or many orders. As long as the items are 
   in stock.
 */
void order(char prdct[], int & amnt);//function for product name and amount of roduct for order
int another();//for repeating some code
int main()
{
	char prdct[SIZE];//product var
	char des[SIZE];//description var
	char brcd[SIZE];//barcode var
	char mkr[SIZE];//maker var
	int amount = 0;//amout var
	product my_product;//product var for class
	warehouse my_warehouse;//warehouse var
	stack my_stack;//stack var
	queue full;//queue var
	queue partial;//queue var
	my_warehouse.insert();//inserts ext file
	cout << "These are our products we have." << endl;
	my_warehouse.display();//displays products in warehouse
	do{
	order(prdct,amount);//calls order function
	my_warehouse.get_prdct(prdct,des,brcd,mkr);//gets data from product
	my_warehouse.update_amount(prdct,amount);//updates stock
	my_stack.push(prdct,des,brcd,mkr,amount);//adds data to stack
	my_stack.peek()//peeks at the top
	}while(another() == 1);//repeats if user wants to add another product to an order
return 0;
}

void order(char prdct[], int & amnt)//order function
{
	cout << "What product do you want to add to the order?(Product name):";
	cin.get(prdct,SIZE,'\n');
	cin.ignore(100,'\n');
	prdct[0] = toupper(prdct[0]);
	cout << "Amount of product:";
	cin >> amnt;
	cin.ignore(100,'\n');
}

int another()//asks user if they want to add another function
{
	char response;
	do{
	cout << "Another product to buy?(Y/N):";
	cin >> response;
	cin.ignore(100,'\n');
	response = toupper(response);
	}while(response != 'Y' && response != 'N');
	if(response == 'Y')
		return 1;//returns 1 if yes
	else if(response == 'N')
		return 0;//returns 0 if no

}
