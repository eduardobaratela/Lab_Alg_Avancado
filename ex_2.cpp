#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
using namespace std;


#define maxt 1000+5

int main() {
	int n;
	int num;
	int x;
	cin >> n;
	int c = 1;
	while (n > 0) {
		cout << "Scenario #" << c++ << endl;
		map<int, int> teamMem; 
		for(int i=0;i<n;i++) {
			cin >> num;
			for(int j=0;j<num;j++) {
				cin >> x;
				teamMem[x] = i;
			}
		}
		queue<int> q, main_q[maxt];	                    
		string command;
		vector<int> myprint;
		while (true) {
			cin >> command;
			if (command == "STOP") break;
			else if (command == "DEQUEUE") {
				int team = q.front();
				myprint.push_back(main_q[team].front());
				main_q[team].pop();
				if (main_q[team].empty()) q.pop();
			}
			else {
				cin >> x;
				int team = teamMem.at(x);
				if (main_q[team].empty()) q.push(team);
				main_q[team].push(x);
			}
		}
		int tam = myprint.size();
		for(int m=0;m<tam;m++) {
			cout << myprint[m] << endl;
		}
		cout << endl;
		cin >> n;
	}
	return 0;
}