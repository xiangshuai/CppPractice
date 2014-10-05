/**
Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*
**/

#include <iostream>
#include <climits>

using namespace std;

// 暴力求解
template<typename T>
T maxProductByBruteForce(T A[], int n)
{
    T maxPt = LONG_MIN ;
    for(int i=0; i<n; i++)
    {
        T smax = LONG_MIN;
        T pt = A[i];
        for(int k=i+1; k<n; k++)
        {
            pt *= A[k];
            if(smax < pt)
            {
                smax = pt;
            }
        }
        if(maxPt < smax)
        {
            maxPt = smax;
        }
    }
    return maxPt;
}

// better
template<typename T>
T maxProductBetter(T A[], int n)
{
    T maxCurrent = 1;
    T minCurrent = 1;
    T maxProduct = INT_MIN;

    for(int i=0; i<n; i++)
    {
        maxCurrent *= A[i];
        minCurrent *= A[i];

        if(maxCurrent > maxProduct)
        {
            maxProduct = maxCurrent;
        }
        if(minCurrent > maxProduct)
        {
            maxProduct = minCurrent;
        }
        if(minCurrent > maxCurrent)
        {
            swap(maxCurrent, minCurrent);
        }
        if(maxCurrent < 1)
        {
            maxCurrent = 1;
        }
    }
    return maxProduct;
}

// 动态规划
template<typename T>
T maxProductBest(T A[], int n)
{
    T maxPt[n];
    T minPt[n];
    maxPt[0] = minPt[0] = A[0];
    T value = maxPt[0];
    for(int i=1; i<n; i++)
    {
        maxPt[i] = max(max(A[i], maxPt[i-1]*A[i]), minPt[i-1]*A[i]);
        minPt[i] = min(min(A[i], minPt[i-1]*A[i]), maxPt[i-1]*A[i]);
        value = max(value, maxPt[i]);
    }
    return value;
}

// 记录区间起点 未完成
pair<int, int> maxProduct(int A[], int n)
{
    int S = 0, s = 0;
    pair<int, int> ret = make_pair(0, 0);
    int maxPt = A[0], minPt = A[0];
    int value = maxPt;

    int maxCurrent = 1;
    int minCurrent = 1;
    for(int i=1; i<n; i++)
    {
        maxCurrent *= A[i];
        minCurrent *= A[i];
        if(maxCurrent > minCurrent)
        {
            maxPt = maxCurrent;
            minPt = minCurrent;
        }
        else
        {
            swap(S, s);
            maxPt = minCurrent;
            minPt = maxCurrent;
        }
        if(maxPt < A[i])
    }
    return ret;
}

int main()
{
//    double A[6] = {-2.54,0,3,0.5,8,-1};
//    double maxPt = maxProductByBruteForce(A, 6);
    //int A[4] = {2,3,-2,4};
//    int A[2] = {0, 2};
//    int A[1] = {-2};
//    int maxPt = maxProductBest(A, 1);
    double A[6] = {-2.54,0,3,0.5,8,-1};
    double maxPt = maxProductBest(A, 6);
    cout << maxPt << endl;
}
