#include <bits/stdc++.h>
#include "headerfiles/phonebook.h"
using namespace std;

int main()
{
  func('a');
  // string firstName = " ";
  while (true)
  {
    cout << "------------- Phonebook Application -------------\n";
    cout << "Enter 1 to add\n";
    cout << "Enter 2 to search\n";
    cout << "Enter choice";
    int choice;
    cin >> choice;
    string fname, lname, phone;
    string query;

    switch (choice)
    {
    case 1:
      cout << "Enter firstname:\n";
      cin >> fname;
      cout << "Enter lastname:\n";
      cin >> lname;
      cout << "Enter phone:\n";
      cin >> phone;
      addEntry(fname, lname, phone);
      break;
    case 2:
      cout << "Enter 1 to search partially\n";
      cout << "Enter 2 to search partially\n";
      int searchChoice;
      cin >> searchChoice;
      if (searchChoice == 1)
      {
        cout << "Enter query to search partially:\n";
        cin >> query;
        searchPartially(query);
      }
      else if (searchChoice == 2)
      {
        cout << "Enter query to search completely:\n";
        cin >> query;
        searchCompletely(query);
      }
      break;

    default:
      cout << "Choice other than A, B and C";
      break;
    }
  }
  return 0;
}