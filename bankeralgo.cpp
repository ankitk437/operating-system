

#include <bits/stdc++.h>
#define ll long long int
#define   ull         unsigned long long
#define   ld          long double
#define   v          vector <ll>
#define   vv          vector<vector<long long>>
#define   pl          pair<long long,long long>
#define   vp          vector<pair<long long,long long>>
#define   vpp         vector<pair<long long,pair<long long,long long>>>
#define   vvp         vector<vector<pair<long long,long long>>>
#define   sl          set<long long>
#define   sp          set<pair<long long>>
#define   pb          push_back
#define   mp          make_pair
#define   eb          emplace_back
#define   ft          first
#define   sd          second

//#define   f(i,a,b)    for(ll i=a;i<b;i++)
#define   bb(i,a,b)   for(ll i=a;i>=b;i--)
#define   test        ll tt{0};cin>>tt;while(tt--)
#define all(x) x.begin(),x.end()
//#define mod 1000000007

using namespace std;

long long binpow(long long a, long long b, long long m) {
a %= m;
long long res = 1;
while (b > 0) {
if (b & 1)
res = res * a % m;
a = a * a % m;
b >>= 1;
}
return res;
}
  


  
vector<int> bankeralgo(int n,int m,vector<vector<int>> alloc,vector<vector<int>> max,vector<int> avail){

 
    vector<int> vis(n,0), ans(n,0); int ind = 0;

    vector<vector<int>> needed(n,vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            needed[i][j] = max[i][j] - alloc[i][j];
    }
    
    vector<int> totalalloc(m,0);
    vector<int> allocprocess;
    int totalprocess=0;
    //int prev=0;
    for (int k = 0; k < n&&totalprocess<n; k++) {
        for (int i = 0; i < n; i++) {
			
            if (vis[i] == 0) {
                
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (needed[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++){
                        avail[y] += alloc[i][y];}
                        totalprocess++;
                    vis[i] = 1;
                }
            }
        }
        
       
        
    }
   
      int flag = 1;
       
      for(int i=0;i<n;i++)
    {
      if(vis[i]==0)
      {
        flag=0;
        
        break;
      }
    }
     
    if(flag==0)return {};
    else return ans;
     
 

 


}
int main() {
  
vector<vector<int>> alloc{ {0,1,1},{ 2,1,0},{2,1,1},{2,3,1} };
vector<vector<int>> max{ {3,4,4 },{5,1,1 },{ 4,5,7},{ 5,6,7}   };
vector<int> avail{6,7,4 };
 vector<int> ans=bankeralgo(4,3,alloc,max,avail);
 if(ans.size()==0)cout<<"can't be allocated and system in deadlock";
 else {
	 cout<<"correct sequence of allocation of resouce to avoid deadlock";
	 cout<<endl;
	 for(int i:ans)cout<<i<<" ";
	 cout<<endl;
	 
	 }

   


    }
   // 1 12 8
