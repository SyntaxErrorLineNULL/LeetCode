package problem144

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func preorderTraversal(root *TreeNode) []int {
	var values []int
	var cur *TreeNode
	var last *TreeNode

	if root == nil {
		return values
	}

	cur = root

	for cur != nil {
		if cur.Left == nil {
			values = append(values, cur.Val)
			cur = cur.Right
		} else {
			last = cur.Left
			for last.Right != nil && last.Right != cur {
				last = last.Right
			}

			if last.Right == nil {
				values = append(values, cur.Val)
				last.Right = cur
				cur = cur.Left
			} else {
				last.Right = nil
				cur = cur.Right
			}
		}
	}

	return values
}
