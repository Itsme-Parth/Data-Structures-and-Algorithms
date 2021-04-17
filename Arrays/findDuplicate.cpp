class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() > 1)
        {
            int slow = nums[0], fast = nums[nums[0]];
            while(slow != fast)//first loop is used to find the meeting point of the pointers
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }
            slow = 0;
            while(slow != fast)//this will set them to the starting of the loop
            {
                slow = nums[slow];
                fast = nums[fast];
            }
        return slow;
        }
        return -1;
    }
};