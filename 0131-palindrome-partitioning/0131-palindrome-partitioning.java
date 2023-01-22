class Solution {
    public List<List<String>> partition(String s) {
        return partition_4(s);
    }
    public List<List<String>> partition_4(String s) {
        List<List<String>> res = new ArrayList<>();
        helper_backtracking(s, 0, new ArrayList<>(), res, new boolean[s.length()][s.length()]);
        return res;
    }
    private void helper_backtracking(String s, int begin,
                                     List<String> list, List<List<String>> res, boolean[][] dp){
        if (begin == s.length()){
            res.add(new ArrayList<>(list));
            return;
        }

        for (int idx = begin; idx >= 0 && idx < s.length(); idx++){
            idx = s.indexOf(s.charAt(begin), idx);
            if (idx < 0) return;
            //if (idx - begin > 2) System.out.println(dp[begin + 1][idx - 1]);
            if (s.charAt(begin) == s.charAt(idx) && (idx - begin <= 2 || dp[begin + 1][idx - 1])){
                dp[begin][idx] = true;
                list.add(s.substring(begin, idx + 1));
                helper_backtracking(s, idx + 1, list, res, dp);
                list.remove(list.size() - 1);
            }
        }
    }
}