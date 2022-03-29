/*

        Problem Description

        You are given a set of coins A. In how many ways can you make sum B assuming you have infinite amount of each coin in the set.

        NOTE:

        Coins in set A will be unique. Expected space complexity of this problem is O(B).
        The answer can overflow. So, return the answer % (106 + 7).


        Problem Constraints

        1 <= A <= 500
        1 <= A[i] <= 1000
        1 <= B <= 50000



        Input Format

        First argument is an integer array A representing the set.
        Second argument is an integer B.



        Output Format

        Return an integer denoting the number of ways.



        Example Input

        Input 1:

        A = [1, 2, 3]
        B = 4
        Input 2:

        A = [10]
        B = 10


        Example Output

        Output 1:

        4
        Output 2:

        1


        Example Explanation

        Explanation 1:

        The 4 possible ways are:
        {1, 1, 1, 1}
        {1, 1, 2}
        {2, 2}
        {1, 3} 
        Explanation 2:

        There is only 1 way to make sum 10.

*/

int mod=1e6+7;

int coinSum(vector<int> &A, int i, int j, vector<vector<int>> &dp){
    if(i==0 && j==0)    return 1;
    if(i==0)    return 0;
    if(j==0)    return 1;
    if(dp[i][j]!=-1)    return dp[i][j];
    dp[i][j]=coinSum(A, i-1, j, dp)%mod;
    if(j>=A[i-1]){
        dp[i][j]=(dp[i][j]+coinSum(A, i, j-A[i-1], dp))%mod;
    }
    return dp[i][j];
}

int Solution::solve(vector<int< &A, int B){
    vector<vector<int>> dp(A.size()+1, vector<int> (B+1, -1));
    return coinSum(A, A.size(), B, dp);
}
