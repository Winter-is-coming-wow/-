#include<iostream>
#include"util.cpp"
using namespace std;

//冒泡排序
//提前结束
void bubbleSort(vector<int>&arr)
{
    if(arr.size()<2) return;
    for(int i=0;i<arr.size();++i)
    {
        bool swapped=false;
        for(int j=1;j<arr.size()-i;++j)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr,j-1,j);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}

//提前结束+冒泡界优�?
void bubbleSort_opt(vector<int>&arr)
{
    if(arr.size()<2) return;
    bool swapped=true;
    int lastSwappedIdx=arr.size()-1;
    int swappedIdx=-1;
    while(swapped)
    {
        swapped=false;
        for(int i=0;i<lastSwappedIdx;++i)
        {
            if(arr[i]>arr[i+1])
            {
                swap(arr,i,i+1);
                swapped=true;
                swappedIdx=i;
            }
        }
        lastSwappedIdx=swappedIdx;
    }
}

//选择排序
void selectSort(vector<int>&arr)
{
    if(arr.size()<2) return;
    for(int i=0;i<arr.size();++i)
    {
        int minIdx=i;
        for(int j=i+1;j<arr.size();++j)
        {
            if(arr[j]<arr[minIdx])
            {
                minIdx=j;
            }
        }
        if(minIdx!=i) swap(arr,i,minIdx);
    }
}
//双元选择排序
void selectSortDouble(vector<int>&arr)
{
    if(arr.size()<2) return;
    int n=arr.size();
    for(int i=0;i<n-1-i;++i)
    {
        int minIdx=i,maxIdx=i;
        for(int j=i+1;j<n-i;++j)
        {
            if(arr[j]<arr[minIdx]) minIdx=j;
            if(arr[j]>arr[maxIdx]) maxIdx=j;
        }
        if(minIdx==maxIdx) break;
        if(minIdx!=i) swap(arr,i,minIdx);
        if(maxIdx==i) maxIdx=minIdx;
        if(maxIdx!=n-i-1) swap(arr,n-i-1,maxIdx);
    }
}

int main()
{
    vector<int>arr={1,-4,5,0,87,2,465,78,4,322};
    selectSortDouble(arr);
    for(auto &i:arr)
    {
        cout<<i<<' ';
    }
    cout<<endl;
    system("pause");
    return 0;
}