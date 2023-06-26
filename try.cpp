class Solution
{
public:
    int solve(bool Alice, int i, int capacity, vector<int> &v, int n, vector<vector<int>> &dp)
    {
        if (i >= n)
        {
            // 1st unpicked index is out of bounds
            return 0;
        }
        int res = 0;
        // dp table 0th row is alice and 1st row is bob
        // dp[0][i] for alice at ith index
        if (Alice == true)
        {
            int memo = dp[0][i];
            if (memo != 0)
            {
                return memo;
            }
            // its alices turn to play
            // we gonna return max of all scores returned by all branches
            // hence set res to int min
            res = INT_MIN;
            // x denotes how many elements picked by alice => [1st] or [1st , 2nd] or [1,2,3]
            // at x==0 pick v[i]
            // at x==1 pick v[i]+v[i+1]
            // at x==2 pick v[i] +v[i+1]+v[i+2]
            // store a prefix array
            int prefix = 0;
            for (int x = 0; x < capacity; x++)
            {
                if (i + x < n)
                {
                    prefix += v[i + x];
                    // we send i+x+1 to recursive call
                    int score = prefix + solve(false, i + x + 1, 3, v, n, dp);
                    res = max(res, score);
                }
            }
            dp[0][i] = res;
            return res;
        }
        else
        {
            // we are playing for bob hence from all the alice scores we get from next branch we will return the min score
            int memo = dp[1][i];
            if (memo != 0)
            {
                return memo;
            }
            res = INT_MAX;
            for (int x = 0; x < capacity; x++)
            {
                res = min(res, solve(true, i + x + 1, 3, v, n, dp));
            }
            dp[1][i] = res;
            return res;
        }
    }

    string stoneGameIII(vector<int> &v)
    {

        // 3 variables to keep track of
        //  1. whose turn it is
        //  2. current unpicked index i
        //  3. maximum capacity of pick (which is 3 throughout the problem)
        int n = v.size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        int i = 0, capacity = 3;
        int AliceScore = solve(true, i, capacity, v, v.size(), dp);
        int total = 0;
        for (int i = 0; i < v.size(); i++)
        {
            total += v[i];
        }
        int BobScore = total - AliceScore;
        cout << "Alice Score: " << AliceScore << "  BobScore: " << BobScore << endl;
        if (BobScore == AliceScore)
        {
            return "Tie";
        }
        else if (BobScore > AliceScore)
        {
            return "Bob";
        }
        else
        {
            return "Alice";
        }
    }
};