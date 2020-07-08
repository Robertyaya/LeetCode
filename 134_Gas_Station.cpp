#include <bits/stdc++.h>
using namespace std;
// gas  = [1,2,3,4,5]
// cost = [3,4,5,1,2]
// 將每一點能到達最遠的距離記錄下來
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
}
/**
 * Brute force
 * Time: O(N^2), Space: O(1)
 */
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    for (int i = 0; i < gas.size(); i++)
    {
        // Choose the start index first
        if (cost[i] > gas[i])
            continue;

        int start_index = i;
        int tank = 0;
        for (int j = 0; j <= gas.size(); j++)
        {
            int circul_index = (j + start_index) % gas.size();
            tank += gas[circul_index];  // 加油
            tank -= cost[circul_index]; // 到下一個點
            if (tank < 0)
                break;
        }

        if (tank >= 0)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> vec2 = {3, 4, 5, 1, 2};
    cout << canCompleteCircuit(vec, vec2) << endl;
}