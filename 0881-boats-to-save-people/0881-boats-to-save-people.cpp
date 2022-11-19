class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int boatsRequired = 0;
        int low = 0;
        int high = n-1; 
        
        while(low <= high)
        {
            if(low == high)
            {
                boatsRequired++;
                break;
            }
            else if(people[low] + people[high] <= limit)
            {
                boatsRequired++;
                low++;
                high--;
            }
            else
            {
                boatsRequired++;
                high--;
            }
        }
        return boatsRequired;
    }
};


// 1, 2, 2, 3, 



// 1, 1, 1, 2, 2, 3, 4

// 1, 2, 2, 3        3