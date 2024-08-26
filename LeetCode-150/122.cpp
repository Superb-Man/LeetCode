class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 2) {
            return max(0,prices[1]-prices[0]) ;
        }
        int sum = 0 ;
        int start = 0 , ending = 0 ; 
        bool in = false , dec = false ;
        for(int i = 0 ; i < prices.size() -1 ; i++) {
            if(prices[i] <= prices[i+1]) in = true ;
            if(prices[i] > prices[i+1]) dec = true ;
            if(i == 0) {

                continue ;
            }
            if(prices[i-1] > prices[i] && prices[i]<=prices[i+1]){
                start = i ;
                
            } else if(prices[i] >= prices[i-1] && prices[i] > prices[i+1]) {
                sum+=prices[i] - prices[start] ;
                ending = i ;
            }
        }
        if(in && !dec) sum = prices[prices.size()-1] - prices[0] ;
        else if(!in && dec) sum = 0 ;
        else if(start > ending) {
            ending = prices.size()-1 ;
            sum+=prices[ending] - prices[start] ;
        }

        return sum ;
    }
};