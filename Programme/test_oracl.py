import random, math
from pgcd import pgcd

def test_oracl():
    for _ in range(100_000):  
        a = random.randint(0, 10**12)
        b = random.randint(0, 10**12)
        assert pgcd(a, b) == math.gcd(a, b)