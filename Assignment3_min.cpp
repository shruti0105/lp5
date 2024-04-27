#include<bits/stdc++.h>
#include<omp.h>

using namespace std;

int findMin(int arr[],int n)
{
    int minm=arr[0];

    #pragma omp parallel for reduction(min: minm)
    for(int i=0;i<n;i++)
    {
        if(arr[i]<minm)
        {
            minm=arr[i];
        }

    }

    return minm;
}

int findMax(int arr[],int n)
{
    int maxm=arr[0];

    #pragma omp parallel for reduction(max: maxm)
    for(int i=0;i<n;i++)
    {
        if(arr[i]>maxm)
        {
            maxm=arr[i];
        }

    }

    return maxm;
}

int summation(int arr[],int n)
{
    int sum=0;
    #pragma omp parallel for reduction(+ :sum)
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }

    return sum;
}

double average(int sum,int n)
{
    return (double)(sum)/n;
}


int main()
{
    int n=5;
    int arr[]={1,2,3,4,6};
    cout<<findMin(arr,n)<<endl;
    cout<<findMax(arr,n)<<endl;
    int sum=summation(arr,n);
    cout<<sum<<endl;
    cout<<average(sum,n);

}