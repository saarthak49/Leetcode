/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */

function getLeaves(root, leaves) {
    if (root == null) return;

    if (root.left == null && root.right == null) {
        leaves.push(root.val);
    }

    getLeaves(root.left, leaves);
    getLeaves(root.right, leaves);
}

function same(l1, l2) {
    if (l1.length != l2.length) {
        return false;
    }

    for (let i = 0; i <= l1.length - 1; i++) {
        if (l1[i] != l2[i]) {
            return false;
        }
    }

    return true;
}

function leafSimilar(root1, root2) {
    const l1 = [];
    const l2 = [];

    getLeaves(root1, l1);
    getLeaves(root2, l2);

    return same(l1, l2);
}
