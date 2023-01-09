#include <iostream>
#include <vector>
using namespace std;

const char ALF[9]= {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

void permutacions(string& s, int n, int idx, vector<bool>& used) {
	if (idx == n) cout << s << endl;
	else {
		for (int i = 0; i < n; ++i) {
			if (not used[i] and (idx == 0 or s[idx-1] != ALF[i]-1)) {
				used[i] = true;
				s[idx] = ALF[i];
				permutacions(s, n, idx+1, used);
				used[i] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	string s(n, 'X');
	vector<bool> used(n, false);
	permutacions(s, n, 0, used);
}	
