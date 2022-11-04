#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	struct TrieNode *children[26];
	vector<int> isWordEnd;
};

struct TrieNode *constructor()
{
	struct TrieNode *parent = new TrieNode;

	for (int i = 0; i < 26; i++)
		parent->children[i] = NULL;

	return parent;
};

int SerialNo = 0;
int welcomeMenu()
{
	cout << "\n------------- Phonebook Application ------------\n\n";
	cout << "Enter 1 to add contact\n";
	cout << "Enter 2 to search contact\n";
	cout << "Enter any other number to exit\n";
	cout << "Enter choice:\n";
	int choice;
	cin >> choice;
	return choice;
}

unordered_map<int, vector<string>> database;

struct TrieNode *fnameTrie = constructor();
struct TrieNode *lnameTrie = constructor();
struct TrieNode *phoneTrie = constructor();

void insertInTrie(struct TrieNode *root, string key, int SerialNo)
{
	struct TrieNode *iterator = root;
	for (int level = 0; level < key.length(); level++)
	{
		int index = key[level] - 'a';
		if (!iterator->children[index])
			iterator->children[index] = constructor();

		iterator = iterator->children[index];
	}

	iterator->isWordEnd.push_back(SerialNo);
}

bool isPhoneNumber(string &phone)
{
	if (phone.size() > 15 or phone.size() < 7)
		return false;
	for (char &digit : phone)
		if (!isdigit(digit))
			return false;

	return true;
}

void insertInPhoneBook()
{
	string fname, lname, phone;
	bool phoneFlag = true;

	cout << "Enter First Name:\n";
	cin >> fname;
	cout << "Enter Last Name:\n";
	cin >> lname;

	while (phoneFlag)
	{
		cout << "Enter Phone Number:\n";
		cin >> phone;
		phoneFlag = isPhoneNumber(phone);
		if (!phoneFlag)
			cout << "You have entered invalid phone number. Please try again.\n";
		else
		{
			SerialNo++;
			database.insert({SerialNo, {fname, lname, phone}});

			insertInTrie(fnameTrie, fname, SerialNo);
			insertInTrie(lnameTrie, lname, SerialNo);
			insertInTrie(phoneTrie, phone, SerialNo);

			break;
		}
	}
}

void printer(struct TrieNode *iterator)
{
	for (int &it : iterator->isWordEnd)
	{
		for (string &details : database[it])
			cout << details << '\t';
		cout << endl;
	}
}

void DFS(struct TrieNode *root, string currPrefix)
{
	printer(root);

	for (int i = 0; i < 26; i++)
		if (root->children[i])
		{
			char child = 'a' + i;
			DFS(root->children[i], currPrefix + child);
		}
}

void searchCompletely(TrieNode *root, string query)
{
	struct TrieNode *iterator = root;
	for (char &c : query)
	{
		int ind = c - 'a';
		if (!iterator->children[ind])
		{
			cout << "No Complete Match for the query.\n";
			return;
		}

		iterator = iterator->children[ind];
	}

	if (iterator->isWordEnd.size())
	{
		printer(iterator);
	}
	else
		cout << "No Complete Match for the query.\n";
}
int searchPartially(TrieNode *root, string query)
{
	struct TrieNode *iterator = root;
	for (char &c : query)
	{
		int ind = c - 'a';
		if (!iterator->children[ind])
			return 0;

		iterator = iterator->children[ind];
	}
	DFS(iterator, query);
	return 1;
}

void searchInPhoneBook()
{
	cout << "Enter 1 to search by First Name\n";
	cout << "Enter 2 to search by Last Name\n";
	cout << "Enter 3 to search by Phone Number\n";

	TrieNode *TrieHeader;
	while (true)
	{
		int searchFilter;
		cin >> searchFilter;
		if (searchFilter == 1)
		{
			TrieHeader = fnameTrie;
			break;
		}
		else if (searchFilter == 2)
		{
			TrieHeader = lnameTrie;
			break;
		}
		else if (searchFilter == 3)
		{
			TrieHeader = phoneTrie;
			break;
		}
		else
			cout << "Wrong Option Selected. Enter correct option.\n";
	}
	cout << "Enter 1 to search Partially\n";
	cout << "Enter 2 to search Completely\n";
	int searchChoice;
	cin >> searchChoice;

	string query;
	while (true)
	{
		if (searchChoice == 1)
		{
			cout << "Enter query to search partially:\n";
			cin >> query;
			cout << "\t\tOUTPUT\n";
			int result = searchPartially(TrieHeader, query);
			if (!result)
			{
				cout << "No Matching Result Found.\n";
			}
			break;
		}
		else if (searchChoice == 2)
		{
			cout << "Enter query to search completely:\n";
			cin >> query;
			cout << "\t\tOUTPUT\n";
			searchCompletely(TrieHeader, query);
			break;
		}
		else
			cout << "Invalid Choice. PLEASE TRY AGAIN!\n";
	}
}