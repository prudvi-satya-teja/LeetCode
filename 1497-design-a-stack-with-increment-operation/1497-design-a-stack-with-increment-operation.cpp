class CustomStack {
public:
    vector<int> v;
    int top = -1;
    CustomStack(int maxSize) {
        for(int i=0; i<maxSize; i++) {
            v.push_back(0);
        }
    }
    
    void push(int x) {
        if(top == v.size()-1) {
            return;
        }
        top++;
        v[top] = x;
    }
    
    int pop() {
        if(top == -1) {
            return -1;
        }
        int ele =  v[top];
        top--;
        return ele;
        
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k && i <= top; i++) {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */