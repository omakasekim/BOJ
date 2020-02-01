#include <iostream>
using namespace std;

int N, M, dir[2][4] = { {-1,1,0,0}, {0,0,-1,1} };
char board[50][50];
bool chk[50][50];
int sx, sy;

void dfs(int tx, int ty, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nx = tx + dir[0][i];
		int ny = ty + dir[1][i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (cnt >= 3 && nx == sx && ny == sy) {
			cout << "Yes\n";
			exit(0);
		}
		if (!chk[nx][ny] && board[nx][ny] == board[sx][sy]) {
			chk[nx][ny] = true;
			dfs(nx, ny, cnt + 1);
			chk[nx][ny] = false;
		}
	}
}


int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (sx = 0; sx < N; sx++) {
		for (sy = 0; sy < M; sy++) {
			memset(chk, 0, sizeof(chk));
			chk[sx][sy] = true;
			dfs(sx, sy, 0);
			chk[sx][sy] = false;
		}
	}

	cout << "No\n";
}