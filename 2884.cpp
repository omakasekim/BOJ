#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;
	if (m >= 45) m -= 45;
	else {
		if (h == 0) h = 24;
		--h;
		m += 15;
	}
	cout << h << " " << m << "\n";
}