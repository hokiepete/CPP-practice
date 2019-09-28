#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, S, P, Q;
    scanf("%d %d %d %d",&N,&S,&P,&Q);
    int arr,check; 
    int div = pow(2,31);
    int n=0;
    arr = S % div;
    for(int i=0;i<N;i++){
        check = arr*P + (Q % div);
        if(arr != check){
            arr = check;
            n++;
        }
        else{
            break;
        }
    }
    //int len;
    //len = min(n,N);
    cout << n;//len;
    return 0;
}
