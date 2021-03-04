const students = ["Олександр", "Ігор", "Олена", "Іра", "Олексій", "Світлана"]
const themes = ["Диференційне рівняння", "Теорія автоматів", "Алгоритми і структури даних"]
const marks = [4, 5, 5, 3, 4, 5]

//#1
function studentSort(arr) {
  let studentsArray = [...arr]
  let girls = []
  let boys = []
  let cover = []
  for (let i = 0; i < studentsArray.length; i++) {
    if (studentsArray[i].endsWith("а")) {
    girls.push(studentsArray[i])
    } else {
      boys.push(studentsArray[i])
      }
  }
for (let i = 0; i < girls.length; i++) {
   cover.push( [boys[i], girls[i]] )
  }
  return cover
}

//#2
function givingThemes(covers, themes) {
  const studentsThemes = []
  for(let i = 0; i < covers.length; i++){
    studentsThemes[i] =  [ covers[i] ,  themes[i]  ]
  }
  return studentsThemes
}
const covers =  studentSort(students) 
const allTheme = givingThemes(covers, themes)

//#3
function givingTask(students, marks) {
  const studentsTask = []
  for(let i = 0; i<students.length; i++){
    studentsTask[i] = [ students[i], marks[i] ]
  }
  return studentsTask
}
const lastmarks = givingTask(students , marks)

//#4
function getNamesThemeTaska(allTheme, marks){
  const fulldata = []
  for(let i = 0; i < allTheme.length; i++){
    fulldata[i] = [ allTheme[i], marks[i]  ]
     
  }
  return fulldata
}
const full = getNamesThemeTaska(allTheme, marks)

console.log(covers);
console.log(allTheme)
console.log(lastmarks)
console.log(full);















