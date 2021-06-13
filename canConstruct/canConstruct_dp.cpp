#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> map;

/*
* m: size of target, n: size of array
* TIME COMPLEXITY: O(m*n*m)
* SPACE COMPLEXITY: O(m*m)
*/

bool canConstruct(string target, vector<string>& words)
{
	if (map.find(target) != map.end()) return map[target];
	if (target == "") return true;

	for(int i =0;i<words.size(); ++i)
		if (target.find(words[i]) == 0)
		{
			string suffix = target.substr(words[i].length(), target.length() - words[i].length());
			bool result = canConstruct(suffix, words);
			if (result)
			{
				map[target] = result;
				return true;
			}
		}

	map[target] = false;
	return false;
}
int main()
{
	string t;
	int n;

	cin >> t;
	cin >> n;

	vector<string> wordBank(n);
	for (auto& s : wordBank) cin >> s;


	if (canConstruct(t, wordBank)) cout << "\nTrue" << endl;
	else cout << "\nFalse" << endl;

	return 0;
}
