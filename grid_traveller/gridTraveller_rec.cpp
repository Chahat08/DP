#include <iostream>

using namespace std;

/*
* TIME COMPLEXITY: O(2^(p+q))
* SPACE COMPLEXITY: O(p+q)
*/

long gridTraveller(int p, int q)
{
	if (p == 0 || q == 0) return 0;
	if (p == 1 && q == 1) return 1;
	return (gridTraveller(p - 1, q) + gridTraveller(p, q - 1));
}

int main()
{
	int p, q;
	cin >> p >> q;
	cout << gridTraveller(p, q)<< endl;
	return 0;
}