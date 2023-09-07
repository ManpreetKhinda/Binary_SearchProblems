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
long long int hours(vi &piles, int rate){
    long long int hrs=0;
    for(int i=0;i<piles.size();i++){
        hrs+=ceil(double(piles[i])/(double)rate);
    }
    return hrs;
}
int minspeed(vi& piles, int h){
    int high=*max_element(piles.begin(),piles.end());
    int low=1;
    while(low<=high){
        int mid=(low+high)/2;
        long long int th=hours(piles,mid);
        if(th<=h)high=mid-1;
        else low=mid+1;
    }
    return low;
}