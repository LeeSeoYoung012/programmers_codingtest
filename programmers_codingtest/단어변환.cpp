#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <algorithm>


using namespace std;

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	queue<pair<int, string> >q;
	vector<int>check(words.size(), 51);
	q.push(make_pair(-1, begin));
	while (!q.empty()) {
		int idx = q.front().first;
		string str = q.front().second;
		q.pop();
		//   cout<<str<<endl;
		//   cout<<check[idx]<<endl;
		if (str == target) { answer = check[idx]; break; }
		for (int i = 0; i<words.size(); i++) {
			int count = 0;
			if (str.find(words[i]) != string::npos) {
				count++;
			}
			if (count == 2) {
				if (idx == -1) {
					check[i] = 1;
				}
				else {
					if (check[i]>check[idx] + 1) {
						cout << check[i] << endl;
						check[i] = check[idx] + 1;
						q.push(make_pair(i, words[i]));
					}
				}
			}
		}
	}
	return answer;
}