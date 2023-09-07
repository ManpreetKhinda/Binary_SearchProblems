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

bool ispossible(vi& stalls,int dist, int cows){
    int cntcows=1, last=stalls[0];
    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-last>=dist){
            cntcows++;
            last=stalls[i];
        }
        if(cntcows>=cows)return true;
    }
    return false;
}
int maxdis(vi &stalls, int n, int k){
    sort(stalls.begin(),stalls.end());
    int low=1, high=stalls[n-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(ispossible(stalls,mid,k))low=mid+1;
        else high=mid-1;
    }
    return high;
}