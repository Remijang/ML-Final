g++ knn+svm.cpp -DN=$1 -Ofast -w -o out
./out
g++ knn+svm.cpp -DN=$1 -Ofast -w -o out
./out
./libsvm/svm-train -s 0 -t 2 -c $2 -r 1 -q train.svm model
./libsvm/svm-predict -q train.svm model predict
./grab train.svm predict
