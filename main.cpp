#include <fstream>
#include <sstream>
#include "headerfiles/phonebook.h"
using namespace std;

int main()
{
	vector<string> row;
	string line, word;
	fstream file("test.csv", ios::in);
	if (file.is_open())
	{
		cout << "Reading data from CSV File." << endl;
		while (getline(file, line))
		{
			row.clear();	

			getline(file, line);

			stringstream s(line);

			while (getline(s, word, ','))
			{
				row.push_back(word);
			}
			insertInPhoneBookFromCSV(row[0], row[1], row[2]);
		}
	}
	else
		cout << "Could not open the file\n";

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
			return 0;
			break;
		}
	}
}