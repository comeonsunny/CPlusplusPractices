import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt("data.txt",dtype=np.int32,delimiter=' ')
x = []
y = []
for i in data:
    x.append(i[0])
    y.append(i[1])
    print(i[0])

data = np.loadtxt("data2.txt",dtype=np.int32,delimiter=' ')
x2 = []
y2 = []
for i in data:
    x2.append(i[0])
    y2.append(i[1])

plt.rcParams["font.sans-serif"] = ['SimHei']
plt.rcParams["axes.unicode_minus"] = False

x_value = x
y_value = y

plt.scatter(x_value, y_value,s=1,c="hotpink",label="AES_CTR")
plt.scatter(x2, y2,s=1,c="blue",label="SSS")

plt.title("data analyze")
plt.xlabel("数量")
plt.ylabel("时间（毫秒）")
plt.legend()
plt.show()
