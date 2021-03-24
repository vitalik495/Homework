//#9 splitting into letters
function divideByThree(word, long) {
  let arr = []
  if (word.length < 3){
  
    return false,  "Ви ввели слово, довжина якого є меншою від умови. Змініть слово!"
  } else {
  for (let i = 0; i < word.length; i+=long) {
    arr.push(word.toLowerCase().substring(i,i+long))  
  }
}

  return arr  
}

//#1 random array 
function getRandomArray(len, min, max ){
  let randomArray = []
  for (let i = 0; i < len; i++) {
    randomArray[i] = (Math.floor( Math.random()*(max - min + 1) )+ min)
  }
 
  return randomArray
}

//#3 avarage
function getAverage(numbers){
  const newArr = numbers.filter(number => Number.isInteger(number))
  
  return Number(newArr.reduce((accumulator,number) => accumulator + number / newArr.length,0).toFixed(2))
}
const arr = [6, 2, 55, 11];
const averageNumber = getAverage(arr);

//#6 Positiv nambers
function countPositiveNumbers(...numbers) {
  const filtered = numbers.filter((element) => element > 0)
 
  return filtered.length
}
  
//#5 filter nambers
function filterEvenNumbers(...numbers) {
  
  return numbers.filter(number => number % 2 && Number.isInteger(number))
}
const oddNumbers = filterEvenNumbers(31, 33, 33, 33, 1, 4, 5.5, 9)

//#7 Numbers which divided by five
function getDividedByFive(...numbers) {
  
  return numbers.filter((element) => element % 5 === 0)
}

console.log(divideByThree("fdssfdfcds", 2))
console.log(getRandomArray(14, 5, 100))
console.log(averageNumber)
console.log(countPositiveNumbers(1, -2, 3, -4, -5, 6))
console.log(oddNumbers)
console.log(getDividedByFive(111, 555, 100, 5, 55, 34, 76, 9));