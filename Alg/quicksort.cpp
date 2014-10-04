#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
int choosePivot(vector<T> &A, int left, int right)
{
    return left;
}

template<typename T>
void qsswap(vector<T> &A, int i, int k)
{
    T temp = A[i];
    A[i] = A[k];
    A[k] = temp;
}

template<typename T>
int partion(vector<T> &A, int left, int right)
{
    int pivotIndex = choosePivot(A, left, right);
    T pivotValue = A[pivotIndex];
    // swap A[pivotIndex] and A[right]
    qsswap(A, pivotIndex, right);

    int storeIndex = left;
    for(int i=left; i<right; i++)
    {
        if(A[i]<pivotValue)
        {
            qsswap(A, storeIndex, i);
            storeIndex++;
        }
    }
    qsswap(A, storeIndex, right);
    return storeIndex;
}

template<typename T>
void quicksort(vector<T> &A, int i, int k)
{
    int p = partion(A, i, k);
    if(i<k)
    {
        quicksort(A, i, p-1);
        quicksort(A, p+1, k);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    vector<float> A;
    A.clear();
    A.push_back(5);
    A.push_back(4);
    A.push_back(6);
    A.push_back(2);
    A.push_back(9);
    A.push_back(1);
    quicksort(A, 0, A.size()-1);
    //sort(A.begin(), A.end());
    for(int i=0; i<A.size(); i++)
    {
        cout << A[i] << endl;
    }
    return 0;
}
