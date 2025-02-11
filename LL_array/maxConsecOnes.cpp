#include <iostream>

using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                ans = max(count, ans);
                count = 0;
            }
            else
            {
                count++;
            }
        }
        ans = max(count, ans);
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
    int ans = object.findMaxConsecutiveOnes(arr);
    cout << ans;
}