#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M, stat[2], K;
	bool chk = false;
	cin >> N >> M;
	cin >> stat[0] >> stat[1];
	while (M--) {
		cin >> K;
		if (K >= stat[chk]) chk = !chk;
	}
	cout << stat[chk] << "\n";
}