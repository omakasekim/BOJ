#include <bits/stdc++.h>
using namespace std;

int tmp, maxv, maxi;

int main()
{
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		if (maxv < tmp) {
			maxv = tmp;
			maxi = i;
		}
	}
	cout << maxv << "\n" << maxi + 1 << "\n";
}