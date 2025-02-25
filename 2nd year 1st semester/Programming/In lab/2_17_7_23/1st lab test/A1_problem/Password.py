flag = 1
while flag:
    pwd = input("Enter Password: ")
    # pwd = "AAAAAAa3AA"
    if(len(pwd)>=8 and len(pwd)<=12):
        lst = list(set(pwd))
        low = up = dig= sy = 0
        for i in lst:
            if(i.islower()):
                low = 1
            if(i.isupper()):
                up = 1
            if(i.isdigit()):
                dig = 1
            if(i in ("%", "$", "#", "&", "@") ):
                sy = 1
        if(low and up and dig and sy):
            print("Valid Password. Welcome !!!")
            flag = 0
        else:
            print("Invalid password. Please enter a valid password again")
    else:
        print("Invalid password. Please enter a valid password again")
    
        