/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var answer = math.MinInt64

func getAnswer(root *TreeNode, low, high int) {
    if root == nil {
        return
    }

    if low != math.MaxInt64 {
        answer = int(math.Max(float64(answer), math.Abs(float64(root.Val - low))))
    }

    if high != math.MinInt64 {
        answer = int(math.Max(float64(answer), math.Abs(float64(root.Val - high))))
    }

    high = int(math.Max(float64(root.Val), float64(high)))
    low = int(math.Min(float64(root.Val), float64(low)))

    getAnswer(root.Left, low, high)
    getAnswer(root.Right, low, high)
}

func maxAncestorDiff(root *TreeNode) int {
    answer = math.MinInt64

    low := math.MaxInt64
    high := math.MinInt64

    getAnswer(root, low, high)

    return answer
}