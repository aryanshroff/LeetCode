#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void generate_factors(int limit, unordered_set<string> &h, int a, int b)
{
    int x = 2;
    while (b * x < limit)
    {
        int v1 = a * x;
        int v2 = b * x;
        string s = to_string(v1) + to_string(v2);
        h.insert(s);
        x++;
    }
}

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
                string s = to_string(a) + to_string(b);
                if (h.find(s) == h.end())
                {
                    cout << a << " " << b << " " << val <<"  working: "<< a * a << " + " << b * b << " = " << val * val << endl;
                    cout<<endl;
                    h.insert(s);
                    // generate factors of 3 and 5 and b is the largest one so we check if b is less than limit
                    generate_factors(limit, h, a, b);
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