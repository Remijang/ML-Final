import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from sklearn.datasets import make_gaussian_quantiles
from sklearn.ensemble import AdaBoostClassifier
from sklearn.metrics import accuracy_score
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
def MAE(preds, targets):
    preds = np.array(preds)
    targets = np.array(targets)
    return np.sum(np.abs(preds-targets)) / targets.size


# read csv
df = pd.read_csv("new_train.csv")
df2 = pd.read_csv("new_test.csv")

# get x and y
y = df['Danceability'].to_numpy().astype(np.int32)
X = df.drop(['Danceability'], axis=1).to_numpy()
X2 = df2.to_numpy()

X_train, X_test, y_train, y_test = train_test_split(
     X, y, test_size=3400, random_state=1126
)

bdt_real = AdaBoostClassifier(
    DecisionTreeClassifier(max_depth=5), n_estimators=300, learning_rate=0.5
)

model = bdt_real.fit(X_train, y_train)

"""
real_test_errors = []
discrete_test_errors = []
real_predict = []
discrete_predict = []

for real_test_predict, discrete_test_predict in zip(
    bdt_real.staged_predict(X_test), bdt_discrete.staged_predict(X_test)
):
    real_test_errors.append(1.0 - MAE(real_test_predict, y_test))
    discrete_test_errors.append(1.0 - MAE(discrete_test_predict, y_test))

n_trees_discrete = len(bdt_discrete)
n_trees_real = len(bdt_real)

# Boosting might terminate early, but the following arrays are always
# n_estimators long. We crop them to the actual number of trees here:
discrete_estimator_errors = bdt_discrete.estimator_errors_[:n_trees_discrete]
real_estimator_errors = bdt_real.estimator_errors_[:n_trees_real]
discrete_estimator_weights = bdt_discrete.estimator_weights_[:n_trees_discrete]
"""

y_pred = model.predict(X2).round(0)
np.savetxt("predict", y_pred.astype(int), fmt='%i', delimiter=",")
