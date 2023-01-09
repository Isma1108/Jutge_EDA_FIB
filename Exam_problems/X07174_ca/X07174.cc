#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;
	
bool ok(const VI& div, int num) {
	for (int i = 0; i < div.size(); ++i) {
		if (num%div[i] == 0) return false;
	}
	return true;
}

void bt(int n, const VI& div, int idx, int total) {
	if (idx == n) cout << total << endl;
	else {
		for (int i = 0; i <= 9; ++i) {
			if (ok(div, total*10 + i)) {
				bt(n, div, idx+1, total*10 + i);
			}
		}
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		VI div(m);
		for (int i = 0; i < m; ++i) cin >> div[i];
		bt(n, div, 0, 0);
		cout << "----------" << endl;
	}
}
