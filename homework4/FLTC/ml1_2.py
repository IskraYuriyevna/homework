from sklearn.model_selection import train_test_split
# model_selection模块包含与模型选择，数据集划分，交叉验证等相关的工具
# 倒入train_test_split函数，用于将数据集划分为训练集(training set)和测试集(test set)

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
#seaborn库是基于matplotlib的高级可视化库，用于美化图表样式

sns.set_theme()
#设置seaborn的全局主题样式，后续图表会自动应用seaborn的默认风格（如灰色背景白色网格）

DATASET = []
#初始化空列表存储生成的二维坐标点

for x in np.linspace(-1,1,50):
    for y in np.linspace(-np.sqrt(1-x**2),np.sqrt(1-x**2),50):
        DATASET.append([x,y])
# x在[-1,1]内均匀生成50个点（np.linspace的作用）
# 内层循环：对每一个x计算y的范围为[-sqrt(1-x^2),sqrt(1-x^2)]，并在该范围内生成50个点
# 这样使得每一个(x,y)都位于单位圆内或上面（x^2+y^2<=1）
# 然后将生成的每一个点添加到DATASET列表中

DATASET = np.array(DATASET)
# 将列表转为Numpy数组，便于后续的向量化操作

plt.figure(figsize=(8.8))
plt.scatter(DATASET[:,0],DATASET[:,1])
# 创建一个大小为8*8英寸的图形窗口，确保散点图显示为正方形（避免宽高比失真）
# 绘制散点图，DATASET[:,0]提取所有点的x坐标，DATASET[:,1]提取所有点的y坐标，显示均匀分布点

y = np.sum(DATASET,axis=-1)
# 对数组的最后一个轴进行求和，结果存储在y中。DATASET的原始形状为(2500,2)，即2500个二维点，每个点形如[x,y]
# 二维数组的轴编号为0和1,-1轴表示最后一个维度，也就是1，沿列方向操作,即为存储点的数据的维度，将其加和

# X_train , X_test , y_train , y_test = train_test_split(DATASET , y , test_size = 0.25)
# plt.figure(figsize=(8.8))
# plt.scatter(X_train[:,0],X_train[:,1],label="train")
# plt.scatter(X_test[:,0],X_test[:,1],label="test")
# plt.legend()

# set random seed for np.random
np.random.seed(42)
# 随机种子采用42只是因为很多程序员都采用42,一般实际使用会采用更随机的值，比如

X_train,X_test,y_train,y_test = train_test_split(
    DATASET,y,test_size = 0.25,random_state = 42
)
# 数据集划分，将x和y分别划分成训练集和测试集，test_size=0.25代表测试集占25%，训练集占75%
# DATASET是形状为(2500,2)的特征数据，y是形状为(2500,)的目标值（每个点的x,y）
# 如果需要分成三个部分，如训练集，测试集和验证集，可以分割两次
# 验证集可以用于模型选择和调参，在训练阶段反复使用，测试集只在最后使用。可以使用60%-20%-20%的方法

plt.figure(figsize=(8.8))
#创建画布
plt.scatter(X_train[:,0],X_train[:,1],label='train')
# 训练集中所有点的x坐标和y坐标，标签为train，用蓝色标出（默认）
plt.scatter(X_test[:,0],X_test[:,1],label="test")
# 测试集中所有点的x坐标与y坐标，标签为train，用橙色标出（默认）
plt.lengend()
# 绘制图例
