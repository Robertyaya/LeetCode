#include <bits/stdc++.h>
using namespace std;
/**
 * Time: O(N), Space: O(1)
 * 解題流程: total用來記錄全部的gas-cost是否大於0, 
 * 如果小於0則一定沒有index可以繞一圈, 如果大於0則一定有一個index可以繞一圈, 
 * 至於如何找出那個target index就是利用sum and start_index
 * ex: [a,b,c,d,e,f]
 * 假設從a出發加到c之後小於0, "那麼a,b,c這3個一定都不可能是target index"
 * 因為我們根據結果知道a不是, 那假設b是的話->a一定會是(違反假設) 因此a,b,c都不可能是
 * 如果要滿足a不是 b是的這個假設, 代表a<0 and b>0 那如果這樣的話start_index就會從b開始而不會從a開始 因此違反假設
 * 如果start_index 沒到b那代表a and b此時皆>0
 * 因此直接把start_index設成下一個繼續尋找
 * 
 */
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int total = 0;
    int sum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        total += (gas[i] - cost[i]);
        sum += (gas[i] - cost[i]);
        if (sum < 0)
        {
            start = i + 1;
            sum = 0;
        }
    }
    return total < 0 ? -1 : start;
}
/**
 * Brute force
 * Time: O(N^2), Space: O(1)
 * 解題流程: 先選start_index如果gas and cost相減小於0則不可能為start_index因為根本不可能到下一點
 * 選完start_index之後, 開始一路加過去, 過程中還沒到繞一圈之前, 如果tank小於0了則代表此index不可能, 直接break
 * 如果繞完一圈了, 則代表此index OK
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
    vector<int> a = {3, 3, 4};
    vector<int> b = {3, 4, 4};
    cout << canCompleteCircuit(a, b) << endl;
}
