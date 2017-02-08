#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N = 0;
    int M = 0;
    cin >> N >> M;

    vector<int> nodes(N);
    for (int i = 0; i < N; i++)
        nodes[i] = 0;

    vector<pair<int, int> > edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--;
        edges[i].second--;
    }

    for (int i = int(edges.size()) - 1; i >= 0; i--) {
        pair<int, int> e = edges[i];
        nodes[e.first]++;
        nodes[e.second] += nodes[e.first];
    }

    int cuts = 0;
    for (int i = 1; i < N; i++) {
        if ((nodes[i] % 2) == 0)
            cuts++;
    }

    cout << cuts << endl;

    return 0;
}
