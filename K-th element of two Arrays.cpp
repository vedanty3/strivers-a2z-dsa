class Solution {
	public:
		int kthElement(int nums1[], int nums2[], int n1, int n2, int k) {
			if(n2<n1) {
				return kthElement(nums2, nums1, n2, n1, k);
			}
			int lo = max(0, k-n2);
			int hi = min(k, n1);

			while(lo<=hi) {
				int cut1 = (lo + hi)/2;
				int cut2 = k - cut1;

				int left1 = cut1==0 ? INT_MIN : nums1[cut1-1];
				int left2 = cut2==0 ? INT_MIN : nums2[cut2-1];

				int right1 = cut1==n1 ? INT_MAX : nums1[cut1];
				int right2 = cut2==n2 ? INT_MAX : nums2[cut2];

				if(left1<=right2 and left2<=right1) {
					return max(left1, left2);
				} else if(left1<right2) {
					lo = cut1 + 1;
				} else {
					hi = cut1 - 1;
				}
			}

			return -1;

		}
};
