import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.datasets import make_gaussian_quantiles
from sklearn.ensemble import AdaBoostClassifier
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.model_selection import GridSearchCV

def MAE(preds, targets):
    preds = np.array(preds)
    targets = np.array(targets)
    return np.sum(np.abs(preds-targets)) / targets.size

params = {
    'max_depth': [2, 3, 5, 10, 20, 40],
    'min_samples_leaf': [5, 10, 20, 50, 100, 200],
    'criterion': ["gini", "entropy", "log_loss"]
}

params2 = {
    'n_estimators' : [100, 200, 300, 400, 500],
    'learning_rate' : [0.001, 0.002, 0.005, 0.01, 0.02, 0.05, 0.1]
}

# read csv
s = "std_target_imputed_"
print(s)
df = pd.read_csv(s + "train.csv")
df2 = pd.read_csv(s + "test.csv")

# get x and y
y = df['Danceability'].to_numpy().astype(np.int32)
X = df.drop(['Danceability'], axis=1).to_numpy()
X2 = df2.to_numpy()
"""
X_train, X_test, y_train, y_test = train_test_split(
     X, y, test_size=3400, random_state=1125
)
"""

X_train = X
y_train = y
"""
grid_search = GridSearchCV(estimator=AdaBoostClassifier(
            DecisionTreeClassifier(max_depth=20, min_samples_leaf=50, criterion="entropy", random_state=42)), 
                           param_grid=params2, 
                           cv=5, n_jobs=-1, verbose=2, scoring = "neg_mean_absolute_error")

grid_search.fit(X, y)

print(grid_search.best_estimator_)

best = grid_search.best_estimator_

"""
bdt_real = AdaBoostClassifier(
    DecisionTreeClassifier(max_depth=20, min_samples_leaf=50, criterion="entropy", random_state=42), n_estimators=500, learning_rate=0.2
)

model = bdt_real.fit(X_train, y_train)
"""

model = best.fit(X_train, y_train)
"""

y_pred = model.predict(X2).round(0)
np.savetxt("predict", y_pred.astype(int), fmt='%i', delimiter=",")

