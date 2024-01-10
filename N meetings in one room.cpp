class Solution {
	public:

		static bool comparator(pair<int, int>&p1, pair<int, int>&p2) {
			if(p1.second<p2.second) {
				return true;
			}
			return false;
		}

		int maxMeetings(int start[], int end[], int n) {
			int s = INT_MIN;
			int e = INT_MIN;
			int meetings_ct = 0;
			vector<pair<int, int>>vp;

			for(int i=0; i<n; ++i) {
				vp.push_back({start[i], end[i]});
			}

			sort(vp.begin(), vp.end(), comparator);


			for(int i=0; i<n; ++i) {
				if(vp[i].first>e) {
					s = vp[i].first;
					e = vp[i].second;
					++meetings_ct;
				}
			}

			return meetings_ct;
		}
};
