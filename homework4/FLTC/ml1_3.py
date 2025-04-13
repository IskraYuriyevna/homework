import sklearn
# 常用的模型：
# sklearn.linear_model 线性关系预测
    # 线性回归(LinearRegression)：预测连续值（如房价的预测）
    # 对数几率回归(LogisticRegression)：分类任务（如二分类和多分类）
    # 岭回归(Ridge)：带L2正则化的线性回归
    # Lasso(Lasso)：带L1正则化的线性回归
# sklearn.tree 决策树模型（小规模，模型可解释性）
    # DecisionTreeClassifier：分类任务（如客户流失预测）
    # DecisionTreeRegressor：回归任务（如房价预测）
# sklearn.svm 支持向量机（适合高维数据，如文本分类）
    # （核技巧(Kernel Trick)可处理非线性问题（如rbf核）），总的来说时候小样本的非线性分类/回归问题
    # SVC:分类任务（如图像分类）
    # SVR:回归任务（如时间序列预测）
# sklearn.ensemble 集成学习（复杂数据，高精度，Kaggle竞赛）
    # 随机森林(RandomForestClassifier/Regressor):多棵决策树的集成
    # 梯度提升树(GrandientBoostingClassifier/Regressor)：逐步优化残差
    # AdaBoost(AdaBoostClassifier)：加权弱分类器集成
    # Bagging(BaggingClassifier)：并行训练基模型
# sklearn.cluster 无监督聚类分析（客户分群，图像分割，无标签数据探索）
    # K-means(KMeans):将数据划分为K个簇
    # DBSCAN(DBSCAN)：基于密度聚类（自动识别噪声点）
    # 层次聚类(AgglomerativeClusterting):树状结构聚类
# sklearn.neibours 近邻算法（适合小数据集的推荐系统）
    # K-近邻分类(KNeighborsClassifier):基于相似样本的投票分类
    # K-近邻回归(KNeighborsResressor):基于近邻样本的平均值预测
    # 最近邻搜索(NearesNeighbors):无监督查找最近的样本

# 接下来我们调用监督学习和无监督学习来训练模型，如sklearn.fit(X,y).fit(X).fit X y
X = np.linspace(-np.pi,np.pi,1000).reshape(-1,1)
y = np.cos(X)
plt.plot(X,y)

# 将样本拆分为train和test
X_train, x_test, y_train, y_test = train_test_split(X, y, test_size=0.3, shuffle=True, random_state=42)
# 从sklearn.ensemble模块中选择一些算法
from sklearn.ensemble import RandomForestRegressor
# 创建导入类的对象
regressor = RandomForestRegressor()
# 通过调用.fit()函数对其进行训练
regressor.fit(X_train,y_train)

# 对测试样本进行预测
y_pred = regressor.predict(x_test)
plt.scatter(x_test, y_test, label="truth observations")
plt.scatter(x_test, y_pred, s=5, c='r',label='predictions')
plt.legend()
plt.show()

# 质量评估
regressor.score(x_test,y_test)