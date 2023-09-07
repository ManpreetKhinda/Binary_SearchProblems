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
int findpivot(vi &a){
    int low=0, high=a.size()-1;
    int index, ans=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[low]<=a[high]){
            if(a[low]<ans){
                index=low;
                ans=a[low];
                break;
            }
        }
        if(a[low]<=a[mid]){
            if(a[low]<ans){
                index=low;
                ans=a[low];
            }
            low=mid+1;
        }
        else {
            high=mid-1;
            if(a[mid]<ans){
                index=mid;
                ans=a[mid];
            }
        }
    }
    return index;
}
bool findpair(vi &a, int k){
    int left=findpivot(a);
    int right=(a.size()+left-1)%a.size();
    while(left!=right){
        if(a[left]+a[right]==k)return 1;
        else if(a[left]+a[right]<k)left=(left+1)%a.size();

        else right=(right+a.size()-1)%a.size();
    }
    return false;
}
int main(){
    vi a={11,15, 6, 8, 9, 10};
    
    cout<<findpair(a,45);
}