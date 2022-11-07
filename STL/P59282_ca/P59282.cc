#include <iostream>
#include <queue>
using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(4);
	priority_queue<int, vector<int>, greater<int>> pq;
	double average = 0.0;
	int max, num;

	string op;
	while (cin >> op) {
		if (op == "number") {
			cin >> num;
			if (pq.empty()) max = num;
			else if (num > max) max = num;
			pq.push(num);
			average += num;
		}
		else if (not pq.empty()) {
			average -= pq.top();
			pq.pop();
		}
		if (pq.empty()) cout << "no elements" << endl;
		else cout << "minimum: " << pq.top() << ", maximum: " << max << ", average: " << average/pq.size() << endl;
	}
}
