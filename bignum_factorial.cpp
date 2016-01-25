#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

typedef unsigned char uchar;

void trace(const vector<uchar> &arr) {
	int len = int(arr.size());
	for(int i = (len - 1); i >= 0; i --)
		cout << int(arr[i]);
	cout << endl;
}

bool equal(const vector<uchar> &a, const vector<uchar> &b) {
	if(a.size() != b.size())
		return false;
	for(size_t i = 0; i < a.size(); i ++)
		if(a[i] != b[i])
			return false;
	return true;
}

vector<uchar> to_array(int n) {
	if(n < 1) {
		vector<uchar> empty(1, 1);
		return empty;
	}

	vector<uchar> res;
	do {
		res.push_back(n % 10);
		n /= 10;
	} while(n);
	return res;
}

vector<uchar> sum(const vector<uchar> &a, const vector<uchar> &b) {
	size_t len = max(a.size(), b.size());
	vector<uchar> res(len, 0);
	int e = 0;
	for(size_t i = 0; i < res.size(); i ++) {
		if(i < a.size())
			res[i] += a[i];
		if(i < b.size())
			res[i] += b[i];
		res[i] += e;
		e = res[i] / 10;
		res[i] %= 10;
	}
	if(e)
		res.push_back(e);
	return res;
}

void shift_left(vector<uchar> &a, int shift) {
	for(int i = 0; i < shift; i ++)
		a.insert(a.begin(), 0);
}

bool zero(const vector<uchar> &a) {
	for(size_t i = 0; i < a.size(); i ++)
		if(a[i])
			return false;
	return true;
}

vector<uchar> mul(const vector<uchar> &a, const vector<uchar> &b) {
	vector<uchar> res;

	if(zero(a) || zero(b)) {
		res.push_back(0);
		return res;
	}

	int shift = 0;
	for(size_t i = 0; i < b.size(); i ++) {
		vector<uchar> c;
		uchar e = 0;
		for(size_t j = 0; j < a.size(); j ++) {
			uchar d = b[i] * a[j] + e;
			c.push_back(d % 10);
			e = d / 10;
		}
		if(e)
			c.push_back(e);
		shift_left(c, shift);
		res = sum(res, c);
		shift ++;
	}
	return res;
}

vector<uchar> fact(int n) {
	return (n <= 1)
		? to_array(1)
		: mul(to_array(n), fact(n - 1));
}

int main(void) {
	int n = 0;
	cin >> n;
	//n = 25;
	vector<uchar> f = fact(n);
	trace(f);

#if 0
	srand(time(NULL));

	/* Testing sum function */
	for(int i = 0; i < 1000; i ++) {
		//cout << "test" << i << "..." << endl;
		int a = rand() / 2;
		int b = rand() / 2;
		int c = a + b;
		vector<uchar> arr_c = sum(to_array(a), to_array(b));
		vector<uchar> expected_c = to_array(c);
		if(!equal(arr_c, expected_c)) {
				cout << "ERROR sum: " << a << ", " << b << endl;
				cout << "Expected: " << c << endl;
				cout << "Calculated: ";
				trace(arr_c);
				return 0;
		}
	}
	cout << "Sum OK" << endl;

	/* Testing mul function */
	for(int i = 0; i < 1000; i ++) {
		//cout << "test" << i << "..." << endl;
		int a = sqrt(rand());
		int b = sqrt(rand());
		int c = a * b;
		vector<uchar> arr_c = mul(to_array(a), to_array(b));
		vector<uchar> expected_c = to_array(c);
		if(!equal(arr_c, expected_c)) {
				cout << "ERROR mul: " << a << ", " << b << endl;
				cout << "Expected: " << c << endl;
				cout << "Calculated: ";
				trace(arr_c);
				return 0;
		}
	}
	cout << "Mul OK" << endl;
#endif

	return 0;
}
