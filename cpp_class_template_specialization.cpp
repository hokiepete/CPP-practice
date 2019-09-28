#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
template<>
struct Traits<Fruit>{
    static string name(int index){
        string output;
        if(index==0){
            output = "apple";
        }else if (index==1){
            output = "orange";
        }else if (index==2){
            output = "pear";
        }else{
            output = "unknown";
        }
        return output;
    }
};
template<>
struct Traits<Color>{
    static string name(int index){
        string output;
        if(index==0){
            output = "red";
        }else if (index==1){
            output = "green";
        }else if (index==2){
            output = "orange";
        }else{
            output = "unknown";
        }
        return output;
    }
};

// Define specializations for the Traits class template here.


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
