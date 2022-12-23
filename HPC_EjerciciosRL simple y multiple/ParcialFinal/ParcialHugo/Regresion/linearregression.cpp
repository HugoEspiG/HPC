#include "linearregression.h"
#include <eigen3/Eigen/Dense>
#include <iostream>
#include <cmath>
#include <vector>

float LinearRegression::F_OLS_Costo(Eigen::MatrixXd X,Eigen::MatrixXd y,Eigen::MatrixXd theta)
{
    Eigen::MatrixXd m_interior=pow((X*theta-y).array(),2);

    return m_interior.sum()/(2*X.rows()); 
}



std::tuple<Eigen::VectorXd,std::vector<float>>LinearRegression::Gradiente(Eigen::MatrixXd X,Eigen::MatrixXd y,Eigen::MatrixXd  theta,float alpha,int num_iter){
     Eigen::MatrixXd temporal=theta;
     int parametros=theta.rows();

     std::vector<float> costo;
     costo.push_back(F_OLS_Costo(X,y,theta));




      for(int i=0;i<num_iter;i++){
         Eigen::MatrixXd error=X*theta-y;
         for(int j=0; j<parametros;j++){
             Eigen::MatrixXd X_i=X.col(j);
             Eigen::MatrixXd termino=error.cwiseProduct(X_i);

             temporal(j,0)=theta(j,0)-((alpha/X.rows())*termino.sum());

         }


         theta=temporal;
         costo.push_back(F_OLS_Costo(X,y,theta));
     }

     return std::make_tuple(theta,costo);
}

float LinearRegression::R2_Score(Eigen::MatrixXd y,Eigen::MatrixXd y_hat){
    auto numerador= pow((y-y_hat).array(),2).sum();
    auto denominador= pow((y.array()-y.mean()),2).sum();
    return 1-(numerador/denominador);
}
