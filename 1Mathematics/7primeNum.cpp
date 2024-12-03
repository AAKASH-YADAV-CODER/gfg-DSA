#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//Method 1 O(n)
/*
bool prime(int n){
    if(n==1){
        return false;
    }
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
*/


//Method 2 O(sqrtn)


// bool prime(int n){
//     if(n==1){
//         return false;
//     }
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0){
//             return false;
//         }
//     }
//     return true;
// }



//Method 3 this is more optimized in O(sqrtn)
bool prime(int n){
    if(n==1){
        return false;
    }
    if(n==2 || n==3){
        return true;
    }
    if(n%2==0 || n%3==0){
        return false;
    }
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0){
            return false;
        }
    }
    return true;

}
int main() {
    cout<<prime(2)<<endl;
   return 0;
}