#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//Method 1
/**
int gcd(int a,int b){
    int res=min(a,b);
    while(res>0){
        if(a%res==0 && b%res==0){
            break;
        }else{
            res--;
        }
    }
    return res;
}
 */
//Method 2 this is by eucliden's algorithm
/*
int gcd(int a,int b){
    while(a!=b){
        if(a>b){
            a=a-b;
        }else{
            b=b-a;
        }
    }
    return a;
}
*/
int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main() {
    cout<<gcd(12,15)<<endl;
   return 0;
}