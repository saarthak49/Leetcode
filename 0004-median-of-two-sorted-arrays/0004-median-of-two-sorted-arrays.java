class Solution {
    
    public double findMedianInArray(int[] nums1)
    {
        int n = nums1.length;
        if(n == 0)
            return 0;

        if( n%2 == 0 )
        {
            return (nums1[(n-1)/2] + nums1[(n/2)])/2.0;
        }
        return nums1[(n - 1)/2];
    }

    public double findMedian(int[] nums1, int[] nums2) {

        int n = nums1.length;
        int m = nums2.length;

        if( n == 0)
            return findMedianInArray(nums2);

        int low = 0;
        int high = n;


        int m1 = 0;
        int m2 = 0;


        while (low <= high) {
            int i = low + (high - low) / 2;
            int j = (m + n + 1) / 2 - i;

            if (i <= n - 1 && j >= 1 && nums1[i] < nums2[j - 1]) {
                low = i + 1;
            } else if (j <= m - 1 && i >= 1 && nums2[j] < nums1[i - 1]) {
                high = i - 1;
            } else {
                if (i == 0)
                    m1 = nums2[j - 1];
                else if (j == 0)
                    m1 = nums1[i - 1];
                else
                    m1 = Math.max(nums1[i - 1], nums2[j - 1]);

                if (i == n)
                    m2 = nums2[j];
                else if (j == m)
                    m2 = nums1[i];
                else
                    m2 = Math.min(nums1[i], nums2[j]);
                break;
            }
        }

        if ((m + n) % 2 == 0)
            return (m1 + m2) / 2.0;
        return m1;


    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        if (nums1.length < nums2.length)
            return findMedian(nums1, nums2);
        return findMedian(nums2, nums1);
    }
}