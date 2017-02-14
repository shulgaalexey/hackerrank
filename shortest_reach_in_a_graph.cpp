#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int INF = 1000000;

int main(void)
{
	int Q = 0;
	cin >> Q;
	for (int c = 0; c < Q; c++) {
		int n = 0, m = 0;
		cin >> n >> m;

		vector<vector<int> > adj(n);
		for (int i = 0; i < m; i++) {
			int u = 0, v = 0;
			cin >> u >> v;
			adj[u - 1].push_back(v - 1);
			adj[v - 1].push_back(u - 1);
		}

		vector<int> V(n);
		for (int i = 0; i < n; i++)
			V[i] = INF;

		int S = 0;
		cin >> S;
		V[S - 1] = 0;

		queue<int> q;
		q.push(S - 1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (size_t i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i];
				if (V[v] == INF) {
					V[v] = V[u] + 1;
					q.push(v);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (i != (S - 1))
				cout << ((V[i] == INF) ? (-1) : (6 * V[i])) << " ";
		}
		cout << endl;
	}
	return 0;
}
