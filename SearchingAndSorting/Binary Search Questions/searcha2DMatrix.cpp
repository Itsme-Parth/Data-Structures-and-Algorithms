class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int key)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int i = 0, j = m - 1;
        while (i >= 0 && i < n && j >= 0 && j < m) //keeping it in the bounds of the matrix
        {
            if (matrix[i][j] == key) //if found return true
                return true;
            else if (matrix[i][j] > key) //if greater move to left
                j--;
            else if (matrix[i][j] < key) //if smaller move down
                i++;
        }
        return false; //else return false
    }
};