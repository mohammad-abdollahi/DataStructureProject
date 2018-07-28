#include <iostream>
#include <queue>
using namespace std;

class heapNode{
public:
    char data;
    unsigned int freq;
    heapNode *l,*r;

    heapNode(char d, unsigned int freq){
        this->r=this->l=NULL;
        this->freq=freq;
        this->data=d;
    }
};


struct compare {

        bool operator()(heapNode* l, heapNode* r)

        {
            return (l->freq > r->freq);
        }
};


void print(struct heapNode *base, string str){
    if (!base)
        return;

    if (base->data != '$')
        cout << base->data << ": " << str << "\n";

    print(base->l, str + "0");
    print(base->r, str + "1");
}


void Huffman(char data[], int freq[], int size)
{
    struct heapNode *left, *right, *top;

    priority_queue <heapNode*, vector<heapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new heapNode(data[i], freq[i]));

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new heapNode('$', left->freq + right->freq);

        top->l = left;
        top->r = right;

        minHeap.push(top);
    }

    print(minHeap.top(), "");
}

int main()
{

    char arr[27] = {};
    int freq[27] = {};
    int i = 0, size=0;
    cout<<"Enter the number of characters:";
    cin>>size;


    while(i<size)
    {
        cout<<"Enter character:";
        cin>>arr[i];
        cout<<"Enter frequency:";
        cin>>freq[i];
        i++;
    }

    Huffman(arr, freq, i);

    return 0;
}
