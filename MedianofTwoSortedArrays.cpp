class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<int> arr;  

        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);  
                i++;
            } else {
                arr.push_back(nums2[j]); 
                j++;
            }
            k++;
        }
        while (i < m) {
            arr.push_back(nums1[i]);  
            i++;
            k++;
        }
        while (j < n) {
            arr.push_back(nums2[j]); 
            j++;
            k++;
        }

        if ((m + n) % 2 != 0) {
            return arr[(m + n) / 2];
        } else {
            int x = (m + n) / 2;
            double p = arr[x];
            double q = arr[x - 1];
            return (p + q) / 2;
        }
    }
};
