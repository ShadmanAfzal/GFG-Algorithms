#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    char data;
    int freq;
    Tree *left, *right;

    Tree(char c, unsigned freq)
    {
        this->data = c;
        this->freq = freq;
        this->left = this->right = NULL;
    }
};

struct compare
{
    bool operator()(Tree *left, Tree *right)
    {
        return (left->freq > right->freq);
    }
};

void printCode(Tree* top, string str){

    if(!top)
        return;

    if(top->data != '$'){
        cout<<top->data<<" : "<<str<<"\n";
    }

    printCode(top->left, str+'0');
    printCode(top->right, str+'1');
}

void HuffmanCoding(vector<char> character, vector<unsigned> freq)
{
    Tree* left, *right, *top;
    priority_queue<Tree *, vector<Tree *>, compare> pq;

    for(int i=0;i<character.size();i++){
        pq.push(new Tree(character[i],freq[i]));
    }

    while(pq.size()){
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        top = new Tree('$',left->freq+right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    printCode(pq.top(),"");
}

int main()
{
    vector<char> character{'a', 'b', 'c', 'd', 'e', 'f'};
    vector<unsigned> freq{5, 9, 12, 13, 16, 45};

    HuffmanCoding(character,freq);
}