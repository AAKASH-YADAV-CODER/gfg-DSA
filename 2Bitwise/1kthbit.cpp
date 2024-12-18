#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//We need to check the kth bit is set or not there are two way of doing it by dividing and by multiplying 



//1 by multipy method means 2^k-1 = number which have set bit at kth position
void isSet(int n,int k){
    /*
    int x=1;
    for(int i=0;i<(k-1);i++)
        x=x*2;
    */
    int x=1<<(k-1);
    if( (n&x) !=0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}


//2 by divide method means 2^k-1 times we need to divide to get the kth bit at last and then we check by n&1 that last bit set or not
void isSetD(int n,int k){//Time Complexity theta(k)
    /*
    for(int a=0;a<k-1;a++)
        n=n/2;
    Or */
    int x=n>>(k-1);
    if((x&1) !=0)
        cout<<"yes"<<endl;
    else
        cout<<"No"<<endl;
}


int main() {
    // isSet(5,1);
    isSetD(5,3);
   return 0;
}