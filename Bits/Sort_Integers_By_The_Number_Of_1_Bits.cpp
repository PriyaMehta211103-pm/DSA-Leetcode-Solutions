/* Problem : Sort Inetegrs By The Number Of 1 bits
Platform:Leetcode
Difficulty:Easy
Link:https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

Intuition:
Every number can be represented in binary form.
Example:
3 → 11 → 2 set bits
5 → 101 → 2 set bits
8 → 1000 → 1 set bit
So sorting should prioritize:
First → Numbers with fewer 1s in binary.
Then → Smaller number if tie.
This is a custom sorting problem, where default sorting won’t work.
We need a custom comparator.
C++ gives us a super powerful built-in function:
__builtin_popcount(n)
which directly returns the number of set bits in an integer.
That’s why your solution is clean and optimal.


Approach:
Define a Custom Comparator
For two numbers a and b:
Count set bits using __builtin_popcount()
If counts are equal → return a < b
Otherwise → return countA < countB
Step 2: Use std::sort()
Pass the lambda comparator inside sort().




//code
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda=[](int &a,int &b){
                int countA=__builtin_popcount(a);
                int countB=__builtin_popcount(b);
                if(countA==countB)
                {
                    return a<b;
                }
                return countA<countB;
        };
        sort(begin(arr),end(arr),lambda);
        return arr;
    }
};


//time complexity
O(nlogn)

//space complexity
O(1)

