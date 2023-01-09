#include <iostream>
using namespace std;

void bt(string& sol, int n, int c, int idx, int x, int y, int z) {
	if (idx == n) cout << sol << endl;
	else {
		if (x < c) {sol[idx] = 'x'; bt(sol,n,c,idx+1,x+1,0,0);}
		if (y < c) {sol[idx] = 'y'; bt(sol,n,c,idx+1,0,y+1,0);}
		if (z < c) {sol[idx] = 'z'; bt(sol,n,c,idx+1,0,0,z+1);}
	}
}

int main() {
	int n, c;
	while (cin >> n >> c) {
		string str(n, 'x');
		bt(str, n, c, 0, 0, 0, 0);
		cout << "--------------------" << endl;
	}
}
