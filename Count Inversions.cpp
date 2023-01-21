#include <bits/stdc++.h>
using namespace std;

long long cntCrossInversions(long long *arr, int s, int e)
{
    long long i = s;
    long long mid = s + (e - s) / 2;
    long long j = mid + 1;
    long long k = 0;
    long long cnt = 0;
    vector<long long> tmp;

    while (i <= mid and j <= e)
    {
        if (arr[i] <= arr[j])
        {
            tmp.emplace_back(arr[i]);
            i++;
        }
        else
        {
            tmp.emplace_back(arr[j]);
            j++;
            cnt += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        tmp.emplace_back(arr[i]);
        i++;
    }

    while (j <= e)
    {
        tmp.emplace_back(arr[j]);
        j++;
    }

    for (int i = s; i <= e; ++i)
    {
        arr[i] = tmp[k++];
    }

    return cnt;
}

long long cntInversions(long long *arr, int s, int e)
{
    if (s >= e)
        return 0;
    long long mid = s + (e - s) / 2;
    long long cnt = cntInversions(arr, s, mid);
    cnt += cntInversions(arr, mid + 1, e);
    cnt += cntCrossInversions(arr, s, e);
    return cnt;
}

long long getInversions(long long *arr, int n)
{
    long long int ans = cntInversions(arr, 0, n - 1);
    return ans;
}