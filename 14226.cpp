#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
queue<pii> q;
bool chk[1001][1001];
#define FR q.front().first
#define SE q.front().second

int main()
{
	int S;
	cin >> S;
	q.push({ 1, 0 });
	int t = 0, siz;
	while (!q.empty()) {
		siz = q.size();
		while (siz--) {
			if (FR == S) {
				cout << t << "\n";
				return 0;
			}
			
			if (FR <= S && !chk[FR][FR]) {
				q.push({ FR, FR });
				chk[FR][FR] = true;
			}
			if (FR + SE <= S && !chk[FR + SE][SE]) {
				q.push({ FR + SE, SE });
				chk[FR + SE][SE] = true;
			}
			if (FR - 1 >= 0 && FR - 1 <= S && !chk[FR - 1][SE]) {
				q.push({ FR - 1, SE });
				chk[FR - 1][SE] = true;
			}
			
			q.pop();
		}
		++t;
	}
}