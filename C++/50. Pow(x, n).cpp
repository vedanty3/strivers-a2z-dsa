// Binary exponentiation
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long tmp = n > 0 ? n : (long long)(-1) * n;
        double ans = 1;
        while (tmp)
        {
            if (tmp & 1)
            {
                ans *= x;
            }

            x *= x;
            tmp >>= 1;
        }

        return n < 0 ? (double)(1.0) / ans : ans;
    }
};

// Recursive
class Solution
{
public:
    double powr(double x, int n)
    {
        if (!n)
        {
            return 1;
        }
        else if (n == 1)
        {
            return x;
        }

        double ans = powr(x, n / 2);

        if (n & 1)
        {
            return x * ans * ans;
        }

        else
        {
            return ans * ans;
        }
    }
    double myPow(double x, int n)
    {
        if (n < 0)
            return 1 / powr(x, n);
        return powr(x, n);
    }
};