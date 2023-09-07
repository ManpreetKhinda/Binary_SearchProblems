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
int studs(vi&books, int limit, int n){
    int numstuds=1, curr=0;
    for(int i=0;i<n;i++){
        if(curr+books[i]>limit){
            numstuds++;
            curr=books[i];
        }
        else curr+=books[i];
    }
    return numstuds;
}

int minbookallocation(vi &books, int n,int k){
    if(k>n)return -1;
    int low=*max_element(books.begin(),books.end());
    int high=accumulate(books.begin(),books.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int students=studs(books,mid,n);
        if(students>k)low=mid+1;
        else high=mid-1;
    }
    return low;
}