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
bool ispossible(vi & arr, int day, int m, int k){
    int cnt=0, bouquet=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<=day)cnt++;
        else{
            bouquet+=(cnt/k);
            cnt=0;
        }
    }
    bouquet+=cnt/k;
    return bouquet>=m;
}

int mindays(vi&bloomday,int m, int k){
    int val=m*k;
    if(val>bloomday.size())return -1;
    int low=*min_element(bloomday.begin(),bloomday.end());
    int high=*max_element(bloomday.begin(),bloomday.end());
    while(low<=high){
        int mid=(low+high)/2;
        if(ispossible(bloomday, mid,m,k))high=mid-1;
        else low=mid+1;
    }
    return low;
}