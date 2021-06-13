#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> map;

int countConstruct(string target, vector<string>& words)
{
	if (map.find(target) != map.end()) return map[target];
	if (target == "") return 1;

	int sum = 0;
	for (int i = 0; i < words.size(); ++i)
	{
		if (target.find(words[i]) == 0)
		{
			string suffix = target.substr(words[i].length(), target.length() - words[i].length());
			int res = countConstruct(suffix, words);
			map[target] = res;
			sum += res;
		}
	}
	return sum;
}

int main()
{
	string t;
	int n;
	cin >> t >> n;
	vector<string> words(n);
	for (auto& w : words) cin >> w;
	cout << countConstruct(t, words);
	return 0;
}