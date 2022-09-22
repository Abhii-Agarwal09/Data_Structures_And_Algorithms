#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  vector<int> temp;
  int i = 0, j = 0;
  while (i <= m && j <= n)
  {
    if (nums1[i] < nums2[j])
    {
      temp.push_back(nums1[i++]);
    }
    else if (nums1[i] > nums2[j])
    {
      temp.push_back(nums2[j++]);
    }
    else if (nums1[i] == nums2[j])
    {
      temp.push_back(nums1[i++]);
      temp.push_back(nums2[j++]);
    }
  }
  nums1.clear();
  for (int i = 0; i < m+n; i++) {
    nums1[i] = temp[i];
  }
  // for (int i = 0; i < (m + n); i++)
  // {
  //   cout << temp[i] << " ";
  // }
  cout << endl;
}

int main()
{
  vector<int> nums1;
  vector<int> nums2;

  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int el;
    cin >> el;
    nums1.push_back(el);
  }

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int el;
    cin >> el;
    nums2.push_back(el);
  }

  for (int i = 0; i < (m + n); i++)
  {
    cout << nums1[i] << " ";
  } cout << endl;

  merge(nums1, m, nums2, n);

  for (int i = 0; i < (m + n); i++)
  {
    cout << nums1[i] << " ";
  } cout << endl;
  return 0;
}