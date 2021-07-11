#include <bits/stdc++.h>
using namespace std;

vector<int> deno{1, 2, 5, 10, 20,
              50, 100, 500, 1000};

void printChange(int currency){
    int remaining = currency;
    sort(deno.begin(), deno.end());
    cout<<"Change : ";
    for(int i = deno.size()-1; i >=0; i--){
        while(deno[i] <= currency)
        {
            currency -= deno[i];
            cout<<deno[i]<<" ";
        }
    }
}

int main()
{
    cout<<"Enter amount: ";
    int currency;
    cin>>currency;
    printChange(currency);
}