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
int count(vi &arr, int div){
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        cnt+=ceil((double)arr[i]/(double)div);
    }
    return cnt;
}

int smallestid(vi &nums, int k){
    int low=1, high=*max_element(nums.begin(),nums.end());
    while(low<=high){
        int mid=(low+high)/2;
        if(count(nums,mid)<=k)high=mid-1;
        else low=mid+1;
    }
    return low;
}