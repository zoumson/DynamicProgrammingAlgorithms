#include "dp.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    // std::cout << "Enter:\n";
    // int n;
    // std::cin >> n;
    //  std::cout << "\n"
    //<< fib_rec(n) << "\n";
    //<< fib_rec_memo(n, m) << "\n";
    //<< fib_rec_memo(n, std::map<int, long long>()) << "\n";
    /*
        if (can_sum_rec_memo(300, {7, 14}, std::map<int, bool>()))
        {
            std::cout << "yes\n";
        }
        else
        {
            std::cout << "no\n";
        }
        */
    /*
 if (can_reach_zero(10))
 {
     std::cout << "yes\n";
 }
 else
 {
     std::cout << "no\n";
 }
*/

    // std::vector<int> n = how_sum_rec(7, {2, 3});
    /*
    int t = 300;
    std::vector<int> m = {7, 14};
    auto n = how_sum_rec(t, m);
    if (n == NULL)
        return 0;
    for (auto it = n->begin(); it != n->end(); ++it)
    {
        std::cout << *it << "\n";
    }
    */
    /*
     int t = 8;
     std::vector<int> m = {2, 3, 5};
     std::map<int, std::vector<int> *> mm;
     auto n = how_sum_rec_memo(t, m, mm);
     if (n == NULL)
         return 0;
     for (auto it = n->begin(); it != n->end(); ++it)
     {
         std::cout << *it << "\n";
     }
     */
    /*
        int t = 8;
        std::vector<int> m = {1, 4, 5};
        std::map<int, std::vector<int> *> mm;
        auto n = best_sum_rec(t, m);
        if (n == NULL)
            return 0;
        for (auto it = n->begin(); it != n->end(); ++it)
        {
            std::cout << *it << "\n";
        }
    */

    // int t = 10;
    // std::vector<int> m = {1, 4, 5};
    // std::map<int, std::vector<int> *> mm;
    // auto n = best_sum_rec_memo(t, m, mm);
    // if (n == NULL)
    //     return 0;
    // for (auto it = n->begin(); it != n->end(); ++it)
    // {
    //     std::cout << *it << "\n";
    // }

    // // min coins change
    // std::vector<int> coins = {1, 5, 7};

    // std::cout << "Minimum number: " << za::minCoinChange(coins, 11) << "\n";
    // // 3

    // coin duplication change

    // std::vector<int> coins = {2, 3, 5};

    // std::cout << "Ways: " << za::distinctChangeDuplication(coins, 9) << "\n";

    // removing digits

    // answer ==> 5 for input 27
    // std::cout << za::removingDigits(27) << std::endl;
    // std::cout << za::reduceZero(27) << std::endl;
    // uniquePathsWithObstacles
    // => 3
    // std::vector<std::vector<int>> obstacleGrid = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {1, 0, 0, 0}};

    // std::cout << za::uniquePathsWithObstacles(obstacleGrid) << std::endl;

    // std::vector<std::vector<int>> bookData = {{4, 10}, {4, 8, 5, 3}, {5, 12, 8, 1}};
    // std::cout << za::bookShop(bookData) << std::endl;
    std::vector<int> arr = {2, 0, 2};
    std::cout << "all:" << za::arrayDescription(3, 5, arr) << std::endl;
    return 0;
}
