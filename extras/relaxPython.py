
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
  list_ = []
  maxValue = arr[0]
  for item in range(len(arr)) :
    if maxValue<arr[item] : maxValue= arr[item]
  iterator = len(str(maxValue))
  for index in range(iterator) :
    

  print(length)

radixSort([1,20,2,3])
#print(bubbleSort([1,0,7,6,25,0,1,2]))
#solution = binarySearch([1,2,3],3)
#1print(solution)
