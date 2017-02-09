#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int INF = 1000000;

int main(void)
{
	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N = 0; // ladders
		int M = 0; // snakes
		cin >> N;

		vector<pair<int, int> > ladders(N);
		for (int i = 0; i < N; i++)
			cin >> ladders[i].first >> ladders[i].second;

		cin >> M;
		vector<pair<int, int> > snakes(M);
		for (int i = 0; i < M; i++)
			cin >> snakes[i].first >> snakes[i].second;

		vector<int> nodes(101);
		nodes[0] = 0; // ignored
		nodes[1] = 0; // start
		for (int i = 2; i < 101; i++)
			nodes[i] = INF;

		vector<vector<int> > adj(101); // Adacency lists for each node
		for (int i = 1; i < 101; i++) {
			for (int j = 1; j <= 6; j++) {
					if ((i + j) <= 100) {
						adj[i].push_back(i + j);
					}
			}
		}

		// Setting jupmps for ladders
		for (int i = 0; i < N; i++) {
			const pair<int, int> l = ladders[i];
			adj[l.first].clear();
			adj[l.first].push_back(l.second);
		}

		// Setting jupmps for snakes
		for (int i = 0; i < M; i++) {
			const pair<int, int> s = snakes[i];
			adj[s.first].clear();
			adj[s.first].push_back(s.second);
		}

		// Finding Single-source Shortes Path: Dijkstra => BFS
		queue<int> q;
		q.push(1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			// Correcting way length for ladders and snakes
			int w = 1;
			if ((adj[u].size() == 1) && (u != 99))
				w = 0;

			for (size_t i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i];
				if (nodes[v] > (nodes[u] + w)) {
					nodes[v] = nodes[u] + w;
					q.push(v);
				}
			}
		}

        if (nodes[100] >= INF)
            nodes[100] = -1;

		cout << nodes[100] << endl;
	}
	return 0;
}
