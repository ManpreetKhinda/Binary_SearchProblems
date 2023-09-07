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

/*
for(int i=0;i<arr.size();i++){
    if(arr[i]<=k)k++;
    else break;
}
return k
*/

int findkthpositive(vi&arr, int k){
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k)low=mid+1;
        else high=mid-1;
    }
    return low+k;
}