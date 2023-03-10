#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//with using the ans variable , passed by reference


void vp(vector <int> &v){
    cout<<"[";
    for(int i=0;i<v.size();i++){
        if(v[i]!=0){
            char x=i+'a';
            cout<<x<<":"<<v[i]<<" ";
        }
    }
    cout<<" ]"<<endl;
}

void vp2(vector <string> &v,int ipas){
    cout<<"[";
    for(int i=0;i<ipas;i++){
        cout<<v[i]<<" ";
    }
    cout<<" ]"<<endl;
}

void status(int ipas,int ans,vector <int>v,vector <string>& a){
    cout<<"ipas: "<<ipas<<" ans: "<<ans<<endl;
    vp(v);
    vp2(a,ipas);
}

int findCount(vector <int> &v){
    int c=0;
    for(int i=0;i<v.size();i++){
        if(v[i]!=0){
            c++;
        }
    }
    return c;
}


   int helper(vector <int>& v,vector <string>& a,int ipas,int &ans){
        
        if(ipas==0){
            cout<<"Base Case ";
            status(ipas,ans,v,a);
            return ans;
        }
        string s=a[ipas-1];
        
        status(ipas,ans,v,a);
        int a1=helper(v,a,ipas-1,ans);
        //we accept it
        bool match=false;
        for(int i=0;i<s.length();i++){
            char x=s[i];
            int find=x-'a';
            if(v[find]==1){
                match=true;
                break;
            }
            else{
                v[find]=1;
            }
        }
        if(match==true){
            cout<<"A2 rejected ";
            status(ipas,ans,v,a);
            ans=a1;
            return ans;

        }
        else{
            
            //match is false i.e we have to find a2 too
            
            ans+=s.length();
            int a2=helper(v,a,ipas-1,ans);
            cout<<"Max of a1,a2 ";
            
            cout<<"a1: "<<a1<<" a2: "<<a2<<endl;
            status(ipas,ans,v,a);
            ans=max(a1,a2);
            return ans;
        }
    }
    
    int maxLength(vector<string>& a) {
        vector <int> v(26,0);
        int x=0;
        int ans=helper(v,a,a.size(),x);
        return ans;
    }

    int main(){
        vector <string> s={"tn","iq","ueu"};
        vector <string> s2={"cha","r","ers"};
        vp2(s2,s2.size());
        int ans=maxLength(s2);
        cout<<"Ans is: "<<ans<<endl;
        return 0;
    }