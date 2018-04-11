#include <lib/pen.h>


void fruto(Pen &p, int lado, int radius){

    if(lado < 60 ){
    p.setColor(sf::Color::Red);
    p.circle(radius);
}
}

void arvore(Pen& p,int lado, int radius){

    if(lado < 1)
        return;
        p.setColor(sf::Color::Green);
        p.walk(lado);
        p.right(30);
        arvore(p,lado - 10, radius);
        p.left(60);
        arvore(p,lado - 10, radius);
        p.right(30);
        p.walk(-lado);
        for(int i = 0;i < 10 ;i++){
        fruto(p,lado, i);
        }
        p.setColor(sf::Color::Green);
}

void fractal(){

    Pen p(900, 700);

    p.setXY(450, 650);
    //espessura
    p.setThickness(1);
    //graus pra começar
    p.setHeading(90);
    //Velocidade
    p.setSpeed(300);

    int lado = 100;
    p.setColor(sf::Color::Cyan);
    //fruto(p,lado, );
    arvore(p, lado, 5);

    p.wait();
}

int main(){
    fractal();
    return 0;
}
