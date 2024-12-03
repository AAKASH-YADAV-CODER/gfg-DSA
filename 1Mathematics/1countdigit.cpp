#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int countDigit(int x)
{
    int digit = 0;
    while (x != 0)
    {
        x = x / 10;
        digit++;
    }
    return digit;
}
int main()
{
    cout << countDigit(1) << endl;
    return 0;
}
// Time Complexity = theta(d) where d is digit it mean for every digit it take d time's