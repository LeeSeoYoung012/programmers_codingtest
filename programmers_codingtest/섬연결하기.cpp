#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//크루스칼로 풀기 , 걸린시간: 15분

bool cmp(vector<int>a, vector<int>b) {

	return a[2]<b[2];

}

int getparent(vector<int>&parent, int i)
{
	if (i == parent[i]) { return i; }
	return parent[i] = getparent(parent, parent[i]);
}

void makeunion(vector<int>&parent, int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a>b) { parent[a] = b; }
	else { parent[b] = a; }
}

bool unionfind(vector<int>&parent, int a, int b) {
	a = getparent(parent, a);
	b = getparent(parent, b);
	if (a == b) { return true; }
	return false;
}


int solution(int n, vector<vector<int>> costs) {
	int answer = 0;
	sort(costs.begin(), costs.end(), cmp);
	vector<int>parent(n);
	for (int i = 0; i<n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i<costs.size(); i++) {
		int s = costs[i][0];
		int e = costs[i][1];
		if (!unionfind(parent, s, e)) {
			makeunion(parent, s, e);
			answer += costs[i][2];
		}
	}
	return answer;
}