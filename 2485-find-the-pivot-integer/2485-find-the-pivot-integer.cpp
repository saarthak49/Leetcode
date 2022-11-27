class Solution {
public:
    int pivotInteger(int n) {
        int sumUptoN = n * (n + 1 ) / 2;
        for(int i = 1; i<=n; i++)
        {
            int a = i * (i + 1)/2;
            if(a == sumUptoN - a + i)
                return i;
        }
        return -1;
    }
};