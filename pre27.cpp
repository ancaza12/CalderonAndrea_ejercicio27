//Codigo tomado de https://www.youtube.com/watch?v=UhZ1ESRR4OM

#include <iostream>
#include <cmath>
void integralE(float tf,float dt, int w);
void integralI(float tf,float dt, int w);
float ynE(float t, float dt, float w);
float ynI(float t, float dt, float w);
void error(float w);


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
    
    error(w);
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

void error(float w){
    float teo=exp(-4);
    float exper1= ynE(4/w, 0.1,w);
    float exper2=ynE(4/w, 0.01,w);
    float exper3=ynE(4/w, 1,w);
    
    float error1E= teo- exper1/teo;
    float error2E= teo - exper2/teo;
    float error3E= teo -exper3/teo;
    
    float exper1I= ynI(4/w, 0.1,w);
    float exper2I=ynI(4/w, 0.01,w);
    float exper3I=ynI(4/w, 1,w);
    
    float error1I= teo- exper1I/teo;
    float error2I= teo - exper2I/teo;
    float error3I= teo -exper3I/teo;
 
    std::cout <<"error1E= "<< error1E << std::endl;
    std::cout <<"error2E= "<< error2E << std::endl;
    std::cout <<"error3E= "<< error3E << std::endl;    
    std::cout <<"error1I= "<< error1I << std::endl;
    std::cout <<"error2I= "<< error2I << std::endl;
    std::cout <<"error3I= "<< error3I << std::endl;

}