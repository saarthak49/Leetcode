class RandomizedSet {
    
    private Map<Integer, Integer> mp;
    private List<Integer> list;
    private int size;
    private Random rand;

    public RandomizedSet() {
        this.mp = new HashMap<>();
        this.list = new ArrayList<>();
        this.size = 0;
        this.rand = new Random();
    }
    
    public boolean insert(int val) {
        if(mp.containsKey(val))
            return false;
        list.add(val);
        mp.put(val, this.size);
        this.size++;
        return true;
    }
    
    public boolean remove(int val) {
        if(!mp.containsKey(val))
            return false;
        int index = mp.get(val);
        int elem = this.list.get(size - 1);
        Collections.swap(list, size-1, index);
        mp.put(elem, index);
        mp.remove(val);
        list.remove(size - 1);
        size--;
        return true;
    }
    
    public int getRandom() {
        int index = this.rand.nextInt(size);
        return this.list.get(index);
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */