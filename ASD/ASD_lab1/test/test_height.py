import pytest
from src import height, create


@pytest.mark.parametrize("height_tree_data, expected_result, wrong_result", [
    (create.create_tree([-1]), 1, 10),
    (create.create_tree([-1, 1]), 1, 10),
    (create.create_tree([-1, 0, 0]), 2, 10),
    (create.create_tree([4, -1, 4, 1, 1]), 3, 10),
    (create.create_tree([-1, 0, 4, 0, 3]), 4, 10)
])
def test_is_height(height_tree_data, expected_result, wrong_result):
    assert (height.height_tree(height_tree_data, -1)) == expected_result
    assert (height.height_tree(height_tree_data, -1)) != wrong_result
