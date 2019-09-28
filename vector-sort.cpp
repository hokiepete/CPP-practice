#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> vec;
    int N;
    int input;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input;
        vec.push_back(input);

    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<N;i++){
        cout << vec[i] << " ";
    }
    return 0;

}
