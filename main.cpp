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
