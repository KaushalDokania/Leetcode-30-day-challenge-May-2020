/* @Author: Kaushal Dokania
    Date: 5th May 2020

URL: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3287/
Title:  Best Time to Buy and Sell Stock II

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Time Complexity:    O(n)
*/

#include <stdio.h>
#include <stdlib.h>

void getArrayInput(int *a, int n) {
    int i;
    for (i=0; i<n; ++i)
        scanf("%d", &a[i]);
}

int max_profit(int* prices, int pricesSize) {
    int i, max_profit=0, d=0;
    for (i=1; i<pricesSize; ++i) {
        d = prices[i]-prices[i-1];
        if (d > 0)
            max_profit += d;
    }
    return max_profit;
}

int main() {
    int n, i;
    scanf("%d", &n);
    int *a = (int*)malloc(sizeof(int)*n);
    getArrayInput(a, n);
    //int n = sizeof(a)/sizeof(a[0]);
    printf("Max profit: %d", max_profit(a,n));
    return 0;
}