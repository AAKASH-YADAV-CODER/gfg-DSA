#include<bits/stdc++.h>
#include<iostream>
using namespace std;

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
//1 Method in O(n)
/*
void printPrime(int n){
   for(int i=2;i<n;i++){
      if(prime(i)){
         int x=i;
         while(n%x==0){
            cout<<i<<endl;
            x=x*i;
         }
      }
   }
}
*/
//2 Method in O(sqrt(n))
/*
void printPrime(int n){
   for(int i=2;i*i<=n;i++){
      if(prime(i)){
         while(n%i==0){
            cout<<i<<endl;
            n=n/i;
         }
      }
   }
}
*/


//3 Method more optimize
void printPrime(int n){
   if(n==1 || n<0){
      cout<<"this is Not prime Number"<<endl;
   }
   if(n%2==0){
      cout<<2<<endl;
      n=n/2;
   }
   if(n%3==0){
      cout<<3<<endl;
      n=n/3;
   }
   for(int i=5;i*i<=n;i+=6){
      while(n%i==0){
         cout<<i<<endl;
         n=n/i;
      }
      while(n%(i+2)==0){
         cout<<(i+2)<<endl;
         n=n/(i+2);
      }
   }
}
int main() {
   printPrime(1092);
   return 0;
}