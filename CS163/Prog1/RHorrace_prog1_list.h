#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//Horrace, Robert
/*
   This .h file is designed for listing classes
   that contain the functions and variables that
   are going to be used by the main program.
 */

const int SIZE = 50;//always 50
const int VIEW = 500;//always 500
class candidate
{
	public:
		candidate();//contructor
		~candidate();//estructor
		void get_info(char nm[SIZE],char pnt[VIEW], int & pll, char thght[VIEW]);//get info function
		void update_polls(int & plls);//update poll function
		void display();//displays variable function
	private:
		char * name;//name DAA
		char * views;//views DAA
		int polls;//poll rank
		char * thoughts;//opinion DAA
};
struct candinode//node for LLL
{
	candidate data;//data for candidate class
	candinode * next;//next node
};
class party
{
	public:
		party();//constructor
		~party();//destructor
		void insert_party(char pltc[SIZE]);//insert party name
		void copy(char pltc[SIZE]);//copies party name
		void display();//dislays party
	private:
		char * prty;//party DAA
};
class candilist
{
	public:
		candilist();//constructor
		~candilist();//destructor
		void add(char nm[SIZE],char pnt[VIEW], int & pll, char thght[VIEW]);//adds candidate in a node
		void display();//displays each node
		
		
	private:
		candinode * head;//node head
};
struct partynode
{
	party data;//data
	candilist * list;//candinode variable
	partynode * next;//next
};
class partylist
{
	public:
		partylist();//constructor
		~partylist();//destructor
		void add_party(char pltc[SIZE]);
		void get_party(char pltc[SIZE]);
		void add_candidate(char political[SIZE], char nm[SIZE],char pnt[VIEW], int & pll, char thght[VIEW]);//adds candidate in a node
		void display();//displays party and cnadidtaes in the party
	private:
		partynode * p_head;
};
