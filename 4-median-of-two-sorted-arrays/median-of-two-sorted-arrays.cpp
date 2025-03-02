class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vect1(nums1.size() + nums2.size());
        int m = vect1.size();
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), vect1.begin());
        sort(vect1.begin(),vect1.end());
        if (m%2!=0){
            return double(vect1[(m/2)]);
        }
        else{
            return double(vect1[(m/2)-1]+vect1[(m/2)])/2;
        }
    }
};