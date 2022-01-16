#include "dp.h"
namespace za
{
    // slower try fib of 6, 7 and 50
    // Time O(2^n)
    // Space O(n)
    // n is tree height
    // for time complexity, think of decreasing n by 1 at a time
    // for each level branching factor is used here it's 2
    // due to fib(n-1) and fib(n-2)
    int fib_rec(int &n)
    {
        if (n <= 2)
        {
            return 1;
        }
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
    int fib_rec(int &&n)
    {
        if (n <= 2)
        {
            return 1;
        }
        return fib_rec(n - 1) + fib_rec(n - 2);
    }

    // faster , try fib of 50
    long long fib_rec_memo(int n, std::map<int, long long> &m)
    {
        if (m.find(n) != m.end())
        {
            return m[n];
        }
        if (n <= 2)
        {
            return 1;
        }
        m[n] = fib_rec_memo(n - 1, m) + fib_rec_memo(n - 2, m);
        return m[n];
    }
    long long fib_rec_memo(int n, std::map<int, long long> &&m)
    {
        if (m.find(n) != m.end())
        {
            return m[n];
        }
        if (n <= 2)
        {
            return 1;
        }
        m[n] = fib_rec_memo(n - 1, m) + fib_rec_memo(n - 2, m);
        return m[n];
    }

    // tree height is n, target number
    // branching factor is m size
    // time O(n^m)
    // space O(m*n)
    bool can_sum_rec(int &n, std::vector<int> &m)
    {
        if (n < 0)
        {
            return false;
        }

        if (n == 0)
        {
            return true;
        }

        for (auto &i : m)
        {
            int d = n - i;
            if (can_sum_rec(d, m))
            {
                return true;
            }
        }
        return false;
    }
    bool can_sum_rec(int &&n, std::vector<int> &&m)
    {
        if (n < 0)
        {
            return false;
        }

        if (n == 0)
        {
            return true;
        }

        for (auto &i : m)
        {
            int d = n - i;
            if (can_sum_rec(d, m))
            {
                return true;
            }
        }
        return false;
    }

    bool can_sum_rec_memo(int &n, std::vector<int> &m, std::map<int, bool> &p)
    {
        if (p.find(n) != p.end())
        {
            return p[n];
        }
        if (n < 0)
        {
            return false;
        }
        if (n == 0)
        {
            return true;
        }

        for (auto &i : m)
        {
            int d = n - i;
            if (can_sum_rec_memo(d, m, p))
            {
                p[n] = true;
                return true;
            }
        }
        p[n] = false;
        return false;
    }
    bool can_sum_rec_memo(int &&n, std::vector<int> &&m, std::map<int, bool> &&p)
    {
        if (p.find(n) != p.end())
        {
            return m[n];
        }
        if (n < 0)
        {
            return false;
        }
        if (n == 0)
        {
            return true;
        }

        for (auto &i : m)
        {
            int d = n - i;
            if (can_sum_rec_memo(d, m, p))
            {
                p[n] = true;
                return true;
            }
        }
        p[n] = false;
        return false;
    }

    bool can_reach_zero(int n)
    {
        if (n < 0)
            return false;
        if (n == 0)
        {
            return true;
        }

        for (int i = 1; i <= 9; i++)
        {
            int d = n - i;
            if (can_reach_zero(d))
            {
                return true;
            }
        }

        return false;
    }
    /*
    int can_reach_zero_how(int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
        {
            return 1;
        }
        int t = 0;
        for (int i = 1; i <= 9; i++)
        {
            int d = n - i;
            t += can_reach_zero_how(d);
        }

        return t;
    }
    */

    // time O(n^m*m)
    // space O(m)
    std::vector<int> *how_sum_rec(int &n, std::vector<int> &m)
    {
        if (n < 0)
        {
            return nullptr;
        }
        if (n == 0)
        {
            std::vector<int> *tmp = new std::vector<int>();
            return tmp;
        }
        for (auto &i : m)
        {
            int d = n - i;
            auto r = how_sum_rec(d, m);

            if (r != nullptr)
            {
                r->push_back(i);
                return r;
            }
        }

        return nullptr;
    }

    std::vector<int> *how_sum_rec_memo(int &n, std::vector<int> &m, std::map<int, std::vector<int> *> &p)
    {
        if (p.find(n) != p.end())
        {
            return p[n];
        }
        if (n < 0)
        {
            return nullptr;
        }
        if (n == 0)
        {
            std::vector<int> *tmp = new std::vector<int>();
            p[n] = tmp;
            return tmp;
        }
        for (auto &i : m)
        {
            int d = n - i;
            auto r = how_sum_rec(d, m);

            if (r != nullptr)
            {
                r->push_back(i);
                p[n] = r;
                return r;
            }
        }
        p[n] = nullptr;
        return nullptr;
    }

    std::vector<int> *best_sum_rec(int &n, std::vector<int> &m)
    {
        if (n < 0)
        {
            return nullptr;
        }
        if (n == 0)
        {
            std::vector<int> *tmp = new std::vector<int>();
            return tmp;
        }

        std::vector<int> *rr = nullptr;

        for (auto &i : m)
        {

            int d = n - i;
            auto r = best_sum_rec(d, m);

            if (r != nullptr)
            {
                r->push_back(i);

                if (rr == nullptr || (rr != nullptr && r->size() < rr->size()))
                {
                    rr = r;
                }
            }
        }
        return rr;
    }

    std::vector<int> *best_sum_rec_memo(int n, std::vector<int> &m, std::map<int, std::vector<int> *> &p)
    {
        if (p.find(n) != p.end())
        {
            return p[n];
        }
        if (n < 0)
        {
            return nullptr;
        }
        if (n == 0)
        {

            std::vector<int> *tmp = new std::vector<int>();
            return tmp;
        }

        std::vector<int> *rr = nullptr;

        for (auto i : m)
        {

            int d = n - i;
            auto r = best_sum_rec_memo(d, m, p);

            if (r != nullptr)
            {

                r->push_back(i);
                if (rr == nullptr || (rr != nullptr && r->size() < rr->size()))
                {

                    rr = r;
                }
            }
        }
        if (rr != nullptr)
        {
            p[n] = rr;
        }
        return rr;
    }

    /*

    std::vector<int> how_sum_rec(int &&n, std::vector<int> &&m)
    {
        if (n < 0)
        {
            return NULL;
        }
        if (n == 0)
        {
            return std::vector<int>();
        }
        std::vector<int> r;
        for (auto &i : m)
        {
            int d = n - i;
            auto rr = how_sum_rec(d, m);

            if (rr != nullptr)
            {
                r = rr;
                r.push_back(d);
            }
        }

        return r;
    }
    */

    int minCoinChange(std::vector<int> coins, int amount)
    {
        // create an array to hold the minimum number of coins to make each amount
        // amount + 1 so that you will have indices from 0 to amount in the array

        std::vector<int> minCoins(amount + 1, INT_MAX);
        // there are 0 ways to make amount 0 with positive coin values
        minCoins[0] = 0;
        // look at one coin at a time
        for (auto &coin : coins)
        {
            for (int i = 0; i <= amount; i += 1)
            {
                // make sure the difference between the current amount and the current coin is at least 0
                // replace the minimum value
                if ((i - coin) >= 0)
                {
                    minCoins[i] = std::min(minCoins[i], minCoins[i - coin] + 1);
                }
            }
        }
        // if the value remains Infinity, it means that no coin combination can make that amount
        return minCoins[amount] != INT_MAX ? minCoins[amount] : -1;
    }

    // with or without permutation?
    //  order does not matter
    // 1-3 and 3-1 counted as 1
    int distinctChangeNoDuplication(int amount, std::vector<int> &coins)
    {
        std::vector<int> all(amount + 1, 0);
        all[0] = 1;

        for (int j = 0; j < coins.size(); j++)
        {
            for (int i = 0; i <= amount; i++)
            {
                if (i - coins[j] >= 0)
                    all[i] += all[i - coins[j]];
            }
        }
        return all[amount];
    }
    int distinctChangeDuplication(std::vector<int> &coins, int amount)
    {
        const int MOD = (int)1e9 + 7;
        std::vector<int> all(amount + 1, 0);
        all[0] = 1;

        for (int i = 0; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0)
                    all[i] += all[i - coins[j]];

                all[i] = all[i] % MOD;
            }
        }

        return all[amount];
    }

    uint64_t removingDigits(uint64_t inputVal)
    {
        uint64_t minSteps[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        uint_fast8_t digit0 = 0;
        for (uint64_t val = 10; val <= inputVal; ++val)
        {
            digit0 = val % 10;
            uint64_t digitVal = val;
            uint64_t minPrevStep = 0;
            bool prevStepSet = false;
            while (digitVal > 0)
            {
                uint64_t nextDigitVal = digitVal / 10;
                uint_fast8_t digit = digitVal - nextDigitVal * 10;
                if (digit > 0)
                {
                    uint64_t prevStep = 0;
                    if (digit > digit0)
                    {
                        prevStep = minSteps[10 + digit0 - digit];
                    }
                    else
                    {
                        prevStep = minSteps[digit0 - digit];
                    }
                    if (!prevStepSet || prevStep < minPrevStep)
                    {
                        minPrevStep = prevStep;
                        prevStepSet = true;
                    }
                }
                digitVal = nextDigitVal;
            }
            minSteps[digit0] = minPrevStep + 1;
        }
        return minSteps[digit0];
    }

    // Function to reduce an integer N
    // to Zero in minimum operations by
    // removing digits from N
    int reduceZero(int N)
    {
        // Initialise dp[] to steps
        std::vector<int> dp(N + 1, 1e9);

        dp[0] = 0;

        // Iterate for all elements
        for (int i = 0; i <= N; i++)
        {

            // For each digit in number i
            for (char c : std::to_string(i))
            {

                // Either select the number
                // or do not select it
                dp[i] = std::min(dp[i],
                                 dp[i - (c - '0')] + 1);
            }
        }

        // dp[N] will give minimum
        // step for N
        return dp[N];
    }

}