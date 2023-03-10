#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int limit)
{
    unordered_set<string> h;
    for (int i = 1; i < limit; i++)
    {
        for (int j = 1; j < limit; j++)
        {
            int res = i * i + j * j;
            int val = sqrt(res);
            if (val * val == res)
            {
                int a = min(i, j);
                int b = max(i, j);
                string s=to_string(a)+to_string(b);
                if(h.find(s)==h.end()){
                    cout<<a<<" "<<b<<" "<<val<<endl;
                    h.insert(s);
                }
            }
        }
    }
}

int main()
{
    solve(50);
    return 0;
}