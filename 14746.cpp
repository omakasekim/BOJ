#include <bits/stdc++.h>
using namespace std;

vector<int> arr[2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int N, M, C1, C2, tmp;
	cin >> N >> M >> C1 >> C2;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		arr[0].push_back(tmp);
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		arr[1].push_back(tmp);
	}

	sort(arr[0].begin(), arr[0].end());
	sort(arr[1].begin(), arr[1].end());

	int idx, minv, cnt;
	idx = cnt = 0;
	minv = 0x7fffffff;

	for (int i = 0; i < N; i++) {
		int locmin = 0x7fffffff;
		int loccnt = 1;
		while (idx < M && abs(arr[0][i] - arr[1][idx]) <= locmin) {
			if (abs(arr[0][i] - arr[1][idx]) == locmin) {
				int dumidx = idx;
				while (dumidx < M && abs(arr[0][i] - arr[1][dumidx]) == locmin) {
					++loccnt;
					++dumidx;
				}
				break;
			}
			locmin = abs(arr[0][i] - arr[1][idx]);
			++idx;
		}
		if (minv > locmin) {
			minv = locmin;
			cnt = loccnt;
		}
		else if (minv == locmin) cnt += loccnt;
	}

	cout << abs(C1 - C2) + minv << " " << cnt << "\n";
}