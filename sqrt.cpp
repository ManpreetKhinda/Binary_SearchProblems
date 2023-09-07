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
/* binary seatch on answers*/
long long sqrt(long long x){
    int low=1,high=x;
    while(low<=high){
        long long int mid=(low+high)/2;
        if(mid*mid<=x){

            low=mid+1;
        }
        else high=mid-1;
    }
    return high;
}
/* nth root of an integer*/
int funct(int mid,int n,int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=mid;
        if(ans>m)return 2;
       
    }
    if(ans==m)return 1;
    return 0;
}
int nthroot(int n, int m){
    int low=1,high=m;
    while(low<=high){
        int mid=(low+high)/2;
        int midN=funct(mid,n,m);
        if(midN==1)return mid;
        else if(midN==0)low=mid+1;
        else high=mid-1;
    }
    return -1;
}

