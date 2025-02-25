exam_marks =[ 
{ 
    "ID":"214001", 
    "name": "A", 
    "CT": [18,7,17,11], 
    "Final_Exam": [[25,20,33],[10,34,15]], 
    "Attendance": [27,36]
},
{   
    "ID":"214002",
    "name": "B",
    "CT": [11,17,13,19],
    "Final_Exam": [[28,0,33],[19,30,27]],
    "Attendance": [28,36]   
},
{
    "ID":"214003",
    "name": "C",
    "CT": [10,14,9,18],
    "Final_Exam": [[14,8,10],[6,13,9]],
    "Attendance": [20,36]
},
{
    "ID":"214004",
    "name": "D",
    "CT": [13,20,16,20],
    "Final_Exam": [[29,17,33],[16,30,25]],
    "Attendance": [32,36]
},
{
    "ID":"214005",
    "name": "E",
    "CT": [0,8,6,0],
    "Final_Exam": [ [7,0,8], [11,0,0] ],
    "Attendance": [12,36]
}]

def calculation(dic):
    mark = 0
    id = ""
    name = ""
    for key, value in dic.items():
        if(key=='ID'):
            id = value
        if(key == 'name'):
            name = value

        if(key=='CT'):
            value.sort()
            mark += sum(value[1:]) 
        if(key=='Final_Exam'):
            mark += sum(value[0])
            mark += sum(value[1])
        if(key=="Attendance"):
            mark += (value[0]*30)/value[1] 
    mark //= 3;
    
    message = "Hello, {name} with ID: {id} has obtained "
    if(mark>=80 and mark<= 100):
        print(message.format(name=name, id=id) , "A+")
    elif(mark >= 75 and mark <= 80):
        print(message.format(name=name, id=id), "A")
    elif(mark >= 70 and mark <= 75):
        print(message.format(name=name, id=id), "A-")
    elif(mark >= 65 and mark <= 70):
        print(message.format(name=name, id=id), "B+")
    elif(mark >= 60 and mark <= 65):
        print(message.format(name=name, id=id), "B")
    elif(mark >= 55 and mark <= 60):
        print(message.format(name=name, id=id), "B-")
    elif(mark >= 50 and mark <= 55):
        print(message.format(name=name, id=id), "C+")
    elif(mark >= 45 and mark <= 50):
        print(message.format(name=name, id=id), "C")
    elif(mark >= 40 and mark <= 45):
        print(message.format(name=name, id=id), "D")
    else:
        print(message.format(name=name, id=id), "F")

for data in exam_marks:
    calculation(data)