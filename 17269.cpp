#include <bits/stdc++.h>
using namespace std;

int N, M;
string a, b;
int alpha[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 };

int main()
{
	cin >> N >> M;
	cin >> a >> b;
	string tmp;
	int i;
	for (i = 0; i < min(N, M); i++) {
		tmp += a[i];
		tmp += b[i];
	}
	if (N < M) tmp += b.substr(i, M - i);
	else tmp += a.substr(i, N - i);

	queue<int> q;
	for (i = 0; i < N + M; i++) q.push(alpha[tmp[i] - 'A']);
	
	while (q.size() > 2) {
		int siz = q.size();
		int cue = q.front();
		q.pop();
		for (int i = 0; i < siz - 1; i++) {
			q.push((cue + q.front()) % 10);
			cue = q.front();
			q.pop();
		}
	}
	if (q.front() != 0) cout << q.front();
	q.pop();
	cout << q.front() << "%\n";
}