#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //CASE 1:

    //BRUTE FORCE
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i= 0; i<n; i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        for(int i=0; i<n/2; i++){
            nums[2*i]= pos[i];
            nums[2*i+1]= neg[i];
        }
        return nums;
    }


    //BETTER
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size();
        vector<int>arr(n,0);
        int pos=0, neg=1;
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                arr[pos]= nums[i];
                pos=pos+2;
            }else{
                arr[neg]= nums[i];
                neg= neg+2;
            }
        }
        return arr;
    }

    //CASE 2:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i=0; i<n; i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        int p= pos.size();
        int t= neg.size();
        if(p>t){
            for(int i=0; i<t; i++){
                nums[i*2]= pos[i];
                nums[i*2+1]= neg[i];
            }
            int index=t*2;
            for(int i=t; i<p; i++){
                nums[index]= pos[i];
                index++;
            }
        }else{
            for(int i=0; i<p; i++){
                nums[i*2]= pos[i];
                nums[i*2+1]= neg[i];
            }
            int index=p*2;
            for(int i=p; i<t; i++){
                nums[index]= neg[i];
                index++;
            }
        }
        return nums;
    }
};
int main() {
    return 0;
}