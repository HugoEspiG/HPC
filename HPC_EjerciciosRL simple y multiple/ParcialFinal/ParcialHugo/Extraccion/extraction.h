#ifndef EXTRACTION_H
#define EXTRACTION_H
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <list>
#include <vector>
#include <fstream>



class Extraction
{

    std::string dataset;       
    std::string delimitador;      
    bool header;                  


public:

    Extraction(std::string data,
               std::string separador,
               bool cabecera):
    dataset(data),delimitador(separador), header(cabecera){}


    std::vector<std::vector<std::string>>LeerCSV();

    Eigen::MatrixXd CSVtoEigen(
            std::vector<std::vector<std::string>>dataSet,
            int filas,
            int columnas);

auto Promedio(Eigen::MatrixXd datos)->decltype(datos.colwise().mean());
auto Desviacion(Eigen::MatrixXd datos)->decltype(((datos.array().square().colwise().sum()) / (datos.rows()-1)).sqrt());
Eigen::MatrixXd Norm(Eigen::MatrixXd datos);
std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd> TrainTestSplit(Eigen::MatrixXd datos, float size_train);
void VectortoFile(std::vector<float> vector,std::string file_name);
void EigentoFile(Eigen::MatrixXd matriz, std::string file_name);
};
#endif
