#include <iostream>

using namespace std;

// O(2^N) time complexity
// O(N) space complexity

int fib(int x)
{
	if(x==1 || x==2) return 1;
	else return (fib(x-1)+fib(x-2));
}

int main()
{
	int n;
	cin>>n;
	cout<< endl <<fib(n) <<endl;
}