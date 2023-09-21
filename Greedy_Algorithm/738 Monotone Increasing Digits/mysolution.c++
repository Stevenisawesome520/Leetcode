class Solution {
public:
    int monotoneIncreasingDigits(int n) {

        int digits[10] = {0};
        int num = n;
        for(int i = 9; i >= 0 && num != 0; i--)
        {
            digits[i] = num % 10;
            num /= 10;
        }
        
        int dup = 0;

        for(int i = 0; i < 9; i++)
        {
            if(digits[i] == digits[i+1])
            {
                
                dup += digits[i+1] * pow(10, (9 - (i + 1)));

            }
            else if(digits[i] > digits[i+1])
            {
                int subN = 0;
                for(int j = i + 1; j < 10; j++)
                {
                    subN += digits[j] * pow(10, (9 - j));
                }

                return n - (dup + subN + 1);

            }
            else
                dup = 0;
        }

        return n;
    }
};
