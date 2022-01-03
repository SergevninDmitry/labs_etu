import pytest
from src import heap


def test_heapreplace():
    assert heap.heapreplace([(0, 0), (0, 1)], (1, 0)) == (0, 0)
    assert heap.heapreplace([(0, 1), (1, 0)], (2, 1)) == (0, 1)
    assert heap.heapreplace([(1, 0), (2, 1)], (4, 0)) == (1, 0)
