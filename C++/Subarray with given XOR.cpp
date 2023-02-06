int Solution::solve(vector<int> &A, int B)
{
    int xorr = 0, cnt = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < A.size(); ++i)
    {
        xorr ^= A[i];
        if (xorr == B)
        {
            ++cnt;
        }
        if (mpp.find(xorr ^ B) != mpp.end())
        {
            cnt += mpp[xorr ^ B];
        }

        mpp[xorr]++;
    }

    return cnt;
}
