#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	struct TrieNode *children[26];
	bool isWordEnd;
};

struct TrieNode *constructor()
{
	struct TrieNode *parent = new TrieNode;
	parent->isWordEnd = false;

	for (int i = 0; i < 26; i++)
		parent->children[i] = NULL;

	return parent;
}

void insert(struct TrieNode *root, string key)
{
	struct TrieNode *iterator = root;

	for (int level = 0; level < key.length(); level++)
	{
		int index = key[level] - 'a';
		if (!iterator->children[index])
			iterator->children[index] = constructor();

		iterator = iterator->children[index];
	}

	iterator->isWordEnd = true;
}

void dfs(struct TrieNode *root, string currPrefix)
{
	if (root->isWordEnd)
		cout << currPrefix << endl;

	for (int i = 0; i < 26; i++)
		if (root->children[i])
		{
			char child = 'a' + i;
			dfs(root->children[i], currPrefix + child);
		}
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

	// complete matching wala start from here
	dfs(iterator, query);
	return 1;
}
