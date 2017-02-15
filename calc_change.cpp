#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n = 0, m = 0;
	cin >> n >> m;

	int *C = new int[m];
	for (int i = 0; i < m; i++)
		cin >> C[i];

	long *DP = new long[n + 1];
	for (int i = 0; i <= n; i++)
		DP[i] = 0;
	DP[0] = 1;

	for (int i = 0; i < m; i++) {
		const int coin = C[i];
		for (int j = coin; j <= n; j++)
			DP[j] += DP[j - coin];
	}

	cout << DP[n] << endl;

	delete [] C;
	delete [] DP;

	return 0;
}

