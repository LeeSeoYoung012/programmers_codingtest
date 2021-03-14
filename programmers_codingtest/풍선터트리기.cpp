#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
	int answer = 0;
	int sz = a.size();
	vector<int>leftmin(sz);
	vector<int>rightmin(sz);

	int minnum = 1000000000;
	for (int i = 0; i<a.size(); i++) {
		if (a[i]<minnum) { minnum = a[i]; }
		leftmin[i] = minnum;
	}
	minnum = 1000000000;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[i]<minnum) { minnum = a[i]; }
		rightmin[i] = minnum;
	}

	for (int i = 0; i<a.size(); i++) {
		if (rightmin[i] >= a[i] || leftmin[i] >= a[i]) { answer++; }
	}


	return answer;
}