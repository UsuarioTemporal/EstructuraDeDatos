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
  m = 0
  list_ = [[] for i in range(10)]
  maxValue = arr[0]
  for idex,item in enumerate(arr):
    if maxValue<item : maxValue=item
  iterator = len(str(maxValue))
  for index in range(iterator) :
    for i,content in enumerate(arr) :
      temp = (content//pow(10,index))%10
      list_[int(temp)].append(content)
    for x in range(10) :
      for y in range(len(list_[x])):
        arr[m]=list_[x][y]
        m= m+1
  print(list_)


radixSort([1,20,2,3])
#print(bubbleSort([1,0,7,6,25,0,1,2]))
#solution = binarySearch([1,2,3],3)
#1print(solution)


