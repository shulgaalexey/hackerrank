#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	vector<node *> children;
	node *parent;
	int rank;
	int id;
	node() : parent(NULL), rank(0), id(0) {}
};

void trace(const vector<node *> &tree)
{
	return;
	cout << "Tracing:" << endl;
	for (size_t i = 0; i < tree.size(); i++) {
		node *n = tree[i];
		cout << "<id: " << n->id << " rank: " <<  n->rank;
		cout << " children: " << n->children.size() << ": [";
		for (size_t j = 0; j < n->children.size(); j++) {
			node *c = n->children[j];
			cout << int(c->id) << " ";
		}
		cout << "]> " << endl;
	}
}

int calc_rank(node *root)
{
	if (!root)
		return 0;
	root->rank = 1;
	for (size_t i = 0; i < root->children.size(); i++)
		root->rank += calc_rank(root->children[i]);

	return root->rank;
}

void raise_decreas(node *root, int rank)
{
	if (!root)
		return;
	root->rank -= rank;
	raise_decreas(root->parent, root->rank);
}

int count_cuts(node *root)
{
	if (!root)
		return 0;

	int cnt = 0;
	for (size_t i = 0; i < root->children.size(); i++)
		cnt += count_cuts(root->children[i]);

	if (!(root->rank & 1)) {
		//cout << "CUTTING: id=" << root->id << " rank =" << root->rank << endl;
		if (root->parent) {
			cnt++;
			raise_decreas(root->parent, root->rank);
		}
	}

	return cnt;
}

int main(void)
{
	int N = 0;
	int M = 0;
	cin >> N >> M;

	vector<node *> tree(N);
	for (int i = 0; i < N; i++) {
		tree[i] = new node;
		tree[i]->rank = 0;
		tree[i]->parent = NULL;
		tree[i]->id = i;
	}

	vector<pair<int, int> > edges(M);

	for (int i = 0; i < M; i++) {
		int from = 0;
		int to = 0;
		cin >> from >> to;
		edges[i].first = from - 1;
		edges[i].second = to - 1;
	}

	for (int i = 0; i < M; i++) {
		node *child = tree[edges[i].first];
		node *parent = tree[edges[i].second];
		parent->children.push_back(child);
		child->parent = parent;
	}

	trace(tree);

	calc_rank(tree[0]);

	trace(tree);

	const int ret = count_cuts(tree[0]);

	trace(tree);

	cout << ret << endl;

	for (int i = 0; i < N; i++)
		delete tree[i];

	return 0;
}
