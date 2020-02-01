#include <bits/stdc++.h>
using namespace std;

int N, M, dir[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
bool nation[11][11], mstvisit[11];
int visit[11][11], dist[11][11];
queue<pair<int, int>> q;
int natcnt, ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> nation[i][j];

	for (int i = 0; i < 11; i++) for (int j = 0; j < 11; j++) dist[i][j] = 0x7fffffff;

	//preprocessing
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (nation[i][j] && !visit[i][j]) {
				++natcnt;
				visit[i][j] = natcnt;
				q.push({ i, j });

				while (!q.empty()) {
					int tx = q.front().first;
					int ty = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = tx + dir[0][k];
						int ny = ty + dir[1][k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

						if (!visit[nx][ny] && nation[nx][ny]) {
							visit[nx][ny] = natcnt;
							q.push({ nx, ny });
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j]) {
				int thisnat = visit[i][j];
				for (int k = 0; k < 4; k++) {
					int brilen = 0;
					int nx = i;
					int ny = j;
					while (1) {
						++brilen;
						nx += dir[0][k];
						ny += dir[1][k];
						if (nx < 0 || nx >= N || ny < 0 || ny >= M) break;
						if (visit[nx][ny]) {
							if (visit[nx][ny] != thisnat && brilen > 2) {
								dist[thisnat][visit[nx][ny]] = min(dist[thisnat][visit[nx][ny]], brilen - 1);
								dist[visit[nx][ny]][thisnat] = min(dist[visit[nx][ny]][thisnat], brilen - 1);
							}
							break;
						}
					}
				}
			}
		}
	}

	priority_queue<pair<int, int>> pq;
	for (int i = 1; i <= natcnt; i++) {
		if (dist[1][i] != 0x7fffffff) pq.push({ -dist[1][i], i });
	}
	mstvisit[1] = true;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (!mstvisit[here]) {
			mstvisit[here] = true;
			ans += cost;
			for (int i = 1; i <= natcnt; i++) {
				if (dist[here][i] != 0x7fffffff && !mstvisit[i]) pq.push({ -dist[here][i], i });
			}
		}
	}

	for (int i = 1; i <= natcnt; i++) {
		if (!mstvisit[i]) {
			cout << "-1\n";
			return 0;
		}
	}
	cout << ans << "\n";
}