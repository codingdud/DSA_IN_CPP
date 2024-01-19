#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print(auto &s){
    for(auto v:s){
        cout<<v<<endl;
    }
}

int main(){
    multiset<string> s; //red blck tree
    s.insert("abcd");
    s.insert("akabo");
    s.insert("asdasd");
    s.insert("abcd");
    auto it=s.find("abcd");
    if(it==s.end()){
        cout<<"no output"<<endl;
    }else{
       //cout<<*it<<endl;
       s.erase(it);
    }
    print(s);
    return 0;
}