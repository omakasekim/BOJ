#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
queue<int> q;
bool visit[501];
vector<int> graph[501];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	visit[1] = true;
	q.push(1);

	int cnt = -1;
	for (int i = 0; i < 3; i++) {
		int siz = q.size();
		while (siz--) {
			++cnt;
			int t = q.front();
			q.pop();

			for (auto i : graph[t]) {
				if (!visit[i]) {
					visit[i] = true;
					q.push(i);
				}
			}
		}
	}
	cout << cnt << "\n";
}