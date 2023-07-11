class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size()-1;
        
        while(true){
            if(nums[(end-begin)/2 + begin]==target)
                return (end-begin)/2 + begin;
            else if(begin==end-1 || begin==end){
                if(nums[begin]==target)
                    return begin;
                else if(nums[end]==target)
                    return end;
                return -1;
            }
            else if(nums[(end-begin)/2+ begin] < target){
                begin = (end-begin)/2+ begin;
            }
            else{
                end = (end-begin)/2+ begin;
            }
        }          
    }
};
