file = open("bill.txt", "r")
resutl = file.readlines()

cal = dict()
def process(line):
    
    d = line[0].split("[")[1].split("]")[0]
    if(d in cal):
        cal[d] += int(line[1])
    else:
        cal[d] = int(line[1])

for line in resutl:
    process(line.strip().split("$"))

for key , val in cal.items():
    print(f"{key} ${val}")