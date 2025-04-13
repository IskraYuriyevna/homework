# 使用模型
from sklearn.model_selection import cross_val_score
from sklearn.datasets import load_wine
from sklearn.neighbors import KNeighborsClassifier

# 读取另一个经典的数据集wine
X, y = load_wine(return_X_y=True) 
# 创建KNN分类器的实例
clf = KNeighborsClassifier(n_neighbors=5)
# 交叉验证
scores = cross_val_score(clf, X, y,cv=10)
# 输出平均值
print(f"Mean score:{score.mean():.4f}")
# 显示成绩的分布
plt.figure(figsize=(10,6))
sns.histplot(scores,kde=true)
plt.title("Disbuntion of score KNN")
plt.xlabel("Score")
plt.ylabel("Number")
plt.tight_layout()
plt.show()