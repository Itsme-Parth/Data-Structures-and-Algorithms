class Solution
{
public:
    bool isSafe(vector<vector<int>> m, int n, int row, int col)
    {
        if (row < 0 || row >= n || col < 0 || col >= n || !m[row][col]) //checking if the cell is blocked or a wall
            return false;
        return true;
    }
    void printPathUtil(vector<vector<int>> m, int n, int row, int col, vector<string> &paths, string &currPath)
    {
        if (row == n - 1 && col == n - 1)
        {
            paths.push_back(currPath);
            return;
        }

        int i;
        int row_change[] = {1, -1, 0, 0};   //It can be either the row up or the row below
        int col_change[] = {0, 0, -1, 1};   //It can be either column to the left or to the right
        char move[] = {'D', 'U', 'L', 'R'}; //Moves the right will have to take

        for (i = 0; i < 4; i++) //Traversing through all the four possible cases
        {
            if (isSafe(m, n, row + row_change[i], col + col_change[i])) //If the cell isn't blocked
            {
                currPath.push_back(move[i]);                                                    //Push the current move
                m[row][col] = 0;                                                                //Block the current cell
                printPathUtil(m, n, row + row_change[i], col + col_change[i], paths, currPath); //calling recursively to complete the path
                m[row][col] = 1;                                                                //Undoing the changes
                currPath.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> paths;
        if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        {
            return paths;
        }
        int row = 0, col = 0;
        string currPath = "";
        printPathUtil(m, n, row, col, paths, currPath);
        sort(paths.begin(), paths.end()); //sorting the paths
        return paths;
    }
};