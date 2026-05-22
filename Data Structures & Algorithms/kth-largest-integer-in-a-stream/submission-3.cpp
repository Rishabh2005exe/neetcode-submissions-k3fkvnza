class KthLargest {
    int k;
    priority_queue<int>pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int x:nums)
            pq.push(x);
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int>pq2 =pq;
        int temp=k;
        temp--;
        while(temp)
        {
            pq2.pop();
            temp--;
        }
        return pq2.top();
    }
};
