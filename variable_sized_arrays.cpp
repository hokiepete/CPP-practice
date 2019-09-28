#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,q,len,temp;
    vector<vector<int>> main_vec;
    vector<int> temp_vec;
    cin >> n;
    cin >> q;
    for(int i=0;i<n;i++){
        cin >> len;
        for(int j=0;j<len;j++){
            cin >> temp;
            temp_vec.push_back(temp);
        }
        main_vec.push_back(temp_vec);
        temp_vec.clear();
    }
    int i,j;
    for(int z=0;z<q;z++){
        cin >> i;
        cin >> j;
        cout << main_vec[i][j] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

