#include <iostream>
#include <vector>
#include <string>

using namespace std;

int sum = 0;
/*
* m: size of target, n: size of array
* TIME COMPLEXITY: O(n^m * m)
* SPACE COMPLEXITY: O(m*m)
*/
bool countConstruct(string target, vector<string>& words)
{
	if (target == "") return true;

	for (int i = 0; i < words.size(); ++i)
	{
		if (target.find(words[i]) == 0)
		{
			string suffix = target.substr(words[i].length(), target.length() - words[i].length());
			if (countConstruct(suffix, words)) ++sum;
		}
	}

	return false;
}

int main()
{
	string t;
	int n;

	cin >> t >> n;

	vector<string> words(n);
	for (auto& s : words) cin >> s;

	countConstruct(t, words);
	cout << sum;

	return 0;
}
/*
purple 5
purp p ur le purpl
-> 2

abcdef 5
ab abc cd def abcd
-> 1

skateboard 7
bo rd ate t ska sk boar
-> 0

eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef 6
e ee eee eeee eeeee eeeeee
-> 0

enterapotentpot 7
a p ent enter ot o t
-> 4

*/