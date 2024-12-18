#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Naive Method explicitly handling 0 and repeatedly dividing 0
/*
bool powTwo(int n){
    if(n==0){
        return false;
    }
    while(n!=1){
        if(n%2!=0)
            return false;
        n=n/2;
    }
    return true;
}
*/


//2 brain kerningam's algorithm 
bool powTwo(int n){
    // if(n==0) 
    //     return false;
    return (n&& ((n&(n-1))==0));
}

int main() {
    cout<<powTwo(7)<<endl;
   return 0;
}