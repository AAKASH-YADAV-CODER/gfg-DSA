#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//Efficient Solution
/** 
bool isSorted(int arr[],int size){
    for(int i=1;i<size;i++){
        if(arr[i]<arr[i-1]){
            return false;
        }
    }
    return true;
}
*/
//Efficient Solution By me 
bool isSorted(int arr[],int size){
    int firstEle=0;
    for(int a=1;a<size;a++){
        if(arr[a]<arr[firstEle]){
            return false;
            
        }else{
            firstEle++;
        }
    }
    return true;
}
int main() {
    // int n=6;
    int arr[]={1,2,13,4,5,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr,size)<<endl;
    
   return 0;
}