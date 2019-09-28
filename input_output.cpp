#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    float a, b, c;
    //cout << "Please enter 3 numbers between 1 and 1000, separated by a space.\n";
    cin >> a >> b >> c;
    if(a<1 || a>1000 || b<1 || b>1000 || c<1 || c>1000 ){
        cout << "numbers must be between 1 and 1000.\n";
    }
    else{
        cout << a + b + c << "\n";
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
