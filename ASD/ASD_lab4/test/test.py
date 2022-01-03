import pytest

from src import RabinKarp


def tests():
    assert RabinKarp.RabinKarp("abc", "fhsdjkabfscabc") == [11]
    assert RabinKarp.RabinKarp("a", "abacaba") == [0, 2, 4, 6]
    assert RabinKarp.RabinKarp("", "") == []
    assert RabinKarp.RabinKarp("aaa", "bbbbbbbbbbb") == []


tests()
