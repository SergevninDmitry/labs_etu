import input, height, create

if __name__ == '__main__':
    data = input.input_data()
    tree = create.create_tree(data)
    print(height.height_tree(tree, - 1))
