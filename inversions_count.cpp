#include <iostream>
using namespace std;

long long merge(int *a, int p, int r)
{
	int q = (p + r) / 2;
	int *buf = new int[r - p + 1];
	int cur = 0;
	int i = p;
	int j = q + 1;
	long long swaps = 0;
	while ((i <= q) && (j <= r)) {
		if (a[i] > a[j]) {
			buf[cur++] = a[j++];
			swaps += q - i + 1;
		} else {
			buf[cur++] = a[i++];
		}
	}

	while (i <= q)
		buf[cur++] = a[i++];

	while (j <= r)
		buf[cur++] = a[j++];

	for (int i = 0; i < (r - p + 1); i++)
		a[p + i] = buf[i];

	delete [] buf;

	return swaps;
}

long long merge_sort(int *a, int p, int r)
{
	if (p == r)
		return 0;
	int q = (p + r) / 2;
	long long swaps = 0;
	swaps += merge_sort(a, p, q);
	swaps += merge_sort(a, q + 1, r);
	swaps += merge(a, p, r);
	return swaps;
}

int main(void)
{
	int D = 0;
	cin >> D;
	//D = 1;

	for (int d = 0; d < D; d++) {
		int N = 0;
		cin >> N;
		//N = 5;
		//int input[] = {2, 1, 3, 1, 2};
		int *a = new int[N];
		for (int i = 0; i < N; i++)
			cin >> a[i];
			//a[i] = input[i];

		long long swaps = merge_sort(a, 0, N - 1);

		cout << swaps << endl;

		delete [] a;
	}
}
