import pytest
from pgcd import pgcd

@pytest.mark.parametrize("a,b,attendu", [
    (48, 18, 6),
    (21, 14, 7),
    (17, 13, 1),
    (0, 5, 5),
    (10, 0, 10)
])
def test_pgcd_param(a, b, attendu):
    assert pgcd(a, b) == attendu
