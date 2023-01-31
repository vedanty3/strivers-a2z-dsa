// BRUTE FORCE
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        vector<int> freq(n + 1, 0);
        int *ans = new int[2];
        for (int i = 0; i < n; ++i)
        {
            freq[arr[i]]++;
        }

        for (int i = 1; i <= n; ++i)
        {
            if (freq[i] == 0)
            {
                ans[1] = i;
            }
            else if (freq[i] > 1)
            {
                ans[0] = i;
            }
        }

        return ans;
    }
};

// Optimal
class Solution
{
public:
    int *findTwoElement(int *A, int n)
    {
        int res = 0;
        int mask = 0;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
        {
            res ^= A[i];
            res ^= (i + 1);
        }

        int *ans = new int[2];

        while (res)
        {
            if (res & 1)
            {
                break;
            }
            mask++;
            res >>= 1;
        }

        int set_bit = 1 << mask;

        for (int i = 0; i < n; i++)

        {
            if (set_bit & A[i])
            {
                x ^= A[i];
            }
            else
            {
                y ^= A[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (set_bit & i)
            {
                x ^= i;
            }
            else
            {
                y ^= i;
            }
        }

        int x_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (x == A[i])
            {
                x_count++;
            }
        }

        if (x_count > 0)
        {
            ans[0] = x;
            ans[1] = y;
            return ans;
        }

        ans[0] = y;
        ans[1] = x;
        return ans;
    }
};
