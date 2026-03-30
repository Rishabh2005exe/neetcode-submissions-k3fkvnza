class MinStack {
    private:
        struct node
        {
            int item;
            int minsofar;
            node* next;
        };

        node* topnode;

    public:
        MinStack() {
            topnode =NULL;
        }
    
    void push(int val) {
        node* n = new node;
        n->item = val;
        
        if(topnode == NULL)
            n->minsofar = val;
        else
            n->minsofar = (val < topnode->minsofar) ? val: topnode->minsofar;
        n->next = topnode;
        topnode = n;
    }
    
    void pop() {
        node* r;
        if(topnode!= NULL)
        {
            r = topnode;
            topnode = topnode->next;
            delete r;
        }
    }
    
    int top() {
        return topnode->item;
    }
    
    int getMin() {
        return topnode->minsofar;
    }
};
