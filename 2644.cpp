#include <bits/stdc++.h>
using namespace std;
int N, M, a, b, x, y;
vector<int> graph[101];
int visit[101];

int main()
{
	cin >> N;
	cin >> a >> b;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	for (int i = 0; i < 101; i++) visit[i] = 0x7fffffff;
	queue<int> q;
	q.push(a);
	visit[a] = 0;

	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t == b) {
			cout << visit[b] << "\n";
			return 0;
		}

		for (auto i : graph[t]) {
			if (visit[t] + 1 < visit[i]) {
				visit[i] = visit[t] + 1;
				q.push(i);
			}
		}
	}
	cout << "-1\n";
}