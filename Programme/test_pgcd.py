from pgcd import pgcd

def test_pgcd():
    assert pgcd(48, 18) == 6
    assert pgcd(21, 14) == 7
    assert pgcd(17, 13) == 1
    assert pgcd(0, 5) == 5
    assert pgcd(10, 0) == 10