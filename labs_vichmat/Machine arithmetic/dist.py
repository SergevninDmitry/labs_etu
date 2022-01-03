from squared import squared
from sub import sub
from add import add
from math import sqrt


def distanse(point_1, point_2):
    x1, y1, z1 = point_1
    x2, y2, z2 = point_2
    x_x = squared(sub(x2, x1))
    y_y = squared(sub(y2, y1))
    z_z = squared(sub(z2, z1))
    sum = add(add(x_x, y_y), z_z)
    return sqrt(sum)
