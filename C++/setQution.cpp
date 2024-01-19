#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void print(auto &s){
    for(auto v:s){
        cout<<v<<endl;
    }
}
int main(){
    set <string> s;
    int n;
    cin>>n;
    string word;
    for(int i=0;i<n;i++){
        cin>>word;
        s.insert(word);
    }
    print(s);
    return 0;
}