#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	if (B >= C) {
		cout << "-1\n";
		return 0;
	}
	double ans = (double)A / (double)(C - B);
	double tmp = ceil(ans);
	if (ans == tmp) tmp += 1.0;
	cout << (int)tmp << "\n";
}