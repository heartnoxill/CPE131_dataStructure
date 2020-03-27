# bubble sort
class Node:
    def __init___(self, data):
        self.data = data
        self.next = None
        self.head = None

class linkedList:
    def __init__(self):
        self.head = None

    def push(self, newdata):
        newNode = Node()
        newNode.data = newdata
        newNode.next = self.head
        self.head = newNode

    def bubbleSort(self):
        while True:
            swap_value = 0
            move = self.head
            while (move.next != None):
                if move.data > move.next.data:
                    swap_value += 1
                    move.data, move.next.data = move.next.data, move.data
                    move = move.next
                else:
                    move = move.next
                
            if swap_value == 0:
                break
            else:
                continue

    def printList(self): 
        tp = self.head 
        while (tp): 
            print(tp.data)
            tp = tp.next

LList = linkedList()
LList.push(2)
LList.push(8)
LList.push(15)
LList.push(30)
LList.push(5)
LList.printList()
print("\n\n")
LList.bubbleSort()
LList.printList()


