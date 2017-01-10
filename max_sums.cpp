#include <iostream>
using namespace std;

void solve(int *a, const int N, int *cont, int *non_cont) {
	if (N < 1) {
		*cont = 0;
		*non_cont = 0;
	} else if (N == 1) {
		*cont = a[0];
		*non_cont = a[0];
	} else {
		int max_sum = a[0];
		int cur_sum = 0;
		int positive_sum = 0;
		for (int i = 0; i < N; i ++) {
			cur_sum += a[i];
			cur_sum = max(0, cur_sum);
			max_sum = max(max_sum, cur_sum);

			if (a[i] > 0)
				positive_sum += a[i];
		}
        
        if (!positive_sum) {}
            int global_max = a[0];
            for (int i = 1; i < N; i++)
                if (a[i] > global_max)
                    global_max = a[i];
            max_sum = global_max;
            positive_sum = global_max;
        }
            
		*cont = max_sum;
		*non_cont = positive_sum;
	}
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

#if 0
	{ // 1.1
		int a[] = {1, 2, 3, 4};
		const int N = int(sizeof(a) / sizeof(a[0]));
		int cont = 0;
		int non_cont = 0;
		solve(a, N, &cont, &non_cont);
		cout << cont << " " << non_cont << endl;
	}

	{ // 1.2
		int a[] = {2, -1, 2, 3, 4, -5};
		const int N = int(sizeof(a) / sizeof(a[0]));
		int cont = 0;
		int non_cont = 0;
		solve(a, N, &cont, &non_cont);
		cout << cont << " " << non_cont << endl;
	}
#endif


	int T = 0;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N = 0;
		cin >> N;
		int *a = new int[N];
		for (int i = 0; i < N; i ++)
			cin >> a[i];

		int cont = 0;
		int non_cont = 0;
		solve(a, N, &cont, &non_cont);

		cout << cont << " " << non_cont << endl;
		delete [] a;
	}

	return 0;
}
