
class Entry
{
    int entryTime;
    int executionTime;
    int index;
}




class Comparator1 implements Comparator<Entry>
{
    @Override
    public int compare(Entry e1, Entry e2)
    {
        if (e1.entryTime < e2.entryTime)
            return -1;
        else if (e1.entryTime > e2.entryTime)
            return 1;
        else
        {
            if (e1.executionTime < e2.executionTime)
                return -1;
            else if (e1.executionTime > e2.executionTime)
                return 1;
            else
                return e1.index - e2.index;
        }
    }
}

class Comparator2 implements Comparator<Entry>
{
    @Override
    public int compare(Entry e1, Entry e2)
    {
        if (e1.executionTime < e2.executionTime)
                return -1;
        else if (e1.executionTime > e2.executionTime)
            return 1;
        else
            return e1.index - e2.index;
    }
}






class Solution {
    public int[] getOrder(int[][] task) {
    
        Queue<Entry> tasks = new PriorityQueue(new Comparator1());
        Queue<Entry> executionList = new PriorityQueue(new Comparator2());
        
        int index = 0;
        for(int[] a : task)
        {
            Entry entry = new Entry();
            entry.entryTime = a[0];
            entry.executionTime = a[1];
            entry.index = index++;
            
            
            tasks.offer(entry);
        }
        if(tasks.isEmpty())
            return new int[]{};
        
        int currTime = 0;
        int[] ans = new int[index];
        index = 0;
        while(!tasks.isEmpty() || !executionList.isEmpty())
        {
        
            if(executionList.isEmpty())
                currTime = Math.max(tasks.peek().entryTime, currTime);
        
            while(!tasks.isEmpty() && tasks.peek().entryTime <= currTime)
            {
                Entry e = tasks.poll();
                executionList.offer(e);
            }
            Entry e = executionList.poll();
            currTime += e.executionTime;
            ans[index++] = e.index;
        }
        return ans;
    }
}