function generateBlocks() {
  const grid = document.querySelector('.grid')
  grid.style.display = 'grid'
  blockRandomColor()
}

function blockRandomColor() {
  const grid = document.querySelectorAll('.block')
  grid.forEach(item => item.style.backgroundColor = `rgb(${getRandomColor(0, 255)}, ${getRandomColor(0, 255)}, ${getRandomColor(0, 255)})`)
}

function getRandomColor(min, max){

  return Math.ceil(Math.random() * (max - min) + min)
}

function generateBlocksInterval(time = 1000) {
  setInterval(() => blockRandomColor(), time)
}

