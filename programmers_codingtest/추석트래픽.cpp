#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int solution(vector<string> lines) {
	int answer = 0;
	string spent;

	vector<double>start;
	vector<double>end;

	map<double, int>m;
	int minspent = 4;
	for (int i = 0; i<lines.size(); i++) {
		string str = lines[i];

		spent = str.substr(24);
		int send = spent.size() - 1;
		spent = spent.substr(0, send); //시간의 's' 빼주기

		double totalseconds = 60 * 60 * stod(time.substr(0, 2)) + 60 * stod(time.substr(3, 2)) + stod(time.substr(6, 2)) + stod(time.substr(9));
		double servertime = stod(spent);

		start.push_back(totalseconds - servertime + 0.001);
		end.push_back(totalseconds);


	}
	int t = 0;
	for (int i = 0; i<start.size(); i++) {
		double s = start[i];
		double e = end[i];
		t = 1;


		for (int j = i + 1; j<start.size(); j++) {
			if (s + 1 >= start[j] || e + 1>start[j]) {
				t++;
			}
		}
		answer = max(answer, t);
	}

	return answer;
}