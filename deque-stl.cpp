#include <iostream>
#include <deque> 
using namespace std;

/*
int find_max(deque<int> dq){
    int max = 0;//dq[0];
    //cout << dq[0] << endl;
    for(int i=1;i<dq.size();i++){
        //cout << dq[i] << endl;
        if(dq[i]>max){
            max = i;//dq[i];
        }
    }
    return max;
}

//
int find_max(deque<int> dq){
    int max = dq[0];
    //cout << dq[0] << endl;
    for(int i=1;i<dq.size();i++){
        //cout << dq[i] << endl;
        if(dq[i]>max){
            max = dq[i];//dq[i];
        }
    }
    return max;
}
*/
void printKMax(int arr[], int n, int k){
    //Write your code here.
    //int max = arr[0];

    deque<int> dq;
    //dq.push_back(1);
    for(int i=0;i<k;i++){
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    //cout << arr[dq.front()] << " ";

    for(int i=k;i<n;i++){
        //cout << arr[dq.front()] << " ";
        printf("%d ",arr[dq.front()]);
        while(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }
        while(!dq.empty() && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);

    }
    //cout << arr[dq.front()] << endl;
    printf("%d\n",arr[dq.front()]);


    /*
    deque<int> dq;
    dq.push_back(arr[0]);
    int max = 0;
    for(int i=1;i<k;i++){
        dq.push_back(arr[i]);
        if(arr[i]>arr[max]){
            max = i;
        }
    }
    //int max = find_max(dq);
    //printf("%d ",dq[max]);
    cout << dq[max] << " ";
    for(int i=k;i<n;i++){
        dq.pop_front();
        max--;
        dq.push_back(arr[i]);

        if(dq.back()>dq[max]){
            max = dq.size()-1;
        }
        if(max<0){
            max = find_max(dq);
        }
        //printf("%d ",dq[max]);
        cout << dq[max] << " ";

        //cout << arr[i] << "\n";

    }
    printf("\n");

    //
    deque<int> dq;
    for(int j=0;j<k;j++){
        dq.push_back(arr[j]);
        //cout << dq.back() << endl;
    }
    printf("%d ",find_max(dq));
    //cout << find_max(dq)<< " ";
    for(int i=k;i<n;i++){
        dq.pop_front();
        dq.push_back(arr[i]);
        //cout << dq.back() << endl;
        //cout << find_max(dq)<< " ";
        printf("%d ",find_max(dq));

    }
    //cout << endl;
    printf("\n");
    */

}

int main(){
  
    int t;
    //cin >> t;
    scanf("%d",&t);
    while(t>0) {
        int n,k;
        //cin >> n >> k;
        scanf("%d %d",&n,&k);
        int i;
        int arr[n];
        for(i=0;i<n;i++)
              //cin >> arr[i];
              scanf("%d",&arr[i]);
        printKMax(arr, n, k);
        t--;
      }
      return 0;
}

