class Node:
        def __init__(self, dataval=None):
            self.dataval = dataval
            self.nextval = None

class SLinkedList:
    def __init__(self):
        self.headval = None

    def listprint(self):
        printval = self.headval
        while printval is not None:
            print (printval.dataval)
            printval = printval.nextval
    
    def push(self, newdata):
        NewNode = Node(newdata)
        NewNode.nextval = self.headval
        self.headval = NewNode

    def insertNode(self, newdata, index):
        if index==1:
            list.push(newdata)
        else:
            PreviousNode = Node()
            PreviousNode.nextval = self.headval
            for i in range(0,int(index)-1):
                PreviousNode = PreviousNode.nextval
            NewNode = Node(newdata)
            NewNode.nextval = PreviousNode.nextval
            PreviousNode.nextval = NewNode

    def removeNode(self, index):
        PreviousNode = Node()
        PreviousNode.nextval = self.headval
        if index==1:
            self.headval = PreviousNode.nextval.nextval
        else:
            for i in range(0,int(index)-1):
                PreviousNode = PreviousNode.nextval
            PreviousNode.nextval = PreviousNode.nextval.nextval

list = SLinkedList()
list.headval = Node("Mon")
e2 = Node("Tue")
e3 = Node("Wed")
# Link first node to second node
list.headval.nextval = e2

# Link second node to third node
e2.nextval = e3
list.push("Sun")
list.insertNode("Test",1)
list.insertNode("Hello",3)
list.removeNode(1)
list.listprint()