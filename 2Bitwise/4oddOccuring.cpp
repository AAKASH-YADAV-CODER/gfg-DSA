#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//1Method Naive sol Function to find the element
// occurring odd number of times
/*

int getOddOccurrence(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++) {

        int count = 0;

        for (int j = 0; j < arr_size; j++) {
            if (arr[i] == arr[j])
                count++;
        }
        if (count % 2 != 0)
            return arr[i];
    }
    return -1;
}

*/


//2 this is by xor property i> x^x=0 ii>x^0=x

int getOddOccurrence(int arr[],int n){
    int firstEle=arr[0];
    for(int i=1;i<n;i++){
        firstEle=firstEle^arr[i];
    }
    return firstEle;
}


// driver code
int main()
{
    int arr[] = { 2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]);//1 element = 4byte so 52/4=13;

    // Function calling
    cout << getOddOccurrence(arr, n)<<endl;

    return 0;
}