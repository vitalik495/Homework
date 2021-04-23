async function getRandomChinese(length){
  let i = 0;
  let time = "";
  while(i < length){
    await new Promise( (resolve) => {
      time += String.fromCharCode( Date.now() ).slice(-5)
      i++;
      setTimeout( () => {
        resolve(time)
      }, 50);
    });
  };
  console.log(time);
};
getRandomChinese(4);