g++ knn+svm.cpp -DN=$1 -Ofast -w -o out
./out
g++ knn+svm2.cpp -DN=$1 -Ofast -w -o out
./out
./libsvm/svm-train -s 0 -t 2 -c $2 -g $3 -m 2048 -q -h 0 train.svm model
./libsvm/svm-predict train.svm model predict
./grab train.svm predict
./libsvm/svm-predict test.svm model predict
