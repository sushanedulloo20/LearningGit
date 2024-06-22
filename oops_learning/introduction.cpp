#include<iostream>
#include<vector>
#include<set>
using namespace std;



int partition(vector<int> &v,int start,int end){
    int target=v[start];
    int count_less=0;
    for(int i=start+1;i<=end;i++){
        if(v[i]<=target){
            count_less++;
        }
    }
    int ind= start+count_less;
    v[start]= v[ind];
    v[ind]=target;
    int i=start;
    int j=end;
    while(i<j){
        if(v[i]>target && v[j]<=target){
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i++;
            j--;
        }
        else{
            if(v[i]<=target){
                i++;
            }
            if(v[j]>target){
                j--;
            }
        }
    }
    return ind;




}
void quickSort(vector<int> &v,int start,int end){
    if(start<end){
        int p=partition(v,start,end);
        quickSort(v,start,p-1);
        quickSort(v,p+1,end);

    }


}

void reject(vector<vector<int>> &v,int i,vector<int> nums){
    if(nums.size()==0){
        vector<int> temp(0);
        v.push_back(temp);
        return;
    }
    int size=nums.size()-1;
    vector<int> temp(size,0);
    bool flag=false;
    int k=0;
    for(auto e: nums){
        if(e==i && flag==false){
            flag=true;
        }
        else{
            temp[k++]=e;
        }
    }
    v.push_back(temp);
}
void solve(vector<int> nums,int index,vector<int> output,vector<vector<int>> &ans){
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }


    solve(nums,index+1,output,ans);
    int element=nums[index];
    output.push_back(element);
    solve(nums,index+1,output,ans);


}

vector<vector<int>> subsets(vector<int> nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(nums,index,output,ans);
    return ans;

}
void display(vector<vector<int>> v){
    for(auto row:v){
        if(row.size()==0){
            cout<<"NULL";
        }
        else{
        for(auto e:row){
            cout<<e<<" ";
        }}
    }}



int main(){
    // vector<int> v={1,2,3};
    // vector<vector<int>> result=subsets(v);
    // display(result);
    set<vector<int>> s;
    s.insert({1,2});
    s.insert({1,2,3});
    s.insert({1,2
    

    


}