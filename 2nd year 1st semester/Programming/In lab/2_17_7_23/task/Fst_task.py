# ct_mark = [20,18,17,12]
ct_mark = input("ct mark (a,b,c,d) : ").split(",")
l = list()
for c in ct_mark:
    l.append(int(c))
l.remove(min(l))
mark = sum(l)
att = int(input("Attandance mark : "))
final = int(input("Final mark : "))

totlal = (mark+att+final)/3

if(totlal>=80 and totlal<=100): print(f"{totlal:.3f}% A+")
elif(totlal<80 and totlal>=75):  print(f"{totlal:.3f}% A")
elif(totlal<75 and totlal>=70):  print(f"{totlal:.3f}% A-")
elif(totlal<70 and totlal>=65):  print(f"{totlal:.3f}% B")
elif(totlal<65 and totlal>=60):  print(f"{totlal:.3f}% B+")
elif(totlal<60 and totlal>=55):  print(f"{totlal:.3f}% B-")
elif(totlal<55 and totlal>=50):  print(f"{totlal:.3f}% C")
elif(totlal<50 and totlal>=45):  print(f"{totlal:.3f}% C-")
elif(totlal<45 and totlal>=40):  print(f"{totlal:.3f}% D")
else:  print(f"{totlal:.3f}% F")
