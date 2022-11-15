class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum = 0;
        int n = tickets.size();
        int count = 0;
        for(int i = 0; i<=n - 1; i++)
        {
            if(tickets[i] < tickets[k])
            {
                sum += tickets[i];
                if(i < k)
                    count++;
            }
            else 
                sum += tickets[k] - 1;
        }
        return sum + k - count + 1;
        
    }
};