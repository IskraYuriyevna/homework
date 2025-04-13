#В этой задаче мы предлагаем Вам заполнить пропуски в коде, чтобы реализовать следующую схему обучения модели и проверки её качества. Заполните фрагменты приведённого ниже кода так, чтобы обучение отвечало следующим параметрам:
#Размер тестовой выборки = 0.3 от всей выборки
#Включите перемешивание Установите значение random_state = 42

from sklearn.linear_model import LogisticRegression
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
#Впишите название функции для разбиения выборки на тренировочную и тестовую#
from sklearn.preprocessing import StandardScaler
#TODO: импортируйте StandardScaler из соответствующего модуля

# Загрузка датасета
X, y = load_breast_cancer(return_X_y=True)
# Разбиение датасета на train и test
X_train, x_test, y_train, y_test = train_test_split(X,y,test_size=0.25,random_state=43,shuffle=True)#Впишите функцию с нужными параметрами. Не забывайте про random_state!#

# Задание классификатора и его обучение
clf = LogisticRegression()
# Предобработка датасета при помощи StandardScaler
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
x_test = sc.transform(x_test)

# Обучеение модели
# TODO: вызовите функцию обучения модели на тренировочной выборке X_train с вектором ответов y_train
clf.fit(X_train,y_train)#WRITE HERE#

# Оценка качества получившегося решения
score = clf.score(x_test, y_test)
#В качестве ответа на это задание впишите получившуюся оценку качества до второго знака после запятой включительно (то есть,если ответ 0.6572343, впишите 0.65).
print(f"{score:.2f}")
