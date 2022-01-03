import pytest
from src import create


@pytest.mark.parametrize("create_tree_data, expected_result, wrong_result", [
    (([-1]), {-1: [0]}, {-1: [1]}),
    (([-1, 1]), {-1: [0], 1: [1]}, {-1: [0], 1: [0]}),
    (([-1, 0, 0]), {-1: [0], 0:[1, 2]}, {-1: [1], 0:[1, 2]}),
    (([4, -1, 4, 1, 1]), {-1: [1], 1:[3, 4], 4:[0, 2]}, {-1: [2], 1:[3, 4], 4:[0, 2]}),
    (([-1, 0, 4, 0, 3]), {-1: [0], 0: [1, 3], 3: [4], 4: [2]}, {-1: [1], 0: [1, 3], 3: [4], 4: [2]})
])
def test_is_create_tree(create_tree_data, expected_result, wrong_result):
    assert (create.create_tree(create_tree_data)) == expected_result
    assert (create.create_tree(create_tree_data)) != wrong_result
