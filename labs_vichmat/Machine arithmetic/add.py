def add(x, y):
    z = x + y
    if abs(x) > abs(y):
        zz = (x - z) + y
    else:
        zz = (y - z) + x
    return z + zz
