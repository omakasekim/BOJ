#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, tmp;
	cin >> N;
	int maxv = INT_MIN;
	int minv = INT_MAX;	
	while (N--) {
		cin >> tmp;
		maxv = max(tmp, maxv);
		minv = min(tmp, minv);
	}
	cout << minv << " " << maxv << "\n";
}