import pytest
from src import merge


@pytest.mark.parametrize("data, expected_result, wrong_result", [
    ([[], []], [[], []], None),
    ([[0], [-1]], [[0], [-1]], None),
    ([[0, 1, 2, 3], [0, 2, -4, 5]], [[2, 0, 1, 3], [-4, 0, 2, 5]], [[0, 1, 2, 3], [-4, 0, 2, 5]]),
    ([[0, 1, 2, 3, 4], [-2654, 24534, -14, 0]], [[0, 2, 3, 1, 4], [-2654, -14, 0, 24534]],
     [[2, 0, 3, 1, 4], [-2654, -14, 0, 24534]]),
    ([[0, 1, 2], [35, -282, 83]], [[1, 0, 2], [-282, 35, 83]], [[0, 1, 2], [35, -282, 83]])
])
def test_is_create_tree(data, expected_result, wrong_result):
    assert (merge.merge(data)) == expected_result
    assert (merge.merge(data)) != wrong_result
