const students = ["Олександр", "Ігор", "Олена", "Іра", "Олексій", "Світлана"]
const themes = ["Диференційне рівняння", "Теорія автоматів", "Алгоритми і структури даних"]
const marks = [4, 5, 5, 3, 4, 5]

//#1
function getPairs(arr) {
  let studentsArray = [...arr]
  let girls = []
  let boys = []
  let pair = []
  for (let i = 0; i < studentsArray.length; i++) {
    if (studentsArray[i].endsWith("а")) {
    girls.push(studentsArray[i])
    } else {
      boys.push(studentsArray[i])
      }
  }
for (let i = 0; i < girls.length; i++) {
   pair.push( [boys[i], girls[i]] )
  }
  return pair
}

//#2
function givingThemes(pairs, themes) {
  const studentsThemes = []
  for(let i = 0; i < pairs.length; i++){
    studentsThemes.push ([pairs[i].join(" i "),themes[i]])
  }
  return studentsThemes
}
const pairs =  getPairs(students) 
const allTheme = givingThemes(pairs, themes)

//#3
function givingTask(students, marks) {
  const studentsTask = []
  for(let i = 0; i<students.length; i++){
    studentsTask.push(  [ students[i], marks[i] ])
  }
  return studentsTask
}
const lastmarks = givingTask(students , marks)

//#4
function getNamesThemeTask(allTheme, marks){
  const namesWThemesWMarks = []
  for(let i = 0; i < allTheme.length; i++){
    namesWThemesWMarks.push( [ allTheme[i].join(" "), marks[i] ] )
     
  }
  return namesWThemesWMarks
}
const dataNamesWThemesWMarks = getNamesThemeTask(allTheme, marks)

console.log(pairs)
console.log(allTheme)
console.log(lastmarks)
console.log(dataNamesWThemesWMarks);















