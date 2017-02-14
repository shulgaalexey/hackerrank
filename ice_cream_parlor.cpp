#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*class IceCream {

  public:
  int flavor;
  int index;

  IceCream(int flavor, int index) {

  }
  };

  int binarySearch(int first, int last, vector<IceCream> arr, int search) {

  }*/

int main() {
	int T;
	int N, M;
	cin >> T;
	for(int test = 0; test < T; test++) {
		cin >> M >> N;

		map<int, vector<int> *> m; // first - cost, second - id
		for (int i = 1; i <= N; i++) {
			int c = 0;
			cin >> c;
			if (!m.count(c))
				m[c] = new vector<int>();
			m[c]->push_back(i);

		}

		int id1 = -1;
		int id2 = -1;
		for (map<int, vector<int> *>::iterator it = m.begin(); it != m.end(); ++it) {
			if (m.count(M - it->first)) {
				if ((M - it->first) == it->first) {
					vector<int> *v = it->second;
					id1 = (*v)[0];
					id2 = (*v)[1];
				} else {
					vector<int> *v1 = m[M - it->first];
					vector<int> *v2 = m[it->first];
					id1 = (*v1)[0];
					id2 = (*v2)[0];
				}
				break;
			}
		}
		if (id1 > id2) {
			int tmp = id1;
			id1 = id2;
			id2 = tmp;
		}

		cout << id1 << " " << id2 << endl;

		for (map<int, vector<int> *>::iterator it = m.begin(); it != m.end(); ++it) {
			vector<int> *v = it->second;
			delete v;
		}

		/*vector<IceCream> arr;
		  arr.reserve(n);

		  for (int i = 0; i < n; i++) {
		  int cost;
		  cin >> cost;
		  arr.push_back(IceCream(cost, i + 1));
		  }

		  sort(arr.begin(), arr.end(), compare);
		  int firstIndex = 100000, secondIndex = 100000;
		  for(int i = 0; i < n - 1 ; i++) {
		  int search = m - arr[i].flavor;
		  if(search >= arr[i].flavor) {
		  int index = binarySearch( i + 1, n - 1, arr, search);
		  if( index != -1 ) {
		  cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
		  break;

		  }
		  }
		  }*/

	}

}


