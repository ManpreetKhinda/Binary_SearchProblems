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
int stationsreq(vi & stations, long double dist){
    int cnt=0;
    for(int i=1;i<stations.size();i++){
        int numberinbetween=(stations[i]-stations[i-1])/dist;
        if((stations[i]-stations[i-1])/dist==numberinbetween+dist){
            numberinbetween--;
        }
        cnt+=numberinbetween;
    }
    return cnt;
}
double findmindistance(vi& stations, int k){
    int n=stations.size();
    long double low=0;
    long double high=0;
    for(int i=0;i<n-1;i++){
        high=max(high, (long double)(stations[i+1]-stations[i]));
    }
    long double diff=1e-6;
    while(high-low>diff){
        long double mid=(low+high)/2;
        int cnt=stationsreq(stations,mid);
        if(cnt>k)low=mid;
        else high=mid;
    }
    return high;
}