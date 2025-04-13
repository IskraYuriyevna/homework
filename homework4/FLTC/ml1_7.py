# 管道
# 类sklearn Pipeline可以用于对数据应用大量转换，训练分类器，计算质量指标，可以简化优化所有代码的过程
from sklearn.pipeline import pipe
from sklearn.preprocessing import StandardScaler
from sklearn.datasets import load_wine
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split

# 加载数据集wine
X, y = load_wine(return_X_y=True) 

# 拆分为train和test
X_train, X_test , y_train , y_test = train_test_split(X ,y ,test_size=0.3, shuffle=True)

# 创建Pipeline并对其进行训练
pipe = Pipeline([
    ('scaler',StandardScaler()),
    ('classifier',KNeighborsClassifier(n_neibors=5))
])
pipe.fit(X_train,y_train)

# 模型评估
score = pipe.score(X_test,y_test)

print(f"Score of model:{scort:.4f}")
print(f"Error:{sum(pipe.predict(X_test) != y_test)/len(y_test):.4f}")