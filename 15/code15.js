 // Task 1
let start = 1;
let end = Infinity;
let step = 1;
let iterationCount = 0;
function* createIdGenerator() {
  for (let i = start; i < end; i += step) {
    iterationCount++;
    yield i;
  }

return iterationCount;
}

const idGenerator = createIdGenerator()

console.log("Task#1");
console.log("idGenerator" + " " + idGenerator.next().value );
console.log("idGenerator" + " " + idGenerator.next().value );
console.log("idGenerator" + " " + idGenerator.next().value );
console.log("idGenerator" + " " + idGenerator.next().value );
console.log("");
