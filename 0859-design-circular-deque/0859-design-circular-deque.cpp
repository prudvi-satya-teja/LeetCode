class MyCircularDeque {
public:
    vector<long long> v;
    int k = 0;
    int si = -1;
    int ei = -1;

    MyCircularDeque(int k) {
        pulic: 
            for(int i=0; i<k; i++) {
                v.push_back(-1);
            }
            this->k = k;
    }
    
    bool insertFront(int value) {
        if(si == -1 && ei ==  -1) {
            si = 0;
            ei = 0;
        }
        else if(si == 0) {
            if(k-1 == ei) {
                return false;
            }
            si = k-1;
        }
        else {
            if(si-1 == ei) return false;
            si = si - 1;
        }

        v[si] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(si == -1 && ei == -1) {
            si = 0;
            ei = 0;
        }
        else if(ei == k-1) {
            if(si == 0) {
                return false;
            }
            ei = 0;
        }
        else {
            if(si == ei +1) {
                return false;
            }
            
            ei = (ei + 1);
        }
        v[ei] = value;
        return true;
    }
    
    bool deleteFront() {
        
        if(si == -1 && ei == -1) {
            return false;
        }
        else if(si == ei) {
            v[si] = -1;
            si = -1;
            ei = -1;
        }
        else {
            v[si] = -1;
            si = (si + 1) % (k);
        }
        return true;
    }
    
    bool deleteLast() {
        if(si == -1 && ei == -1) {
            return false;
        }
        else if(si == ei) {
            v[si] = -1;
            si = -1;
            ei = -1;
            
        }
        else if(ei == 0 ) {
            ei = k-1;
        }
        else {
            ei = (ei - 1);
        }
        return true;
    }
    
    int getFront() {
         if(si == -1 && ei == -1) {
            return -1;
        }
        return v[si];
    }
    
    int getRear() {
        if(si == -1 && ei == -1) {
            return -1;
        }
        return v[ei];
    }
    
    bool isEmpty() {
        if(si == -1 && ei == -1) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(((ei + 1 ) % k) == si) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */