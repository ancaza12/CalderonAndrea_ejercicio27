//Codigo tomado de https://www.youtube.com/watch?v=UhZ1ESRR4OM

#include <iostream>
#include <cmath>
void integralE(float tf,float dt, int w);
void integralI(float tf,float dt, int w);
float ynE(float t, float dt, float w);
float ynI(float t, float dt, float w);



int main(){
    float w = 2;
    std::cout <<"Error de 0.1"<< std::endl;
    integralE(4/w, 0.1/w, w);
    integralI(4/w, 0.1/w, w);
    
    std::cout <<"Error de 0.01"<< std::endl;
    integralE(4/w, 0.01/w, w);
    integralI(4/w, 0.01/w, w); 
    
    std::cout <<"Error de 1"<< std::endl;
    integralE(4/w, 1/w, w);
    integralI(4/w, 1/w, w);
	return 0;
}

float ynE(float t, float dt, float w){
    float ysig= exp(-w*t) - dt*w*exp(-w*t);
    return ysig;
}

float ynI(float t, float dt, float w){
    float ysig= exp(-w*t) - dt*w*exp(-w*t +1);
    return ysig;
}


void integralE(float tf,float dt, int w){
    std::cout <<"Integral explicita de Euler"<< std::endl;

    for(float t=0; t<tf;t+=dt){
        float yE= ynE(t, dt,w);   
        std::cout <<"t= "<< t << " " << "Integral= "<< yE<< std::endl;
    }
}

void integralI(float tf,float dt, int w){
    std::cout <<"Integral implicita"<< std::endl;

    for(float t=0; t<tf;t+=dt){
        float yI= ynI(t, dt,w);
        std::cout <<"t= "<< t << " " << "Integral= "<< yI << std::endl;
    }
}



void error(float dt, float w){
    float teo=exp(-4);
    float exper1= ;
    float exper2=;
    float exper3=;
    
    float error1= teo- exper1/teo;
    float error2= teo - exper2/teo;
    float error3= teo -exper3/teo;
    std::cout <<"error1= "<< error1 << std::endl;
    std::cout <<"error2= "<< error2 << std::endl;
    std::cout <<"error3= "<< error3 << std::endl;

}