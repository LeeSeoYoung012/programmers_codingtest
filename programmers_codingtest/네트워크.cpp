#include <string>
#include <vector>
#include <cstring>

using namespace std;
int check[201];

//걸린 시간: 25분

void dfs(vector<vector<int>>&v, int now) {

	for (int i = 0; i<v[now].size(); i++) {
		if (check[v[now][i]] == 0) {
			check[v[now][i]] = 1;
			dfs(v, v[now][i]);

		}
	}

	return;


}


int solution(int n, vector<vector<int>> computers) {

	int answer = 0;

	memset(check, 0, sizeof(check));
	vector<vector<int>>v(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i<computers.size(); i++) {
		for (int j = 0; j<computers.size(); j++) {
			if (i != j && computers[i][j] == 1) {
				v[i + 1].push_back(j + 1);
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			dfs(v, i);
			answer++;
		}
	}


	return answer;
}