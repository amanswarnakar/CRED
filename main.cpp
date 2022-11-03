#include <bits/stdc++.h>
#include "headerfiles/phonebook.h"
using namespace std;

int main()
{
	Trie fnameTrie, lnameTrie, phoneTrie;
	while (true)
	{
		cout << "\n------------- Phonebook Application ------------\n\n";
		cout << "Enter 1 to add contact\n";
		cout << "Enter 2 to search contact\n";
		cout << "Enter any other number to exit\n";
		cout << "Enter choice:\n";
		int choice, searchFilter, searchChoice;
		cin >> choice;
		bool phoneFlag = true;
		string fname, lname, phone;
		string query;

		switch (choice)
		{
		case 1:
			cout << "Enter First Name:\n";
			cin >> fname;
			cout << "Enter Last Name:\n";
			cin >> lname;
			while (true)
			{
				cout << "Enter Phone Number:\n";
				cin >> phone;
				// cout << phone << endl;
				phoneFlag = true;
				if (phone.size() == 10)
				{
					for (auto &s : phone)
					{
						// cout << s << " ";
						if (s - '0' > 9 || s - '0' < 0)
						{
							phoneFlag = false;
							break;
						}
					}
				}
				else
				{
					phoneFlag = false;
				}
				if (!phoneFlag)
					cout << "You have entered invalid phone number. Please try again.\n";
				else
				{
					break;
				}
			}

			addEntry(fname, fnameTrie);
			addEntry(lname, lnameTrie);
			addEntry(phone, phoneTrie);
			break;
		case 2:
			// while (true)
			{
				cout << "Enter 1 to search by First Name\n";
				cout << "Enter 2 to search by Last Name\n";
				cout << "Enter 3 to search by Phone Number\n";
				cin >> searchFilter;
				// while (true)
				{
					switch (searchFilter)
					{
					case 1:
						cout << "Enter 1 to search partially by First Name\n";
						cout << "Enter 2 to search completely by First Name\n";
						cin >> searchChoice;
						if (searchChoice == 1)
						{
							cout << "Enter query to search partially:\n";
							cin >> query;
							cout << boolalpha << searchPartially(query, fnameTrie) << endl;
						}
						else if (searchChoice == 2)
						{
							cout << "Enter query to search completely:\n";
							cin >> query;
							cout << boolalpha << searchCompletely(query, fnameTrie) << endl;
						}
						break;
					case 2:
						cout << "Enter 1 to search partially by Last Name\n";
						cout << "Enter 2 to search completely by Last Name\n";
						cin >> searchChoice;
						if (searchChoice == 1)
						{
							cout << "Enter query to search partially:\n";
							cin >> query;
							cout << boolalpha << searchPartially(query, lnameTrie) << endl;
						}
						else if (searchChoice == 2)
						{
							cout << "Enter query to search completely:\n";
							cin >> query;
							cout << boolalpha << searchCompletely(query, lnameTrie) << endl;
						}
						break;
					case 3:
						cout << "Enter 1 to search partially by Phone Number\n";
						cout << "Enter 2 to search completely by Phone Number\n";
						cin >> searchChoice;
						if (searchChoice == 1)
						{
							cout << "Enter the ";
							cout << "Enter query to search partially:\n";
							cin >> query;
							cout << boolalpha << searchPartially(query, phoneTrie) << endl;
						}
						else if (searchChoice == 2)
						{
							cout << "Enter query to search completely:\n";
							cin >> query;
							cout << boolalpha << searchCompletely(query, phoneTrie) << endl;
						}
						break;
					default:
						cout << "Choice other than 1, 2 and 3. Please enter valid choice\n";
						break;
					}
				}
			}
			break;

		default:
			cout << "Thank you for using our PhoneBook Application.\n";
			return 0;
			break;
		}
	}
	return 0;
}