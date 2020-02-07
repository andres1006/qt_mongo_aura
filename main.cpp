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

int main(int argc, char *argv[])
{
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

    OData *data = new OData();
    process *procesamiento = new process();

    data->setClbFileName("/home/andresagudelo/Documentos/OCTAVE proyects/PATOLOGIAS/temp/ControlesGrupoA/paciente_grupoA_20/CC9-03062018-104702"); // datos de la calibración asociada a una prueba.
    data->setTstFileName("/home/andresagudelo/Documentos/OCTAVE proyects/PATOLOGIAS/temp/ControlesGrupoA/paciente_grupoA_20/TSVV-03062018-104825"); // datos de la prueba
    data->open(0);
    data->importCsv();
    qDebug()<<"m_processedData.size() =";
    qDebug()<<data->dataSize();
    procesamiento->sendToDB(data,"paciente_grupoA_20","TSVV-03062018-104825","localhost",27017);

}
