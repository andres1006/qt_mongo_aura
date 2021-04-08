
const fs = require('fs');

const starProcess = require('./runProcess');
let runProcess = null;
//singlenton de intancia de funcion para proceso de consola
if (!runProcess) {
  runProcess = starProcess();
}

//Funcion muestra archivo que contiene una carpeta y explora sus hijos
const searchFilesTest = (path) => {
  return new Promise((resolve, reject) => {
    try {
      let calibracion = "";
      fs.readdir(path, (err, files) => {
        if (err) return console.log(err);
        //Busca en las carpetas la primer calibracion de la prueba
        for (let i = 0; i < files.length; i++) {
          let stats = fs.statSync(`${path}/${files[i]}`);
          if (stats.isDirectory()) {
            if (fs.readdirSync(path)[i].substring(1, -1) == 'C') {
              calibracion = fs.readdirSync(path)[i];
              break;
            }
          }
        }
        let failed = 0;
        for (let i = 0; i < files.length; i++) {
          let stats = fs.statSync(`${path}/${files[i]}`);
          if (stats.isDirectory()) {
            if (fs.readdirSync(path)[i].substring(1, -1) == 'T') {
              let command = `./qt_mongo_prueba '${path}/${calibracion}' '${path}/${
                fs.readdirSync(path)[i]
              }' '${path.split('/')[path.split('/').length - 1]}' '${
                fs.readdirSync(path)[i]
              }'`;
              runProcess(command).then(data => {
                if (data.code !== 0) {
                  failed++;
                }
              });
            }
          }
        }
        if (failed === 0) {
          resolve(true);
        } else {
          resolve(false);
        }
      });
    } catch (error) {
      reject(error);
    }
  });
};

searchFilesTest('/home/sebastian/Escritorio/patologia_01002/paciente_01002');