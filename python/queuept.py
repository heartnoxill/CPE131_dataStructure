class Queue:
    def __init__(self):
        self.queue = list()

    def addtoq(self, dataval):
        if dataval not in self.queue:
            self.queue.insert(0, dataval)
            return True
        return False

    def size(self):
        return len(self.queue)

    def removefromq(self):
        if len(self.queue)>0:
            return self.queue.pop()
        return ("No elements in queue!")

q = Queue()
q.addtoq("Mon")
q.addtoq("Tue")
q.addtoq("Wed")
for i in range(0,4):
    print(q.removefromq())  
 