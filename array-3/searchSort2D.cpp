#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int column = matrix[0].size();
        int val = 0;
        int i = 0, j = column - 1;
        while (i < row && j >= 0)
        {
            val = matrix[i][j];
            if (val == target)
            {
                return true;
            }
            else if (val > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int target;
    cin >> target;
    Solution object;
    bool ans = object.searchMatrix(arr, target);
    cout << ans << endl;
}