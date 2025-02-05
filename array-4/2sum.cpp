#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mppos;
        for (int i = 0; i < n; i++)
        {
            int search = target - nums[i];
            if (mppos.find(search) != mppos.end())
            {
                ans.push_back(i);
                ans.push_back(mppos[search]);
                return ans;
            }
            mppos[nums[i]] = i;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    Solution object;
    vector<int> ans = object.twoSum(arr, target);
    for (int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }
}