#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
int n, k;
cin>>n>>k;

vector<vector<int>> bc(n+1);
for(auto& v:bc)v.resize(k+1);

for(int i=0;i<=n;++i) bc[i][0]=1; // n choose 0 = 1
for(int i=0;i<=n;++i) bc[i][i]=1; // n choose n = 1

for(int i=1;i<=n;++i)
for(int j=1;j<=k;++j) 
bc[i][j]=bc[i-1][j-1]+bc[i-1][j]; // (n choose k) = (n-1 choose k-1) + (n-1 choose k)
                     
printf("%d", bc[n][k]);
return 0;
}