class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0 , c = 0;
        int c1 = 1;
        while(n>0){
          if(n%10!=0){
            c+=((n%10)*c1);
            c1*=10;
            sum+=(n%10);
          }
          n/=10;
        }
        c*=sum;
        return c;
    }
};