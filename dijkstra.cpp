#include <iostream>
#include <vector>
#include <list>
using namespace std;

static const int INF = 2 * 100000;

struct node;

struct edge {
	node *to;
	int w;
	edge(node *t, int _w) : to(t), w(_w) {}
};

struct node {
	vector<edge *> adj;
	int d;
	node() : d(INF) {}
};

void relax(node *n, edge *e)
{
	if (e->to->d > (n->d + e->w))
		e->to->d = n->d + e->w;
}

/*
node *extract_min(vector<node *> &Q)
{
	size_t min_idx = 0;
	for (size_t i = 1; i < Q.size(); i++)
		if (Q[i]->d < Q[min_idx]->d)
			min_idx = i;
	node *n = Q[min_idx];
	Q.erase(Q.begin() + min_idx);
	return n;
}
*/

node *extract_min(list<node *> &Q)
{
	node *min_node = Q.front();
	list<node *>::iterator min_it = Q.begin();
	list<node *>::iterator it = Q.begin();
	++it;
	for (; it != Q.end(); ++it) {
		node *n = *it;
		if (n->d < min_node->d) {
			min_node = n;
			min_it = it;
		}
	}
	Q.erase(min_it);
	return min_node;
}

void dijkstra(const vector<node *> &G, node *s)
{
	s->d = 0;

	//vector<node *> Q = G;
	list<node *> Q;
	for (size_t i = 0; i < G.size(); i++)
		Q.push_back(G[i]);

	while (!Q.empty()) {
		node *n = extract_min(Q);
		for (size_t i = 0; i < n->adj.size(); i++)
			relax(n, n->adj[i]);
	}
}

void add_edge(const vector<node *> &G, int from, int to, int w)
{
	G[from]->adj.push_back(new edge(G[to], w));
}

int main(void)
{
	int T = 0;
	cin >> T;
	for (int test = 0; test < T; test++) {
		int N = 0, M = 0;
		cin >> N;
		cin >> M;
		vector<node *> G(N);
		for (int n = 0; n < N; n++)
			G[n] = new node();
		vector<edge *> E(M);
		for (int e = 0; e < M; e++) {
			int x = 0, y = 0, r = 0;
			cin >> x;
			cin >> y;
			cin >> r;
            if (x == y)
                continue;
			add_edge(G, x - 1, y - 1, r);
			add_edge(G, y - 1, x - 1, r);
		}
		int s = 0;
		cin >> s;

		dijkstra(G, G[s - 1]);

		for (size_t i = 0; i < G.size(); i++) {
			if (int(i + 1) == s)
				continue;
			if (G[i]->d < INF)
				cout << G[i]->d << " ";
			else
				cout << "-1 ";
		}
		cout << endl;

		for (size_t i = 0; i < G.size(); i++) {
			for (size_t j = 0; j < G[i]->adj.size(); j++)
				delete G[i]->adj[j];
			delete G[i];
		}
	}
	return 0;
}

