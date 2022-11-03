#include <bits/stdc++.h>
#include "headerfiles/phonebook.h"
using namespace std;

int main()
{
	Trie fnameTrie, lnameTrie, phoneTrie;
	while (true)
	{
		cout << "------------- Phonebook Application -------------\n";
		cout << "Enter 1 to add\n";
		cout << "Enter 2 to search\n";
		cout << "Enter choice:\n";
		int choice, searchFilter;
		cin >> choice;
		string fname, lname, phone;
		string query;

		switch (choice)
		{
		case 1:
			cout << "Enter First Name:\n";
			cin >> fname;
			cout << "Enter Last Name:\n";
			cin >> lname;
			cout << "Enter Phone Number:\n";
			cin >> phone;
			addEntry(fname, fnameTrie);
			addEntry(lname, lnameTrie);
			addEntry(phone, phoneTrie);
			break;
		case 2:
			while (true)
			{
				cout << "Enter 1 to search by First Name\n";
				cout << "Enter 2 to search by Last Name\n";
				cout << "Enter 3 to search by Phone Number\n";
				cin >> searchFilter;
				switch (searchFilter)
				{
				case 1:
					cout << "Enter 1 to search partially by First Name\n";
					cout << "Enter 2 to search completely by First Name\n";
					int searchChoice;
					cin >> searchChoice;
					if (searchChoice == 1)
					{
						cout << "Enter query to search partially:\n";
						cin >> query;
						searchPartially(query, fnameTrie);
					}
					else if (searchChoice == 2)
					{
						cout << "Enter query to search completely:\n";
						cin >> query;
						cout << boolalpha << searchCompletely(query, fnameTrie);
					}
					break;
				case 2:
					cout << "Enter 1 to search partially by Last Name\n";
					cout << "Enter 2 to search completely by Last Name\n";
					int searchChoice;
					cin >> searchChoice;
					if (searchChoice == 1)
					{
						cout << "Enter query to search partially:\n";
						cin >> query;
						searchPartially(query, lnameTrie);
					}
					else if (searchChoice == 2)
					{
						cout << "Enter query to search completely:\n";
						cin >> query;
						cout << boolalpha << searchCompletely(query, lnameTrie);
					}
					break;
				case 3:
					cout << "Enter 1 to search partially by Phone Number\n";
					cout << "Enter 2 to search completely by Phone Number\n";
					int searchChoice;
					cin >> searchChoice;
					if (searchChoice == 1)
					{
						cout << "Enter the ";
						cout << "Enter query to search partially:\n";
						cin >> query;
						searchPartially(query, phoneTrie);
					}
					else if (searchChoice == 2)
					{
						cout << "Enter query to search completely:\n";
						cin >> query;
						cout << boolalpha << searchCompletely(query, phoneTrie);
					}
					break;
				}
			}
			break;

		default:
			cout << "Choice other than A, B and C";
			break;
		}
	}
	return 0;
}