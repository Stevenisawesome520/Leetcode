//Static Dynamic Programming
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Since cntPerfectSquares is a static vector, if 
        // cntPerfectSquares.size() > n, we have already calculated the result 
        // during previous function calls and we can just return the result now.
        static vector<int> cntPerfectSquares({0});
        
        // While cntPerfectSquares.size() <= n, we need to incrementally 
        // calculate the next result until we get the result for n.
        while (cntPerfectSquares.size() <= n)
        {
            int m = cntPerfectSquares.size();
            int cntSquares = INT_MAX;
            for (int i = 1; i*i <= m; i++)
            {
                cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            }
            
            cntPerfectSquares.push_back(cntSquares);
        }
        
        return cntPerfectSquares[n];
    }
};

//Mathematical Solution
class Solution 
{  
private:  
    int is_square(int n)
    {  
        int sqrt_n = (int)(sqrt(n));  
        return (sqrt_n*sqrt_n == n);  
    }
    
public:
    // Based on Lagrange's Four Square theorem, there 
    // are only 4 possible results: 1, 2, 3, 4.
    int numSquares(int n) 
    {  
        // If n is a perfect square, return 1.
        if(is_square(n)) 
        {
            return 1;  
        }
        
        // The result is 4 if and only if n can be written in the 
        // form of 4^k*(8*m + 7). Please refer to 
        // Legendre's three-square theorem.
        while ((n & 3) == 0) // n%4 == 0  
        {
            n >>= 2;  
        }
        if ((n & 7) == 7) // n%8 == 7
        {
            return 4;
        }
        
        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++)
        {  
            if (is_square(n - i*i)) 
            {
                return 2;  
            }
        }  
        
        return 3;  
    }  
}; 
