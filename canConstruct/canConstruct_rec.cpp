#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
* m: size of target, n: size of array
* TIME COMPLEXITY: O(n^m * m)
* SPACE COMPLEXITY: O(m*m)
*/

bool canConstruct(string target, vector<string>& words)
{
	if (target == "") return true;
	
	for (int i = 0; i < words.size(); ++i)
	{
		if (target.find(words[i]) == 0)
		{
			string suffix = target.substr(words[i].length(), target.length() - words[i].length());
			if (canConstruct(suffix, words)) return true;
		}
	}

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

/*
TEST CASES:

abcdef 5
ab abc cd def abcd
-> true

skateboard 7
bo rd ate t ska sk boar
-> false

enterapotentpot 7
a p ent enter ot o t
-> true

eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef 6
e ee eee eeee eeeee eeeeee
-> false

*/