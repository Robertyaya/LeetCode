#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(logN), Space: O(1)
 * 解題流程: 猜數字, 有一個API會return此時猜的數字是比正確的大或比較小
 * 1. 從1~n猜一個target value, 會有API告訴你此時該往上或往下走, Binary Search problem
 */
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n)
{
    int l = 1;
    int r = n;
    while (r >= l)
    {
        int mid = l + (r - l) / 2;
        int flag = guess(mid);
        if (flag == 0)
            return mid;
        else if (flag == -1)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
}