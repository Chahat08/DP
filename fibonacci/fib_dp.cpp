#include <iostream>
#include <vector>

using namespace std;

// auxialliary vector for memoization
// USE HASH TABLES TO AVOID THE EXTRA SPACE REQUIRED FOR INDICES 0, 1, 2
vector<int> v;

// O(N) time complexity: actually more like O(2N)
// O(N) space complexity

int fib(int n)
{
if(v[n]!=-1) return v[n];
if(n<=2) {return 1;}
v[n] = fib(n-1) + fib(n-2);
return v[n];
}

int main()
{
int n;
cin>>n;
v.resize(n+1, -1);
cout<<fib(n)<<endl;
}