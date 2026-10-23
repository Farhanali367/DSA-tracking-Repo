class Solution {
public:
    int ans=pow(2,20)-1;
    #define fr(i,n) for(int i=0;i<n;i++)
    bool check=false;
    int m=0;
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
 
        fr(i,n){
            if(nums[i]!=i){
                check=true;
                break;
            }
        }

        if(!check) return 0;


        fr(i,n){
            if(nums[i]!=i){
                ans&=nums[i];
            }
        }
        return ans;
    }
};