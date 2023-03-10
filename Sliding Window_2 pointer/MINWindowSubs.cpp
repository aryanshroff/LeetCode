#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void mapPrinter(unordered_map <char,int> h){
    for(auto it=h.begin();it!=h.end();it++){
        cout<<it->first<<" -> "<<it->second<<endl;
    }
    cout<<endl;
}

string minWindow(string s, string t)
{
    string res = "";
    int resL = INT_MAX;
    if (t.length() > s.length())
    {
        return res;
    }
    bool found = false;
    unordered_map<char, int> h;
    for (int i = 0; i < t.length(); i++)
    {
        h[t[i]]++;
    }
    int match = 0;
    unordered_map<char, int> h2;
    for (int i = 0; i < t.length(); i++)
    {
        char c = s[i];
        auto it = h.find(c);
        if (it != h.end())
        {
            // c is present in t
            h2[c]++;
            auto it2 = h2.find(c);
            if (it2->second == it->second)
            {
                match++;
            }
        }
    }
    mapPrinter(h);
    mapPrinter(h2);
    // by the end of this foor loop we have window of size t,match count,h1 ,h2 with count
    int i = 0, j = t.size() - 1;
    int len = 0;
    int target = h.size();
    while (true)
    {
        cout<<"Line 51 1st line of while loop"<<endl;
        cout<<" i= "<<i<<"window start,end: "<<s[i]<<","<<s[j]<<" j= "<<j<<endl;
        len = j + 1 - i;
        if (match == target and len < resL)
        {
            // update the res
            cout<<"Line 56"<<endl;

            string ans = "";
            for (int k = i; k <= j; k++)
            {
                ans.push_back(s[k]);
            }
            res = ans;
            resL = res.length();
            if (len == t.size())
            {
                // our answer cant get any better than this
                break;
            }
        }
        if (match < target)
        {
            // expand
        cout<<"Line 74 match<target"<<endl;

            if (j == s.length() - 1)
            {
                cout<<"j= "<<j<<" s.length()-1= "<<s.length()-1<<endl;
                // we got expand ka call when we cant expand=>break
        cout<<"Line 79"<<endl;

                break;
            }
            j++;
            if (h.find(s[j]) != h.end())
            {
                // s[j] is in t , we need to update the cound
        cout<<"Line 87 updating the count"<<endl;

                h2[s[j]]++;
                auto it = h.find(s[j]);
                auto it2 = h2.find(s[j]);
                if (it->second == it2->second)
                {
                    // abhi abhi same hua hai
                    match++;
                }

                // if it2->second>it->second
                // pehle hi match inc ho chuka hai , wo dont inc match we dont dec match
            }
        }
        else
        {
        cout<<"Line 104"<<endl;

            // when match>=target
            // compress
            if (i == s.length() - 1)
            {
                // we got compress ka call when we cant compress
                break;
            }
            auto it = h.find(s[i]);
            if (it != h.end())
            {
                // s[i] was present in t, s[i] was also present in our window
                // hence we need to dec its count
                h2[s[i]]--;
                // to check if matches are affected
                auto it2 = h2.find(s[i]);
                if (it2->second == it->second - 1)
                {
                    // abhi abhi kam hua hai
                    match--;
                    // if it2->sec=2 and it->sec=5 matlaab pehli hi kam chuka hai so
                    // we made the matches less before only no need to reduce it now

                    // if it2->sec>=it->sec i. farak nahi padhga hai no need to reduce
                }
            }
            // in any case we reduce compress the window match found or not
            i++;
        }
    }

    return res;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<s<<endl;
    string ans = minWindow(s, t);
    cout << "Ans: " << ans << endl;
    return 0;
}