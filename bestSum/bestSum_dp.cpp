#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
* m: targetSum, n: size of array
* TIME COMPLEXITY: O(n*m)
* SPACE COMPLEXITY: O(m)
*/

vector<int> null_vector()
{
	return {};
}

vector<int> one_vector()
{
	return { -1 };
}

unordered_map<int, vector<int>> map;

vector<int> howSum(int sum, vector<int>& v)
{
	if (map.find(sum) != map.end()) return map[sum];
	if (sum == 0) return one_vector();
	if (sum < 0) return null_vector();

	int len = INT_MAX;
	vector<int> final_result;

	for (int i = 0; i < v.size(); ++i)
	{
		vector<int> result(howSum(sum - v[i], v));
		if (!result.empty() && result.size() < len)
		{
			result.push_back(v[i]);
			final_result.clear();
			final_result = result;
			len = result.size();
		}
	}
	if (!final_result.empty())
	{
		map[sum] = final_result;
		return final_result;
	}
	else 
	{
		map[sum] = null_vector();  return null_vector();
	}
}

int main()
{
	int s, n;
	cin >> s >> n;

	vector<int> v(n);
	for (auto& i : v) cin >> i;
	vector<int> res(howSum(s, v));

	if (!res.empty())
	{
		res.erase(res.begin());
		cout << "[ ";
		for (auto& i : res) cout << i << " ";
		cout << "]";
	}
	else cout << "NULL";

	cout << endl;


	return 0;
}