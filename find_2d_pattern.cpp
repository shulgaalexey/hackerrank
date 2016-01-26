#include <iostream>
#include <string>
using namespace std;


bool solution(char *G, const int R, const int C,
	      char *P, const int r, const int c) {

	for(int i = 0; i <= (R -r); i ++) {
		for(int j = 0; j <= (C - c); j ++) {

			// Is it a top-left item of the pattern?
			if(G[i * C + j] != P[0])
				continue;

			// Check if all elements of the pattern are there
			bool fail = false;
			for(int row = 0; row < r; row ++) {
				for(int col = 0; col < c; col ++) {
					if(G[(i+row) * C + j + col] !=
					   P[row * c + col]) {
						fail = true;
						break;
					}
				}
				if(fail)
					break;
			}

			// While pattern is found
			if(!fail)
				return true;

		}
	}
	return false;
}

int main(){
	int t = 0;
	cin >> t;
	for(int a0 = 0; a0 < t; a0++){

		int R = 0;
		int C = 0;
		cin >> R >> C;
		char *G = new char [R * C];
		for(int i = 0; i < R; i++){
			string str;
			cin >> str;
			for(int j = 0; j < C; j ++)
				G[i * C + j] = str[j];
		}
		int r = 0;
		int c = 0;
		cin >> r >> c;
		char *P = new char [r * c];
		for(int i = 0; i < r; i++){
			string str;
			cin >> str;
			for(int j = 0; j < c; j ++)
				P[i * c + j] = str[j];
		}

		// Find a 2D pattern
		if(solution(G, R, C, P, r, c))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		delete [] G;
		delete [] P;
	}
	return 0;
}
