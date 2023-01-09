#include <iostream>
#include <vector>
using namespace std;

void bt(string& s, int idx, int n, int height) {
	if (idx == n) cout << s << endl;
	else {
		if (height > 0) {
			s[idx] = 'd'; 
			bt(s, idx+1, n, height-1);
		}
		s[idx] = 'h'; bt(s, idx+1, n, height);
		s[idx] = 'u'; bt(s, idx+1, n, height+1);
	}
}

int main() {
	int n;
	cin >> n;
	string s(n, 'h');
	bt(s, 0, n, 0);
}
