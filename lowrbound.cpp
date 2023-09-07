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

/*
smallest index sucht hat arr[ind]>=x
lb=lower_bound(arr,arr+n)-arr;
similar fo upper
upper bound smallesst index such tha arr[ind]>x;
min_element(arr,arr+n)
*/
int lowerbound(vector<int>&arr,int n, int x ){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
int upperbound(vector<int>&arr,int n,int x){
    int low=0,high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
/* arr[ind]<=x*/
int floor(vector<int>&arr,int n,int x){
    int low=0,high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=x){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
}
