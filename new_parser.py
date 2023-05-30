import csv
fin = open('new_train.csv')
rows = csv.reader(fin)
fout = open('new_train', 'w')
writer = csv.writer(fout, delimiter=' ')
r = 0
for row in rows :
    if r == 0:
        r = r + 1
        continue
    writer.writerow(row)
