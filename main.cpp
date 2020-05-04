//#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QFile>
#include "aurajson.h"
#include "process.h"
#include "data.h"

#include <mongocxx/client.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/exception/exception.hpp>


#include <iostream>
#include <dirent.h>

using namespace std;

void list_dir(string dir)
{
  DIR * directorio;
  struct dirent * elemento;
  string elem;
  if (directorio = opendir(dir.c_str()))
  {
   while (elemento = readdir(directorio))
   {
    elem = elemento->d_name;
    if (elem != "." && elem != "..") cout << elem << endl;
   }
  }
  closedir(directorio);
}

void init(string pathalistar)
{
  cout << "Ruta del directorio a listar: ";
  string dir;
  getline(cin, dir);
  list_dir(pathalistar);
  init(pathalistar);
}

int main(int argc, char *argv[])
{


    //list_dir(path);
/*
Prueba con Json. Los archivos necesarios para esta parte son: AuraJson.cpp/.h
*//*
    QString filepath = "/home/MargaretHamilton/PruebaJSON/datos.json";

    int patologia[] = {2,5};

    bool analisis[4] = {1,0,1,0};

    bool resultados[3] = {1,0,0};



    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(Json.toJson());
    file.close();


    AuraJson json(filepath,"AURA10",25,"HUCV",patologia,analisis,resultados);
    json.createJson();
    json.writeJson();*/


/*
Prueba subida datos a Mongo DB: los archivos necesarios para esta parte son: logger.cpp/.h, data.cpp/.h, process.cpp/.h, qutils.cpp/.h y utilsprocess.cpp/.h
*/

    //init();
    //system("PAUSE");
    //return 0;

    /*
    para
    argv[1] -> recibe la ruta de la calibracion
    argv[2] -> recibe la ruta del test
    argv[3] -> recibe nombre de la paciente
    argv[2] -> recibe nombre del test
*/



    OData *data = new OData();
    process *procesamiento = new process();

    data->setClbFileName(argv[1]); // datos de la calibración asociada a una prueba.
    data->setTstFileName(argv[2]); // datos de la prueba
    data->open(0);
    data->importCsv();
    qDebug()<<"m_processedData.size() =";
    //qDebug()<<data->dataSize();
    procesamiento->sendToDB(data,argv[3],argv[4],"localhost",27017);// argv 3 => nombre del paciente, argv 4 nombre de la prueba

}
