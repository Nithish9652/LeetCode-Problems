class MedianFinder {
public:
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(s.size() == 0){
             s.push(num);
             return;
        }
        else if(s.size() > g.size()){
           if(num < s.top()){
             g.push(s.top());
             s.pop();
             s.push(num);
           } 
           else{
             g.push(num);
           }
        }
        else{
           if(num < s.top()) s.push(num);
           else{
             g.push(num);
             s.push(g.top());
             g.pop();
           } 
        }

    }
    
    double findMedian() {
        if(s.size() > g.size()) return static_cast<double>(s.top()); 

        else
           return (static_cast<double>(s.top()) + static_cast<double>(g.top())) / 2.0;

    }
};