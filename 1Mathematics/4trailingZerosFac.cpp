#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}
int countZeros(int n){
    int factres=factorial(n);
    int res=0;
    while(factres%10==0){
        res++;
        factres=factres/10;
    }
    return res;
}


int main(){
    cout<<countZeros(9)<<endl;
    return 0;
}