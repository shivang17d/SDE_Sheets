class Solution {
public:
    int dp[1001];
    int help(vector<int>& arr,int d,int i) {
        if(dp[i]!=-1)return dp[i];
        int ans=1,n=arr.size();
        
        //right
        for(int j = i+1 ; j <= min(i+d,n-1) && arr[i] > arr[j] ; j++)
            ans = max(ans,1+help(arr,d,j));
        //left
        for(int j = i-1 ; j >= max(i-d,0) && arr[i] > arr[j] ; j--)
            ans = max(ans,1+help(arr,d,j));
        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        memset(dp,-1,sizeof dp);
        int ans = 1;
        for(int i = 0 ; i < arr.size() ; i++) ans = max(ans,help(arr,d,i));
        return ans;
    }
};
