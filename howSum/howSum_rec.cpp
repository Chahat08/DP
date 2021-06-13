#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> null_vector()
{
	return {};
}

vector<int> one_vector()
{
	return {-1};
}

vector<int> howSum(int sum, vector<int>& v)
{
	if (sum == 0) return one_vector(); // return vector with -1 as first element
	if (sum < 0) return null_vector(); // return empty vector

	for (int i = 0; i < v.size(); ++i)
	{
		vector<int> result(howSum(sum - v[i], v));
		if (result.empty() != true) {
			result.push_back(v[i]); return result;
		}
	}
	return null_vector();
}

int main()
{
	int s, n;
	cin >> s >> n;

	vector<int> v(n);
	for (auto& i : v) cin >> i;
	vector<int> res(howSum(s, v));
	
	if (!res.empty()) res.erase(res.begin());

	cout << endl;
	for (auto& i : res) cout << i << " ";

	return 0;
}