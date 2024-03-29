/*

        Problem Description

        You are climbing a stair case and it takes A steps to reach to the top.

        Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



        Problem Constraints

        1 <= A <= 36



        Input Format

        The first and the only argument contains an integer A, the number of steps.



        Output Format

        Return an integer, representing the number of ways to reach the top.



        Example Input

        Input 1:

        A = 2
        Input 2:

        A = 3


        Example Output

        Output 1:

        2
        Output 2:

        3


        Example Explanation

        Explanation 1:

        Distinct ways to reach top: [1, 1], [2].
        Explanation 2:

        Distinct ways to reach top: [1 1 1], [1 2], [2 1].

*/

int climbStairsHelper(int n, vector<int> &dp){
    if(n<=2)    return n;
    if(dp[n]!=-1)   return dp[n];
    dp[n]=climbStairsHelper(n-1, dp)+climbStairsHelper(n-2, dp);
    return dp[n];
}

int Solution::solve(int A){
    vector<int> dp(A+1, -1);
    return climbStairsHelper(A, dp);
}