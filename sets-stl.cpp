#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N,x,y;
    set<int> s;
    cin >> N;
    while(N--){
        cin >> y >> x;
        if(y==1){
            s.insert(x);
        }else{
            auto it = s.find(x);
            if(y==2 && it!=s.end()){
                s.erase(x);
            }else if(y==3 && it!=s.end()){
                cout << "Yes" << endl;
            }else if(y==3 && it==s.end()){
                cout << "No" << endl;
            }

        }

    }
    return 0;
}



