#include <iostream>
#include "headerfiles/phonebook.h"
using namespace std;

int main()
{
	while (true)
	{
		int choice = welcomeMenu();
		switch (choice)
		{
		case 1:
			insertInPhoneBook();
			break;
		case 2:
			searchInPhoneBook();
			break;
		default:
			cout << "Thank you for using PhoneBook Application.\n -> by Blackmar-Diemer Gambit\n";
			break;
		}
	}
}