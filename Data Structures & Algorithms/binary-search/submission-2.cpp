class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1; // 5
        int mid=0;
        while (left <= right) { // 0<5t, 3<5t, 3<4t, 3<5t
            mid = left + (right - left) / 2; // 2, 4, 4, 4
            if (nums[mid] == target) { // 2==3f, 6==3f, 6==3f, 6==3f
                return mid;
            } else if (nums[mid] > target) { // 2>3f, 6>3t, 6>3t, 
                right = mid-1; // 4, 5
            } else { // 2<3t
                left = mid + 1; // 3
            } 
        }
        return -1;
    }
};
