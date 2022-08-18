#include <bits/stdc++.h>
// #include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {

/*
  sort(nums.begin(), nums.end());
  int i = 0;
  int j = nums.size() - 1;

  while (i < j) {
    cout << i << " " << j << endl;
    int sum = nums[i] + nums[j];
    cout << sum << endl;
    if (sum < target) {
      i++;
    } else if (sum > target) {
      j--;
    } else if (sum == target) {
      vector<int> ans;
      ans.push_back(i);
      ans.push_back(j);
      return ans;
    }
  }
  vector<int> ans;
  ans.push_back(-1);
  ans.push_back(-1);
  return ans;
*/
  /*
  vector<int> ans;
  for (int i = 0; i < nums.size(); i++) {
    int el = nums[i];
    for (int j = i+1; j < nums.size(); j++) {
      if (target == (el + nums[j])) {
        ans.push_back(i);
        ans.push_back(j);
        return ans;
      }
    }
  }
  ans.push_back(-1);
  ans.push_back(-1);
  return ans;
  */
}

int main() {
  vector<int> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int el;
    cin >> el;
    v.push_back(el);
  }
  vector<int> ans = twoSum(v, 7);
  cout << "ans: " << v[ans[0]] << " " << v[ans[1]] << endl;
  cout << "ans: " << ans[0] << " " << ans[1] << endl;
  return 0;
}