using namespace std;
/*
i-th bit of integer x = ((x << i) & 1)
*/

/*
・負数に対するビット演算(C++20まで未定義動作？実装に依存するため、あまりやるべきではなさそう)
左シフト(ex. -2 << 1) → エラー
右シフト(ex. -2 >> 1 = -1) → 小さくなるが、-1より小さくならない... → (任意の負数 >> 31) = -1が成り立つ？
and(ex. -2 & 2 = 1)
*/

/*
・解説を見て
 → 1とか-1は使っていいらしい...
1 - 1みたいな演算に-1を使ってはいけないと...
*/

// 128:32
int sum(int a, int b){ // return a + b
    bool flag = false;
    int answer = 0;
    for (int i = 0; i < 11; i++){
        if ((a >> i) & 1 and (b >> i) & 1 and flag){
            answer ^= (1 << i);
            flag = true;
        }else if ((a >> i) & 1 and (b >> i) & 1){
            flag = true;
        }else if (((a >> i) & 1 or (b >> i) & 1) and flag){
            continue;
        }else if ((a >> i) & 1 or (b >> i) & 1){
            answer ^= (1 << i);
        }else if (flag){
            answer ^= (1 << i);
            flag = false;
        }
    }
    return answer;
}

int subtraction(int a, int b){ // return a - b (assuming a > b)
    bool flag = false;
    int answer = 0;
    // 8通り
    for (int i = 0; i < 11; i++){
        if ((a>>i) & 1 and (b>>i) & 1 and flag){
            answer ^= (1<<i);
            flag = true;
        }else if ((a>>i) & 1 and (b>>i) & 1 and !flag){
            continue;
        }else if (!((a>>i) & 1) and (b>>i) & 1 and flag){
            flag = true;
            continue;
        }else if (!((a>>i) & 1) and (b>>i) & 1 and !flag){
            answer ^= (1 << i);
            flag = true;
        }else if ((a>>i) & 1 and !((b>>i) & 1) and flag){
            flag = false;
        }else if ((a>>i) & 1 and !((b>>i) & 1) and !flag){
            answer ^= (1 << i);
        }else if (!((a>>i) & 1) and !((b>>i) & 1) and flag){
            answer ^= (1 << i);
            flag = true;
        }
    }
    return answer;
}

int solution1(int a, int b){ // return a + b
    int answer;
    if (a == 0){
        answer = b;
    }else if (b == 0){
        answer = a;
    }else if (a * b > 0){
        answer = (a < 0 ? -1 : 1) * sum(abs(a), abs(b));
    }else{
        if (a >= 0){
            if (abs(a) > abs(b)){
                answer = subtraction(abs(a), abs(b));
            }else{
                answer = -subtraction(abs(b), abs(a));
            }
        }else{
            if (abs(b) > abs(a)){
                answer = subtraction(abs(b), abs(a));
            }else{
                answer = -subtraction(abs(a), abs(b));
            }
        }
    }
    return answer;
}

class Solution {
public:
    int getSum(int a, int b) {
        return solution1(a, b);
    }
};
