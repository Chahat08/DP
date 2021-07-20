#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main(int argc, char* argv[])
{
int n=atoi(argv[1]);

if(n<0){cout<<"not defined"; return -1;}
if(n==0 || n==1){cout<<n; return 0;}

vector<int> fib(n+1);
fib[0]=0,fib[1]=1;
for(int i=2;i<=n;++i)
fib[i]=fib[i-1]+fib[i-2];

cout<<fib[n];
return 0;
}