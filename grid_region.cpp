#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;

	vector<vector<int> > G(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> G[i][j];
	}

	int max_region_size = 0;
	int region_index = 1;

	vector<pair<int, int> > updater(8);
	updater[0] = pair<int, int>(-1, -1);
	updater[1] = pair<int, int>(-1, 0);
	updater[2] = pair<int, int>(-1, 1);
	updater[3] = pair<int, int>(0, 1);
	updater[4] = pair<int, int>(1, 1);
	updater[5] = pair<int, int>(1, 0);
	updater[6] = pair<int, int>(1, -1);
	updater[7] = pair<int, int>(0, -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 1) {
				region_index++;
				int region_size = 0;
				queue<pair<int, int> > q;
				q.push(pair<int, int>(i, j));
				G[i][j] = region_index;
				while (!q.empty()) {
					region_size++;
					pair<int, int> c = q.front();
					q.pop();
					for (int k = 0; k < 8; k++) {
						pair<int, int> adj = c;
						adj.first += updater[k].first;
						adj.second += updater[k].second;
						if ((adj.first >= 0) && (adj.first < n)
								&& (adj.second >= 0) && (adj.second < m)
								&& (G[adj.first][adj.second] == 1)) {
							q.push(adj);
							G[adj.first][adj.second] = region_index;
						}
					}
				}
				if (region_size > max_region_size)
					max_region_size = region_size;
			}
		}
	}

	cout << max_region_size << endl;
	return 0;
}
