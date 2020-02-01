#include <bits/stdc++.h>
using namespace std;

int N, K, M, tmp;
vector<int> city[100001], hypertube[1000];
bool visit[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> K >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> tmp;
			city[tmp].push_back(i);
			hypertube[i].push_back(tmp);
		}
	}

	queue<int> q;
	q.push(1);
	visit[1] = true;

	int cnt = 0;
	while (!q.empty()) {
		++cnt;
		int siz = q.size();
		while (siz--) {
			int t = q.front();
			q.pop();
			for (auto i : city[t]) {
				for (auto j : hypertube[i]) {
					if (!visit[j]) {
						if (j == N) {
							cout << cnt + 1 << "\n";
							return 0;
						}
						visit[j] = true;
						q.push(j);
					}
				}
			}
		}
	}
	cout << "-1\n";
}