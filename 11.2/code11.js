const btn1 = document.querySelector("#item1");
const btn2 = document.querySelector("#item2");
const btn3 = document.querySelector("#item3");

const allButton = document.querySelectorAll (".btn")
function clearBtn (allButton){
  for (let i=0; i<allButton.length;i++){
    console.log (allButton[i].classList.remove('btn-bord'));
  }
}


btn1.addEventListener('click',function (){
  clearBtn (allButton);
  btn1.classList.add('btn-bord');
  const snd = new Audio("1.mp3");
  snd.play();
})

btn2.addEventListener('click', function (){
  clearBtn(allButton);
  btn2.classList.add('btn-bord');
  const snd = new Audio("2.mp3");
  snd.play();  
})

btn3.addEventListener('click', function (){
  clearBtn (allButton);
  btn3.classList.add('btn-bord');
  const snd = new Audio("3.mp3");
  snd.play();  
})

document.addEventListener('keypress', function(e){
  switch (e.code){
    case "KeyA":
      clearBtn(allButton);
      btn1.classList.add('btn-bord');
      const snd = new Audio("1.mp3");
      snd.play();
  break;
            
  case "KeyT":
    clearBtn(allButton);
    btn2.classList.add('btn-bord');
    const snd1 = new Audio("2.mp3");
    snd1.play();
  break;

  case "KeyL":
    clearBtn(allButton);
    btn3.classList.add('btn-bord');
    const snd2 = new Audio("3.mp3");
    snd2.play();
  break;
  }
})

