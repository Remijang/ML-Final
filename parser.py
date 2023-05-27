import csv
fin = open('train.csv')
rows = csv.reader(fin)
fout = open('train', 'w')
writer = csv.writer(fout, delimiter=' ')
r = 0
for row in rows :
    if r == 0:
        r = r + 1
        continue
    tmp = []
    for i in range(1,14):
        if not row[i]:
            tmp.append(-1)
        else:
            tmp.append(row[i])
    if not row[14]:
        tmp.append(-1)
    else:
        if row[14] == 'album':
            tmp.append(1)
        else:
            tmp.append(0)
    for i in range(15,17):
        if not row[i]:
            tmp.append(-1)
        else:
            if row[i] == "True":
                tmp.append(1)
            else:
                tmp.append(0)
    if not row[23]:
        tmp.append(-1)
    else:
        tmp.append(row[23])
    tmp.append(row[0])
    writer.writerow(tmp)
