using namespace std;

/*
1 <= m, n, <= 100
Binom(m + n - 2, m - 1)
(m, n) = (3, 2) -> Binom(3, 1) = 3
(m, n) = (3, 7) -> Binom(8, 2) = 8 * 7 / 2 = 28

Binom(a, b) = a * (a - 1) * ... (a - b + 1) / (b * (b - 1) ... * 1)
*/
// O((m + n)^2)
// 10:58
int solution1(int m, int n){
    // Binom(a, b)
    const int a = m + n - 2;
    const int b = min(m, n) - 1;
    int answer = 1;
    vector<bool> already(b);
    for (int i = a; i >= (a - b + 1); i--){
        answer *= i;
        for (int j = 1; j <= b; j++){
            if (already[j-1]) continue;
            if (answer % j == 0){
                answer /= j;
                already[j-1] = true;
            }
        }
    }
    return answer;
}


class Solution {
public:
    int uniquePaths(int m, int n) {
        return solution1(m, n);
    }
};
