#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N,temp,Q;
    vector<int> vec;
    cin >> N;
    while(N--){
        cin >> temp;
        vec.push_back(temp);
    }
    cin >> Q;
    vector<int>::iterator low;
    int pos;
    while(Q--){
        cin >> temp;
        low = lower_bound(vec.begin(), vec.end(), temp);
        /*
        if(vec[low-vec.begin()]==temp){
            cout << "Yes " << (low-vec.begin())+1 << endl;
        }else{
            cout << "No " << (low-vec.begin())+1 << endl;
        }
        */
        cout << (*low==temp?"Yes ":"No ") << (low-vec.begin())+1 << endl;
        
        
        /*
        if(find(vec.begin(),vec.end(),temp)!=vec.end()){
            for(int i=0;i<vec.size();i++){
                if(temp==vec[i]){
                    pos = i+1;
                    break;
                }

            }            
            cout << "Yes " << pos << endl;
        }else{
            
            cout << "No " << (low - vec.begin()) + 1 << endl;
        }
        */
    }


    return 0;
}
