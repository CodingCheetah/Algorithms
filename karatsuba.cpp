/*
    coded by PRATYAKSH GARG
    11-FEB-2024
*/

// Time Complexity:- O(n^1.59)
// Space Complexity:- O(logn)

#include <iostream>
#include <cmath>
using namespace std;
long long karatsuba(long long x,long long y){
    if(x<10 || y<10)
        return x*y;
    int n = max((int)log10(x) +1, (int)log10(y)+1);
    int m = n/2;
    long long high1 = x/pow(10,m);
    long long low1 = x%(long long)pow(10,m);
    long long high2 = y/pow(10,m);
    long long low2 = y%(long long)pow(10,m);
    long long z0 = karatsuba(low1,low2);
    long long z1 = karatsuba(low1+high1,low2+high2);
    long long z2 = karatsuba(high1, high2);
    return (z2 * pow(10,2*m)) + ((z1-z2-z0)*pow(10,m)) + z0;

}
int main(){
    long long num1 = 12345678, num2 = 87654321;
    cout << "Multiplication Result: " << karatsuba(num1, num2) << endl;
    return 0;
}

