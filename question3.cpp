 #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define vl vector<ll>
    #define pb push_back
    #define endl '\n'
    #define pf push_front
    #define OO 1e18
    #define vi vector<int>
    #define vs vector<string>
    #define dql deque<ll>
    #define GO  cin.tie(0);cout.tie(0);ios::sync_with_stdio(0)
    #define tt int t;cin>>t
    #define nn long long n;cin>>n
    #define       forn(i,n)              for(int i=0;i<n;i++)
    #define  all(v)  v.begin(), v.end()
    #define allr(v) v.rbegin() , v.rend()
#define ld long double
#define R return
#define C continue
#define print(a) for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
#define rfor(i,n) for(int i=n-1;i>=0;i--)
int n;
int a[5][3]={
{1,20,2},
{10,25,50},
{25,5,5},
{21,4,4},

{4,1,1}

};
pair<int,pair<int,int>> solve(int index,int cur_wight,int cur_size);

pair<int,pair<int,int>> dp[5][100][100];
int max_size,max_wight;
int main(){
    for(int i=0;i<5;i++){
    for(int j=0;j<100;j++){
        for(int k=0;k<100;k++){
            dp[i][j][k]={-1,{-1,-1}};
        }
    }
}
cin>>max_size>>max_wight;
pair<int,pair<int,int>> tmp=solve(0,max_wight,max_size);
cout<<tmp.first<<endl;
cout<<tmp.second.first<<endl;
cout<<tmp.second.second<<endl;

///


}
//price wight number of taken elements
pair<int,pair<int,int>> solve(int index,int cur_wight,int cur_size){
if(index>=5 || cur_size<=0 || cur_wight<=0) return {0,{0,0}};
    if( -1 != dp[index][cur_wight][cur_size].first)
{
    return dp[index][cur_wight][cur_size];
}
 pair<int,pair<int,int>> k1=solve(index+1,cur_wight,cur_size);
pair<int,pair<int,int>>  k2={0,{0,0}};
if(cur_size-a[index][2]>=0 && cur_wight-a[index][1]>=0){

   pair<int,pair<int,int>>tmp= solve(index+1,cur_wight-a[index][1],cur_size-a[index][2]);
      k2={a[index][0]+tmp.first,{a[index][1]+tmp.second.first,1+tmp.second.second}};
}
dp[index][cur_wight][cur_size]=max(k1,k2);
return dp[index][cur_wight][cur_size];
}
