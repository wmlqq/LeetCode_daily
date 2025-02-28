#include<list>
#include<vector>
#define SIZE 100
using namespace std;
class MyHashSet {
        private:
        vector<list<int>>hashset;
        int max_size;

        int hash(int key){
            return key%max_size;
        }

        public:
            MyHashSet():hashset(SIZE),max_size(SIZE) {
                
            }
            
            void add(int key) {
                int index=hash(key);
                for(auto it=hashset[index].begin();it!=hashset[index].end();it++){
                    if(*it==key)return;
                }
                hashset[index].push_back(key);
            }
            
            void remove(int key) {
                int index=hash(key);
                hashset[index].remove(key);
            }
            
            bool contains(int key) {
                int index=hash(key);
                for(int k:hashset[index]){
                    if(k==key)return true;
                }
                return false;
            }
        };
        
        /**
         * Your MyHashSet object will be instantiated and called as such:
         * MyHashSet* obj = new MyHashSet();
         * obj->add(key);
         * obj->remove(key);
         * bool param_3 = obj->contains(key);
         */