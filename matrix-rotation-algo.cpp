#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct coords {
	int x;
	int y;
};

int coords2idx(const coords &c, const int M, const int N) {
	return (c.y * N + c.x);
}

void solution(vector<int> &a, const int M, const int N, const int R) {
	// Analyze particular cases
	if((M == 2) && (N == 2)) { // Matrix 2x2
		vector<int> d(a.size());
		d[0] = a[0];
		d[1] = a[1];
		d[2] = a[3];
		d[3] = a[2];
        int R1 = R % 4;
        vector<int> r(a.size());
		for(size_t i = 0; i < a.size(); i ++)
			r[i] = d[(i + R1) % 4];
        a[0] = r[0];
		a[1] = r[1];
		a[2] = r[3];
		a[3] = r[2];
		return;
	}

	int level_M = M;
	int level_N = N;
	const int level_num = M / 2;
	for(int level = 0; level < level_num; level ++) {
		int level_len = 2 * (level_M + level_N - 2);
		int level_R = R % level_len;
		if(level_R == 0)
			continue;
		vector<coords> level_coords;
		coords c = {level, level};

		// First point of level
		level_coords.push_back(c);

		// ceil
		for(int i = 1; i < level_N; i ++) {
			c.x ++;
			level_coords.push_back(c);
		}

		// right wall
		for(int i = 1; i < level_M; i ++) {
			c.y ++;
			level_coords.push_back(c);
		}

		// floor
		for(int i = 1; i < level_N; i ++) {
			c.x --;
			level_coords.push_back(c);
		}

		// left wall
		for(int i = 1; i < (level_M - 1); i ++) {
			c.y --;
			level_coords.push_back(c);
		}

		// Prepare level data
		vector<int> level_data(level_len);
		for(int i = 0; i < level_len; i ++) {
			int idx = coords2idx(level_coords[i], M, N);
			level_data[i] = a[idx];
		}

		// Rotate level
		vector<int> rotated_level_data(level_len);
		for(int i = 0; i < level_len; i ++) {
			int rotated_idx = (i + level_R) % level_len;
			rotated_level_data[i] = level_data[rotated_idx];
		}

		// Apply rotated level
		for(int i = 0; i < level_len; i ++) {
			int idx = coords2idx(level_coords[i], M, N);
			a[idx] = rotated_level_data[i];
		}

		// Goto next level
		level_M -= 2;
		level_N -= 2;

		if((level_M <= 0) || (level_N <= 0))
			break;
	}
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int M = 0;
	int N = 0;
	int R = 0;
	cin >> M >> N >> R;

	vector<int> a(M * N, 0);
	for(int i = 0; i < M; i ++)
		for(int j = 0; j < N; j ++)
			cin >> a[i * N + j];

	solution(a, M, N, R);

	for(int i = 0; i < M; i ++) {
		for(int j = 0; j < N; j ++)
			cout << a[i * N + j] << " ";
		cout << endl;
	}

#if 0
	// Test
	for(int R = 1; R < 10; R ++) {
		for(int M = 2; M <= 300; M ++) {
			for(int N = 2; N <= 300; N ++) {
				vector<int> a(M * N, 13);
				solution(a, M, N, R);
			}
		}
	}
#endif

	return 0;
}
