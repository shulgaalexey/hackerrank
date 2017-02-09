#include <iostream>
#include <vector>
#include <queue>
using namespace std;

static const int INF = 1000000;

int main(void)
{
	int N, E;
	cin >> N >> E;

	vector<vector<pair<int, int> > > adj(N);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back(pair<int, int>(v - 1, w));
		adj[v - 1].push_back(pair<int, int>(u - 1, w));
	}

	int fare = 0;

	vector<bool> visited(N);
	for (int i = 0; i < N; i++)
		visited[i] = false;

	queue<int> q;
	q.push(0);
	visited[0] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();

		if (u == (N - 1))
			break;

		int cur_min = INF;
		int min_idx = -1;
		for (size_t i = 0; i < adj[u].size(); i++) {
			pair<int, int> p = adj[u][i];
			if (!visited[p.first]) {
				visited[p.first] = true;
				int cur_fare = p.second - fare;
				if (cur_fare < cur_min) {
					cur_min = cur_fare;
					min_idx = p.first;
				}
			}
		}

		q.push(min_idx);
		fare += std::max(cur_min, 0);
	}

	cout << fare << endl;
	return 0;
}
