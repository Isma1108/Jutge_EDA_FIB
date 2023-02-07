#include <iostream>
#include <vector>
using namespace std;

void backtracking(string& sol, int n, int idx, int m, int a) {
	if (idx == n) cout << sol << endl;
	else {
		if (m > 0) {
			sol[idx] = 'b';
			backtracking(sol, n, idx+1, m-1, a+1);
		}
		if (a > 0) {
			sol[idx] = 's';
			backtracking(sol, n, idx+1, m+1, a-1);
		}
	}
}

int main() {
	int n, c;
	cin >> n >> c;
	string str(n, 'b');
	backtracking(str, n, 0, c, 0);
}
