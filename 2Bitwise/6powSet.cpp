#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printPowerSet(string s){
    int size=s.length();
    int powsize=1<<size;
    for(int i=0;i<powsize;i++){
        for(int j=0;j<size;j++){
            if((i&(1<<j))!=0)
                cout<<s[j];
        }
        cout<<endl;
    }
}
int main() {
    string s = "abc";
    printPowerSet(s);
    return 0;
   return 0;
}