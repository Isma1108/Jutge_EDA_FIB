#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string s; //Global var, needed to define the order in a comp function

struct comp {
	bool operator()(string& a, string& b) {
		string s2 = s.substr(0,a.size());
		if (a.size() != b.size()) return a.size() > b.size();
		if (a == b) return true;
		if (a == s2) return false;
		if (b == s2) return true;
		if (a < b) return (a < s2 and s2 < b);
		else return (a > s2 and s2 > b);
		return true;
	}
};


int main() {
	while (cin >> s) {
		char op;
		string supp;
		priority_queue<string,vector<string>,comp> wait_list;
		int tickets = 0;
		while (cin >> op and op != 'E') {
			if (op == 'S') {
				cin >> supp;
				wait_list.push(supp);	
			}
			else ++tickets;
			while (not wait_list.empty() and tickets > 0) {
				cout << wait_list.top() << endl;
				--tickets;
				wait_list.pop();
			}
		}
		cout << tickets << " ticket(s) left" << endl;
		cout << wait_list.size() << " supporter(s) with no ticket" << endl << endl;
	}
}
