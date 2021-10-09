def mergeSort(unsorted_arr):
    if len(unsorted_arr) <= 1:
        return

    middle = len(unsorted_arr)//2  # [2]

    # starting from 0 till middle element
    left = unsorted_arr[:middle]


    # starting from middle to end of arra
    right = unsorted_arr[middle:]

    # (recursion) this will return sorted left and right arrays
    mergeSort(left)
    mergeSort(right)

    # return the final sorted array
    merged_sorted_array(left,right, unsorted_arr)




# to merge two sorted arrays and return a single sorted array
def merged_sorted_array(sorted_arr1, sorted_arr2, unsorted_arr):

    # specifying lengths of both sorted arrays
    len_arr1 = len(sorted_arr1)
    len_arr2 = len(sorted_arr2)

    # starting from first element
    i = j = k = 0

    # iterate through each element and compare elements
    while i < len_arr1 and j < len_arr2:
        if sorted_arr1[ i ] < sorted_arr2[ j ]:
            unsorted_arr[k] = sorted_arr1[i]
            i+=1

        else:
            unsorted_arr[k] = sorted_arr2[j]
            j += 1

        k+=1

    # if first condition is true append the element directly
    while i < len_arr1:
        unsorted_arr[k] = sorted_arr1[i]
        i += 1
        k += 1

    # if second condition is true append the element directly
    while j < len_arr2:
       unsorted_arr[k]=sorted_arr2[j]
       j += 1
       k+=1


arr = [9,4,6,2,4,8,1]
mergeSort(arr)
print(arr)