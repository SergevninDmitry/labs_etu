CN = 1 + 2 ** 27


def squared(x):
    x_accuracy = CN * x
    hx = (x - x_accuracy) + x_accuracy  # представление с большей точностю
    tx = x - hx
    z = x * x
    zz = (((hx * hx - z) + hx * tx) + tx * hx) + tx * tx
    return z + zz
