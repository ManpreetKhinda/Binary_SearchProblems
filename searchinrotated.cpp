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

/* search in rotated array w/o dups*/
int search(vi&nums, int k){
    int n=nums.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==k)return mid;
        if(nums[low]<=nums[mid]){
            if(nums[low]<=k && k<=nums[mid]){
                high=mid-1;
            }
            low=mid+1;
        }
        else {
            if(nums[mid]<=k && k<=nums[high]){
                low=mid+1;
            }
            else high=mid-1;
        }
    }
    return -1;
}
/* search in rotated array with dups*/
int search(vi &nums, int k){
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==k)return true;
        if(nums[low]==nums[mid] &&nums[mid]==nums[high]){
            low++;high--;
            continue;
        }
        if(nums[low]<=nums[mid]){
            if(nums[low]<=k &&nums[mid]>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            if(nums[mid]<=k &&nums[high]>=k){
                low=mid+1;
            }
            else high=mid-1;
        }
    }
    return 0;
}

