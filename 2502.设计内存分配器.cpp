#include<vector>
using namespace std;
class Allocator {
    private:
        vector<int> memoryID;
        int n;

    public:
        Allocator(int n):n(n),memoryID(n,-1) {
            
        }
        
        int allocate(int size, int mID) {
            int firstFree=-1,countFree=0;
            for(int i=0;i<n;i++){
                if(memoryID[i]==-1){
                    if(firstFree==-1){
                        firstFree=i;
                    }
                    countFree++;
                }
                else{
                    countFree=0;
                    firstFree=-1;
                }
                if(countFree==size){
                    for(int j=firstFree;j<firstFree+size;j++){
                        memoryID[j]=mID;
                    }
                    return firstFree;
                }
            }
            return -1;
        }
        
        int freeMemory(int mID) {
            int count=0;
            for(int i=0;i<n;i++){
                if(memoryID[i]==mID){
                    memoryID[i]=-1;
                    count++;
                }
            }
            return count;
        }
    };
    
    /**
     * Your Allocator object will be instantiated and called as such:
     * Allocator* obj = new Allocator(n);
     * int param_1 = obj->allocate(size,mID);
     * int param_2 = obj->freeMemory(mID);
     */