#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to find all unique quadruplets that sum up to the target
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans; // Stores the resulting quadruplets
        int n = nums.size();     // Get the size of the input array

        // Sort the array to facilitate the two-pointer approach
        sort(nums.begin(), nums.end());

        // First loop to select the first number
        for (int i = 0; i < n; i++)
        {
            // Skip duplicate elements to avoid duplicate quadruplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Second loop to select the second number
            for (int j = i + 1; j < n; j++)
            {
                // Skip duplicate elements to avoid duplicate quadruplets
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                long long sum = nums[i] + nums[j]; // Store the sum of the first two numbers
                int k = j + 1;                     // Left pointer
                int l = n - 1;                     // Right pointer

                // Two-pointer approach to find the remaining two numbers
                while (k < l)
                {
                    long long total = sum + nums[k] + nums[l]; // Compute the total sum of four numbers

                    // If the sum matches the target, store the quadruplet
                    if (total == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        // Skip duplicate values for the third number
                        while (k < l && nums[k] == nums[k + 1])
                            k++;

                        // Skip duplicate values for the fourth number
                        while (k < l && nums[l] == nums[l - 1])
                            l--;

                        k++; // Move left pointer forward
                        l--; // Move right pointer backward
                    }
                    else if (total < target)
                    {
                        k++; // Increase sum by moving left pointer
                    }
                    else
                    {
                        l--; // Decrease sum by moving right pointer
                    }
                }
            }
        }
        return ans; // Return all valid quadruplets
    }
};

int main()
{
    int n;
    cin >> n;           // Take input for the size of the array
    vector<int> arr(n); // Create a vector to store the array elements

    // Take input for array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target; // Take input for the target sum

    Solution object;                                       // Create an instance of the Solution class
    vector<vector<int>> ans = object.fourSum(arr, target); // Call the fourSum function

    // Print the resulting quadruplets
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}