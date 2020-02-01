	#include <bits/stdc++.h>
	using namespace std;

	#define pii pair<int, int>

	int N, sx, sy, ans, ocean[20][20], dir[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
	int sharkSiz = 2, sharkEaten;
	bool visit[20][20];
	queue<pii> q;
	vector<pii> prey;

	int main()
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> ocean[i][j];
				if (ocean[i][j] == 9) sx = i, sy = j, ocean[i][j] = 0;
			}
		}
	
		while (1) {
			q.push({ sx, sy });
			visit[sx][sy] = true;
			int len = 0;
			while (!q.empty()) {
				int siz = q.size();
				++len;
				while (siz--) {
					int tx = q.front().first;
					int ty = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = tx + dir[0][i];
						int ny = ty + dir[1][i];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (!visit[nx][ny] && ocean[nx][ny] <= sharkSiz) {
							visit[nx][ny] = true;
							q.push({ nx, ny });
							if (ocean[nx][ny] < sharkSiz && ocean[nx][ny] > 0) prey.push_back({ nx, ny });
						}
					}
				}
				if (prey.size()) {
					sort(prey.begin(), prey.end());
					ocean[prey[0].first][prey[0].second] = 0;
					++sharkEaten;
					if (sharkEaten == sharkSiz) {
						++sharkSiz;
						sharkEaten = 0;
					}
					ans += len;
					sx = prey[0].first;
					sy = prey[0].second;
					break;
				}
			}
			if (prey.empty()) break;
			prey.clear();
			while (!q.empty()) q.pop();
			memset(visit, 0, sizeof(visit));
		}
		cout << ans << "\n";
	}