class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        
        int low = 0, high = n1;
        
        while (low <= high) {
            int cut1 = (low + high) / 2; 
            int cut2 = (n1 + n2) / 2 - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];
            
            if (l1 > r2) 
                high = cut1 - 1;
            else if (l2 > r1) 
                low = cut1 + 1;
            else 
                return (n1 + n2) % 2 ? min(r1, r2) : (max(l1,l2) + min(r1, r2)) / 2.0;
        }
        
        return -1;
    }
};
