#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// 1 Method Naive Sol in O(n^2)
int largestNumIndex1(int arr[],int n){
    for(int i=0;i<n;i++){
        bool flage=true;
        for(int j=0;j<n;j++){
            if(arr[j]>arr[i])
                flage=false;
        }
        if(flage==true){
            return i;
        }
    }
    return -1;
}
// 2 Method Efficient Sol in O(n)
int largestNumIndex(int arr[],int n){
    int res=0;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[res]){
            res=i;
        }
    }
    return res;
}

int main() {
    int arr[]={1,2,32,45,5,65};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<largestNumIndex(arr,n)<<endl;
    cout<<"hi aakash"<<endl;
   return 0;
};