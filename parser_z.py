import csv
fin = open('train_z.csv')
rows = csv.reader(fin)
fout = open('train_z', 'w')
writer = csv.writer(fout, delimiter=' ')
r = 0
for row in rows :
    if r == 0:
        r = r + 1
        continue
    tmp = []
    for i in range(1,18):
        tmp.append(row[i])

    tmp.append(row[0])
    writer.writerow(tmp)
