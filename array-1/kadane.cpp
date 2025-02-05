#include <iostream>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0, maxSum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (sum + nums[i] > nums[i])
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
            }
            maxSum = max(sum, maxSum);
            return maxSum;
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
    Solution object;
    int maxSum = object.maxSubArray(arr);
    cout << maxSum << endl;
}