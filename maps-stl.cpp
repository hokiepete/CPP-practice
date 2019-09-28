#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int Q,type, Y;
    string X;
    map<string, int> mp;
    cin >> Q;
    while(Q--){
        cin >> type >> X;
        //cout << Q << " " << X << endl;
        map<string,int>::iterator itr=mp.find(X);
        switch(type){
            case 1:
                //cout << "here 1" << endl;
                cin >> Y;
                if(itr==mp.end()){
                    //mp.insert(make_pair(X,Y));
                    mp[X] = Y;
                }else{
                    //mp.insert(make_pair(X,mp[X]+Y));
                    mp[X] += Y;
                }
                break;
            case 2:
            //cout << "here 2" << endl;
                if(itr!=mp.end()){
                    mp.erase(X);
                }
                break;
            case 3:
            //cout << "here 3" << endl;
                if(itr!=mp.end()){
                    cout << mp[X] << endl;
                }else{
                    cout << 0 << endl;
                }
                break;
        } 

    }
    return 0;
}



