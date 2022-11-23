#include "Extraccion/extraction.h"
#include "Regresion/linearregression.h"
#include <stdlib.h>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <cmath>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <list>
#include <fstream>

using namespace std;

int main(int argc,char *argv[])
{
    Extraction ExData (argv[1], argv[2], argv[3]);

    LinearRegression modeloLR;

 
    std::vector<std::vector<std::string>>dataframe= ExData.LeerCSV();


    int filas = dataframe.size()+1;
    int columnas = dataframe[0].size();
   
    Eigen::MatrixXd matData=ExData.CSVtoEigen(dataframe,filas,columnas);

    Eigen::MatrixXd matNorm=ExData.Norm(matData);

    Eigen::MatrixXd X_train, y_train, X_test, y_test;
    std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd>div_datos=ExData.TrainTestSplit(matNorm,0.8);

    std::tie(X_train, y_train, X_test, y_test) = div_datos;


    Eigen:: VectorXd vectorTrain = Eigen::VectorXd::Ones(X_train.rows());
    Eigen:: VectorXd vectorTest = Eigen::VectorXd::Ones(X_test.rows());


    X_train.conservativeResize(X_train.rows(),X_train.cols()+1);
    X_train.col(X_train.cols()-1)=vectorTrain;

    X_test.conservativeResize(X_test.rows(),X_test.cols()+1);
    X_test.col(X_test.cols()-1)=vectorTest;



    Eigen::VectorXd theta = Eigen::VectorXd::Zero(X_train.cols());



    float alpha = 0.01;
    int iteraciones= 1000;


    Eigen::VectorXd thetaOut;
    std::vector<float>costo;

    std::tuple<Eigen::VectorXd,std::vector<float>>gradiente=modeloLR.Gradiente(X_train,y_train,theta,alpha,iteraciones);


    std::tie(thetaOut,costo)=gradiente;



    auto prom_data=ExData.Promedio(matData);
    std::cout<<"\nPromedio: "<<prom_data<<std::endl;


    auto var_prom_independientes=prom_data(0,3);

    auto datos_escalados=matData.rowwise()-matData.colwise().mean();


    auto desviacion=ExData.Desviacion(datos_escalados);
    std::cout<<"\nDesviación: "<<desviacion<<std::endl;


    auto var_desviacion_ind=desviacion(0,3);

    Eigen::MatrixXd y_train_hat=(X_train*thetaOut*var_desviacion_ind).array()+var_prom_independientes;

    Eigen::MatrixXd y_e=matData.col(3).topRows(854);

    float metrica_R2_train=modeloLR.R2_Score(y_e,y_train_hat);

    std::cout<<"\nR2-train: "<<metrica_R2_train<<std::endl;

    Eigen::MatrixXd y_test_hat=(X_test*thetaOut*var_desviacion_ind).array()+var_prom_independientes;

    Eigen::MatrixXd y_p=matData.col(3).bottomRows(213);

    float metrica_R2_test=modeloLR.R2_Score(y_p,y_test_hat);

    std::cout<<"\nR2-test: "<<metrica_R2_test<<std::endl;



    return EXIT_SUCCESS;
}
