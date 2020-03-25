def selectionSort(item_list):
        for foo in range(len(item_list)):
            min_index = foo
            for _ in range(foo+1, len(item_list)):
                if item_list[_] < item_list[min_index]:
                    min_index = _
            item_list[foo], item_list[min_index] = item_list[min_index], item_list[foo]

List1 = [5,32,7,55,9,12]
print(List1)
selectionSort(List1)
print(List1)