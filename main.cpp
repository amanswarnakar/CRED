#include <bits/stdc++.h>
#include "headerfiles/phonebook.h"
using namespace std;

int main()
{
	// Trie fnameTrie, lnameTrie, phoneTrie;
	struct TrieNode *fnameTrie = constructor();
	struct TrieNode *lnameTrie = constructor();
	struct TrieNode *phoneTrie = constructor();
	while (true)
	{
		cout << "\n------------- Phonebook Application ------------\n\n";
		cout << "Enter 1 to add contact\n";
		cout << "Enter 2 to search contact\n";
		cout << "Enter any other number to exit\n";
		cout << "Enter choice:\n";
		int choice, searchChoice;
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
				phoneFlag = true;
				if (phone.size() == 10)
				{
					for (auto &s : phone)
					{
						if (s - '0' > 9 or s - '0' < 0)
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

			insert(fnameTrie, fname);
			insert(lnameTrie, lname);
			insert(phoneTrie, phone);

			break;
		case 2:
			int searchFilter;
			while (true)
			{
				cout << "Enter 1 to search by First Name\n";
				cout << "Enter 2 to search by Last Name\n";
				cout << "Enter 3 to search by Phone Number(10 Digits)\n";
				cin >> searchFilter;
				bool searchFlag = true;

				if (searchFilter > 3)
				{
					searchFlag = false;
				}
				if (!searchFlag)
					cout << "You have entered invalid choice. Please try again.\n";
				else
				{
					break;
				}
			}

			TrieNode *TrieHeader;
			if (searchFilter == 1)
				TrieHeader = fnameTrie;
			else if (searchFilter == 2)
				TrieHeader = lnameTrie;
			else if (searchFilter == 3)
				TrieHeader = phoneTrie;
			else
				cout << "Wrong Option Selected.\n";

			cout << "Enter 1 to search Partially\n";
			cout << "Enter 2 to search Completely\n";
			cin >> searchChoice;
			if (searchChoice == 1)
			{
				cout << "Enter query to search partially:\n";
				cin >> query;
				cout << "OUTPUT\n";
				int result = searchPartially(TrieHeader, query);
				if (!result)
				{
					cout << "No Matching Result Found.\n";
				}
			}
			else if (searchChoice == 2)
			{
				// STILL TO BE DONE
			}
			else
			{
				cout << "Invalid Choice. PLEASE TRY AGAIN!\n";
				break;
			}
			break;
		default:
			cout << "Thank you for using PhoneBook Application.\n -> by Blackmar-Diemer Gambit\n";
			return 0;
			break;
		}
	}
}