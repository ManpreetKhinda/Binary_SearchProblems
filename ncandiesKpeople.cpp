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
vector<int> solve(int n,int k){
    int count=0;
    int ind=1;
    vector<int>ans(k,0);
    while(n){
        int t1=(ind-1)*k;
        int t2=(ind)*k;
        int s1=(t1*(t1+1))/2;
        int s2=(t2*(t2+1))/2;
        int res=s2-s1;
        if(res<=n){
            count++;
            n-=res;
            ind++;
        }
        else{
            int i=0;
            int term=((ind-1)*k)+1;
            while(n>0){
                if(term<=n){
                    ans[i++]=term;
                    n-=term;
                    term++;
                }
                else{
                    ans[i++]=n;
                    n=0;
                }
            }
        }
    }
    for(int i=0;i<k;i++){
        ans[i]+=(count*(i+1))+(k*count*(count-1))/2;
    }
    return ans;
}
vector<int> solvebs(int n,int k){
    int count=0;
    int ind=1;
    vector<int>ans (k,0);
    int low=0,high=n;
    while(low<=high){
        int mid=(low+high)/2;
        int sum=(mid*(mid+1))/2;
        if(sum<=n){
            count=mid/k;
            low=mid+1;
        }
        else high=mid-1;
    }
    int last=(count*k);
    n-=(last*(last+1))/2;
    int i=0;
    int term=(count*k)+1;
    while(n){
        if(term<=n){
            ans[i++]=term;
            n-=term;
            term++;
        }
        else {
            ans[i]+=n;
            n=0;
        }
    }
    for(int i=0;i<k;i++){
        ans[i]+=(count*(i+1))+(k*(count-1)/2);
    }
}
vector<int> dist(int n,int k){
    vector<int> res(k,0);
    int i=0;
    while(n>0){
        int to_distri=min(n,i+1);
        res[i%k]+=to_distri;
        n-=to_distri;
        i+=1;
    }
    return res;
}