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
    map<int,string> m;//red black tree
    m[1]="abcd"; //O(log(n))
    m[5]="cdc";
    m[3]="abc";
    m.insert({4,"afg"});
    m[1]="A";
    auto it=m.find(3);//log(n)
    if(it==m.end()){
        cout<<"no output"<<endl;
    }else{
       cout<<it->first<<" "<<it->second<<endl;
    }
    m.erase(it);
    /* map<int,string> :: iterator it;
    for(it=m.begin();it!=m.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    } */
    print(m);
    return 0;
}
