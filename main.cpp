#include <iostream>
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

    printCodes(base->left, str + "0");
    printCodes(base->right, str + "1");
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

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    print(minHeap.top(), "");
}

