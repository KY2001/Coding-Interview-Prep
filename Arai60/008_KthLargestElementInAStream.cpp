#include<bits/stdc++.h>

using namespace std;

// 19:40
// Time: O(nlog(n)) for KthLargest
// Time: O(log(n)) for add

// Space: O(n)

class KthLargest {
  private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
  public:
    KthLargest(int k, vector<int>& nums) {
      k = k;

      for (const int num: nums) {
        pq.push(num);
      }

      while(pq.size() > k) {
        pq.pop();
      }

      while(pq.size() < k) {
        pq.push(-INT_MAX);
      }
    }

    int add(int val) {
      const int current_kth_largest = pq.top();
      if (val <= current_kth_largest) {
        return current_kth_largest;
      }

      pq.pop();
      pq.push(val);
      return pq.top();
    }
};
