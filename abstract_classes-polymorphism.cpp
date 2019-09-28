#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache{
    public:
        LRUCache(int capacity){
            cp = capacity;
        }
        void set(int key, int value) override{
            if(cp<=0){
                return;
            }
            //cout << key << " " << value << endl;
            Node* N;
            if(mp.empty()){ // if Empty
                //cout << "list empty" << endl;
                N = new Node(key,value);
                head = tail = N;
                mp[key] = N;
            }else if(mp.size()<cp){ //if not empty and not full
                //cout << "list not empty not full" << endl;
                if(!mp.count(key)){ //if key is not in list
                    //cout << "new key" << endl;
                    N = new Node(NULL,head,key,value);
                    head->prev = N;
                    head = N;
                    mp[key] = N;
                }else{
                    //cout << "old key" << endl;
                    N = mp[key];
                    if(N==head){
                        N->value = value;
                    }else if(N==tail){
                        N->prev->next = NULL;
                        tail = N->prev;
                        N->next = head;
                        N->prev = NULL;
                        head->prev = N;
                        head = N;
                        N->value = value;
                    }else{
                        N->prev->next = N->next;
                        N->next->prev = N->prev;
                        head->prev = N;
                        head = N;
                        N-> prev = NULL;        
                        N->value = value;                
                    }
                }

            }else{ // if full
                //cout << "list full" << endl;
                tail = tail->prev;
                mp.erase(tail->next->key);
                delete tail->next;
                tail->next = NULL;
                if(!mp.count(key)){ //if key is in list
                    //cout << "new key" << endl;
                    N = new Node(NULL,head,key,value);
                    head->prev = N;
                    head = N;
                    mp[key] = N;
                    
                }else{
                    //cout << "old key" << endl;
                    N = mp[key];
                    if(N==head){
                        N->value = value;
                    }else{
                        N->prev->next = N->next;
                        N->next->prev = N->prev;
                        head->prev = N;
                        head = N;
                        N-> prev = NULL;
                        N->value = value;                        
                    }
 
                }

            }
        }
        int get(int key) override{
            int out=-1;
            if(mp.count(key)){
                Node* N = mp[key];
                out = N->value;
            }
            return out;
        }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
