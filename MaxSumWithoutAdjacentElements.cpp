/*

        Problem Description

        Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

        Note: You can choose more than 2 numbers.



        Problem Constraints

        1 <= N <= 20000
        1 <= A[i] <= 2000



        Input Format

        The first and the only argument of input contains a 2d matrix, A.



        Output Format

        Return an integer, representing the maximum possible sum.



        Example Input

        Input 1:

        A = [   
                [1]
                [2]    
            ]
        Input 2:

        A = [   
                [1, 2, 3, 4]
                [2, 3, 4, 5]    
            ]


        Example Output

        Output 1:

        2
        Output 2:

        8


        Example Explanation

        Explanation 1:

        We will choose 2.
        Explanation 2:

        We will choose 3 and 5.

*/

int maxSum(vector<int> &B, int i, vector<int> &dp){
    if(i==0)    return B[0];
    if(i==1)    return max(B[0], B[1]);
    if(dp[i]!=-1)   return dp[i];
    dp[i]=max(maxSum(B, i-1, dp), B[i]+maxSum(B, i-2, dp));
    return dp[i];
}

int Solution::solve(vector<vector<int>> &A){
    vector<int> B;
    for(int i=0;i<A[0].size();i++){
        B.push_back(max(A[0][i], A[1][i]));
    }
    vector<int> dp(B.size(), -1);
    return maxSum(B, B.size()-1, dp);
}