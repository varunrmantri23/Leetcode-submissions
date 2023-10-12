class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int start = 0;
        int end = n - 1;
        int mid;
        mid = (start + end)/2;
        while(start < end){
            

            if(mountainArr.get(mid) < mountainArr.get(mid+1)){
                start = mid + 1;
            }else{
                end = mid;
            }

            mid = (start + end)/2;
        }

        int peak = mid;

        start = 0;
        end = peak;
        
        while(start <= end){
            mid = (start + end) / 2;
            int middle = mountainArr.get(mid);
            if(middle > target){
                end = mid-1;
            }else if(middle < target){
                start = mid + 1;
            }else{
                return mid;
            }
        }

        start = peak ;
        end = n - 1;

        while(start <= end){
            mid = (start + end)/2;

            int middle = mountainArr.get(mid);

            if(middle > target){
                start = mid+ 1;
            }else if(middle < target){
                end = mid - 1;
            }else{
                return mid;
            }
        }

        return -1;
    }
};