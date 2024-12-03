#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//In this we are printing all prime number which are comes to 1 to n-the given num
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
//1 Method(Naive Sol) in O(n)
/*
void printPrime(int n){
    for(int i=2;i<=n;i++){
        if(prime(i)){
            cout<<i<<endl;
        }
    }
}
*/


//2 Method this is by Sieve of Eratosthenes
void printPrime(int n){
    // vector<bool> isPrime(n+1,true);
    bool isPrime[n+1];
    memset(isPrime,true,sizeof(isPrime));
    for(int i=2;i*i<=n;i++){
        if(isPrime[i]==true){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(isPrime[i]){
            cout<<i<<endl;
        }
    }
}
int main() {
    printPrime(23);
   return 0;
}