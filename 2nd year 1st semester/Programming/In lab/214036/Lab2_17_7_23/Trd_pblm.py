
while(True):
    score = float(input("Enter your score : "))

    if(score>=80 and score<=100): print("A+")
    elif(score<80 and score>=75):  print("A")
    elif(score<75 and score>=70):  print("A-")
    elif(score<70 and score>=65):  print("B")
    elif(score<65 and score>=60):  print("B+")
    elif(score<60 and score>=55):  print("B-")
    elif(score<55 and score>=50):  print("C")
    elif(score<50 and score>=45):  print("C-")
    elif(score<45 and score>=40):  print("D")
    else:  print("F")
