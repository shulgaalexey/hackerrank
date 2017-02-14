#include <iostream>
#include <string>
#include <map>
using namespace std;

class node {
public:
	char v;
	map<char, node *> children;
	bool is_word;
	int words_count;
	node() : v(0), is_word(false), words_count(0) {}
};

node *move_to_end(const string &str, node *root)
{
	if (str.empty() || !root)
		return NULL;
	if (root->children.count(str[0])) {
		if (str.length() == 1)
			return root->children[str[0]];
		else
			return move_to_end(str.substr(1), root->children[str[0]]);
	} else {
		return NULL;
	}
}

/*int count_words(node *root)
{
	if (!root)
		return 0;
	int count = 0;
	if (root->is_word)
		count++;
	for (map<char, node *>::iterator it = root->children.begin();
			it != root->children.end(); ++it) {
		count += count_words(it->second);
	}
	return count;
}*/

void add(const string &str, node *root)
{
	if (!root || str.empty())
		return;
	root->words_count++;
	if (root->children.count(str[0])) {
		add(str.substr(1), root->children[str[0]]);
	} else {
		node *n = new node();
		n->v = str[0];

		root->children[str[0]] = n;
		if (str.length() == 1) {
			n->is_word = true;
			n->words_count = 1;
		} else {
			add(str.substr(1), n);
		}
	}
}

int find_partial(const string &str, node *root)
{
	if (str.empty() || !root)
		return 0;
	node *word_end = move_to_end(str, root);
	//return count_words(word_end); // Recursive counting causing time outs
	if (!word_end)
		return 0;
	else
		return word_end->words_count;
}

int main(void)
{
	int N = 0;
	cin >> N;

	node *contacts = new node();

	for (int i = 0; i < N; i++) {
		string op;
		string contact;
		cin >> op >> contact;
		if (op == "add")
			add(contact, contacts);
		else if (op == "find")
			cout << find_partial(contact, contacts) << endl;
		else
			cout << "Unknown command" << endl;
	}

	delete contacts;
	return 0;
}
