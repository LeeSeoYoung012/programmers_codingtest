#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;


int solution(int n) {
	int answer = 0;
	int arr[60005];

	arr[0] = 0; // 가로의 길이가 i 일때 채우는 방법의 수 : arr[i]
	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000007;
	}

	answer = arr[n];
	return answer;
}