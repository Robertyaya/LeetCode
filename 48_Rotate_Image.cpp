#include <bits/stdc++.h>
using namespace std;
/** Time: O(N)(N is matrix size), Space: O(1)
 * 解題流程: start代表start index, end代表end index, offset: 代表進到下一層會有的offset
 * 所有matrix從這3個數字可以組合出來
 * 因為要in-place, 因此分成4步
 * 1. Top to temp: 先將top放到temp裡 (0~3 -> next layer: 1~2)
 * 2. Left to top: 因為已經將top數值save起來, 因此此處可以直接覆蓋top的數值,
 * 此處有一個關鍵在於, 複寫的時候要從"後面"複寫原因是 ex: 角落處為交界, 若從第一個開始複寫
 * 第一個數字就會蓋到top的第一個也就是left的最後一個, 則left的最後一個就消失了, 因此從left最後蓋到top的最後
 * 以下皆是如此(bottom to left, right to bottom)
 * 另外要注意index的數值, 分兩個部份
 * 1. 當層數字的迭代(基本上就是0~3->1~2)差別在於可能會倒過來 ex: 如果只有end-i第一層index為3~0沒問題
 * 但到了下一層就會是1~0 但我們想要的是2~1, 因此需要加上一個offset  
 * 2. Layer的變動, 基本上就由offset所控制
 * 最後每一次算完當成layera的rotate之後, update start index and end index 以及offset
 * 還要清空用來暫存top value的temp vector
 * 
 */
void rotate(vector<vector<int>> &matrix)
{
    vector<int> temp;
    int offset = 0;
    int start = 0;
    int end = matrix.size() - 1;
    while (end > start)
    {
        // Top to temp
        for (int i = start; i <= end; i++)
            temp.push_back(matrix[offset][i]);

        // Left to top
        for (int i = start; i <= end; i++)
            matrix[offset][end - i + offset] = matrix[i][offset];

        // Bottom to left
        for (int i = start; i <= end; i++)
            matrix[i][offset] = matrix[end][i];

        // Right to bottom
        for (int i = start; i <= end; i++)
            matrix[end][i] = matrix[end - i + offset][end];

        // Temp to right
        for (int i = start; i <= end; i++)
            matrix[end - i + offset][end] = temp[end - i];

        start++;
        end--;
        offset++;
        temp.clear();
    }
}
int main()
{
}
