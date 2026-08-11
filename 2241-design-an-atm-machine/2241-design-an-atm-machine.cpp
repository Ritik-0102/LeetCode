class ATM {
public:
    vector<int> notes = {20,50,100,200,500};
    vector<long long> balance = vector<long long>(5,0); 
    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<5;i++){
            balance[i] += banknotesCount[i];
        }       
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5,0);
        
        for(int i=4;i>=0;i--){
            if(amount >= notes[i]){

                int notesToWithdraw = min(balance[i] , (long long)(amount / notes[i]));

                amount -= notesToWithdraw * notes[i];
                ans[i] = notesToWithdraw;
            }
        }

        if(amount > 0){
            return {-1};
        }

        for(int i=0;i<5;i++){
            balance[i] -= ans[i];
        }

        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */