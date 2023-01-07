using namespace std;

/*
1: 1
2: 10
3: 11
4: 100
5: 101
6: 110
7: 111
8: 1000
9: 1001
10: 1010
11: 1011
12: 1100
13: 1101
14: 1110
15: 1111
[1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4]
*/

// O(n)
// 10:07
vector<int> solution1(const int n){
    vector<int> answer = {0, 1};
    vector<int> now = {1};
    vector<int> now_next;
    while(answer.size() < n + 1){
        now_next.clear();
        for (auto num : now){
            answer.emplace_back(num);
            now_next.emplace_back(num);
        }
        for (auto num : now){
            answer.emplace_back(num+1);
            now_next.emplace_back(num+1);
        }
        now = now_next;
    }
    while(answer.size() > n + 1){
        answer.pop_back();
    }
    return answer;
}

// O(nlogn)
// 13:26
vector<int> solution2(const int n){
    vector<int> answer;
    for (int i = 0; i <= n; i++){
        answer.emplace_back(__builtin_popcount(i));
    }
    return answer;
}

class Solution {
public:
    vector<int> countBits(int n) {
        return solution1(n);
    }
};
