#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> arr)
    {
        int ans = 0;
        int count = 1;
        for (int num : arr)
        {
            if (num == ans)
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    ans = num;
                    count = 1;
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
    int ans = object.majorityElement(arr);
    cout << ans << endl;
}