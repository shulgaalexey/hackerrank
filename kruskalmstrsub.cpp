#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
using namespace std;

struct edge {
	int from;
	int to;
	int w;
	edge(int f, int t, int _w) : from(f), to(t), w(_w) {}
};

bool mysort(edge *a, edge *b)
{
	if (a->w == b->w) {
		return (a->from + a->to + a->w) < (b->from + b->to + b->w);
	} else {
		return a->w < b->w;
	}
}

void copy(int to, int from, vector<list<int> *> &V)
{
	for (list<int>::iterator it = V[from]->begin(); it != V[from]->end(); ++it)
		V[to]->push_back(*it);
    V[from]->clear();
	V[from] = V[to];
}


int mst_kruskal(vector<edge *> &E, int N)
{
	const int M = int(E.size());
	vector<list<int> *> V(N);
    vector<list<int> *> __to_del(N);
	for (int i = 0; i < N; i++) {
		V[i] = new list<int>();
		V[i]->push_back(i);
        __to_del[i] = V[i];
	}

	std::sort(E.begin(), E.end(), mysort);

	int total = 0;
	for (int i = 0; i < M; i++) {
		edge *e = E[i];
		if (V[e->from] != V[e->to]) {
			total += e->w;
			if (V[e->from] > V[e->to])
				copy(e->to, e->from, V);
			else
				copy(e->from, e->to, V);
			if (int(V[e->from]->size()) == N)
				break;
		}
	}


    for (int i = 0; i < N; i++)
        delete __to_del[i];

	return total;
}

int main(void) {
	/*int N = 0, M = 0;
	cin >> N;
	cin >> M;
	vector<edge *> E(M);
	for (int m = 0; m < M; m++) {
		int x = 0, y = 0, r = 0;
		cin >> x;
		cin >> y;
		cin >> r;
		E[m] = new edge(x - 1, y - 1, r);
	}*/

	int N = 7;
	int M = 9;
	int input[] = {
		1, 6, 4,
		1, 3, 2,
		6, 2, 2,
		2, 3, 5,
		3, 4, 7,
		6, 5, 6,
		5, 7, 4,
		5, 4, 3,
		7, 4, 2}; // 19
	vector<edge *> E(M);
	for (int m = 0; m < M; m++) {
		int x = input[m * 3];
		int y = input[m * 3 + 1];
		int r = input[m * 3 + 2];
		E[m] = new edge(x - 1, y - 1, r);
	}

	const int total = mst_kruskal(E, N);
	cout << total << endl;

	for (int m = 0; m < M; m++)
		delete E[m];

	return 0;
}
