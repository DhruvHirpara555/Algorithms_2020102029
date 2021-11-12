#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

// node of huffman tree
typedef struct Node {
    int freq;
    char sym;
    Node* left;
    Node* right;
} Node;



Node* makeNode(int freq, char sym, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->freq = freq;
    node->sym = sym;
    node->left = left;
    node->right = right;
    return node;
}

// comparator for priority queue
class compare {
    public:
        bool operator()(const Node* a,const Node* b) const
        {
            return a->freq > b->freq;
        }
};

// huffman tree builder fuction

Node* treemaker(unordered_map<char,int> freq,string str){
    vector<Node*> nodes;
    // adding all the frequenncy of the symbols to the priority queue
    for(auto it = freq.begin(); it != freq.end(); it++){
        nodes.push_back(makeNode(it->second,it->first,NULL,NULL));
    }

    priority_queue<Node*,vector<Node*>,compare> pqueue;
    for(auto it = nodes.begin(); it != nodes.end(); it++){
        pqueue.push(*it);
    }
    while (pqueue.size() > 1) {
        // Greedy step :- getting two minimum frequencies nodes from the priority queue
        Node* lchild = pqueue.top();
        pqueue.pop();
        Node* rchild = pqueue.top();
        pqueue.pop();
        // restructure step :- creating a new node with the sum of the two minimum frequencies and adding it to the priority queue
        int p_freq = lchild->freq + rchild->freq;
        Node* parent = makeNode(p_freq, '\0', lchild, rchild);
        pqueue.push(parent);
    }
    Node* root = pqueue.top();
    return root;// returning the huffman tree
}

// making hashmap of the huffman codes
// code is initially empty string then it is appended with 0 or 1 depending on the left or right child
void getcoding(Node* root,unordered_map<char,string> &codemap,string code){

    if(root ==NULL){
        return;
    }
    // if the node is a leaf node then add the code to the hashmap
    if(root->left == NULL && root->right == NULL){
        codemap[root->sym] = code;
    }
    // recursively calling the function for the left and right child
    // appending 0 to the code for left child and 1 for right child
    getcoding(root->left,codemap,code+"0");
    getcoding(root->right,codemap,code+"1");
}

// getting the huffman code for the given inpyt string
string encode(string str,unordered_map<char,string> codemap){
    string encoded;
    for(int i = 0; i < str.length(); i++){
        encoded += codemap[str[i]];
    }
    return encoded; //returning the encoded string
}
// decoding the huffman code
// traversing the huffman tree and checking the bit at the front of the code
// if the bit is 0 then go to the left child else go to the right child
pair<int,string> help_decode(Node* root,int i,string encoded,string decode_char){
    if(root == NULL){
        return make_pair(i,decode_char);
    }
    if(root->left ==NULL && root->right == NULL){
        decode_char = root->sym;
        return make_pair(i,decode_char);
    }

    if(encoded[i] == '0'){
        root = root->left;
    }
    else{
        root = root->right;
    }
    i++;
    return help_decode(root,i,encoded,decode_char);
}

// decode using the huffman tree
// traverse through the huffman tree and get the character from the huffman code
string decode(Node* root,string encoded){
    string decoded;
    decoded = "";
    int i = 0;
    int len = encoded.length();
    while (i<len) {
        pair<int,string> p = help_decode(root,i,encoded,"");
        i = p.first;
        decoded += p.second;
    }
    return decoded;

}

// frequncy of the symbols in the input string
unordered_map<char,int> Count_freq(string str,int len){
    unordered_map<char,int> freq;

    for(int i=0;i<len;i++){
        freq[str[i]]++;
    }
    return freq;
}

int main(){

    string str =  "soda is jod soda is jod soda is jod soda is jod soda is jod soda is jod ";

    int len = str.length();
    unordered_map<char,int> freq = Count_freq(str,len);

    cout << "pritnting freq" << endl;
    for(auto it = freq.begin();it!=freq.end();it++){
        cout<<"\""<<it->first<< "\" - "<<it->second<<endl;
    }

    Node* root = treemaker(freq,str);


    cout << "pritnting ecoding function" << endl;
    unordered_map<char,string> codemap;
    getcoding(root,codemap,"");


    for(auto it = codemap.begin();it!=codemap.end();it++){
        cout<<"\""<<it->first<< "\" - \""<<it->second<<"\""<<endl;
    }


    string encoded = encode(str,codemap);
    cout << "pritnting encoded" << endl;
    cout << encoded << endl;

    string decoded = decode(root,encoded);
    cout << "pritnting decoded" << endl;
    cout << decoded << endl;


}

