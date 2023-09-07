#include <iostream>
#include <cmath>
#include <stack>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#define vi vector<int>
#define vvi vector<vi>
#define pii vector<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
using namespace std;
double median(vector<int>&a, vector<int>&b){
    int n1=a.size();
    int n2=b.size();
    if(n1>n2)return median(b,a);
    int low=0,high=n1;
    int left=(n1+n2+1)/2;
    int n=n1+n2;
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;
        if(mid1<n1)r1=a[mid1];
        if(mid2<n2)r2=b[mid2];
        if(mid1-1>=0)l1=a[mid1-1];
        if(mid2-1>=0)l2=b[mid2-1];
        if(l1<=r2 && l2<=r1){
            if(n%2==1)return max(l1,l2);
            return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
        }
        else if(l1>r2)high=mid1-1;
        else low=mid1+1;
    }
    return 0;
}
/* kth element of two sorted arrays*/
int kth(vector<int>&a, vector<int>&b,int k){
    int n1=a.size();
    int n2=b.size();
    if(n1>n2)return kth(b,a,k);
    int low=max(0,k-n2),high=min(k,n1);
    int left=k;
    // int n=n1+n2;
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=left-mid1;
        int l1=INT_MIN, l2=INT_MIN;
        int r1=INT_MAX, r2=INT_MAX;
        if(mid1<n1)r1=a[mid1];
        if(mid2<n2)r2=b[mid2];
        if(mid1-1>=0)l1=a[mid1-1];
        if(mid2-1>=0)l2=b[mid2-1];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);

        }
        else if(l1>r2)high=mid1-1;
        else low=mid1+1;
    }
    return 0;
}