class Element implements Comparable<Element>
{
    char ch;
    int frequency;
    
    @Override
    public int compareTo(final Element a)
    {
        if(frequency < a.frequency)
            return 1;
        else if(frequency == a.frequency)
            return 0;
        else return -1;
    }
}
class Solution {
    public String frequencySort(String s) {
        int n = s.length();
        
        Map<Character, Integer> mp = new HashMap<>();
        List<Element> lst = new ArrayList<>();
        
        for(int i = 0; i<=n-1; i++)
        {
            if(mp.containsKey(s.charAt(i)))
            {
                int freq = mp.get(s.charAt(i));
                mp.put(s.charAt(i), freq + 1);
            }
            else
                mp.put(s.charAt(i), 1);
        }
        for(Map.Entry<Character, Integer> entry : mp.entrySet())
        {
            Element element = new Element();
            element.ch = entry.getKey();
            element.frequency = entry.getValue();
            lst.add(element);
        }
        
        Collections.sort(lst);
        String finalAns = "";
        for(Element element : lst)
        {
            for(int i = 0; i<=element.frequency - 1; i++)
                finalAns += element.ch;
        }
        return finalAns;
    }
}