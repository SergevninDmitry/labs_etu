def create_tree(data):
    tree = {i: [] for i in data}
    for index, element in enumerate(data):
        tree[element].append(index)
    return tree
