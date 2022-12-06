TC: O(nlogn)

#include <bits/stdc++.h>
using namespace std;
int solve(int n, int k ,vector<int>& v)
{
    // basic goal : hmare array m max k distinct element hone chahiye.

    unordered_map<int,int>mp; // element , ele_count;
    
    for(auto it: v)
    {
        mp[it]++;
    }
    int dis_ele= mp.size();
    if(dis_ele<=k)return 0;
    // else element k se jyada distinct h to nikalna pdega unhe.

    vector<int>sums;
    for(auto it: mp)
    {
        sums.push_back(it.first * it.second);
        // cout<<it.first<<" : "<<it.second<<endl;

    }
    sort(sums.begin(), sums.end());

    dis_ele= dis_ele-k;
    int ans=0;
    for(int i=0; i<dis_ele && i<sums.size(); i++)
    {
        ans+= sums[i];
    }
    return ans;
    
}
int main(){

    cout<<"enter the no of element\n";
    int n, k;
    cin>>n;
    vector<int>v(n);
    cout<<"enter the array value\n";
    for(int i=0; i<n ; i++)cin>>v[i];
    cout<<" enter the value of k\n";
    cin>>k;
    cout<<solve(n, k, v);
    return 0;
}
