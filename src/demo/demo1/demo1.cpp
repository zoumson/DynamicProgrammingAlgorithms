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

    std::vector<int> coins = {2, 3, 5};

    std::cout << "Ways: " << za::distinctChangeDuplication(coins, 9) << "\n";
    return 0;
}
