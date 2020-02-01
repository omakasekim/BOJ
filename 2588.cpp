#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	string b;
	cin >> a >> b;
	for (int i = b.length() - 1; i >= 0; i--) cout << a * (b[i] - '0') << "\n";
	cout << a * stoi(b) << "\n";
}