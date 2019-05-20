#include "RHorrace_prog1_list.h"

using namespace std;

//Horrace, Robert
/* 
   This program is designed to let the user search
   a presidential candidate by party, and then by name.
   The user will also be able to update the list of
   candidates by inserting new candidates and updating
   the polls of the candidates. This will also help the
   user keep track of the candidates.
 */
void read_party(partylist & list);//reads in party
void read(partylist & list);//reads in candidate info
int main()
{
	partylist my_list;
	cout << "Welcome user." << endl;//Welcoms user
	read_party(my_list);//call function
	read(my_list);//call function
	return 0;
}
void read_party(partylist & list)
{
	char temp;//temp varriable
	char correct;
	char politic[SIZE];//for party name
	cout << "Would you like to add a party?(Y/N):";
	cin >> temp;
	cin.ignore(100,'\n');
	temp = toupper(temp);
	if(temp == 'Y')//if answer is yes
	{
		do{
			do{
				cout << "Enter the name of the party:";//enters name of party
				cin.get(politic,SIZE,'\n');
				cin.ignore(100,'\n');
				cout << politic << endl;
				cout << "Is this correct?(Y/N):";
				cin >> correct;
				cin.ignore(100,'\n');
				correct = toupper(correct);
			}while(correct == 'N');
			list.add_party(politic);
			cout << "Add another party?(Y/N):";
			cin >> temp;
			cin.ignore(100,'\n');
			temp = toupper(temp);
		}while(temp == 'Y');

	}
}
void read(partylist & list)
{
	char temp;//temporary character
	char choice;//temporary choice character
	char id[SIZE];//name
	char points[VIEW];//major views
	int count = 0;//poll rank
	char opinion[VIEW];//user's opinion of candidate being a president
	char politic[SIZE];//party of candidate
	cout << "Would you like to insert data for the presidential candidates?(Y/N):";//insert data of candidate?
	cin >> choice;
	cin.ignore(100,'\n');
	choice = toupper(choice);
	if(choice == 'Y')//if answer is yes
	{
		do{
			do{
				cout << "Enter party:";//party
				cin.get(politic,SIZE,'\n');
				cin.ignore(100,'\n');
				cout << "Enter name:";//name
				cin.get(id,SIZE, '\n');
				cin.ignore(100,'\n');
				cout << "Enter 5 major views(separated by commas):";//5 major views
				cin.get(points, VIEW, '\n');
				cin.ignore(100,'\n');
				cout << "Enter polls:";//poll rank
				cin >> count;
				cin.ignore(100,'\n');
				cout << "Enter thoughts of him/her becoming president:";//opinion of becoming president
				cin.get(opinion, VIEW, '\n');
				cin.ignore(100, '\n');

				cout << id << endl;//display name
				cout << points << endl;//display major views
				cout << count << endl;//display poll rank
				cout << opinion << endl;//display opinion
				cout << "Are these correct?(Y/N):";//are inserted variables correct?
				cin >> temp;
				cin.ignore(100,'\n');
				temp = toupper(temp);
			}while(temp != 'Y');//while temp doesn't equal yes
			list.add_candidate(politic,id,points,count,opinion);
			cout << "Add another candidate?(Y/N):";
			cin >> temp;
			cin.ignore(100,'\n');
			temp = toupper(temp);
		}while(temp == 'Y');
	}
}
