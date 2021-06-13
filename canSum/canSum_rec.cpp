#include <iostream>
#include <vector>

using namespace std;

/*
* m: targetSum, n: size of array
* TIME COMPLEXITY: O(n^m)
* SPACE COMPLEXITY: O(m)
*/

bool canSum(int sum, vector<int>& v)
{
	if (sum < 0) return false;
	if (sum == 0) return true;

	for (int i = 0; i < v.size(); ++i)
		if (canSum(sum - v[i], v)) return true;

	return false;
}
int main()
{
	int s, n;
	// s = sum, n = no. of elements in the array

	vector<int> v;
	cin >> s >> n;

	v.resize(n);
	for (auto& i : v) cin >> i;

	if (canSum(s, v)) cout << "True" << endl;
	else cout << "False" << endl;

	return 0;
}