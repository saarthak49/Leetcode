class Solution {
    
    
    public void visit(List<List<Integer>> rooms, int startRoom, boolean[] vis)
    {
        
        
        vis[startRoom] = true;
        for(int room: rooms.get(startRoom))
        {
            if(!vis[room])
            {
                visit(rooms, room, vis);
            }
        }
    }
    
    
    
    
    
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        
        
        
        int n = rooms.size();
        boolean vis[] = new boolean[n + 1];
        
        
        visit(rooms, 0, vis);
        
        
        
        for(int i = 0; i<=n-1; i++)
        {
            if(!vis[i])
                return false;
        }
        return true;
        
        
        
        
        
        
        
        
        
    }
}