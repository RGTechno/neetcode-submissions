class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1==0){
            // median from n2
            if(n2%2==0){
                int a=n2/2;
                int b=(n2/2)-1;
                return double(nums2[a]+nums2[b])/2.0;
            }
            return nums2[n2/2];
        }
        if(n2==0){
            // median from n1
            if(n1%2==0){
                int a=n1/2;
                int b=(n1/2)-1;
                return double(nums1[a]+nums1[b])/2.0;
            }
            return nums1[n1/2];
        }
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int nleft=(n1+n2+1)/2;
        int l=0,r=min(n1,nleft);

        while(l<=r){
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            int mid1 = l+(r-l)/2;
            int mid2 = nleft-mid1;

            if(mid1-1>=0 && n1) l1=nums1[mid1-1];
            if(mid2-1>=0 && n2) l2=nums2[mid2-1];
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];

            if(l1<=r2 && l2<=r1){
                // valid middle indexes
                if((n1+n2)%2==0){
                    return double((max(l1,l2)+min(r1,r2))/2.0);
                }
                return max(l1,l2);
            }

            if(l1>r2){
                r=mid1-1;
            }else{
                l=mid1+1;
            }


        }
        return 0;
    }
};
