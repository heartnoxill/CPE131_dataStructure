class array:
    def __init__(self):
        self.left = 0
        self.right = None
        self.mid = None

    def binarySearch(self, item_list, x):
        left = self.left
        right = self.right
        mid = self.mid
        right = len(item_list) - 1
        while(left <= right):
            mid = int((left + right)/2)
            if(item_list[mid] == x):
                return True
            elif(x < item_list[mid]):
                right = mid - 1
            else:
                left = mid + 1
        return False

if __name__ == '__main__':
    ourArray = array()
    if ourArray.binarySearch([1,2,3,4,5], 2):
        print("Found")
    else:
        print("Not found")
