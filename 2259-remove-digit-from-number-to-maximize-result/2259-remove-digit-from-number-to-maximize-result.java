class Solution {
    public String removeDigit(String number, char digit) {

        int n = number.length();

        String result = "0";

        for(int i = 0; i<=n-1; i++)
        {
            if(number.charAt(i) == digit)
            {
                String nStr = number.substring(0, i) + number.substring(i+1, n);
                if(result.compareTo(nStr) < 0)
                {
                    result = nStr;
                }
            }
        }
        return result;
    }
}