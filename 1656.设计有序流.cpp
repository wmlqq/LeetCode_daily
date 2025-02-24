#include<string>
#include<vector>
using namespace std;
class OrderedStream {
    private:
        int ptr;
        vector<string>stream;

    public:
        OrderedStream(int n) :stream(n+1,""),ptr(1) {
        }
        
        vector<string> insert(int idKey, string value) {
            vector<string>result;
            stream[idKey]=value;
            if(idKey==ptr){
                while(ptr<stream.size()&&stream[ptr]!=""){
                    result.push_back(stream[ptr]);
                    ptr++;
                }
            }
            return result;
        }
    };
    
    /**
     * Your OrderedStream object will be instantiated and called as such:
     * OrderedStream* obj = new OrderedStream(n);
     * vector<string> param_1 = obj->insert(idKey,value);
     */