# 数据预处理

def scale(X):
    x_mean = X.mean(axis=0)
    x_std = X.std(axis=0)
    X_scaled = (X - x_mean)/x_std
    return X_scaled

scales = np.array([1,0.1,10])
x = np.random.randn(1000,3)*scales.reshape(1,-1)
print(x)