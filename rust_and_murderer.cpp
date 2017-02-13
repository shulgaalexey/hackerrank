#include <iostream>
#include <vector>
#include <map>
using namespace std;

static const int INF = 100000;

int main(void)
{
	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N = 0, M = 0;
		cin >> N >> M;
		vector<map<int, bool> > adj(N);
		for (int i = 0; i < M; i++) {
			int x = 0, y = 0;
			cin >> x >> y;
			adj[x - 1][y - 1] = true;
			adj[y - 1][x - 1] = true;
		}

		//vector<bool> visited(N);
		vector<int> V(N);
		for (int i = 0; i < N; i++) {
			V[i] = INF;
			//visited[i] = false;
		}

		int S = 0;
		cin >> S;
		V[S - 1] = 0;
		//visited[S - 1] = true;

		map<int, int> q;
		q[S - 1] = V[S - 1];

		map<int, bool> ND; // Not discovered
		for (int i = 0; i < N; i++)
			ND[i] = true;
		ND.erase(S - 1);


		while (!q.empty()) {
			map<int, int>::iterator it = q.begin(), min_it;
			min_it = it;
			for (; it != q.end(); ++it) {
				if (it->second < min_it->second)
					min_it = it;
			}

			//for (int i = 0; i < N; i++) {
			for (map<int, bool>::iterator di = ND.begin(); di != ND.end(); ++ di) {
				const int i = di->first;
				//if ((i == min_it->first) || (visited[i]) || (adj[min_it->first].count(i) != 0))
				if ((i == min_it->first) || (adj[min_it->first].count(i) != 0))
					continue;

				if (V[i] > (min_it->second + 1))
					V[i] = min_it->second + 1;

				q[i] = V[i];
			}

			//visited[min_it->first] = true;
			ND.erase(min_it->first);
			q.erase(min_it);
		}

		for (int i = 0; i < N; i++) {
			if (i != (S - 1))
                if (V[i] < INF)
                    cout << V[i] << " ";
                else
                    cout << "-1 ";
		}
		cout << endl;
	}
	return 0;
}
