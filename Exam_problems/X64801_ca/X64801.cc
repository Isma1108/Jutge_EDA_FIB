#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int topological_sort(const VVI& graf, VI& preds) {
	queue<int> q;
	for (int i = 0; i < preds.size(); ++i) {
		if (not preds[i]) q.push(i);
	}
	int visited = 0;
	while (not q.empty()) {
		int v = q.front();
		++visited;
		q.pop();
		for (auto j : graf[v]) {
			--preds[j];
			if (not preds[j]) q.push(j);
		}
	}
	return visited;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		VVI graf(n, VI(0));
		VI preds(n, 0);

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			graf[u].push_back(v);
			preds[v] = preds[v] + 1;
		}
		int v = topological_sort(graf, preds);
		cout << (v == n ? "no" : "yes") << endl;
	}
}
