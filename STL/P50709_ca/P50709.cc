#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> pq;
	char c;
	int num;
	while (cin >> c) {
		if (c == 'S') {
			cin >> num;
			pq.push(num);
		}
		else if (c == 'A') {
			if (pq.empty()) cout << "error!" << endl;
			else cout << pq.top() << endl;
		}
		else if (c == 'R') {
			if (pq.empty()) cout << "error!" << endl;
			else pq.pop();
		}
		else if (c == 'I') {
			cin >> num;
			if (pq.empty()) cout << "error!" << endl;
			else {
				num += pq.top();
				pq.pop();
				pq.push(num);
			}
		}
		else if (c == 'D') {
			cin >> num;
			if (pq.empty()) cout << "error!" << endl;
			else {
				num = pq.top() - num;
				pq.pop();
				pq.push(num);
			}
		}
	}
}
