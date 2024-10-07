// problem link - https://codeforces.com/contest/2021/problem/C1
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
void solve()
{
    ll a , b , c;
    cin>>a>>b>>c;
    vector<int>v(a);
    for (int i = 0; i < a; i++)
    {
        cin>>v[i];
    }
    
    vector<int>v1(b);
    for (int i = 0; i < b; i++)
    {
        cin>>v1[i];
    }
    
    int j=0;
    map<int,int>m;
    for (int i = 0; i < b; i++)
    {
        if(v1[i]!=v[j]){
            if(m[v1[i]]==v1[i]){
                continue;
            }
            else{
            cout<<"TIDAK"<<endl;
            return ;
            }
        }
        if(v1[i+1]!=v[j]){
            m[v[j]]=v[j];
            j++;
            continue;

        }

    }
    cout<<"YA"<<endl;
}
int main()
{
    ll t=1;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        solve();
    }
    return 0;
}