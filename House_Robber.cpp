//  Recursion

int dp[105];
    int solve(int currIdx,vector<int>&nums)
    {
        
        if(currIdx>=nums.size()) return 0;
        if( dp[currIdx]  != -1)  return  dp[currIdx];
        int take=nums[currIdx]+solve(currIdx+2,nums);
        int notTake=0+solve(currIdx+1,nums);
        return  dp[currIdx]= max(take,notTake);
    }
    int rob(vector<int>& nums) {
       memset(dp,-1,sizeof(dp));
        return solve(0,nums);
        
    }

    // tablisution
    int rob(vector<int>& nums) {
      int dp[105];
      memset(dp,0,sizeof(dp));
       for(int currIdx=nums.size()-1;currIdx>=0;currIdx--)
        {
         
        int take=nums[currIdx]+dp[currIdx+2];
        int notTake=0+dp[currIdx+1];
          dp[currIdx]= max(take,notTake);
        }
        
        return dp[0];
    }

//  o(N) and o(1) space
int rob(vector<int>& nums) {
      
        int last=0,secondLast=0,currAns=0;
       for(int currIdx=nums.size()-1;currIdx>=0;currIdx--)
        {
         
        int take=nums[currIdx]+secondLast;
        int notTake=0+last;
        currAns = max(take,notTake);
        secondLast=last;
        last=currAns;
        }
        
        return last;
    }