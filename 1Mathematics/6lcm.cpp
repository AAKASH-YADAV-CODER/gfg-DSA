#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//Method 1
/*
int lcm(int a,int b){
    int res=max(a,b);
    while (true)
    {
        if(res%a==0 && res%b==0){
            break;
        }else{
            res++;
        }
    }
    return res;
}
*/
//Method 2
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}
int main() {
    cout<<lcm(4,6)<<endl;
   return 0;
}