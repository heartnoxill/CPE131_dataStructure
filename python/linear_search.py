global count
class Node:
    def __init__(self,data):
        self.data = data    # Assign Data
        self.next = None    # Initialized next as Null

class LinkedList:
    def __init__(self):
        self.head = None    # Initialized head as None
        self.count = 0

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def search(self, x):
        current = self.head
        while current != None:
            self.count += 1
            if current.data == x:
                return True
                return self.count      # data found
            current = current.next
        return False

if __name__ == '__main__':
    count = 0
    list1 = LinkedList()
    list1.push(1)
    list1.push(2)
    list1.push(3)
    list1.push(4)
    list1.push(5)

    if list1.search(4):
        print("Yes")
        print("Tried" , count ,"times")
    else:
        print("No")