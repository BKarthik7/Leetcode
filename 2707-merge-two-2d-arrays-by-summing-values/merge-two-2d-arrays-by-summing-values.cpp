class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> op;
        int m = nums1.size(), n = nums2.size(), o = 0, p = 0;
        while(o < m && p < n){
            if(nums1[o][0] == nums2[p][0]){
                op.push_back({nums1[o][0], nums1[o][1] + nums2[p][1]});
                o++; p++;
            }
            else if(nums1[o][0] < nums2[p][0]){
                op.push_back(nums1[o]);
                o++;
            }
            else{
                op.push_back(nums2[p]);
                p++;
            }
        }

        while(o < m){
            op.push_back(nums1[o]);
            o++;
        }

        while(p < n){
            op.push_back(nums2[p]);
            p++;
        }

        return op;
    }
};