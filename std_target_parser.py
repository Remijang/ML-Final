import csv
fin = open('std_target_imputed_test.csv')
rows = csv.reader(fin)
fout = open('std_target_test', 'w')
writer = csv.writer(fout, delimiter=' ')
r = 0
for row in rows :
    if r == 0:
        r = r + 1
        continue
    writer.writerow(row)
