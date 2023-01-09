#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> VS;
typedef vector<bool> VB;
int n;

void print(const VS& sol) {
	for (int i = 0; i < sol.size(); ++i) cout << sol[i];
	cout << endl;
}

void bt(const VS& str, VB& visited, VS& sol, int idx, char last) {
	if (idx == n) print(sol);
	else {
		for (int i = 0; i < n; ++i) {
			if (not visited[i] and (idx == 0 or last != str[i][0])) {
				visited[i] = true;
				sol[idx] = str[i];
				bt(str, visited, sol, idx+1, str[i][str[i].size()-1]);
				visited[i] = false;	
			}
		}	
	}
}

int main() {
	cin >> n;
	VS str(n);
	for (int i = 0; i < n; ++i) cin >> str[i];
	VS solution(n);
	VB visited(n, false);
	bt(str, visited, solution, 0, 'N');
}
