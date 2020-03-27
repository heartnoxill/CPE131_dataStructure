class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        # self.prev = None

def newNode(x):
    temp = Node(0)
    temp.data = x
    temp.next = None
    return temp

def findMiddle(start, last):
    if(start == None):
        return None
# One variable have to move faster than another variable ** by 2 times 
# If x reaches last, y will be at the middle
    followVar = start
    speedVar = start.next
    while(speedVar != last):
        speedVar = speedVar.next
        if(speedVar != last):
            followVar = followVar.next
            speedVar = speedVar.next
    return followVar

def binarySearch(head, value):
    start = head
    last = None

    while True:
        mid = findMiddle(start, last)
        if(mid==None):
            return None
        
        elif(mid.data == value):
            return mid

        elif(mid.data < value):     # goes right "righted half"
            start = mid.next

        else:               # value < mid.data  , lefted half
            last = mid

        if not (last == None or last != start):
            break
    return None

head = newNode(1)
head.next = newNode(2)
head.next.next = newNode(3)
head.next.next.next = newNode(4)
head.next.next.next.next = newNode(5)

value = 3
if(binarySearch(head, value) == None):
    print("Value not present")
else:
    print("Present")
    
