#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	/*const int M = 6;
	const int N = 5;

	vector<pair<int, int> > obs;
	obs.push_back(pair<int, int>(1, 1));
	obs.push_back(pair<int, int>(3, 1));
	obs.push_back(pair<int, int>(4, 2));
	obs.push_back(pair<int, int>(3, 3));*/
	// Result: 9

	const int M = 8;
	const int N = 8;
	vector<pair<int, int> > obs;
	obs.push_back(pair<int, int>(1, 2));
	obs.push_back(pair<int, int>(1, 6));
	obs.push_back(pair<int, int>(2, 4));
	obs.push_back(pair<int, int>(3, 0));
	obs.push_back(pair<int, int>(3, 2));
	obs.push_back(pair<int, int>(3, 5));
	obs.push_back(pair<int, int>(4, 2));
	obs.push_back(pair<int, int>(5, 3));
	obs.push_back(pair<int, int>(5, 4));
	obs.push_back(pair<int, int>(5, 6));
	obs.push_back(pair<int, int>(6, 1));
	obs.push_back(pair<int, int>(6, 5));
	// Result: 27

	vector<vector<int> > G(M);
	for (int i = 0; i < M; i++)
		G[i].resize(N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			G[i][j] = 0;
		}
	}

	for (size_t i = 0; i < obs.size(); i++)
		G[obs[i].first][obs[i].second] = -1;

	// Bottom row all have score 1
	for (int j = N - 1; j >= 0; j--)
		if (G[M - 1][j] != (-1))
			G[M - 1][j] = 1;

	// DP!!!
	for (int i = M - 2; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (G[i][j] != (-1)) {
				int score = 0;
				if (((j + 1) < N) && (G[i][j + 1]!= (-1)))
					score += G[i][j + 1];
				if (G[i + 1][j] != (-1))
					score += G[i + 1][j];
				G[i][j] = score;
			}
		}
	}

	cout << G[0][0] << endl;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (G[i][j] == (-1))
				cout << "# ";
			else
				cout << G[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}
