//#1 Найбільша цифра числа:
function namegetMaxDigit(number = null) {
  const arr = number.toString().split('')
  return Math.max(...arr)
}


//#2 Число в степені:
function pow(num = null, exponent = null) {
  let result = 1
  for (i = 0; i < exponent; i++) {
     result *= num
  }
  return result
} 

//#3 Велика перша літера:
function firstBigLetter(name) {
  const word = String(name)
  return word.charAt(0).toUpperCase() + word.slice(1).toLowerCase()
}

//#5 Випадкове число з діапазону:
function randomNumber(min, max) {
  return Math.floor(Math.random() * (max - min) ) + min
}
 
//#8 Генерування паролю:
function pass(long = 8) {
  let password = ''
  const number = '1234567890'
  for (let i = 0; i < long; i++) {
    password += Math.round(Math.random() * number.length).toString()   
  }
  return password
}

//#9 Видалення заданої букви з контексту
function deleteLetters (letter, word)  {
  let result = ''
	for (let i = 0; i < word.length; i++) {
    letter === word[i] ? false : result += word[i]
  }
	return result
}


console.log("Найбільша цифра числа:", namegetMaxDigit(121))
console.log("Число в степені:", pow(2, 3))
console.log("Велика перша літера: ", firstBigLetter ("DSC"))
console.log("Випадкове число з діапазону: ", randomNumber(1, 44444))
console.log("Генерування паролю: ", pass(14))
console.log("Видалення заданої букви з контексту: ", deleteLetters("a", "sadasdadcasa"));