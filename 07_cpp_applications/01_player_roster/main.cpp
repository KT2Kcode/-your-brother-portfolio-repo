#include <iostream>
#include <string>
using namespace std;

class Player
{
	string firstname, lastname, position;
	
	public:
			void getFirstName()
			{
				getline(cin, firstname);
			}
			void getLastName()
			{
				getline(cin, lastname);
			}
			void getPosition()
			{
				cin >> position;
			}
			void displayPlayerInfo()
			{
				cout << "              "  << firstname << " " << lastname << "             " << position << endl;
			}
};


int Roster()
{
	Player pla[100];
	for (int i=0; i < 100; i++) // Player entry limit.
	{
		if (i == 0) // A code for first time use in a program.
		{		
		cout << "Welcome to the Player Roster Project! Press ENTER to continue." << endl;
		}
		cin.get();
		cout << "Player " << i + 1 << endl;
		cout << "Enter the Player's First Name." << endl; // Enter the First Name for a player
		pla[i].getFirstName();
		cout << "Enter the Player's Last Name." << endl; // Enter the Last Name for a player
		pla[i].getLastName();
		cout << "Now enter the Player's Position." << endl; // Player's position
		pla[i].getPosition();	
	}
	
	for (int i=0; i < 100; i++) // Player entry limit.
		{
		cout << "Player # " << i + 1 << "   " << " Name                " << "  Position" << endl;
		pla[i].displayPlayerInfo();
		}
	return 0;
	
};

int main()
{
	
	Player pla[100];
	for (int i=0; i < 100; i++) // Player entry limit.
	{
		if (i == 0) // A code for first time use in a program.
		{		
		cout << "Welcome to the Player Roster Project! Press ENTER to continue." << endl;
		}
		cin.get();
		cout << "Player " << i + 1 << endl;
		cout << "Enter the Player's First Name." << endl; // Enter the First Name for a player
		pla[i].getFirstName();
		cout << "Enter the Player's Last Name." << endl; // Enter the Last Name for a player
		pla[i].getLastName();
		cout << "Now enter the Player's Position." << endl; // Player's position
		pla[i].getPosition();
		    	
	}
	
	for (int i=0; i < 100; i++) // Player entry limit.
		{
		cout << "Player # " << i + 1 << "   " << " Name                " << "  Position" << endl;
		pla[i].displayPlayerInfo();
		}
	return 0;
}