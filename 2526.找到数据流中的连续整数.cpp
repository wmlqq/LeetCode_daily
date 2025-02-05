class DataStream {
private:
    int value;      // 目标值
    int k;          // 连续数量要求
    int count;      // 当前连续的目标值数量

public:
    DataStream(int value, int k) : value(value), k(k), count(0) {}
    
    bool consec(int num) {
        if (num == value) {
            count++;
        } else {
            count = 0;
        }
        return count >= k;
    }
};