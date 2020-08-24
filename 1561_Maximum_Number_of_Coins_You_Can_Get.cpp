/**
 * Time: O(NlogN), Space: O(1)
 * 解題流程: 先sorting完, 因為可以任意選3個
 * 因此3好兄弟一定每次都要拿最小的數字
 * 因此前1/3都是3好兄弟拿的
 * 我們從1/3後開始, 每間隔2拿一次相加
 */

int maxCoins(vector<int> &piles)
{
  // O(NlogN)
  sort(piles.begin(), piles.end());
  int res = 0;
  for (int i = piles.size() / 3; i < piles.size(); i += 2)
    res += piles[i];
  return res;
}
