/*  @Author: Kaushal Dokania
    Date: 5th May 2020

URL: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3285/
GFG URL: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
Title:  Maximum Subarray

Description: Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
e.g. { -2 -3 [ 4 -1 -2 1 5 ]-3 }

*/

#include <stdio.h>
#include <stdlib.h>
#include "../utils/util.h"

void getArrayInput(int *a, int n) {
    int i;
    for (i=0; i<n; ++i)
        scanf("%d", &a[i]);
}

/* Each time we get a positive sum compare it with max_sum
and update max_sum if it is greater than max_so_far */
int max_profit(int a[], int n) {
    int i, max_sum=INT_MIN, sum=0;
    for (i=0; i<n; ++i) {
        sum += a[i];
        if (sum > max_sum)                  // if all numbers are negative smallest negative is considered
            max_sum = sum;
        if (sum < 0)                        // reset sum if current subarray sum < 0
            sum = 0;
    }
    return max_sum;
}

int main() {
    int n, i;
    scanf("%d", &n);
    int *a = (int*)malloc(sizeof(int)*n);
    getArrayInput(a, n);
    //int n = sizeof(a)/sizeof(a[0]);
    printf("Max sum: %d", max_profit(a,n));
    return 0;
}