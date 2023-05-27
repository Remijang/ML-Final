import csv
fin = open('test.csv')
rows = csv.reader(fin)
fout = open('test2', 'w')
writer = csv.writer(fout, delimiter=' ')
r = 0
for row in rows :
    if r == 0:
        r = r + 1
        continue
    tmp = []
    for i in range(2,13):
        if not row[i]:
            tmp.append(-1)
        else:
            tmp.append(row[i])
    if not row[13]:
        tmp.append(-1)
    else:
        if row[13] == 'album':
            tmp.append(1)
        else:
            tmp.append(0)
    if not row[22]:
        tmp.append(-1)
    else:
        tmp.append(row[22])
    writer.writerow(tmp)
