#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//1 method Naive sol. We need to count set bits in given number
/*
int countSetBit(int n){
    int res=0;
    while(n>0){
        if(n%2==1)
            res++;
        n=n/2;
    }
    return res;
}
 //or by below expression
int countSetBit(int n){
    int res=0;
    while(n>0){
        if((n&1)==1)
            res++;
        n=n>>1;
    }
    return res;
}
*/


//2 Method by Brain kerningam's (n&(n-1)) only traverse through set bits T.C=theta(setBit).
int countSetBit(int n){
    int res=0;
    while(n>0){
        n=n&(n-1);
        res++;
    }
    return res;
}
int main() {
    cout<<countSetBit(5)<<endl;
   return 0;
}