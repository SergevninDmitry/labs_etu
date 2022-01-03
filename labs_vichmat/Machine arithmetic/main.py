import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from dist import distanse

point1 = [float(i) for i in input().split()]
point2 = [float(i) for i in input().split()]

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(point1[0], point1[1], point1[2])
ax.scatter(point2[0], point2[1], point2[2])
ax.plot([point1[0], point2[0]], [point1[1], point2[1]], [point1[2], point2[2]], color='r')
plt.show()


ans1 = distanse(point1, point2)
ans2 = distanse(point2, point1)
if ans1 == ans2:
    print("При перестановке входных данных алгоритм выдает одно и то же.\nЗначащие биты также равны:")
print(ans1)
print(ans2)

