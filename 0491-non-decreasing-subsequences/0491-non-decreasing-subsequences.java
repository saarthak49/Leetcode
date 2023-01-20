class Solution {
    HashSet<List<Integer>> ans=new HashSet<>();
    public List<List<Integer>> findSubsequences(int[] nums) {
       
        int n=nums.length;
        bcktrk(0,nums,n,new ArrayList<>());
        return new ArrayList<>(ans);
    }
    public void bcktrk(int i,int a[],int n,List<Integer> kk){
        if(i>=n){
            if(kk.size()>1){
                ans.add(kk);
            }
            return;
        }
        if(kk.size()==0 || a[i]>=kk.get(kk.size()-1)){
        kk.add(a[i]);
        bcktrk(i+1,a,n,new ArrayList<>(kk));
        kk.remove(kk.size()-1);
        }
        bcktrk(i+1,a,n,new ArrayList<>(kk));
    }
}