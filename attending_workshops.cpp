#include<bits/stdc++.h>

using namespace std;
#include<vector>
#include<algorithm>
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops{
    int n;
    //vector<Workshops> work_array;
    Workshops* work_array;
};

Available_Workshops* initialize(int* start_time,int* duration,int n){
    Available_Workshops* output = new Available_Workshops;
    output->n = n;
    output->work_array = new Workshops[n];
    for(int i =0;i<n;i++){
        /*
        Workshops temp;
        temp.start_time = start_time[i];
        temp.duration = duration[i];
        temp.end_time = start_time[i]+duration[i];
        output->work_array.push_back(temp);
        */
        output->work_array[i].start_time = start_time[i];
        output->work_array[i].duration = duration[i];
        output->work_array[i].end_time = start_time[i]+duration[i];
        //*/
    }
    return output;
}

bool compare(Workshops &w1,Workshops &w2){
    return w1.end_time < w2.end_time;

}

int CalculateMaxWorkshops(Available_Workshops* input){
    sort(input->work_array,input->work_array+input->n,compare);
    int max_workshops = 0;
    int end_time = 0;
    for(int i=0;i<input->n;i++){
        if(input->work_array[i].start_time>=end_time){
            max_workshops++;
            end_time = input->work_array[i].end_time;
        }
    }
    return max_workshops;
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
