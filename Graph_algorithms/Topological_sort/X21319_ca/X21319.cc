//El meu plantejament funciona, pero dona time limit al jutge :(

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> INP(0);
vector<string> OUT(0);

void topological_sort(unordered_map<string,pair<int,int>>& pred, const unordered_map<string, vector<string>>& M, int valid) {
	unordered_map<string,vector<string>>::const_iterator it;
	while (valid != pred.size()) {
		it = M.begin();
		while (it != M.end() and valid != pred.size()) {
			if (it->second.size() != 0 and (pred[it->first]).first == 0) {
				if (it->second[0] == "A" and pred[it->second[1]].first == 1 and pred[it->second[2]].first == 1) {
					pred[it->first].second = (pred[it->second[1]].second and pred[it->second[2]].second);		
					pred[it->first].first = 1;
					++valid;
				}
				else if (it->second[0] == "O" and pred[it->second[1]].first and pred[it->second[2]].first) {
					pred[it->first].second = pred[it->second[1]].second or pred[it->second[2]].second;		
					pred[it->first].first = 1;
					++valid;
				}
				else if (it->second[0] == "N" and pred[it->second[1]].first) {
					pred[it->first].second = 1 - pred[it->second[1]].second;		
					pred[it->first].first = 1;
					++valid;
				}
			}
			++it;
		}
	}
	unordered_map<string,pair<int,int>>::iterator it2 = pred.begin();
	while (it2 != pred.end()) {
		it2->second.first = 0;
		++it2;
	}
}

int main() {
	unordered_map<string, vector<string>> M;
	unordered_map<string,pair<int,int>> pred_logical_values;
	string p;
	cin >> p;
	while (cin >> p and p != "END") {
		M.insert(make_pair(p,vector<string>(0)));			
		pred_logical_values.insert(make_pair(p, make_pair(0,0)));
		OUT.push_back(p);
	}
	cin >> p;
	while (cin >> p and p != "END") {
		M.insert(make_pair(p, vector<string>(0)));
		pred_logical_values.insert(make_pair(p,make_pair(1,0)));
		INP.push_back(p);
	}
	while (cin >> p and p != "END") {
		if (p == "AND") {
			string p1, p2, p3;
			cin >> p1 >> p2 >> p3;
			if (M.find(p1) == M.end()) {
				M.insert(make_pair(p1, vector<string>(0)));
				pred_logical_values.insert(make_pair(p1,make_pair(0,0)));
			}
			M[p1].push_back("A");
			M[p1].push_back(p2);
			M[p1].push_back(p3);
		}
		else if (p == "NOT") {
			string p1, p2;
			cin >> p1 >> p2;
			if (M.find(p1) == M.end()) {
				M.insert(make_pair(p1, vector<string>(0)));
				pred_logical_values.insert(make_pair(p1,make_pair(0,0)));
			}
			M[p1].push_back("N");
			M[p1].push_back(p2);
		}
		else if (p == "OR") {
			string p1, p2, p3;
			cin >> p1 >> p2 >> p3;
			if (M.find(p1) == M.end()) {
				M.insert(make_pair(p1, vector<string>(0)));
				pred_logical_values.insert(make_pair(p1,make_pair(0,0)));
			}
			M[p1].push_back("O");
			M[p1].push_back(p2);
			M[p1].push_back(p3);
		}
	}
	char input;
	while (cin >> input) {
		pred_logical_values[INP[0]].second = (input == 'T' ? 1 : 0);
		pred_logical_values[INP[0]].first = 1;
		for (int i = 1; i < INP.size(); ++i) {
			cin >> input;
			pred_logical_values[INP[i]].second = (input == 'T' ? 1 : 0);
			pred_logical_values[INP[i]].first = 1;
		}
		
		int valid = INP.size();

		topological_sort(pred_logical_values, M, valid);
		
		cout << (pred_logical_values[OUT[0]].second == 0 ? 'F' : 'T'); 
		for (int i = 1; i < OUT.size(); ++i) {
			cout << ' ';
			cout << (pred_logical_values[OUT[i]].second == 0 ? 'F' : 'T');
		}
		cout << endl;
	}
}
