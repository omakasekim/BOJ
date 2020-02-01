#include <bits/stdc++.h>
using namespace std;

int N, L, R, X, ans, A[15];
bool chk[15];

void dfs(int now) {
	if (now == N) {
		int minv = 0x7fffffff;
		int maxv = -1;
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (chk[i]) {
				++cnt;
				minv = min(minv, A[i]);
				maxv = max(maxv, A[i]);
				sum += A[i];
			}
		}
		if (cnt > 1 && sum >= L && sum <= R && maxv - minv >= X) ++ans;
		return;
	}
	chk[now] = true;
	dfs(now + 1);
	chk[now] = false;
	dfs(now + 1);
}

int main()
{
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) cin >> A[i];
	dfs(0);
	cout << ans << "\n";
}