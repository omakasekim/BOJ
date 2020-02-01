#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
vector<int> graph[20001];
int visit[20001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) visit[i] = 0x7fffffff;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	queue<int> q;
	visit[1] = 0;
	q.push(1);
	
	while (!q.empty()) {
		int t = q.front();
		q.pop();

		for (auto i : graph[t]) {
			if (visit[i] == 0x7fffffff) {
				visit[i] = visit[t] + 1;
				q.push(i);
			}
		}
	}
	int tmax = 0;
	int ti = -1;
	int cnt = 0;
	for (int i = 1; i <= N; i++) tmax = max(tmax, visit[i]);

	for (int i = N; i > 0; i--) {
		if (tmax == visit[i]) {
			++cnt;
			ti = i;
		}
	}

	cout << ti << " " << visit[ti] << " " << cnt << "\n";
}