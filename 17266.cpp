#include <bits/stdc++.h>
using namespace std;

int N, M, light[100000];
int high, low, mid;
bool chk;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> light[i];

	low = 0;
	high = 100001;
	while (low <= high) {
		chk = true;
		mid = (low + high) / 2;
		int l, r;
		if (light[0] - mid > 0) {
			chk = false;
			goto out;
		}

		l = 0;
		r = light[0] + mid;

		for (int i = 1; i < M; i++) {
			if (r < light[i] - mid) {
				chk = false;
				goto out;
			}
			r = light[i] + mid;
		}

		if (r < N) chk = false;

	out: {}
		if (chk) high = mid - 1;
		else low = mid + 1;
	}

	cout << low << "\n";
}