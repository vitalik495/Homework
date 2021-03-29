class Student{
  constructor(university, course, fullName, marks){
    this.university = university
    this.course = course
    this.fullName = fullName
    this.marks = marks
    this.isDismiss = true
  }
    
  get getInfo(){

    return `Студент ${this.course}-го курсу ${this.university} ${this.fullName}`
  }
   
  get getMarks(){
    if(this.isDismiss ){

      return this.marks
   }else return null
  
  }
    
  set setMarks(mark){
    if (this.isDismiss) {
      this.marks.push(mark) 
    }
  }

   getAverageMark() {
    const sum = this.marks.reduce((sum, number) => {
      return sum + number
    }, 0)
    
    return +(sum / this.marks.length).toFixed(2)
  }
    
  dismiss() {
    this.isDismiss = true
    console.log(`Студента відраховано`)
  }
  
  recover() {
    this.isDismiss = false
    console.log(`Студента поновлено`)
  }
}

  class BudgetStudent extends Student{
    constructor(university, course, fullName, marks, isDismiss){
      super(university, course, fullName, marks, isDismiss)
      this.getScholarship = function getScholarship() {
        if (this.getAverageMark() >= 4 && !this.isDismiss) {
          console.log(`Ви отримали 1400 грн. стипендії`)
        } 
        else{
          console.log(
            `Студент не отримує степендію`
          );
        }
      }
      setInterval(() => this.getScholarship(), 30000);  
    }
  }

 const student = new Student(
  'Вищої Школи Психотерапії м.Одеса', 
  '1',
  'Остап Родоманський Бендер',
  [5, 4, 4, 5]
)
  
const studentmoney = new BudgetStudent(
  'Бориславської гімзації', 
  '3',
  'Панчишак Віталій',
  [5, 4, 4, 5, 3]
)
  
  console.log(student.getInfo);
  console.log(student.getMarks)
  student.setMarks = 2;
  console.log(student.getMarks);
  console.log(student.getAverageMark())
  student.dismiss();
  student.recover();
  student.setMarks = 5;
  console.log(student.getMarks);
  
  console.log(studentmoney.getInfo);
  studentmoney.dismiss();
  studentmoney.getScholarship();
  studentmoney.recover();
  studentmoney.getScholarship();
  studentmoney.setMarks = 5;
  studentmoney.getScholarship();