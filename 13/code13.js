const filmLink = "https://swapi.dev/api/films/";
const planetLink = "https://swapi.dev/api/planets/";
const planets = document.querySelector('nexting');
let page = 1;

function getPlanets(){
    getPagePlanets(page)
    

}


document.getElementById("get_info").addEventListener("click", getInfo, {once : true});

function getInfo(e) {
  e.preventDefault()
  fetch('https://swapi.dev/api/films/2')
  .then((response) => {
    return response.json();
  })
  .then((data) => {
    const characters = data.characters;
    const divIndex = document.createElement('div')
    divIndex.innerHTML = "<b>Information about the characters</b>";
    document.body.append(divIndex);

      for (let index = 0; index < characters.length; index++) {
        fetch(characters[index])
        .then((response) => {
          return response.json()
        })
      .then((data) => {
        const divCharachter = document.createElement('div')
        divCharachter.innerHTML = "<b>Name: </b> " + data.name + ", <b>B-day years:</b>"+ data.birth_year + ", <b>gender: </b> "+ data.gender;
        document.body.append(divCharachter);
                    });
            }
        })
}


