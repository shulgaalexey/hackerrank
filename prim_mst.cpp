#include <iostream>
#include <vector>
#include <map>
using namespace std;

static const int INF = 1000000;

int main(void)
{
	int N, M;
	cin >> N >> M;
	map<int, int> V;
	for (int i = 0; i < N; i++)
		V[i] = INF;

	vector<vector<pair<int, int> > > adj(N);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back(pair<int, int>(v - 1, w));
		adj[v - 1].push_back(pair<int, int>(u - 1, w));
	}

	int S = 0;
	cin >> S;
	V[S - 1] = 0;

	int length = 0;
	while (!V.empty()) {
		map<int, int>::iterator it, min_it;
		it = V.begin();
		min_it = V.begin();
		for (; it != V.end(); ++it)
			if (it->second < min_it->second)
				min_it = it;

		int v = min_it->first;
		int w = min_it->second;

		for (size_t i = 0; i < adj[v].size(); i++) {
			pair<int, int> p = adj[v][i];
			int u = p.first;
			int uw = p.second;
			if ((V.count(u) != 0) && (V[u] > uw))
				V[u] = uw;
		}

		length += w;
		V.erase(min_it);
	}

	cout << length << endl;
	return 0;
}
