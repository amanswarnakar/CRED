#include <bits/stdc++.h>
#pragma once
using namespace std;

class TrieNode
{
public:
	char data;
	TrieNode *child[26];
	bool isEnd;

	TrieNode(char ch)
	{
		data = ch;
		for (int i = 0; i < 26; i++)
		{
			child[i] = NULL;
		}
		isEnd = false;
	}
};

class Trie
{

public:
	TrieNode *root;

	Trie()
	{
		root = new TrieNode('\0');
	}

	void insertUtility(TrieNode *root, string word)
	{
		if (word.length() == 0)
		{
			root->isEnd = true;
			return;
		}

		int index = word[0] - 'a';
		TrieNode *child;

		if (root->child[index] != NULL)
		{
			child = root->child[index];
		}
		else
		{
			child = new TrieNode(word[0]);
			root->child[index] = child;
		}

		insertUtility(child, word.substr(1));
	}

	void insert(string word)
	{
		insertUtility(root, word);
	}

	bool completeSearchUtility(TrieNode *root, string word)
	{
		if (word.length() == 0)
		{
			return root->isEnd;
		}

		int index = word[0] - 'a';
		TrieNode *child;

		if (root->child[index] != NULL)
		{
			child = root->child[index];
		}
		else
		{
			return false;
		}

		return completeSearchUtility(child, word.substr(1));
	}

	bool completeSearch(string word)
	{
		return completeSearchUtility(root, word);
	}
};

void addEntry(string insertVal, Trie obj)
{
	obj.insert(insertVal);
}

bool searchPartially(string query, Trie obj)
{
	cout << "Search Partially" << endl;
}

bool searchCompletely(string query, Trie obj)
{
	return obj.completeSearch(query);
}