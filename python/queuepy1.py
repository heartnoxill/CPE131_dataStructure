class Queue:
# constructor to initialize the function
    def __init__(self, capacity):
# lets consider front and rear are at index -1
        self.front = -1
        self.rear = - 1
        # self.Q is the queue between front and rear
        self.Q = [None] * capacity
        # capacity is the maxsize of staorage
        self.capacity = capacity

# to check whether the queue is full
    def isFull(self):
        if self.rear == self.capacity:
            print("Queue is full")
            return

# to check whether the queue is Empty
    def isEmpty(self):
        if self.front == -1 and self.rear == -1:
            print("Queue is empty")
            return

    def Enqueue(self, item):
        if self.isFull():
            print("Queue is full")
            return
# whenever the item is to be added it is added at the end / rear
# we are using cyclic array so below is the logic to traverse from last position to first position
        self.rear = (self.rear + 1) % self.capacity
        self.Q[self.rear] = item
        print(item, " is enqueued")

    def dequeued(self):
        if self.isEmpty():
            return
# whenever the item is to be removed it is removed from the front
        self.front = (self.front + 1) % self.capacity
        print(self.Q[self.front], " is removed")

# to see the item at the from without removing it
    def que_front(self):
        if self.isEmpty():
            print("Queue is empty")

        print("Front item is", self.Q[self.front])

# to check the item at the end
    def que_rear(self):
        if self.isFull():
            print("queue is full")
# to print the value at index of self.rear
        print("rear item is", self.Q[self.rear])


# driver code
queue = Queue(30)
queue.Enqueue(10)
queue.dequeued()
queue.que_front()
queue.que_rear()
