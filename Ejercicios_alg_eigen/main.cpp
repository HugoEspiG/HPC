#include <iostream>
#include<eigen3/Eigen/Dense>

typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> MiMatrixD;//Matriz generica de tipo double

//Ejercicio a
void eje01(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(2,2),m2(2,2);
    //matrices del ejercicio
    m1<<4,-2,1,-7;
    m2<<-1,2,6,-5;
    //calculo e impresion de la operacion
    std::cout<<(3*m1)+(-4*m2)<<"\n\n";
}

//Ejercicio b
void eje02(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(2,2),m2(2,2);
    //matrices del ejercicio
    m1<<0,-1,2,1;
    m2<<1,2,3,4;
    //calculo e impresion de la operacion
    std::cout<<(3*(m2*m1)-(4*m1))/2<<"\n\n";
}

//Ejercicio c
void eje03(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(2,2),m2(2,2),m3(2,2);
    //matrices del ejercicio
    m1<<-3,-2,3,3;
    m2<<5,3,9,4;
    m3<<1,1,0,0;
    //calculo e impresion de la operacion
    std::cout<<(m1.inverse()*m3*m2.transpose().inverse())<<"\n\n";
}

//Ejercicio d
void eje04(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(2,2),m2(2,2);
    //matrices del ejercicio
    m1<<2,1,-4,-3;
    m2<<2,2,6,4;
    //calculo e impresion de la operacion
    std::cout<<(m2*m1.inverse())<<"\n\n";
}

//Ejercicio e
void eje05(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(2,3),m2(3,2),m3(2,2);
    //matrices del ejercicio
    m1<<3,0,-1,0,2,1;
    m2<<1,2,1,0,0,6;
    m3<<-2,0,-2,-5;
    //calculo e impresion de la operacion
    std::cout<<2*(m1*m2+m3)<<"\n\n";
}

//Ejercicio f
void eje06(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(3,3),m2(3,3);
    //matrices del ejercicio
    m1<<1,5,-1,-1,2,2,0,-3,3;
    m2<<-1,-4,3,1,-2,-2,-3,3,-5;
    //calculo e impresion de la operacion
    std::cout<<(m1+(3*m2))<<"\n\n";
}

//Ejercicio g
void eje07(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(3,3),m2(3,3);
    //matrices del ejercicio
    m1<<2,7,3,3,9,4,1,5,3;
    m2<<1,0,2,0,1,0,0,0,1;
    //calculo e impresion de la operacion
    std::cout<<(m2*m1.inverse())<<"\n\n";
}

//Ejercicio h
void eje08(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(3,3),m2(3,3);
    //matrices del ejercicio
    m1<<1,1,1,6,5,4,13,10,8;
    m2<<0,1,2,1,0,2,1,2,0;
    //calculo e impresion de la operacion
    std::cout<<(m1.inverse()*m2)<<"\n\n";
}

//Ejercicio i
void eje09(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(2,2);
    //matrices del ejercicio
    m1<<3,-1,0,2;
    //calculo e impresion de la operacion
    std::cout<<(m1.transpose()*m1-(2*m1))<<"\n\n";
}

//Ejercicio j
void eje10(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(2,2);
    //matrices del ejercicio
    m1<<4,2,-1,0;
    //calculo e impresion de la operacion
    std::cout<<(m1*m1*m1)<<"\n\n";
}

//Ejercicio k
void eje11(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(2,2),m2(2,2),m3(2,2);
    //matrices del ejercicio
    m1<<2,4,3,2;
    m2<<1,0,2,1;
    m3<<7,5,6,1;
    //calculo e impresion de la operacion
    std::cout<<(m1.transpose().inverse()*m3*m2.inverse())<<"\n\n";
}

//Ejercicio l
void eje12(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(2,3),m2(3,2);
    //matrices del ejercicio
    m1<<1,0,-2,2,-1,3;
    m2<<2,-3,-2,0,-1,-2;
    //calculo e impresion de la operacion
    std::cout<<(m1*m1.transpose())+(-2*(m1*m2))<<"\n\n";
}

//Ejercicio m
void eje13(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(1,3),m2(3,2),m3(2,1);
    //matrices del ejercicio
    m1<<4,8,12;
    m2<<3,2,0,1,-1,0;
    m3<<3,-1;
    //calculo e impresion de la operacion
    std::cout<<(m1*m2*m3)<<"\n\n";
}

//Ejercicio o
void eje14(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(3,3),m2(3,3);
    //matrices del ejercicio
    m1<<2,5,7,6,3,4,5,-2,-3;
    m2<<-1,1,0,0,1,1,1,0,-1;
    //calculo e impresion de la operacion
    std::cout<<(m2*m1.inverse())<<"\n\n";
}

//Ejercicio p
void eje15(){//funcion void que hace calculo necesario para el ejercicio
    Eigen::MatrixXf m1(4,4),m2(4,4);
    //matrices del ejercicio
    m1<<1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,-1,-1,1;
    m2<<1,1,0,0,1,0,1,0,1,0,0,1,1,0,1,1;
    //calculo e impresion de la operacion
    std::cout<<(m1.inverse()*m2)<<"\n\n";
}
int main()
{
    std::cout<<"Ejercicio A: \n";
    eje01();
    std::cout<<"Ejercicio B: \n";
    eje02();
    std::cout<<"Ejercicio C: \n";
    eje03();
    std::cout<<"Ejercicio D: \n";
    eje04();
    std::cout<<"Ejercicio E: \n";
    eje05();
    std::cout<<"Ejercicio F: \n";
    eje06();
    std::cout<<"Ejercicio G: \n";
    eje07();
    std::cout<<"Ejercicio H: \n";
    eje08();
    std::cout<<"Ejercicio I: \n";
    eje09();
    std::cout<<"Ejercicio J: \n";
    eje10();
    std::cout<<"Ejercicio k: \n";
    eje11();
    std::cout<<"Ejercicio L: \n";
    eje12();
    std::cout<<"Ejercicio M: \n";
    eje13();
    std::cout<<"Ejercicio 0: \n";
    eje14();
    std::cout<<"Ejercicio P: \n";
    eje15();
    return 0;
}
