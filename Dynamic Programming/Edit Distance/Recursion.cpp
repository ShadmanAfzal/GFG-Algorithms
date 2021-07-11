#include <bits/stdc++.h>
using namespace std;

int MinEdit(string s1,string s2, int m,int n)
{
    if(n==0)
        return m;
    if(m==0)
        return n;
    if(s1[m-1] == s2[n-1])
        return MinEdit(s1,s2,m-1,n-1);
    return 1 + min(min(MinEdit(s1,s2,m,n-1), MinEdit(s1,s2,m-1,n)), MinEdit(s1,s2,m-1,n-1));
}

int main()
{
    string x = "sunday";
    string y = "saturday";
    cout<<MinEdit(x,y,x.size(),y.size());
}