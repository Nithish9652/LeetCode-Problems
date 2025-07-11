class Disjoint{
    public:
    vector<long long>parent,size,num;
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        num.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findUpar(parent[node]);
    }

    void UnionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
            num[ulp_u]+=num[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            num[ulp_v]+=num[ulp_u];
        }
    }
};
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n=nums.size();
        int m=removeQueries.size();
        vector<long long>ans;
        Disjoint ds(n);
        ans.push_back(0);
        vector<int>present(n,0);
        for(int i=0;i<n;i++){
            ds.num[i]=nums[i];     //giving oject num the same value of nums
        }
        long long maxa=0;
        for(int i=m-1;i>=0;i--){
            int cur_ind=removeQueries[i];
            present[cur_ind]=1;
            if(cur_ind-1>=0 && present[cur_ind-1]==1){
                ds.UnionBySize(cur_ind,cur_ind-1);              //if left is present then merge it
            }
            if(cur_ind+1<n && present[cur_ind+1]==1){
                ds.UnionBySize(cur_ind,cur_ind+1);              //if right is present then merge it also with current index
            }
            maxa=max(maxa,ds.num[ds.findUpar(cur_ind)]);        //take maximum at each merge
            ans.push_back(maxa);
        }
        // for(auto it:ans){
        //     cout<<it<<" ";
        // }
        ans.pop_back();                     //at last we get total sum value also we not need this so just removed
        reverse(ans.begin(),ans.end());     
        return ans;
        
    }
};