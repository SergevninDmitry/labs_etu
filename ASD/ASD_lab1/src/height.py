def height_tree(tree, current_root):
    all_res = []
    if current_root not in tree.keys():
        return 0
    for children in tree[current_root]:
        all_res.append(height_tree(tree, children))
    return max(all_res) + 1
#-1 2 2 2
#0 0 1 0