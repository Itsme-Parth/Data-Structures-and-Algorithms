class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int inversePtr = n - 2;
        while(inversePtr >= 0 && nums[inversePtr] >= nums[inversePtr + 1])
            inversePtr--;
        if(inversePtr < 0)//the array is in decreasing order hence here we have to return empty set
        {
            reverse(nums.begin() + inversePtr + 1, nums.end());
            return;
        }
        for(int i = inversePtr; i < n; i++)
        {
            if(nums[i] > nums[inversePtr])
            {
                swap(nums[i], nums[inversePtr]);
                break;
            }
        }
        reverse(nums.begin() + inversePtr + 1, nums.end());
    }
};