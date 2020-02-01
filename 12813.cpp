#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string a, b;
	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) cout << ((a[i] - '0') & (b[i] - '0'));
	cout << "\n";
	for (int i = 0; i < a.length(); i++) cout << ((a[i] - '0') | (b[i] - '0'));
	cout << "\n";
	for (int i = 0; i < a.length(); i++) cout << ((a[i] - '0') ^ (b[i] - '0'));
	cout << "\n";
	for (int i = 0; i < a.length(); i++) cout << ((a[i] - '0') == 0 ? 1 : 0);
	cout << "\n";
	for (int i = 0; i < a.length(); i++) cout << ((b[i] - '0') == 0 ? 1 : 0);
	cout << "\n";
}