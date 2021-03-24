const ukraine = { 
  tax: 0.195,
  middleSalary: 1789,
  vacancies: 11476 
}
const latvia = {
  tax: 0.25,
  middleSalary: 1586,
  vacancies: 3921
}
const litva = {
  tax: 0.15,
  middleSalary: 1509,
  vacancies: 1114 
}

//#0 additional functions
function randomNumber(min, max) {
    
  return Math.floor(Math.random() * (max - min + 1) ) + min 
}

//#1 Salary
function getMyTaxes(salary) {
  
  return +(this. tax * salary).toFixed(2)  
}

//#2 MiddleTaxes
function getMiddleTaxes(country) {
  
  return +(this.tax * this.middleSalary).toFixed(2)
}

//#3 TotalTaxes
function getTotalTaxes(country) {
  
  return +(this.tax * this.middleSalary * this.vacancies).toFixed(2)
}

//#4 MySalary
function getMySalary(country) {
  setInterval(() => {
    const salary = randomNumber(1500, 2000)
    const taxes = this. tax * salary
    const profit = +(salary - taxes).toFixed(2)
    const obj = {
      salary,
      taxes,
      profit
    }
  console.log(obj) }, 1000)
}

console.log(getMyTaxes.call(litva, 1111))
console.log(getMiddleTaxes.call(ukraine))
console.log(getTotalTaxes.call(latvia))
getMySalary.call(latvia)