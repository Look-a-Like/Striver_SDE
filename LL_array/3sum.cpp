#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicates for the first element

            int target = -nums[i];
            int left = i + 1, right = n - 1;

            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1])
                        left++; // Skip duplicates for the second element
                    while (left < right && nums[right] == nums[right - 1])
                        right--; // Skip duplicates for the third element

                    left++;
                    right--;
                }
                else if (sum < target)
                {
                    left++; // Increase sum
                }
                else
                {
                    right--; // Decrease sum
                }
            }
        }
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
    vector<vector<int>> ans = object.threeSum(arr);

    for (const auto &triplet : ans)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}