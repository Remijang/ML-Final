import csv
fin = open('test_z.csv')
rows = csv.reader(fin)
fout = open('test_z', 'w')
writer = csv.writer(fout, delimiter=' ')
r = 0
for row in rows :
    if r == 0:
        r = r + 1
        continue
    tmp = []
    for i in range(0,17):
        tmp.append(row[i])

    writer.writerow(tmp)
