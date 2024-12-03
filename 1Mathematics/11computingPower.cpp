#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//1 Method(Naive Sol) O(n)
// int computPow(int x,int n){
//     int res=1;
//     for(int i=1;i<=n;i++){
//         res*=x;
//     }
//     return res;
// }


//2 Method in O(log(n))
int computPow(int x,int n){
    if(n==0){
        return 1;
    }
    int temp=computPow(x,n/2);
    temp=temp*temp;
    if(n%2==0){
        return temp;
    }else{
        return temp*x;
    }
}

int main() {
    cout<<computPow(2,4)<<endl;
   return 0;
}