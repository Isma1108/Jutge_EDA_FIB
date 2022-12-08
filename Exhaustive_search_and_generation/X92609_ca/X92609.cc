#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector<bool> VB;
int x, n;

int backtracking(const VI& m, int idx, int suma) {
	if (suma == x) return 1;
	else if (idx < n and suma < x) {
		int total = 0;
		total += backtracking(m, idx + 1, suma + m[idx]);
		total += backtracking(m, idx + 1, suma + 2*m[idx]);
		total += backtracking(m, idx + 1, suma);
		return total;
	}
	return 0;
}

int main() {
	while (cin >> x >> n) {
		VI m(n);
		for (int i = 0; i < n; ++i) cin >> m[i];
		cout << backtracking(m, 0, 0) << endl;
	}
}

