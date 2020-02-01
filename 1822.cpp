#include <bits/stdc++.h>
using namespace std;

set<int> sa, sb;
int N, M;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		sa.insert(tmp);
	}

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		sb.insert(tmp);
	}

	vector<int> ans;
	for (auto i : sa) {
		if (sb.find(i) == sb.end()) ans.push_back(i);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto i : ans) cout << i << " ";
	cout << "\n";
}