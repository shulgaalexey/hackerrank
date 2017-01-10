#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node {
public:
	vector<int> children;
	int dist;
	node() : dist(-1) {}
};

int main() {
	int q = 1;
	cin >> q; //~
	for (int t = 0; t < q; t++) {
		int n = 4;
		cin >> n; //~
		node *G = new node[n];
		int m = 2;
		cin >> m; //~

		//int ua[] = {1, 1}; // -----------
		//int va[] = {2, 3}; // -----------

		for (int e = 0; e < m; e++) {
			int u = 0;
			int v = 0;
			cin >> u; //~
			cin >> v; //~
			//u = ua[e]; // -----------
			//v = va[e]; // -----------
			G[u -1].children.push_back(v - 1);
			G[v -1].children.push_back(u - 1);
		}
		int s = 1;
		cin >> s; //~
		G[s - 1].dist = 0;
		queue<int> q;
		q.push(s - 1);
		while (!q.empty()) {
			int cur_node = q.front();
			q.pop();
			node *p = &G[cur_node];
			for (size_t i = 0; i < p->children.size(); i++) {
				int cur_child = p->children[i];
				node *ch = &G[cur_child];
				if (ch->dist >= 0)
					continue;
				ch->dist = p->dist + 1;
				q.push(cur_child);
			}
		}


		for (int i = 0; i < n; i++) {
			if (i == (s - 1))
				continue;
			if (G[i].dist > 0)
				cout << int(6 * G[i].dist) << " ";
			else
				cout << "-1 ";
		}
		cout << endl;
		delete [] G;
	}
	return 0;
}
