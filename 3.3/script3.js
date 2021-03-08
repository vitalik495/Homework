//#1 Найбільша цифра числа:
function getMaxDigit(number = null) {
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
function pass(passLength = 8) {
  let password = ''
  for (let i = 0; i < passLength; i++) {
    password += Math.round(Math.random() * 10).toString()   
  }
  return password
}

//#9 Видалення заданої букви з контексту
function deleteLetters (letter, word)  {
  return word.replaceAll(letter, "")
}

console.log("Найбільша цифра числа:", getMaxDigit(121) )
console.log("Число в степені:", pow(2, 3) )
console.log("Велика перша літера: ", firstBigLetter ("DSC") )
console.log("Випадкове число з діапазону: ", randomNumber(1, 44444) )
console.log("Генерування паролю: ", pass(7) ) 
console.log("Видалення заданої букви з контексту: ", deleteLetters("a", "sssssasasasasasasaaaaaa") );