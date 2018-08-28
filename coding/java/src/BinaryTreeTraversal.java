import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;


public class BinaryTreeTraversal {
    private LinkedList<Integer> result;

    private BinaryTreeTraversal() {
        result = new LinkedList<>();
    }

    public static void main(String[] argv) {
        TreeNode header = new TreeNode(1);
        header.left = new TreeNode(2);
        header.right = new TreeNode(3);
        header.left.left = new TreeNode(4);
        header.left.right = new TreeNode(5);
        header.right.left = new TreeNode(6);
        header.right.right = new TreeNode(7);
        BinaryTreeTraversal traversal = new BinaryTreeTraversal();
        traversal.order_after(header);
        for (int elem : traversal.result) {
            System.out.println(elem);
        }
    }

    // 递归先序遍历
    private void traversal_front(TreeNode head) {
        if (head == null) {
            return;
        }
        result.add(head.val);
        traversal_front(head.left);
        traversal_front(head.right);
    }

    // 递归中序遍历
    private void traversal_mid(TreeNode head) {
        if (head == null) {
            return;
        }
        traversal_mid(head.left);
        result.add(head.val);
        traversal_mid(head.right);
    }

    // 递归后序遍历
    private void traversal_after(TreeNode head) {
        if (head == null) {
            return;
        }
        traversal_after(head.left);
        traversal_after(head.right);
        result.add(head.val);
    }

    // 非递归前序
    private void order_front(TreeNode head) {
        Stack<TreeNode> sta = new Stack<TreeNode>();
        while (head != null) {
            result.add(head.val);
            sta.push(head);
            head = head.left;
        }
        TreeNode node;
        while (!sta.empty()) {
            node = sta.pop();
            if (node.right != null) {
                node = node.right;
                while (node != null) {
                    result.add(node.val);
                    sta.push(node);
                    node = node.left;
                }
            }
        }
    }

    // 非递归中序
    private void order_mid(TreeNode head) {
        Stack<TreeNode> sta = new Stack<TreeNode>();
        while (head != null) {
            sta.push(head);
            head = head.left;
        }
        TreeNode node;
        while (!sta.empty()) {
            node = sta.pop();
            result.add(node.val);
            if (node.right != null) {
                node = node.right;
                while (node != null) {
                    sta.push(node);
                    node = node.left;
                }
            }
        }
    }

    // 非递归后续遍历
    private void order_after(TreeNode head) {
        Stack<TreeNode> sta = new Stack<TreeNode>();
        while (head != null) {
            sta.push(head);
            head = head.left;
        }
        TreeNode node;
        TreeNode last = new TreeNode(-9999);
        while (!sta.empty()) {
            node = sta.peek();
            if (node.right == null || node.right == last) {
                result.add(node.val);
                sta.pop();
                last = node;
            } else {
                node = node.right;
                while (node != null) {
                    sta.push(node);
                    node = node.left;
                }
            }
        }
    }
}

