#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		/* Enter your code here */
        cout << hex << showbase << nouppercase << left << (long long) A << endl;
        
        cout << right << setw(15) << setfill('_') << showpos << dec << fixed << setprecision(2) <<  B << endl;
        cout.precision(9);
        cout << noshowpos << uppercase << scientific << C << endl;


	}
	return 0;

}