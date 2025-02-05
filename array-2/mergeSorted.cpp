#include <iostream>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> arr(m + n);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                arr[k++] = nums1[i++];
            }
            else
            {
                arr[k++] = nums2[j++];
            }
        }
        while (i < m)
        {
            arr[k++] = nums1[i++];
        }
        while (j < n)
        {
            arr[k++] = nums2[j++];
        }
        nums1 = arr;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    Solution object;
    object.merge(arr1, n, arr2, m);
    for (int i = 0; i < n + m; i++)
    {
        cout << arr1[i] << " ";
    }
}