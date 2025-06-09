class Solution {
public:
    int answer(int n,int current,int clipboard){
        if(n==current) return 0;
        if(current>n) return 100000000;
        int copy=2+answer(n,current*2,current);
        int paste=1+answer(n,current+clipboard,clipboard);
        return min(copy,paste);

    }
    int minSteps(int n) {
        if(n==1) return 0;
        return 1+answer(n,1,1);
        
    }
};
