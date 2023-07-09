vector<int> solution1(vector<int> &nums, int target){  // O(N^2) solution
	int N = nums.size();
  vector<int> res;
  for (int i = 0; i < nums.size()-1; i++){
    for (int j = i+1; j < nums.size(); j++){
      if (nums[i] + nums[j] == target){
      	res = {i, j};
			}
    }
  }
  return res;
}

vector<int> solution2(vector<int> &nums, int target){ // O(Nlog(N)) solution
	int N = nums.size();
  vector<int> res;
  set<pair<int, int>> nums_set;
  for (int i = 0; i < N; i++){
  	nums_set.insert({nums[i], i});
  }
  for (int i = 0; i < N - 1; i++){
  	nums_set.erase({nums[i], i});
    if (nums_set.lower_bound({target - nums[i], -1}) == end(nums_set)) continue;
    auto LB = *nums_set.lower_bound({target - nums[i], -1});
    if (nums[i] + LB.first == target){
    	res = {i, LB.second};
    }
  }
  return res;
}

vector<int> solution3(vector<int> &nums, int target){ // O(Nlog(N)) solution
	int N = nums.size();
  vector<int> res(2, 0);
  std::deque<pair<int, int>> nums_index_pair(N);
  for (int i = 0; i < N; i++){
    nums_index_pair[i] = {nums[i], i};
  }
  std::sort(begin(nums_index_pair), end(nums_index_pair));
  while (nums_index_pair.size() > 1){
    int num = nums_index_pair[0].first;
    int idx = nums_index_pair[0].second;
    pair<int, int> num_idx = {target - num, -1};
    nums_index_pair.pop_front();
    if (lower_bound(begin(nums_index_pair), end(nums_index_pair), num_idx) == end(nums_index_pair)) continue;
    auto possible_candidate = *lower_bound(begin(nums_index_pair), end(nums_index_pair), num_idx);
    if (num + possible_candidate.first == target){
      res = {idx, possible_candidate.second};
    }
  }
  return res;
}


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return solution3(nums, target);
    }
};
