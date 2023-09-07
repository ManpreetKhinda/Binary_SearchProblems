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
int findmin(vector<int>&arr){
    int n=arr.size();
    int ans=INT_MAX;
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){
            ans=min(ans,arr[low]);
            break;
        }
        if(arr[low]<=arr[mid]){
            ans=min(ans, arr[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,arr[mid]);
            high=mid-1;
        }
    }
}
/* number of times arr has been rotated*/
int indexofrotation(vi&arr){
    int n=arr.size();
    int low=0,high=n-1;
    int index=-1;
    int mini=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<mini){
                mini=arr[low];
                index=low;
            }
            break;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<mini){
                mini=arr[low];
                index=low;
            }
            low=mid+1;
        }
        else{
            if(arr[mid]<mini){
                mini=arr[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
}

