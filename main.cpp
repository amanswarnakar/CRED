#include <bits/stdc++.h>
#include "headerfiles/phonebook.h"
using namespace std;

int main()
{
    //   func('a');
    // string firstName = " ";
    while (true)
    {
        cout << "------------- Phonebook Application -------------\n";
        cout << "Enter 1 to add\n";
        cout << "Enter 2 to search\n";
        cout << "Enter choice";
        int choice;
        cin >> choice;
        string fname, lname;
        vector<int> phone(10);
        string query;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter firstname:\n";
            cin >> fname;
            cout << "Enter lastname:\n";
            cin >> lname;
            cout << "Enter phone:\n";
            for (int i = 0; i < 10; i++)
            {
                cin >> phone[i];
            }
            addEntry(fname, lname, phone);
            break;
        }
        case 2:
        {
            cout << "Enter 1 to search Partially\n";
            cout << "Enter 2 to search Completely\n";
            int searchChoice;
            cin >> searchChoice;
            if (searchChoice == 1)
            {
                cout << "Enter query to search Partially:\n";
                cin >> query;
                searchPartially(query);
            }
            else if (searchChoice == 2)
            {
                cout << "Enter query to search completely:\n";
                cin >> query;
                searchCompletely(query);
            }
            else
            {
                // wrong option selected
            }
            break;
        }
        default:
        {
            cout << "Choice other than 1,2";
            break;
            // would you like to continue
        }
        }
    }
    return 0;
}