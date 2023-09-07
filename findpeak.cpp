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
int findpeak(vi&arr){
    int n=arr.size();
    if(n==1)return 0;
    if(arr[0]>arr[1])return 0;
    if(arr[n-1]>arr[n-2])return n-1;
    int low=1,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] &&arr[mid]>arr[mid+1])return mid;
        else if(arr[mid]>arr[mid-1])low=mid+1;
        else high=mid-1;
    }
    return -1;
}
