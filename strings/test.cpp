#include <bits/stdc++.h>
using namespace std;

vector<int> rabin_karp(string const& s, string const& t) { //s is pattern , t in which pattern to be found
    const int p = 31; 
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h = (h[i+S] + m - h[i]) % m; 
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}
    int maxRepeating(string t, string s) {
        vector<int> v=rabin_karp(s,t) ;
        int n=v.size();
        int l=s.length();
       
        //sequences will be in sorted order
        int count=1;
        int ans=0;
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }

        for(int i=1;i<n;i++){
            if(v[i-1]+l==v[i]){
                count++;
            }
            else if(v[i-1]+l>v[i]){
                
            }
            else{
                ans=max(ans,count);
                count=1;
            }
        }
        ans=max(count,ans);
        return count;
    }

    int main(){
        string t="abab";
        string p="ab";
        int count=maxRepeating(t,p);
        cout<<" ans: "<<count<<endl;
    }