using namespace std;

// 02:24
// O(1)
int solution1(uint32_t n){
    int answer = 0;
    for (int i = 0; i < 32; i++){
        answer += (n >> i) & 1;
    }
    return answer;
}

// O(1)
// 03:42
int solution2(uint32_t n){
    return __builtin_popcount(n);
}

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return solution2(n);
    }
};
