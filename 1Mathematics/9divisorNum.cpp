#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//1 Method in O(n) in this problem i have to find all num below than the given number could be divide that number like example 15 o/p are 1,3,5,15;
/*
void divisorNum(int n){
    for(int i=1;i<=n;i++){
        if(n%i==0){
            cout<<i<<endl;
        }
    }
}
*/

//2 Method in O(sqrt(n))
/*
void divisorNum(int n){
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cout<<i<<endl;
            if(i!=n/i){//why we do this because it should be print perfect square root num 2 time like 25
                cout<<n/i<<endl;
            }
        }
    }
}
*/

//3 Method in O(sqrt(n)) in order
void divisorNum(int n){
    int i;
    for(i=1;i*i<n;i++){
        if(n%i==0){
            cout<<i<<endl;
        }
    }
    for(;i>=1;i--){
        if(n%i==0){
            cout<<n/i<<endl;
        }
    }
}
int main() {
    divisorNum(15);
   return 0;
}