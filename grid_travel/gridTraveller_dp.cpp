#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;

int gridTraveller(int p, int q)
{
	if (p == 0 || q == 0) return 0;
	if (p == 1 && q == 1) return 1;
	if (v[p - 1][q - 1] != -1) return v[p - 1][q - 1];

	v[p - 1][q - 1] = gridTraveller(p - 1, q) + gridTraveller(p, q - 1);
	return v[p - 1][q - 1];
}

int main()
{
	int p, q;
	cin >> p >> q;

	v.resize(p);
	for (auto& i : v) i.resize(q, -1);

	cout << gridTraveller(p, q);
	return 0;
}