#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int freq;
    char ch;
    Node* left,*right;

    Node(int f, char c, Node* l=NULL, Node* r=NULL)
    {
        freq=f;
        ch=c;
        left=l;
        right=r;
    }
};

struct compare
{
    bool operator()(Node* l , Node* r)
    {
        return l->freq > r->freq;
    }
};


void printCodes(Node* root, string str="")
{
    if(root->ch != '$')
    {
        cout<<root->ch<<"  "<<str<<"\n";
        return;
    }

    printCodes(root->left, str+"0");
    printCodes(root->right, str+"1");
}
void printHCodes(char arr[], int freq[], int n)
{
    priority_queue<Node*, vector<Node*> , compare> h;

    for(int i=0; i<n;i++)
    {
        h.push(new Node(freq[i],arr[i]));
    }

    while( h.size() > 1)
    {
        Node* l = h.top();

        h.pop();

        Node* r = h.top();

        h.pop();

        Node* node = new Node(l->freq+r->freq,'$',l,r);

        h.push(node);
    }

    printCodes(h.top());
}

int main()
{
    int n;
    
    cout<<"Enter the number of distinguished characters : "<<endl;
    cin>>n;

    char arr[n];
    int freq[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Character "<<(i+1)<<" : ";
        cin>>arr[i];

        cout<<"Frequncy "<<(i+1)<<" : ";
        cin>>freq[i];
    }

    cout<<"CHARACTERS AND THEIR FREQUENCIES : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t"<<freq[i]<<endl;
    }


    cout<<"Characters and their codes : "<<endl;
    printHCodes(arr, freq, n);


    return 0;
}
