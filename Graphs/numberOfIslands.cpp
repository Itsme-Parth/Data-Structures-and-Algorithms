class Solution
{
    void checkIslandSize(vector<vector<char>> &matrix, int rows, int cols, int currRow, int currCol)
    {
        //Boundary case for matrix
        if (matrix[currRow][currCol] != '1' || currRow < 0 || currCol < 0 || currRow >= rows || currCol >= cols)
            return;
        //Mark current cell as visited
        matrix[currRow][currCol] = 2;

        /*
            int r[] = {1,-1,0,0};
            int c[] = {0,0,1,-1};
            
            for(int k=0; k<4; k++)
            {
                mark_current_islands(g, i + r[k], j + c[k], rows, cols);
            }
        */

        // Make recursive call in all 4 adjacent directions
        checkIslandSize(matrix, rows, cols, currRow - 1, currCol);
        checkIslandSize(matrix, rows, cols, currRow + 1, currCol);
        checkIslandSize(matrix, rows, cols, currRow, currCol - 1);
        checkIslandSize(matrix, rows, cols, currRow, currCol + 1);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        if (rows == 0) //Empty grid boundary case
            return 0;
        int cols = grid[cols].size();

        //Iterate for all cells of the array
        int islandNum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    checkIslandSize(grid, rows, cols, i, j);
                    islandNum++;
                }
            }
        }
        return islandNum;
    }
};