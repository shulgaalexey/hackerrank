#include <iostream>
#include <vector>
#include <map>
using namespace std;

static const int INF = 1000000;
static const int NEG_INF = -1000000;

int main(void)
{
	int C = 0;
	cin >> C;
	for (int c = 0; c < C; c++) {
		int N, T_IN, M;
		cin >> N >> T_IN >> M;
		vector<vector<int> > adj(N);
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			adj[u - 1].push_back(v - 1);
			adj[v - 1].push_back(u - 1);
		}

		int TOTAL = NEG_INF;
		//for (int T = 2; T < (N / T_IN); T++) {
		for (int T = 2; T <= T_IN; T++) {

			map<int, int> ranks;
			for (int i = 0; i < N; i++)
				ranks[i] = int(adj[i].size());

			int total = 0;


			while (!ranks.empty()) {
				map<int, int>::iterator it = ranks.begin(), max_it;
				max_it = it;
				for (; it != ranks.end(); ++it)
					if (it->second > max_it->second)
						max_it = it;

				if (max_it->second < T)
					break;

				total += T + 1;
				ranks.erase(max_it);

				int h = max_it->first;
				for (int i = 0; i < T; i++) {
					int v = -1;
					int min_rank = INF;
					for (size_t k = 0; k < adj[h].size(); k++) {
						int ch = adj[h][k];
						if ((ranks.count(ch) != 0) && (ranks[ch] < min_rank) && (ranks[ch] > 0)) {
							min_rank = ranks[ch];
							v = ch;
						}
					}

					if (v < 0) {
						cout << "Foot not found" << endl;
						break;
					}

					for (size_t j = 0; j < adj[v].size(); j++) {
						if (ranks.count(adj[v][j]) != 0)
							ranks[adj[v][j]]--;
					}

					ranks.erase(v);
				}

			}
			//cout << "Subtotal: " << total << endl;
			if (total > TOTAL)
				TOTAL = total;
		}

		cout << TOTAL << endl;

	}
	return 0;
}
