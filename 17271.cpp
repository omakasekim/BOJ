#include <bits/stdc++.h>
using namespace std;

#define P 1000000007

int N, M, dp[10001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	dp[1] = 1;
	dp[M] = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] += dp[i - 1];
		if (i - M >= 1) dp[i] += dp[i - M];
		dp[i] %= P;
	}
	cout << dp[N] << "\n";
}