#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    int a;
    char ch;
    stringstream ss(str);;
    vector<int> integers;
    while(ss.rdbuf()->in_avail()!=0){
        ss >> a >> ch;
        integers.push_back(a);
    }
    //ss >> a >> ch >> b >> ch >> c;
    // = {a,b,c};
    return integers;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

