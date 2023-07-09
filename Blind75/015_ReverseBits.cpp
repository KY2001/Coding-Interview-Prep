using namespace std;

// O(1)
// 14:00
uint32_t solution1(uint32_t n){
    uint32_t answer = 0;
    for (int i = 0; i < 32; i++){
        answer += (((n >> i) & 1) << (31 - i));
    }
    return answer;
}

uint32_t
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        return solution1(n);
    }
};
