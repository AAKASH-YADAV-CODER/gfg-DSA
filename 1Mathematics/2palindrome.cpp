#include <bits/stdc++.h>
#include<iostream>
using namespace std;
bool palindrome(int x)
{
    int reverse = 0;
    int temp = x;
    while (temp != 0)
    {
        int ld = temp % 10;
        reverse = reverse * 10 + ld;
        temp = temp / 10;
    }
    if (reverse == x)
    {
        return true;
    }
    return false;
}
int main()
{
    cout << palindrome(1221) << endl;
    return 0;
}
// Time Complexity = theta(d)