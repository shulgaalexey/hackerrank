#include <iostream>
#include <vector>
#include <map>
using namespace std;

static const int INF = 1000000;

class edge {
public:
	int to;
	int w;
	edge() : to(0), w(0) {}
	edge(int _to, int _w) : to(_to), w(_w) {}
};

int main(void)
{
	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N = 0, M = 0;
		cin >> N >> M;

		vector<vector<edge> > adj(N);
		for (int i = 0; i < M; i++) {
			int u = 0, v = 0, w = 0;
			cin >> u >> v >> w;
			adj[u - 1].push_back(edge(v - 1, w));
			adj[v - 1].push_back(edge(u - 1, w));
		}

		map<int, int> nodes;
		for (int i = 0; i < N; i++)
			nodes[i] = INF;

		int S = 0;
		cin >> S;
		nodes[S - 1] = 0;

		vector<int> result(N);
		for (int i = 0; i < N; i++)
			result[i] = -1;

		// Dijkstra
		while (!nodes.empty()) {

			map<int, int>::iterator it = nodes.begin();
			map<int, int>::iterator min_it = nodes.begin();
			for (; it != nodes.end(); ++it) {
				if (it->second < min_it->second)
					min_it = it;

			}
			it = min_it;

			int u = it->first;
			int w = it->second;

			//cout << "Processing: " << u << " (" << w << ")" << endl;

			result[u] = w;
			for (size_t i = 0; i < adj[u].size(); i++) {
				edge e = adj[u][i];
				int v = e.to;
				if ((nodes.count(v) != 0) && (nodes[v] > (nodes[u] + e.w))) {
					nodes[v] = nodes[u] + e.w;
					//cout << "Relaxing: " << v << " (" << nodes[v] << ")" << endl;
				}
			}

			nodes.erase(it);
		}

		for (int i = 0; i < N; i++)
			if (i != (S -1))
				cout << result[i] << " ";
		cout << endl;
	}

	return 0;
}
