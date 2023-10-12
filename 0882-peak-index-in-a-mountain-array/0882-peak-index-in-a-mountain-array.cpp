class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int ans = binaryhelper(arr,0,n-1);
        return ans;
    }
    int binaryhelper(vector<int>&arr, int start, int end){
        int m = arr.size();
        int mid =0;
        if (start <= end) {
            mid = (start + end) / 2;
            
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) {
                return binaryhelper(arr, mid, end);
            } else {
                return binaryhelper(arr, start, mid);
            }
        }
        return -1;
    }
};