#include <bits/stdc++.h>
using namespace std;
// Input: "babad"
// Output: "bab"
string longestPalindrome(string s)
{
    string answer;
    int left_search_index = 0;
    int right_search_index = 0;
    for (int i = 1; i < s.size() - 1; i++)
    {
        // Odd
        left_search_index = i - 1;
        right_search_index = i + 1;
        while (left_search_index > 0 && right_search_index < s.size() - 1)
        {
            if (s[left_search_index] != s[right_search_index])
            {
                left_search_index++;
                right_search_index--;
                break;
            }
            cout << left_search_index << " " << right_search_index << endl;
            left_search_index--;
            right_search_index++;
        }
        answer = s.substr(left_search_index, right_search_index);

        // Even
    }
    return answer;
}
int main()
{
    string str = "bbabbad";
    cout << longestPalindrome(str) << endl;
}
