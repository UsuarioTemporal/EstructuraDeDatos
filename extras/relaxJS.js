const binarySearch = (arr,number)=>{
    if(!arr.length) return false
    if(arr.length===1 && arr[0]!==number) return false
    if(arr.length===1 && arr[0]===number) return true
    let middle = Math.floor(arr.length/2) // parseInt(length)
    if(arr[middle]===number) return true
    if(arr[middle]>number) return binarySearch(arr.slice(0,middle),number)
    if(arr[middle]<number) return binarySearch(arr.slice(middle+1),number)
}

const radixSort = arr=>{
    let iteration = Math.max(...arr).toString().length
    console.log(iteration)
    for (let index = 0; index < iteration; index++) {
        let brackets = Array.from({length:10},()=>[])
        arr.forEach(element => {
            let temp = parseInt(element/Math.pow(10,index))%10
            brackets[temp].push(element)
        });
        arr= [].concat(...brackets)
        // delete brackets
    }
    return arr
}
const bubbleSort= arr=>{
    for(let iteration=0;iteration<arr.length;iteration++){
        for(let i=0;i<arr.length-1;i++){
            if(arr[i]>arr[i+1]) {
                let aux=arr[i]
                arr[i]=arr[i+1]
                arr[i+1]=aux
            }
        }
    }
    return arr
}

// algoritmo parecido al de java  c++
const quickSort_ = arr=>{

}

// algoritmo de quicksort utilizando la rapidez de javascript

const quickSort = arr=>{

}
let arr = [1,2,3,4,5]
let arr_1 = []
let rangeA = 0
let rangeB = 1
// recordar que para obtener números aletorios para numeros enteros positivos -> a+random()*(b-a+1)
for(let i = 0;i<10;i++){
    arr_1.push(parseInt(Math.random()*(rangeB-rangeA+1)+rangeA))
}
let number = 3
console.log(binarySearch(arr,number))
console.log(bubbleSort(arr_1))