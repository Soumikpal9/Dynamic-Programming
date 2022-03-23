/*

        Problem Description

        Given a M x N grid A of integers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

        Return the minimum sum of the path.

        NOTE: You can only move either down or right at any point in time.



        Problem Constraints

        1 <= M, N <= 2000

        -1000 <= A[i][j] <= 1000



        Input Format

        First and only argument is a 2-D grid A.



        Output Format

        Return an integer denoting the minimum sum of the path.



        Example Input

        Input 1:

        A = [
            [1, 3, 2]
            [4, 3, 1]
            [5, 6, 1]
            ]
        Input 2:

        A = [
            [1, -3, 2]
            [2, 5, 10]
            [5, -5, 1]
            ]


        Example Output

        Output 1:

        8
        Output 2:

        -1


        Example Explanation

        Explanation 1:

        The path will be: 1 -> 3 -> 2 -> 1 -> 1.
        Input 2:

        The path will be: 1 -> -3 -> 5 -> -5 -> 1.

*/

int minSumPath(vector<vector<int>> &A, int i, int j, vector<vector<int>> &dp){
    if(i==0 && j==0)    return A[i][j];
    if(i<0 || j<0)  return 2e7;
    if(dp[i][j]!=2e7)   return dp[i][j];
    dp[i][j]=A[i][j]+min(minSumPath(A, i, j-1, dp), minSumPath(A, i-1, j, dp));
    return dp[i][j];
}

int Solution::solve(vector<vector<int>> &A){
    vector<vector<int>> dp(A.size(), vector<int> (A[0].size(), 2e7));
    return minSumPath(A, A.size()-1, A[0].size()-1, dp);
}