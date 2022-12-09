/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */


let answer = Number.MIN_VALUE
var getAnswer = function(root, low, high) {
    if (root == null) return;

    if (low != Number.MAX_VALUE) {
        answer = Math.max(answer, Math.abs(root.val - low));
    }

    if (high != Number.MIN_VALUE) {
        answer = Math.max(answer, Math.abs(root.val - high));
    }

    high = Math.max(root.val, high);
    low = Math.min(root.val, low);

    getAnswer(root.left, low, high);
    getAnswer(root.right, low, high);
}
var maxAncestorDiff = function(root) {
    answer = Number.MIN_SAFE_INTEGER;

        const low = Number.MAX_VALUE;
        const high = Number.MIN_VALUE;

        getAnswer(root, low, high);

        return answer;
};