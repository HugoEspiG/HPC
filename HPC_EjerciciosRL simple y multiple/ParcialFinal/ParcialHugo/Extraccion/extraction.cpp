#include "extraction.h"
#include <stdlib.h>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <cmath>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <list>
#include <fstream>

std::vector<std::vector<std::string>> Extraction::LeerCSV(){

    std::ifstream archivo(dataset);

    std::vector<std::vector<std::string>>datosString;

    std::string linea="";
    while(getline(archivo,linea)){
        std::vector<std::string>vector;

        boost::algorithm::split(vector,linea,boost::is_any_of(delimitador));

        datosString.push_back(vector);

    }

    archivo.close();

    return datosString;
}


Eigen::MatrixXd Extraction::CSVtoEigen(
        std::vector<std::vector<std::string>>dataSet,
        int filas,
        int columnas){

    if(header==true){
        filas=filas-1;
    }
    Eigen::MatrixXd matriz(columnas,filas);

    for(int i=0; i<filas; i++){
        for (int j=0;j<columnas;j++){

            matriz(j,i)=atof(dataSet[i][j].c_str());
        }
    }

    return matriz.transpose();
}


auto Extraction::Promedio(Eigen::MatrixXd datos)->decltype(datos.colwise().mean()){
    return datos.colwise().mean();
}


auto Extraction::Desviacion(Eigen::MatrixXd datos)->decltype(((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt()){
   return((datos.array().square().colwise().sum())/(datos.rows()-1)).sqrt();
}


Eigen::MatrixXd Extraction::Norm(Eigen::MatrixXd datos){

    Eigen::MatrixXd diferenciaPromedio = datos.rowwise() - Promedio(datos);

   Eigen::MatrixXd matrizNormalizada = diferenciaPromedio.array().rowwise()/Desviacion(diferenciaPromedio);


   std::cout<<"\nNormalización:\n "<<matrizNormalizada<<std::endl;
   return matrizNormalizada;

}


std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd> Extraction::TrainTestSplit(Eigen::MatrixXd datos, float size_train){

    int filas_totales=datos.rows();

    int filas_train=round(filas_totales*size_train);

    int filas_test=filas_totales-filas_train;

    Eigen::MatrixXd Train = datos.topRows(filas_train);


    Eigen::MatrixXd X_Train = Train.leftCols(datos.cols()-1);
    Eigen::MatrixXd y_Train = Train.rightCols(1);

    Eigen::MatrixXd Test= datos.bottomRows(filas_test);

    Eigen::MatrixXd X_Test = Test.leftCols(datos.cols()-1);
    Eigen::MatrixXd y_Test = Test.rightCols(1);


    return std::make_tuple(X_Train,y_Train,X_Test,y_Test);
}




void Extraction::VectortoFile(std::vector<float> vector,std::string file_name){
    std::ofstream file_salida(file_name);

    std::ostream_iterator<float> salida_iterador(file_salida,"\n");

    std::copy(vector.begin(),vector.end(),salida_iterador);
}

void Extraction::EigentoFile(Eigen::MatrixXd matriz, std::string file_name){
    std::ofstream file_salida(file_name);
    if(file_salida.is_open()){
        file_salida<<matriz <<"\n";
    }
}
















