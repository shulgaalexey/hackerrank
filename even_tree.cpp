#include <iostream>
#include <vector>
using namespace std;

class node {
public:
	vector<node *> children;
	node *parent;
	int rank;
};

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
	root->rank += rank;
	raise_decreas(root->parent, root->rank);
}

int count_cuts(node *root)
{
	if (!root)
		return 0;

	int cnt = 0;
	for (size_t i = 0; i < root->children.size(); i++)
		cnt += count_cuts(root->children[i]);

	if (!root->rank & 1) {
		cnt++;
		raise_decreas(root->parent, root->rank);
	}

	return cnt;
}

int main(void)
{
	int N = 0;
	int M = 0;
	cin >> N >> M;

	node *tree = new node[N];
	for (int i = 0; i < N; i++) {
		tree[i].rank = 0;
		tree[i].parent = NULL;
	}

	for (int i = 0; i < M; i++) {
		int from = 0;
		int to = 0;
		cin >> from >> to;
		tree[from - 1].parent = &tree[to - 1];
		tree[to - 1].children.push_back(&tree[from - 1]);
	}

	calc_rank(&tree[0]);

	const int ret = count_cuts(&tree[0]);

	cout << ret << endl;

	delete [] tree;
	return 0;
}
