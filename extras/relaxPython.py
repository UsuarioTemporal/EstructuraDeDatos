from math import pow
def binarySearch(arr,number):
  if len(arr)==0 :return False
  if arr[0]!=number and len(arr)==1 : return False
  if arr[0]==number and len(arr)==1: return True
  middle = len(arr)//2
  if arr[middle]==number : return True
  elif arr[middle]>number :return binarySearch(arr[:middle],number)
  else : return binarySearch(arr[middle+1:],number)
    
def bubbleSort(arr) :
  if len(arr)==0 or len(arr)==1: return arr
  for mainIndex in range(len(arr)) :
    for secIndex in range(len(arr)-1) :
      if arr[secIndex]>arr[secIndex+1] : 
        arr[secIndex],arr[secIndex+1]=arr[secIndex+1],arr[secIndex]
  return arr

"""matriz= [0]*5
matriz[0] = [1,2]
print(matriz)"""

def radixSort(arr):

  list_ = [[] for i in range(10)]
  iterator = len(str(max(arr)))
  for index in range(iterator) :
    m = 0
    for i in range(len(arr)) :
      temp = (arr[i]//pow(10,index))%10
      list_[int(temp)].append(arr[i])
    for x in range(10) :
      if len(list_[x])==0 : continue
      for y in range(len(list_[x])):
        arr[m]=list_[x][y]
        m= m+1
      list_[x].clear()
      
  print(arr)

def radixSort2(arr):
  iterator = len(str(max(arr)))
  for i in range(iterator) :
    brackets=[[] for i in range(10)]
    for index,item in enumerate(arr) :
      temp = item//pow(10,i)%10
      brackets[temp].append(item)
    # TODO en javascript arr = [].concat(...brackets) hacer eso en python
    arr = [item for subList in brackets for item in subList]
  return arr
# este algoritmo se parece al de C++ y java
def quickSort(arr,start,end):
  i = start
  j = end
  pivot = arr[start]
  while i<j :
    while pivot<arr[j]:
      j=j-1
    while pivot>=arr[i] and j>i:
      i=i+1
    if i<j : arr[j],arr[i]=arr[i],arr[j]
  arr[start],arr[i]=arr[i],pivot
  if start<j-1: quickSort(arr,start,j-1)
  if end>i+1 :quickSort(arr,i+1,end)

  

# algoritmo quicksort para el lenguaje python
def quickSortPython(arr):
  if len(arr)<2 : return arr
  pivot = arr[0]
  less= [i for i in arr[1:] if i<=pivot]
  greater = []

radixSort([1,20,2,3])
list_ = [3,0,1,8,7,2,5,4,9,6]
quickSort(list_,0,len(list_)-1)
print(list_)
#print(bubbleSort([1,0,7,6,25,0,1,2]))
#solution = binarySearch([1,2,3],3)
#1print(solution)


# def sum (x)->1:
#   return sum.__annotations__

# print(sum(4))