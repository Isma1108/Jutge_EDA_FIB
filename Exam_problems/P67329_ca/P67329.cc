#include <iostream>
#include <vector>
using namespace std;

void adn(int idx, int lim, string& s) {
	if (idx == lim) cout << s << endl;
	else {
		s[idx] = 'A'; adn(idx+1, lim, s);
		s[idx] = 'C'; adn(idx+1, lim, s);
		s[idx] = 'G'; adn(idx+1, lim, s);
		s[idx] = 'T'; adn(idx+1, lim, s);
	}
}

int main() {
	int n;
	cin >> n;
	string s(n,'X');
	adn(0, n, s);
}
