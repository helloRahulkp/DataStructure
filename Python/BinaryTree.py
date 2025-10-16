class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

# Create binary tree automatically using level order
def insert_level_order(arr, i):
    if i < len(arr):
        root = Node(arr[i])
        root.left = insert_level_order(arr, 2 * i + 1)
        root.right = insert_level_order(arr, 2 * i + 2)
        return root
    return None

# Preorder Traversal (Root -> Left -> Right)
def preorder(root):
    if root is None:
        return
    print(root.data, end=" ")
    preorder(root.left)
    preorder(root.right)

# Inorder Traversal (Left -> Root -> Right)
def inorder(root):
    if root is None:
        return
    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)

# Postorder Traversal (Left -> Right -> Root)
def postorder(root):
    if root is None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.data, end=" ")

# Height of tree
def height(root):
    if root is None:
        return 0
    return max(height(root.left), height(root.right)) + 1

# Width of a given level
def get_width(root, level):
    if root is None:
        return 0
    if level == 1:
        return 1
    return get_width(root.left, level - 1) + get_width(root.right, level - 1)

# Maximum width of tree
def max_width(root):
    h = height(root)
    max_w = 0
    for i in range(1, h + 1):
        width = get_width(root, i)
        if width > max_w:
            max_w = width
    return max_w

# Driver code
if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6, 7]  # Tree values
    root = insert_level_order(arr, 0)

    print("Preorder:", end=" ")
    preorder(root)
    print("\nInorder:", end=" ")
    inorder(root)
    print("\nPostorder:", end=" ")
    postorder(root)

    print("\n\nMaximum Width of Tree:", max_width(root))