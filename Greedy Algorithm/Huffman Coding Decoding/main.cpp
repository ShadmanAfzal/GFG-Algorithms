#include <bits/stdc++.h>
using namespace std;

map<char, int> countFreq;
map<char, string> countCode;

class HuffmanCode{
public:
    char data;
    int freq;
    HuffmanCode* left, *right;
    HuffmanCode(char c, int freq) {
        this->data = c;
        this->freq = freq;
        this->left = this->right = NULL;
    }
};

struct compare{
    bool operator()(HuffmanCode* a, HuffmanCode* b){
        return (a->freq > b->freq);
    }
};

priority_queue<HuffmanCode*, vector<HuffmanCode*>, compare> pq;

void storeNodes(HuffmanCode* root,string str){
    
    if(root == NULL)  return;

    if(root->data != '$')
        countCode[root->data] = str;

    storeNodes(root->left,str+'0');
    storeNodes(root->right,str+'1');
}

void buildTree(){
    HuffmanCode* left, *right, *top;
    
    for(auto i: countFreq)
        pq.push(new HuffmanCode(i.first, i.second));

    while(pq.size()){
        left = pq.top();
        pq.pop();

        right = pq.top();
        pq.pop();

        top = new HuffmanCode('$', left->freq+right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }

    storeNodes(pq.top(),"");
}

void decodeTree(HuffmanCode* root, string encoded){

    HuffmanCode* curr = root;
    string ans = "";
    for(int i=0;i<encoded.size();i++){
        if(encoded[i]=='0')
            curr = curr->left;
        else
            curr = curr->right;

        if(!curr->left and !curr->right){
            ans += curr->data;
            curr = root;
        }
    }

    cout<<"Decoded Text -> "<<ans+'\0';
}

int main()
{
    string s = "GeeksforGeeks";
    string encoded = "";
    for(int i=0;i<s.size();i++)
        countFreq[s[i]]++;
    buildTree();
    for(auto i: s)
        encoded += countCode[i];
    cout<<"Encoded Text -> "<<encoded<<endl;
    decodeTree(pq.top(),encoded);
}