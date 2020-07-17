def partition(arr, low, high):  # partition function
    pIndex = low-1      # at first will be at -1 pos
    pivot = arr[high]   # pivot will be on the last element in the list 
    for first in range(low, high):  # loop from first to last element
        if arr[first] <= pivot:     # first arr index "first" <= pivot index
            pIndex += 1             # pIndex increase by 1
            arr[pIndex], arr[first] = arr[first], arr[pIndex]   # swap pIndex and first
    arr[pIndex+1], arr[high] = arr[high], arr[pIndex+1]     # when finish the loop, swap high with pIndex+1
    return (pIndex+1)   # return pIndex+1 (will be use as "middle")

def quickSort(arr, low ,high):  # quicksort function (recursion)
    if low < high:              # do if low<high (probably)
        part_index = partition(arr, low, high)  # partition the list (to get pIndex+1 value)
        quickSort(arr, low, part_index-1)       # quicksort on the left partition of pIndex+1
        quickSort(arr, part_index+1, high)      # quicksort on the right partition of pIndex+1

# Testing
arr = [43, 2, 7, 33, 100, 1]
n = len(arr)    # n = length of the list
quickSort(arr, 0, n-1)  
print("Sorted list is:")
for i in range(n):      # loop to print all the value in the list
    print("%d" %arr[i])