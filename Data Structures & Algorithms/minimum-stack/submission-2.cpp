class MinStack {
    private:
        struct node {
            int item;
            int minsofar;
            node *next;
        };

        node *topNode;

    public:

    MinStack() {
        topNode = NULL;
    }
    
    void push(int val) {
        node *n;
        n=new node;
        n->item = val;
        if(topNode==NULL)
            n->minsofar=val;
        else
            n->minsofar = (val< topNode->minsofar)?val:topNode->minsofar;
        n->next=topNode;
        topNode=n;
    }
    
    void pop() {
        node *r;
        if(topNode!=NULL)
        {
            r=topNode;
            topNode = topNode->next;
            delete r;
        }
    }
    
    int top() {
        return topNode->item;
    }

    
    int getMin() {
        return topNode->minsofar;
    }
};
