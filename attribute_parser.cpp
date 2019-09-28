#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;

string remove_last_seg(string name){
    int loop = 1;
    while(loop){
        if(name.back()!='.'){
            name.pop_back();
        }
        else{
            name.pop_back();
            loop = 0;
        }
    }
    return name;
}

//void build_database(map<string,string>& database,int N){
 map<string,string> build_database(int N){
    map<string,string> database;
    string inputstr;
    string name, new_name;
    string attrib, value,eq,key;
    int loop;
    int segments = 0;
    for (int i=0;i<N;i++) {
        getline(cin,inputstr);
        stringstream ss(inputstr);
        ss >> new_name;
        new_name = new_name.substr(1);
        if(new_name[0]!='/'){
            segments++;
            if(name.size()==0){
                name = new_name;
            }
            else {
                name = name + '.' + new_name;
            }
            if(name.back()=='>'){
                name.pop_back();
            }
            //cout << "name is " << name << endl;
            loop = 1;
            while(loop){
                ss >> attrib;
                //cout << "attrib is " << attrib << endl;
                if(attrib == ""){
                    break;
                }
                ss >> eq >> value;
                if(value.back()=='>'){
                    loop=0;
                    value = value.substr(1);
                    value.pop_back();
                    value.pop_back();
                }
                else {
                    value = value.substr(1);
                    value.pop_back();
                }
                key = name+'.'+attrib;
                database[key] = value;
                //cout << key << " is " << database[key] << endl;
                key.clear();
                attrib.clear();
            }
        }
        else {
            //cout << "seg" << segments << endl;
            if(segments>1){
                name = remove_last_seg(name);
            }
            else{
                name.clear();
            }
            segments--;
        }
    }
    return database;
}

void query_database(map<string,string>& database,int Q){
    string inputstr, output;
    for (int i=0;i<Q;i++) {
        getline(cin,inputstr);
        if(inputstr.find('~')!=inputstr.npos){
            replace(inputstr.begin(),inputstr.end(), '~', '.');
        }


        output = database[inputstr];
        if(output == ""){
            output = "Not Found!";
        }
        cout << output << endl;
    }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N,Q;
    scanf("%d %d",&N,&Q);
    cin.ignore();
    map <string,string> database = build_database(N);


    //for(map<string,string>::const_iterator it = database.begin();it != database.end();++it){std::cout << it->first << "\n" << database[it->first] << endl;}

    //cout<< database["a.b.name"] << database["a.b.c.value"] << database["a.b.c.src"] << database["a.b.c.d.name"] << endl;
    query_database(database, Q);
    return 0;
}
