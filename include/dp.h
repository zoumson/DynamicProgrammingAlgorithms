#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <utility>
#include <set>

namespace za
{

    int fib_rec(int &n);
    int fib_rec(int &&n);
    long long fib_rec_memo(int n, std::map<int, long long> &m);
    long long fib_rec_memo(int n, std::map<int, long long> &&m);
    bool can_sum_rec(int &n, std::vector<int> &m);
    bool can_sum_rec(int &&n, std::vector<int> &&m);
    bool can_sum_rec_memo(int &n, std::vector<int> &m, std::map<int, bool> &p);
    bool can_sum_rec_memo(int &&n, std::vector<int> &&m, std::map<int, bool> &&p);
    std::vector<int> *how_sum_rec(int &n, std::vector<int> &m);
    std::vector<int> *how_sum_rec_memo(int &n, std::vector<int> &m, std::map<int, std::vector<int> *> &p);
    std::vector<int> *best_sum_rec(int &n, std::vector<int> &m);
    std::vector<int> *best_sum_rec_memo(int n, std::vector<int> &m, std::map<int, std::vector<int> *> &p);

    // std::vector<int> how_sum_rec(int &&n, std::vector<int> &&m);
    bool can_reach_zero(int n);
    // int can_reach_zero_how(int n);

    int minCoinChange(std::vector<int> coins, int amount);
    int distinctChangeNoDuplication(int amount, std::vector<int> &coins);
    int distinctChangeDuplication(std::vector<int> &coins, int amount);

    uint64_t removingDigits(uint64_t inputVal);
    int reduceZero(int N);
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid);
    int bookShop(std::vector<std::vector<int>> &input);
}