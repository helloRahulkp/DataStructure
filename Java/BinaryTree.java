
class Node {
    int data;
    Node left, right;

    public Node(int item) {
        data = item;
        left = right = null;
    }
}

public class BinaryTree {
    
    // Create binary tree automatically using level order
    Node insertLevelOrder(int[] arr, int i) {
        Node root = null;
        if (i < arr.length) {
            root = new Node(arr[i]);
            root.left = insertLevelOrder(arr, 2 * i + 1);
            root.right = insertLevelOrder(arr, 2 * i + 2);
        }
        return root;
    }

    // Preorder traversal (Root -> Left -> Right)
    void preorder(Node root) {
        if (root == null) return;
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    // Inorder traversal (Left -> Root -> Right)
    void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    // Postorder traversal (Left -> Right -> Root)
    void postorder(Node root) {
        if (root == null) return;
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
    }

    // Calculate height of tree
    int height(Node root) {
        if (root == null)
            return 0;
        return Math.max(height(root.left), height(root.right)) + 1;
    }

    // Get width of a given level
    int getWidth(Node root, int level) {
        if (root == null)
            return 0;
        if (level == 1)
            return 1;
        else
            return getWidth(root.left, level - 1) + getWidth(root.right, level - 1);
    }

    // Get maximum width of the tree
    int getMaxWidth(Node root) {
        int maxWidth = 0;
        int h = height(root);
        for (int i = 1; i <= h; i++) {
            int width = getWidth(root, i);
            if (width > maxWidth)
                maxWidth = width;
        }
        return maxWidth;
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();

        int[] arr = {1, 2, 3, 4, 5, 6, 7};  // Array representation
        Node root = tree.insertLevelOrder(arr, 0);

        System.out.print("Preorder: ");
        tree.preorder(root);
        System.out.print("\nInorder: ");
        tree.inorder(root);
        System.out.print("\nPostorder: ");
        tree.postorder(root);

        int maxWidth = tree.getMaxWidth(root);
        System.out.println("\n\nMaximum Width of Tree: " + maxWidth);
    }
}
