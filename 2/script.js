let numberN = null,  numberM = null 

do{ 
    numberN = Math.trunc(prompt("Введіть число N"))
} while (isNaN (numberN)) // повертання, коли вказано не число 

do{
    numberM = Math.trunc(prompt("Введіть число M"))
} while (isNaN (numberM) ) // повертання, коли вказано не число

const skip = confirm("Пропустити парні?") //так чи ні

console.log(" Число N ", numberN);
console.log(" Число M ", numberM);
console.log(skip);

let sort = (null)
if(numberN <= numberM){
    for(let i = numberN; i<=numberM; i++){
      if  (skip === false || i % 2)
       sort += i 
    }
console.log("Сума чисел з N по M", sort);
} else{
    console.log("Число M є меншим за N! Помилка виконання, змініть числа.");
}












