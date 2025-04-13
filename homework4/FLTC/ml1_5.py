# 数据集
# sklearn中有很多现成的经典的数据集
from sklearn.datasets import load_iris

X,y = load_iris(return_X_y=True)
X.shape