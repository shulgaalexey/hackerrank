#include <iostream>
#include <vector>
using namespace std;

#define GET_ADJ(A, i, j) ((A[i] >> j) & 1)

typedef unsigned long long int64;

void generate_queries(const vector<int64> &d, vector<vector<int64> *> &queries)
{
	const int query_count = 1 << d.size();
	for (int i = 0; i < query_count; i++) {
		int code = i;
		vector<int64> *v = new vector<int64>();
		int idx = 0;
		while(code) {
			if (code & 1)
				v->push_back(d[idx]);
			idx++;
			code >>= 1;
		}
		queries.push_back(v);
	}
}

void release_queries(vector<vector<int64> *> &queries)
{
	for (size_t i = 0; i < queries.size(); i++)
		delete queries[i];
}

void extract_nodes(int64 d, vector<int> &nodes)
{
	int idx = 0;
	while (d) {
		if (d & 1)
			nodes.push_back(idx);
		idx++;
		d >>= 1;
	}
}

int calc_query(const vector<int64> &d)
{
	//----DBG-------------
	/*cout << "Processing query: {";
	for (size_t i = 0; i < d.size(); i++)
		cout << d[i] << " ";
	cout << "} ";*/
	//----DBG-------------

	int64 A[64] = {0};

	// Create Adjacency matrix
	for (size_t k = 0; k < d.size(); k++) {
		vector<int> nodes;
		extract_nodes(d[k], nodes);
		for (size_t i = 0; i < nodes.size(); i++) {
			//cout << endl << "   node: " << nodes[i];
			for (size_t j = i + 1; j < nodes.size(); j++) {
				//cout << "     edge:" << nodes[i] << "---" << nodes[j] << endl;
				A[nodes[i]] |= 1 << nodes[j];
			}
		}
		//cout << endl;
	}

	//----DBG-------------
	/*cout << endl << "Adj Matrix:" << endl;
	for (int i = 0; i < 64; i++)
		cout << A[i] << endl;*/
	//----DBG-------------

	// Kruscal
	int node_sets[64] = {0};
	for (int i = 0; i < 64; i++)
		node_sets[i] = i;

	for (int i = 0; i < 64; i++) {
		for (int j = i + 1; j < 64; j++) {
			if (GET_ADJ(A, i, j)) {
				if (node_sets[i] != node_sets[j]) {
					//cout << "   UNITE: " << i << " & " << j << endl;
					node_sets[j] = node_sets[i];
				}
			}
		}
	}

	//----DBG-------------
	/*cout << endl;
	for (int i = 0; i < 64; i++)
		cout << "   ___  node_sets of .. is: " << i << " .. " << node_sets[i] << endl;*/
	//----DBG-------------


	int count = 0;
	for (int i = 0; i < 64; i++) {
		//cout << "   ___  node_sets: " << i << " .. " << node_sets[i];
		if (node_sets[i] == i)
			count ++;
		//else
		//	cout << "   !!!";
		//cout << endl;
	}


	//cout << "...count: " << count << endl;
	return count;
}

int calc_queries(const vector<vector<int64> *> &queries)
{
	int total = 0;
	for (size_t q = 0; q < queries.size(); q++)
		total += calc_query(*queries[q]);
	return total;
}

int main(void)
{
	int n = 3;
	cin >> n;

	//int input[] = {2, 5, 9};
	vector<int64> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		//d[i] = input[i];
	}

	vector<vector<int64> *> queries;
	generate_queries(d, queries);

	//----DBG-------------
	/*for (size_t i = 0; i < queries.size(); i++) {
		vector<int64> *v = queries[i];
		cout << "{";
		for (size_t j = 0; j < v->size(); j++)
			cout << (*v)[j] << " ";
		cout << "}" << endl;
	}*/
	//----DBG-------------


	const int ret = calc_queries(queries);
	cout << ret << endl;

	release_queries(queries);
	return 0;
}
