#include <lib/pen.h>

void trigo(Pen &p, int lado){
  if(lado < 1)
        return;
    for(int i = 0; i < 4; i++){
    p.walk(lado);
    p.right(45);
    trigo(p, lado/2);
    p.left(90);
    trigo(p, lado/2);
    p.right(45);
}

    p.walk(-lado*3);
}

void fractal(){

    Pen p(900, 750);

    p.setXY(400, 650);
    //espessura
    p.setThickness(1);
    //graus pra começar
    p.setHeading(90);
    //Velocidade
    p.setSpeed(100);


    int lado = 100;
    p.setColor(sf::Color::Cyan);
    trigo(p, lado);

    p.wait();
}

int main(){
    fractal();
    return 0;
}
