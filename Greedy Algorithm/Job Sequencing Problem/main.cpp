#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char ID;
    int deadline;
    int profit;
    Job(int id, int deadline, int profit) : ID(id), deadline(deadline), profit(profit) {}
};

bool compare(Job a, Job b){
    return (a.profit > b.profit);
}

void printJobSequence(vector<Job> jobs, int size){
    vector<bool> slots(size,false);
    vector<int> result(size);

    sort(jobs.begin(),jobs.end(),compare);

    for(int i=0;i<size;i++){
        for(int j = min(size, jobs[i].deadline)-1; j>=0 ; j--){
            if(slots[j]==false){
                result[j] = i;
                slots[j] = true;
                break;
            }
        }
    }

    for(int i=0;i<result.size();i++){
        if(slots[i])
            cout<<jobs[result[i]].ID<<" ";
    }
}

int main()
{
    vector<Job> jobs {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};
    int size = jobs.size();
    printJobSequence(jobs,size);
}