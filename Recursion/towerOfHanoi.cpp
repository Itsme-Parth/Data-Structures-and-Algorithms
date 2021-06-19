class Solution
{
public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    int cnt = 0;
    long long toh(int N, int from, int to, int aux)
    {
        cnt++;
        if (N == 1)
        {
            cout << "move disk " << N << " from rod " << from << " to rod " << to << "\n";
            return cnt;
        }
        toh(N - 1, 1, 2, 3);                                                           //Hypothesis of shifting n - 1 to helper rod
        cout << "move disk " << N << " from rod " << from << " to rod " << to << "\n"; //from source to destination
        toh(N - 1, 2, 3, 1);
        return cnt;
    }
};