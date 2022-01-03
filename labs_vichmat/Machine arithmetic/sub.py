def sub(x, y):
    z = x - y
    if abs(x) > abs(y):
        zz = (x - z) - y
    else:
        zz = x - (y + z)
    return z + zz
