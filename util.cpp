#include<vector>
using namespace std;
void swap(vector<int>v,int i,int j)
{
    int tmp=v[i];
    v[i]=v[j];
    v[j]=tmp;
}

void swapCal(vector<int>v,int i,int j)
{
    if(i==j) return;
    v[i]+=v[j];
    v[j]=v[i]-v[j];
    v[i]-=v[j];
}

void swapXOR(vector<int>v,int i,int j)
{
    if(i==j) return;
    v[i]^=v[j];
    v[j]^=v[i];
    v[i]^=v[j];
}