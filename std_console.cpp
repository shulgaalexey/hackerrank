#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	double f = .0;
	cin >> f;

	string a;
	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin >> ws, a);
	getline(std::cin, a);

	cout << n << endl;
	cout << fixed << setprecision(1) << f << endl;

	cout << a << endl;
}
