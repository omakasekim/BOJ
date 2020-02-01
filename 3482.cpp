#include <bits/stdc++.h>
using namespace std;

int T, C, R, dir[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
char v[1000][1000];
bool visit[1000][1000], visit2[1000][1000];
queue<pair<int, int>> q;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		int maxv = 0;
		memset(visit, 0, sizeof(visit));
		memset(visit2, 0, sizeof(visit2));
		cin >> C >> R;
		for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) cin >> v[i][j];

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (v[i][j] == '.' && !visit[i][j]) {
					visit[i][j] = true;
					q.push({ i, j });
					int tx, ty;
					while (!q.empty()) {
						tx = q.front().first;
						ty = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++) {
							int nx = tx + dir[0][k];
							int ny = ty + dir[1][k];
							if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

							if (v[nx][ny] == '.' && !visit[nx][ny]) {
								visit[nx][ny] = true;
								q.push({ nx, ny });
							}
						}
					}

					q.push({ tx, ty });
					visit2[tx][ty] = true;
					int cnt = 0;

					while (!q.empty()) {
						int siz = q.size();
						++cnt;
						while (siz--) {
							tx = q.front().first;
							ty = q.front().second;
							q.pop();

							for (int k = 0; k < 4; k++) {
								int nx = tx + dir[0][k];
								int ny = ty + dir[1][k];
								if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

								if (v[nx][ny] == '.' && !visit2[nx][ny]) {
									visit2[nx][ny] = true;
									q.push({ nx, ny });
								}
							}
						}
					}
					maxv = max(maxv, cnt);
				}
			}
		}

		cout << "Maximum rope length is " << maxv - 1 << ".\n";
	}
}