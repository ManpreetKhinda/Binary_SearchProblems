#include <iostream>
#include <cmath>
#include <stack>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <numeric>
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
int days(vi &arr, int limit){
    int day=1, load=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]+load>limit){
            day++;
            load=arr[i];
        }
        else load+=arr[i];
    }
    return day;
}

int mindays(vi& weights, int k){
    int low=*min_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int ndays=days(weights,mid);
        if(ndays<=k)high=mid-1;
        else low=mid+1;
    }
    return low;
}
