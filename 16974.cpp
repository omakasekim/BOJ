#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll table[51][2];
ll N, X;

int main()
{
	table[0][0] = table[0][1] = 1;
	for (int i = 1; i <= 50; i++) {
		table[i][0] = table[i - 1][0] * 2 + 1;
		table[i][1] = table[i - 1][1] * 2 + 3;
	}

	cin >> N >> X;

}