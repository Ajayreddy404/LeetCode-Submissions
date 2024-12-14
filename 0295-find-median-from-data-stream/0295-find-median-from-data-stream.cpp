class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.size()==0)   pq1.push(num);
        else if(pq2.size()==0){
            if(num > pq1.top()) pq2.push(num);
            else{
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            }
        }else if(num>=pq2.top()){
            pq2.push(num);
        }else{
            pq1.push(num);
        }

        while(pq2.size()>pq1.size()){
            pq1.push(pq2.top());
            pq2.pop();
        }
        while(pq1.size()>pq2.size()+1){
            pq2.push(pq1.top());
            pq1.pop();
        }
        
    }
    
    double findMedian() {
        double medianNum = 0;
        if(pq1.size()==pq2.size()){
            medianNum = pq1.top() + pq2.top();
            if(pq1.size() && pq2.size())    cout<<pq1.top()<<" "<<pq2.top()<<endl;
            medianNum /= 2;
        }else{
            if(pq1.size() && pq2.size())    cout<<pq1.top()<<" "<<pq2.top()<<endl;
            medianNum = pq1.top();
        }
        return medianNum;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */