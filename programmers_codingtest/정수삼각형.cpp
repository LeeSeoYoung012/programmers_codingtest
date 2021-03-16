#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> triangle) {
	int answer = 0;
	int dp[501][501];

	memset(dp, 0, sizeof(dp));

	int n = triangle.size();
	dp[0][0] = triangle[0][0];
	dp[1][0] = dp[0][0] + triangle[1][0];
	dp[1][1] = dp[0][0] + triangle[1][1];

	for (int i = 2; i<n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j - 1 >= 0) {
				dp[i][j] = triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
			else {
				dp[i][j] = triangle[i][j] + dp[i - 1][j];
			}

		}
	}

	for (int i = 0; i<n; i++) {
		answer = max(answer, dp[n - 1][i]);
	}

	return answer;
}