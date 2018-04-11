#include <lib/pen.h>

void gelo(Pen &p,int dec, int lado){
  float ang = 72;
    if(dec == 0 || lado < 2)
        return;

  p.walk(lado);
  gelo(p,5,lado*0.36);
  p.walk(-lado);
  p.right(ang);
  dec--;
  gelo(p,dec,lado);

}

void fractal(){

    Pen p(900, 750);

    p.setXY(450, 400);
    //espessura
    p.setThickness(1);
    //graus pra começar
    p.setHeading(90);
    //Velocidade
    p.setSpeed(100);

    int dec = 5;
    int lado = 150;
    p.setColor(sf::Color::Cyan);
    gelo(p, dec, lado);

    p.wait();
}

int main(){
    fractal();
    return 0;
}
