https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/1473998542/

class Solution {
public:
double median(vector<int> nums1){
    int n = nums1.size();
    if(n%2==0){
        nth_element(nums1.begin(),nums1.begin()+n/2,nums1.end());
        nth_element(nums1.begin(),nums1.begin()+(n-1)/2,nums1.end());  
        return (double)(nums1[(n-1)/2]+ nums1[n/2])/2.0;
    }else{
        nth_element(nums1.begin(),nums1.begin()+n/2,nums1.end());
        return (double)nums1[n/2]; 
    } 
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        return median(nums1);
    }
};
