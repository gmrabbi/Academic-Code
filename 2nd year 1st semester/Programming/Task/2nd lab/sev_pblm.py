num = input("Enter value : \n").split(",")
# num = "0110,0011,1010,1001,1100, 0100, 1000"
bin_num = list()
dec_num = list()

for i in num:
    dec_num.append(int(i , 2))

for i in dec_num:
    if(i%4==0):
        bin_num.append(bin(i)[2:])
    
for i in bin_num:
    print(f"Output : {(4-len(str(i)))*'0'}{i}" , end=" ")
