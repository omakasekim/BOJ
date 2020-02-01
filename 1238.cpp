#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int N, M, X, a, b, w;
vector<pii> g[2][1001];
int dist[2][1001];
priority_queue<pii> pq;

void dij(int mod) {
	dist[mod][X] = 0;
	pq.push({ 0, X });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if (cost > dist[mod][here]) continue;

		for (auto i : g[mod][here]) {
			if (cost + i.second < dist[mod][i.first]) {
				dist[mod][i.first] = cost + i.second;
				pq.push({ -dist[mod][i.first], i.first });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M >> X;
	while (M--) {
		cin >> a >> b >> w;
		g[0][a].push_back({ b, w });
		g[1][b].push_back({ a, w });
	}

	for (int i = 1; i <= N; i++) dist[0][i] = dist[1][i] = 0x7fffffff;
	dij(0);
	dij(1);

	int maxv = 0;
	for (int i = 1; i <= N; i++) maxv = max(maxv, dist[0][i] + dist[1][i]);
	cout << maxv << "\n";
}