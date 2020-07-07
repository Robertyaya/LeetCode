#include <bits/stdc++.h>
using namespace std;
/**
 * Iterative version
 * Time: O(logN), Space: O(1)
 * 相較於recursive version, iterative version不用呼叫stack, 因此較省空間
 */
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    if (matrix.empty() || matrix[0].empty())
        return false;

    int start = 0;
    int end = matrix.size() - 1;
    int row_index;
    // Find row index first
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (matrix[mid][0] == target)
            return true;
        else if (matrix[mid][0] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    row_index = end;
    if (row_index < 0)
        return false;
    // Find in col
    start = 0;
    end = matrix[row_index].size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (matrix[row_index][mid] == target)
            return true;
        else if (matrix[row_index][mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return false;
}
/**
 * Recursive version
 * Time: O(logN), Space: O(n)(in worst case)
 * 解題流程: 先從row找, 確定是在哪一行, 目的是找出row_index, 此row_index必須小於target value, 且最接近
 * 找出row_index之後再一樣用binary search找是否有在那個row內
 */
bool FindInRow(vector<vector<int>> &matrix, int target, int start, int end, int &index)
{
    // Base case, represent can't find the target value, we need to set the closet index
    // but smaller than target
    if (start > end)
    {
        index = end;
        return false;
    }

    int mid = (start + end) / 2;
    if (matrix[mid][0] == target)
        return true;
    else if (matrix[mid][0] > target)
        return FindInRow(matrix, target, start, mid - 1, index);
    else
        return FindInRow(matrix, target, mid + 1, end, index);
    return false;
}
bool FindInCol(vector<vector<int>> &matrix, int target, int start, int end, int row_index)
{
    if (start > end)
        return false;

    int mid = (start + end) / 2;
    if (matrix[row_index][mid] == target)
        return true;
    else if (matrix[row_index][mid] > target)
        return FindInCol(matrix, target, start, mid - 1, row_index);
    else
        return FindInCol(matrix, target, mid + 1, end, row_index);
    return false;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // 記得要判斷兩個, 如果只寫matrix.empty()會出錯
    if (matrix.empty() || matrix[0].empty())
        return false;

    int row_index;

    // O(logN)
    if (FindInRow(matrix, target, 0, matrix.size() - 1, row_index))
        return true;

    // O(logN)
    if (row_index < 0)
        return false;

    return FindInCol(matrix, target, 0, matrix[row_index].size() - 1, row_index);
}