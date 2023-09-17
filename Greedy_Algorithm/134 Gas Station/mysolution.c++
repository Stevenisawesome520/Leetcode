class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int sum = 0;


        int len = gas.size();

        int idx = -1;        
        for(int i = 0; i < len; i++)
        {
            sum += gas[i] - cost[i];
            if(sum >= 0)
                idx = i;

            gas[i] = gas[i] - cost[i];
            cost[i] = sum;
            
        }
        if(sum < 0)
            return -1;

        int maxS = gas[idx];
        sum = gas[idx];
        int ans = idx--;
        
        while(idx >= 0)
        {
            sum += gas[idx];
            if(sum >= maxS)
            {
                maxS = sum;
                ans = idx;
            }

            idx--;
        }
        
        return ans;


    }
};
