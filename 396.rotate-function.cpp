/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
class Solution
{
    /**
     * Time: O(N), Space: O(1)
     * sum=A+B+C+D
     * F(0)=0A+1B+2C+3D
     * F(1)=0D+1A+2B+3C
     * F(2)=0C+1D+2A+3B
     * F(3)=0B+1C+2D+3A
     * 規律
     * F(1) = F(0)+sum-4D
     * F(2) = F(1)+sum-4C
     * 
     * F(i+1)=F(i)+sum-n*A[n-i]
     */
public:
    int maxRotateFunction(vector<int> &A)
    {
        if (A.empty())
            return 0;

        long sum = 0;
        for (auto v : A)
            sum += v;

        // Initialize A0
        vector<int> vec(A.size(), 0);
        int max_value = 0;
        int i = 0;
        for (auto v : A)
        {
            max_value += (v * i);
            i++;
        }
        vec[0] = max_value;

        for (int i = 1; i < A.size(); i++)
        {
            vec[i] = vec[i - 1] + sum - A.size() * A[A.size() - i];
            max_value = max(vec[i], max_value);
        }
        return max_value;
    }
};
// @lc code=end
