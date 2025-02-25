message = "hello dear how are you"
# input("Enter your message : ")

cont = dict()

for i in message:
    if(i==" "):
        continue
    if(i in list(cont.keys()) ):
        cont[i] += 1
    else:
        cont[i] = 1

sort_asc = dict( sorted(cont.items(), key=lambda x: x[1], reverse=False ))
sort_dec = dict(sorted(cont.items(), key=lambda item: item[1], reverse=True))

print(sort_asc)
print(sort_dec)

with open("store1.txt" , "w") as file:
    lst = message.split(" ")
    cnt = 0
    msg = ''
    for i in lst:
        if(cnt >= 3):
            cnt = 0
        file.write(i)
        file.write(" ")
        cnt += 1
        if(cnt == 3):
            file.write("\n")

print("\nDone")

