from PIL import Image
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt

bm = Image.open("bluemarble.jpg")
bm = np.array(bm.resize([int(d / 10) for d in bm.size])) / 256

lons = np.linspace(-180, 180, bm.shape[1]) * np.pi / 180
lats = np.linspace(-90, 90, bm.shape[0])[::-1] * np.pi / 180

fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")
ax.set_axis_off()

x = np.outer(np.cos(lons), np.cos(lats)).T
y = np.outer(np.sin(lons), np.cos(lats)).T
z = np.outer(np.ones(np.size(lons)), np.sin(lats)).T

ax.plot_surface(x, y, z, rstride=4, cstride=4, facecolors=bm)

plt.show()
