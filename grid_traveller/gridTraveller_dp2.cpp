#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

vector<vector<long>> v;

/*
* TIME COMPLEXITY: O(p*q/2)
* SPACE COMPLEXITY: O(p+q)
*/

long gridTraveller(int p, int q)
{
	if (p == 0 || q == 0) return 0;
	if (p == 1 && q == 1) return 1;
	if (v[p - 1][q - 1] != -1) return v[p - 1][q - 1];

	try {
		if (v.at(q - 1).at(p - 1) != -1) return v[q - 1][p - 1];
	} catch (const std::out_of_range& oor) {}

	v[p - 1][q - 1] = gridTraveller(p - 1, q) + gridTraveller(p, q - 1);
	return v[p - 1][q - 1];
}

int main()
{
	int p, q;
	cin >> p >> q;

	v.resize(p);
	for (auto& i : v) i.resize(q, -1);

	cout << gridTraveller(p, q) << endl;
	return 0;
}