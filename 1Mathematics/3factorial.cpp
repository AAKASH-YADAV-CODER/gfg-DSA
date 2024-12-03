#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int factorial(int x)
{
    // This is by iteration method
    //  int result = 1;
    //  for (int i = 2; i <= x; i++)
    //  {
    //      result = result * i;
    //  }
    //  return result;

    // This is by recursive method but above one is better
    if (x == 0)
    {
        return 1;
    }
    return x * factorial(x - 1);
}
int main()
{
    cout << factorial(3) << endl;
    return 0;
}
// TC= theta(n);