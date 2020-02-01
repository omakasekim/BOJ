#include <bits/stdc++.h>
using namespace std;

int N, arr[100][100], dir[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
bool visit[200][200];
queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	

	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];

	int high, low, fixhigh;
	high = 200;
	low = 0;
	int res = 200;
	while (low <= high) {
		fixhigh = (low + high) / 2;
		bool chk = false;

		for (int fixlow = 0; fixlow <= fixhigh; fixlow++) {
			if (arr[0][0] < fixlow || arr[0][0] > fixhigh) break;
			if (arr[N - 1][N - 1] < fixlow || arr[N - 1][N - 1] > fixhigh) break;
			memset(visit, 0, sizeof(visit));
			arr[0][0] = true;
			q.push({ 0,0 });
			while (!q.empty()) {
				int tx = q.front().first;
				int ty = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = tx + dir[0][i];
					int ny = ty + dir[1][i];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (!visit[nx][ny] && arr[nx][ny] >= fixlow && arr[nx][ny] <= fixhigh) {
						visit[nx][ny] = true;
						q.push({ nx, ny });
					}
				}
			}

			if (visit[N - 1][N - 1]) {
				chk = true;
				res = min(res, fixhigh - fixlow);
			}
			else break;
		}
		if (chk) high = fixhigh - 1;
		else low = fixhigh + 1;
	}
	cout << res << "\n";
}