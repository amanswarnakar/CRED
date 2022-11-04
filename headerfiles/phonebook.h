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
	int choice;
	if (!(cin >> choice) or choice > 2)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		choice = 0;
	}
	return choice;
}

vector<vector<string>> database(23700);

struct TrieNode *fnameTrie = constructor();
struct TrieNode *lnameTrie = constructor();
struct TrieNode *phoneTrie = constructor();

void insertInTrie(struct TrieNode *root, string key, int SerialNo)
{
	struct TrieNode *iterator = root;
	for (int level = 0; level < key.length(); level++)
	{
		int index = key[level] - 'a';
		if (isdigit(key[level]))
			index = key[level] - '0';
		if (!iterator->children[index])
			iterator->children[index] = constructor();

		iterator = iterator->children[index];
	}

	iterator->isWordEnd.push_back(SerialNo);
}

bool isPhoneNumber(string &phone)
{
	for (char &digit : phone)
		if (!isdigit(digit))
			return false;

	return true;
}
void readFromCSV()
{
	string line, word;
	fstream file("gg.csv", ios::in);
	if (file.is_open())
	{
		cout << "Reading data from CSV File." << endl;
		while (getline(file, line))
		{
			vector<string> row;
			stringstream s(line);

			while (getline(s, word, ','))
			{
				row.push_back(word);
			}
			SerialNo++;
			database[SerialNo] = {row[0], row[1], row[2]};
			transform(row[0].begin(), row[0].end(), row[0].begin(), ::tolower);
			transform(row[1].begin(), row[1].end(), row[1].begin(), ::tolower);

			insertInTrie(fnameTrie, row[0], SerialNo);
			insertInTrie(lnameTrie, row[1], SerialNo);
			insertInTrie(phoneTrie, row[2], SerialNo);
		}
	}
	else
		cout << "Could not open the file\n";
}

void insertInPhoneBook()
{
	string fname, lname, phone;
	cout << "Enter First Name:\n";
	cin >> fname;
	cout << "Enter Last Name:\n";
	cin >> lname;

	while (true)
	{
		cout << "Enter Phone Number:\n";
		cin >> phone;

		if (!isPhoneNumber(phone))
			cout << "You have entered invalid phone number. Please try again.\n";
		else
		{
			SerialNo++;
			database[SerialNo] = {fname, lname, phone};

			transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
			transform(lname.begin(), lname.end(), lname.begin(), ::tolower);

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
			if (isdigit(currPrefix.back()))
				child = '0' + i;
			DFS(root->children[i], currPrefix + child);
		}
}

void searchCompletely(TrieNode *root, string query)
{
	struct TrieNode *iterator = root;
	for (char &c : query)
	{
		int ind = c - 'a';
		if (isdigit(c))
			ind = c - '0';
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
		if (isdigit(c))
			ind = c - '0';
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
	int searchFilter;
	while (!(cin >> searchFilter and searchFilter < 4))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input. Please re-enter.\n";
	}
	if (searchFilter == 1)
	{
		TrieHeader = fnameTrie;
	}
	else if (searchFilter == 2)
	{
		TrieHeader = lnameTrie;
	}
	else
	{
		TrieHeader = phoneTrie;
	}

	cout << "Enter 1 to search Partially\n";
	cout << "Enter 2 to search Completely\n";
	int searchChoice;
	string query;

	while (!(cin >> searchChoice) or searchChoice > 3)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input. Please re-enter.\n";
	}

	if (searchChoice == 1)
	{
		cout << "Enter query to search partially:\n";
		cin >> query;
		transform(query.begin(), query.end(), query.begin(), ::tolower);
		cout << "\t\tOUTPUT\n";
		int result = searchPartially(TrieHeader, query);
		if (!result)
		{
			cout << "No Matching Result Found.\n";
		}
	}
	else
	{
		cout << "Enter query to search completely:\n";
		cin >> query;
		transform(query.begin(), query.end(), query.begin(), ::tolower);
		cout << "\t\tOUTPUT\n";
		searchCompletely(TrieHeader, query);
	}
}
