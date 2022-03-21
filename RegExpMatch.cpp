/*

        Problem Description

        Implement wildcard pattern matching with support for ' ? ' and ' * ' for strings A and B.

        ' ? ' : Matches any single character.
        ' * ' : Matches any sequence of characters (including the empty sequence).
        The matching should cover the entire input string (not partial).



        Problem Constraints

        1 <= length(A), length(B) <= 104



        Input Format

        The first argument of input contains a string A.
        The second argument of input contains a string B.



        Output Format

        Return 1 if the patterns match else return 0.



        Example Input

        Input 1:

        A = "aaa"
        B = "a*"
        Input 2:

        A = "acz"
        B = "a?a"


        Example Output

        Output 1:

        1
        Output 2:

        0


        Example Explanation

        Explanation 1:

        Since '*' matches any sequence of characters. Last two 'a' in string A will be match by '*'.
        So, the pattern matches we return 1.
        Explanation 2:

        '?' matches any single character. First two character in string A will be match. 
        But the last character i.e 'z' != 'a'. Return 0.

*/

int check(string A, string B, int i, int j, vector<vector<int>> &dp){
    if(i==-1 && j==-1)  return 1;
    else if(j==-1)  return 0;
    else if(i==-1){
        for(int k=0;k<=j;k++){
            if(B[k]!='*')   return 0;
        }
        return 1;
    }
    if(dp[i][j]!=-1)    return dp[i][j];
    if(A[i]==B[j] || B[j]=='?'){
        dp[i][j]=check(A, B, i-1, j-1, dp);
    }
    else if(B[j]=='*'){
        dp[i][j]=(check(A, B, i, j-1, dp) || check(A, B, i-1, j, dp));
    }
    else{
        dp[i][j]=0;
    }
    return dp[i][j];
}

int Solution::solve(string A, string B){
    vector<vector<int>> dp(A.size(), vector<int> (B.size(), -1));
    return check(A, B, A.size()-1, B.size()-1, dp);
}