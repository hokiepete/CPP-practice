#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string a,b,pa,pb;
    cin >> a;
    cin >> b;
    int a_len,b_len;
    a_len = a.size();
    b_len = b.size();
    
    cout << a_len << " " << b_len << endl;
    cout << a + b << endl;
    pa=b[0];
    for(int i=1;i<a_len;i++){
        pa += a[i];
    }
    pb=a[0];
    for(int i=1;i<b_len;i++){
        pb += b[i];
    }
    cout << pa << " " << pb << endl;
    
    return 0;
}

