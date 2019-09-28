#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,temp,a,b;
    cin >> N;
    vector<int> vec;
    for(int i=0;i<N;i++){
        cin >> temp;
        vec.push_back(temp);
    }

    cin >> temp;
    if(temp < vec.size()){
        vec.erase(vec.begin()+temp-1);
    }
    cin >> a >> b;
    if(a<b && b<vec.size()){
        vec.erase(vec.begin()+a-1,vec.begin()+b-1);
    }
    cout << vec.size() << endl;
    //for(int i=0;i<vec.size();i++){
    for(auto elem : vec){
        cout << elem << " ";
    }
    

    return 0;
}
