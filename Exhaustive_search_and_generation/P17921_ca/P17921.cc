#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> t;
vector<bool> c, d1, d2;

int diag1(int i, int j) {return i + j;}
int diag2(int i, int j) {return i - j + n - 1;}

void dibuixa_solucio() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (t[i] == j) cout << 'Q';
			else cout << '.';
		}
		cout << endl;
	}
	cout << endl;
}

void reines(int i) {
	if (n == i) dibuixa_solucio();
	for (int j = 0; j < n; ++j) {
		if (not c[j] and not d1[diag1(i,j)] and not d2[diag2(i,j)]) {
			t[i] = j;
			c[j] = d1[diag1(i,j)] = d2[diag2(i,j)] = true;
			reines(i+1);
			c[j] = d1[diag1(i,j)] = d2[diag2(i,j)] = false;	
		}
	}
}


int main() {
	cin >> n;
	t = vector<int>(n);
	c = vector<bool>(n, false);
	d1 = d2 = vector<bool>(2*n - 1, false); //Hi ha 2*n - 1 diagonals (pel marcatge)
	reines(0);
}
