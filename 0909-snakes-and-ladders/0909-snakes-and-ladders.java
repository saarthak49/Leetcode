class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        int[] processed = new int[n*n+1];
        for (int i = n-1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                processed[(n-1-i)*n+j+1] = (n-1-i) % 2 == 0 ? board[i][j] : board[i][n-j-1];
            }
        } 
        Queue<Integer> q = new LinkedList<>();
        boolean[] seen = new boolean[processed.length];
        q.add(1);
        seen[1] = true;
        int moves = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                int pos = q.poll();
                if (pos == processed.length-1) {
                    return moves;
                }
                for (int i = pos+1; i <= Math.min(pos + 6, processed.length-1); i++) {
                    int next = processed[i] != -1 ? processed[i] : i;
                    if (!seen[next]) {
                        q.add(next);
                        seen[i] = true;
                        seen[next] = true;
                    }
                }
            }
            moves++;
        }
        return -1;
    }
}