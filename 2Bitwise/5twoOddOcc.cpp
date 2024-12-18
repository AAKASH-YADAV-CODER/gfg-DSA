#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//if we do cout then it give two num which are odd 
/*
int twoOddOccurr(int arr[],int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count%2!=0){
            return arr[i];
        }
    }
    return -1;
}
*/


//2 Method we using tactic which is x&(~(x-1)) this will give the left bit is set at given position of x have the left set bit
void twoOddOccurr(int arr[],int n){
    int x=0;
    for(int a=0;a<n;a++)
        x=x^arr[a];
    

    int k=(x&(~(x-1)));//tactic so k have same left set bit as x have .
    cout<<k<<"This is k value"<<endl;
    int res1=0,res2=0;
    for(int z=0;z<n;z++){
        if((arr[z]&k) != 0)// this will give left bit as 1 bit
            res1=res1^arr[z];
        else                //this give left bit as 0 bit
            res2=res2^arr[z];
    }
    // return (res1,res2);
    cout<<res1<<endl<<res2<<endl;

}
int main() {
    int arr[] = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7, 5};
    int n=sizeof(arr)/sizeof(arr[0]);

    // cout<<twoOddOccurr(arr,n)<<endl;
    twoOddOccurr(arr,n);
   return 0;
}