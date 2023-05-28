import optunity
import optunity.metrics

# comment this line if you are running the notebook
import sklearn.svm
import numpy as np

import csv
dat = []
label = []
path = 'train.scale'
f = open(path, 'r')
rows = csv.reader(f, delimiter=' ')
for row in rows:
    dat.append(np.array(row[0:17]))
    label.append(int (row[17]))

data = np.array(dat).reshape((17170-9,17))
labels = np.array(label)

# compute area under ROC curve of default parameters
@optunity.cross_validated(x=data, y=labels, num_folds=5)
def svm_default_auroc(x_train, y_train, x_test, y_test):
    model = sklearn.svm.SVC().fit(x_train, y_train)
    decision_values = model.decision_function(x_test)
    auc = optunity.metrics.roc_auc(y_test, decision_values)
    return auc

svm_default_auroc(data,labels,data,labels)
