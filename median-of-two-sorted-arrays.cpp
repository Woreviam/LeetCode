class Solution {
public:

    double getMin(vector<int>& nums1, vector<int>& nums2, int& p1, int& p2){

        if(p1 == nums1.size())return nums2[p2++];
        if(p2 == nums2.size())return nums1[p1++];
        if(nums1[p1] <= nums2[p2])return nums1[p1++];
        return nums2[p2++];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size() + nums2.size();
        int mid = (n - 1)/2;
        int p1 = 0, p2 = 0;

        for(int i = 0; i < mid; i++)getMin(nums1, nums2, p1, p2);
        
        if(n&1)return getMin(nums1, nums2, p1, p2);
        return (getMin(nums1, nums2, p1, p2) + getMin(nums1, nums2, p1, p2))/2.0;
    }
};
