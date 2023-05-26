import csv
fin = open('test.csv')
rows = csv.reader(fin)
fout = open('test', 'w')
writer = csv.writer(fout, delimiter=' ')
r = 0
for row in rows :
    if r == 0:
        r = r + 1
        continue
    tmp = [row[16]]
    for i in range(0,13):
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
    for i in range(14,16):
        if not row[i]:
            tmp.append(-1)
        else:
            if row[i] == 'TRUE':
                tmp.append(1)
            else:
                tmp.append(0)
    if not row[22]:
        tmp.append(-1)
    else:
        tmp.append(row[22])
    writer.writerow(tmp)
