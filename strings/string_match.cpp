#include <bits/stdc++.h>
using namespace std;

vector<int> rabin_karp(string const &s, string const &t)
{ // s is pattern , t in which pattern to be found
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}

int rabin(string const &p, string const &t)
{
    if (p.length() > t.length())
    {
        return -1;
    }
    vector<int> occ = rabin_karp(p, t);
    if (occ.size() == 0)
    {
        return -1;
    }

    return occ[0];
}

vector<string> stringMatching(vector<string> &words)
{
    unordered_set<string> h;

    vector<string> res;
    string s = "";
    string p = "";
    int ans = 0;
    for (int i = 0; i < words.size(); i++)
    {
        s = words[i];
        for (int j = i + 1; j < words.size(); j++)
        {
            p = words[j];
            ans = rabin(p, s);
            if (ans != -1)
            {
                h.insert(p);
                continue;
            }
            ans = rabin(s, p);
            if (ans != -1)
            {
                h.insert(s);
            }
        }
    }
    for (auto s : h)
    {
        res.push_back(s);
    }
    return res;
}

int main()
{
    vector<string> v={"tjtm","qxtjtm","tchl","sdtjtm","clz","ztjtm","mvd","bclzoy","qpxt","bclzoyx","syih","clzz"};
    vector<string> res=stringMatching(v);
    for(auto &x:res){
        cout<<x<<" ";
    }
    cout<<endl;
}