class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2)
    {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();

        int total = m + n;
        int half = (total + 1) / 2;

        int left = 0;
        int right = m;

        while(left <= right)
        {
            int cutA = (left + right) / 2;
            int cutB = half - cutA;

            int Aleft = (cutA == 0) ? INT_MIN : nums1[cutA - 1];
            int Aright = (cutA == m) ? INT_MAX : nums1[cutA];
            int Bleft = (cutB == 0) ? INT_MIN : nums2[cutB - 1];
            int Bright = (cutB == n) ? INT_MAX : nums2[cutB];

            if(Aleft <= Bright && Bleft <= Aright)
            {
                if(total % 2 == 1)
                {
                    return max(Aleft, Bleft);
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            }
            else if(Aleft > Bright)
            {
                right = cutA - 1;
            }
            else
            {
                left = cutA + 1;
            }
        }
        return 0.0;
    }
};