#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE (26)

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isWordEnd;
};

struct TrieNode *getNode()
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isWordEnd = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

void insert(struct TrieNode *root, const string key)
{
	struct TrieNode *iterator = root;

	for (int level = 0; level < key.length(); level++)
	{
		int index = key[level] - 'a';
		if (!iterator->children[index])
			iterator->children[index] = getNode();

		iterator = iterator->children[index];
	}

	iterator->isWordEnd = true;
}

bool isLastNode(struct TrieNode *root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return 0;
	return 1;
}

void suggestionsRec(struct TrieNode *root, string currPrefix)
{
	if (root->isWordEnd)
		cout << currPrefix << endl;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
		{
			char child = 'a' + i;
			suggestionsRec(root->children[i], currPrefix + child);
		}
}

int printAutoSuggestions(TrieNode *root, const string query)
{
	struct TrieNode *iterator = root;
	for (char c : query)
	{
		int ind = c - 'a';
		if (!iterator->children[ind])
			return 0;

		iterator = iterator->children[ind];
	}

	if (isLastNode(iterator))
	{
		cout << query << endl;
		return -1;
	}
	suggestionsRec(iterator, query);
	return 1;
}
