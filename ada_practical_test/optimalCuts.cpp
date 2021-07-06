#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> map;
/*
int optimisedCuts(vector<int>& cuts, int l)
{
    if (l < 0)
        return 0;                                                                                  
    // else return l;

    int minimised_value = INT_MAX;

    for (int i = 0; i < l; i++)
    {
        minimised_value = min(minimised_value, cuts[i] + optimisedCuts(cuts, l - i - 1));
        // minimised_value = min(cuts[i]+ optimisedCuts(cuts, l - cuts[i - 1]), optimisedCuts(cuts, l));
        // minimised_value = min(minimised_value, cuts[i] + optimisedCuts(cuts, l - cuts[i]));
        // minimised_value = min(minimised_value, cuts[i] + optimisedCuts(cuts, l - cuts[i]));
    }

    return minimised_value;
}

int optimisedCuts_dp(vector<int>& cuts, int l)
{
    if (map.find(l) != map.end()) return map[l];

    if (l <= 0)
        return 0;

    int minimised_value = INT_MAX;

    for (int i = 0; i < l; i++)
    {
        int res = cuts[i] + optimisedCuts(cuts, l - i - 1);
        if(res < minimised_value)
        {
        minimised_value = res;
        }
    }
    map[l] = minimised_value;
    return minimised_value;
}

int main()
{
    int l, n;
    cin >> l >> n;
    vector<int> cuts(n);
    for (auto& i : cuts) cin >> i;

    cout << optimisedCuts(cuts, l);
    
    return 0;
}*/
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:

    vector <int> arr;
    int dp[109][109];

    int solve(int idx, int jdx, int l, int r) {
        if (idx < 0 || jdx >= arr.size() || idx > jdx)
            return 0;

        if (idx == jdx)
            return r - l;

        if (dp[idx][jdx] != -1)
            return dp[idx][jdx];

        int ans = INT_MAX;
        for (int i = idx; i <= jdx; i++) {
            ans = min(ans, (r - l) + solve(idx, i - 1, l, arr[i]) + solve(i + 1, jdx, arr[i], r));
        }
        return dp[idx][jdx] = ans;

    }



    int minCost(int n, vector<int>& cuts) {

        memset(dp, -1, sizeof dp);
        sort(cuts.begin(), cuts.end());
        this->arr = cuts;

        return solve(0, cuts.size() - 1, 0, n);
    }
};
int main() {
    Solution s = new Solution();
    int n = 10;
    vector<int> g1;
    g1.pushback(3);
    g1.pushback(5);
    g1.pushback(7);
    g1.pushback(8);

    int a = s.minCost(n, g1);
    cout << (a);
    return 0;
}