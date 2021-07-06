#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> null_2d_vector()
{
	return { {} };
}
vector<vector<string>> one_2d_vector()
{
	return { {"1"} };
}
vector<vector<string>> allConstruct(string target, vector<string>& words)
{
	cout << "here";
	if (target == "") return one_2d_vector();

	vector<vector<string>> ways_to_construct(null_2d_vector());

	for (int i = 0; i < words.size(); ++i)
	{
		string suffix = target.substr(words[i].length(), target.length() - words[i].length());
		vector<vector<string>> suffixWays(allConstruct(suffix, words));
		if (!suffixWays.empty())
		{
			for (auto& v : suffixWays) v.insert(v.begin(), words[i]);
			ways_to_construct.insert(ways_to_construct.end(), suffixWays.begin(), suffixWays.end());
		}
		/*cout << endl;
		for (auto& v : ways_to_construct)for (auto& s : v) cout << s << " ";
		cout << endl;*/
	}

	return ways_to_construct;
}
int main()
{
	string t;
	int n;

	cin >> t;
	cin >> n;

	vector<string> wordBank(n);
	for (auto& s : wordBank) cin >> s;

	vector<vector<string>> result = allConstruct(t, wordBank);
	for (auto& v : result)
	{
		for (auto& s : v) cout << s << " ";
		cout << endl;
	}

	return 0;
}