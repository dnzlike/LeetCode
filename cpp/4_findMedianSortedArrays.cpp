class Solution {
public:
    int findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int m = nums1.size();
        int n = nums2.size();
        int i = 0, j = 0;
        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }
            else{
                result.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m){
            result.push_back(nums1[i]);
            i++;
        }
        while(i < m){
            result.push_back(nums2[j]);
            j++;
        }
        return (result[(m + n - 1) / 2] + result[(m + n) / 2]) / 2.0;
    }
};