#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//1Method
int iterativePow(int x,int n){
    int res=1;
    while(n>0){
        if(n%2!=0){
            res=res*x;
        }
        x=x*x;
        n=n/2;
    }
    return res;
}
int main() {
    cout<<iterativePow(4,5)<<endl;
   return 0;
}