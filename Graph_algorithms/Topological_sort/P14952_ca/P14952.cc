#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;

void topological_sort(VI& sol, const vector<VI>& succ, VI& pred) {
	priority_queue<int,vector<int>,greater<int>> Q;
	int n = pred.size();
	for (int i = 0; i < n; ++i) {
		if (pred[i] == 0) Q.push(i);
	}
	while (not Q.empty()) {
		int v = Q.top();
		sol.push_back(v);
		Q.pop();
		for (int j = 0; j < succ[v].size(); ++j) {
			--pred[succ[v][j]];
			if (pred[succ[v][j]] == 0) Q.push(succ[v][j]);
		}
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<VI> succ(n, VI(0));
		VI pred(n, 0);
		for (int i = 0; i < m; ++i) {
			int x, y; 
			cin >> x >> y;
			++pred[y];
			succ[x].push_back(y);
		}
		VI solution;
		topological_sort(solution, succ, pred);
		int n = solution.size();
		if (n == 0) cout << "0" << endl;
		else {
			cout << solution[0];
			for (int i = 1; i < n; ++i) cout << ' ' << solution[i];
			cout << endl;
		}
	}
}
