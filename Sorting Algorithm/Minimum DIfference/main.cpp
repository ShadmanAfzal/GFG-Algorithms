#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{10, 22, 28, 29, 30, 40};
    int l = 0, r = arr.size()-1;
    int result_l, result_r, diff = INT_MAX,x = 54;

    while(l<r){
        if(abs(arr[l]+arr[r]-x) < diff){
            diff = abs(arr[l]+arr[r]-x);
            // cout<<diff<<endl;
            cout<<l<<endl;
            result_l = l;
            result_r = r;
        }
        if(arr[l]+arr[r]>x){
            r--;
        }
        else
            l++;
    }

    cout<<arr[result_l]<<" "<<arr[result_r]<<endl;

}