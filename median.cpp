#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > lower;
priority_queue<int, vector<int>, greater<int> > higher;

void add(int i){
    if(lower.empty())
        lower.push(i);
    else{
        if(lower.size() > higher.size()){
            if(lower.top() > i){
                higher.push(lower.top());
                lower.pop();
                lower.push(i);
            }
            else
                higher.push(i);
        }
        else{
            if(higher.top() >= i)
                lower.push(i);
            else{
                lower.push(higher.top());
                higher.pop();
                higher.push(i);
            }
        }
    }
}

double find(){
    int n = lower.size() + higher.size();
    return (n % 2 == 0) ? (higher.top() + lower.top())/2.0 : (double)(lower.top());

}

int main(void) {
	int N = 0;
	cin >> N;


	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;

        add(a);
        double median10 = 10. * find();

		cout << int(median10 / 10) << "." << int(int(median10) % 10) << endl;
	}

	return 0;
}
