#include <iostream>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int ans = 1;
        int n = nums.size();
        vector<int> anss;
        anss.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                ans++;
                anss.push_back(nums[i]);
            }
            else
            {
            }
        }
        nums = anss;
        return ans;
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
    Solution object;
    int ans = object.removeDuplicates(arr);
    cout << ans;
}