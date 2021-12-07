#include "dp.h"

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