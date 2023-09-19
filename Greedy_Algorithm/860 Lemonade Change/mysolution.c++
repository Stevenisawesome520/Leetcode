class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        if(bills[0] != 5)
            return false;
        five++;

        for(int i = 1; i < bills.size(); i++)
        {
            if(bills[i] == 5)
                five++;
            else if(bills[i] == 10)
            {
                if(five)
                {
                    five--;
                    ten++;
                }
                else
                    return false;
            }
            else if(bills[i] == 20)
            {
                if(ten && five)
                {
                    ten--;
                    five--;
                }
                else if(five >= 3)
                {
                    five -= 3; 
                }
                else
                    return false;
            }
        }

        return true;
        
    }
};
