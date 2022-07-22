//Method 1

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        for(int i = 0 ; i < (1<<n) ; i++) {
            vector<int>v;
            for(int j = 0 ; j < n ; j++) {
                if((1 << j) & i)
                    v.push_back(nums[j]); 
            }   
            ans.push_back(v);
        }
        return ans;
    }
};



//Method 2

class Solution {
public:
    void help(int i, vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans) {
        if(i == nums.size()) {
            ans.push_back(temp);
        }
        else {
            // to take the ith element
            temp.push_back(nums[i]);
            help(i+1,nums,temp,ans);
            
            temp.pop_back();
            
            //to ignore the ith element
            help(i+1,nums,temp,ans);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        help(0,nums,temp,ans);
        return ans;
    }
};
