class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int k = 0;
        for(int i : derived){
            k ^= i;
        }
        return !k;
    }
};