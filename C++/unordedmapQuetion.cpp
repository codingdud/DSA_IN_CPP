#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(auto &m){
    cout<<"size:"<<m.size()<<endl;
    for(auto &pr:m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}

main(){
    unordered_map<string,int> m;
    int n;
    cin >>n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        //m[s]=m[s]+1;
        m[s]++;
    }
    print(m);
    return 0;
}
