#include <iostream>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;

sf::RenderWindow window(sf::VideoMode(1340,700), "Arbol AVL");
int n0=0,n1=1,n2=2,n3=3,n4=4,n5=5,n6=6,n7=7,n8=8,n9=9;

sf::Text text0d; sf::Text text1d; sf::Text text2d; sf::Text text3d; sf::Text text4d;
sf::Text text5d; sf::Text text6d; sf::Text text7d; sf::Text text8d; sf::Text text9d;

sf::RectangleShape line01(sf::Vector2f(30, 5)); sf::RectangleShape line02(sf::Vector2f(30, 5));
sf::RectangleShape line11(sf::Vector2f(30, 5)); sf::RectangleShape line12(sf::Vector2f(30, 5));
sf::RectangleShape line21(sf::Vector2f(30, 5)); sf::RectangleShape line22(sf::Vector2f(30, 5));
sf::RectangleShape line31(sf::Vector2f(30, 5)); sf::RectangleShape line32(sf::Vector2f(30, 5));
sf::RectangleShape line41(sf::Vector2f(30, 5)); sf::RectangleShape line42(sf::Vector2f(30, 5));
sf::RectangleShape line51(sf::Vector2f(30, 5)); sf::RectangleShape line52(sf::Vector2f(30, 5));
sf::RectangleShape line61(sf::Vector2f(30, 5)); sf::RectangleShape line62(sf::Vector2f(30, 5));
sf::RectangleShape line71(sf::Vector2f(30, 5)); sf::RectangleShape line72(sf::Vector2f(30, 5));
sf::RectangleShape line81(sf::Vector2f(30, 5)); sf::RectangleShape line82(sf::Vector2f(30, 5));
sf::RectangleShape line91(sf::Vector2f(30, 5)); sf::RectangleShape line92(sf::Vector2f(30, 5));

//funcion extraida de: http://horiacondrea.com/2013/03/14/quick-tip-sprite-cliked-in-sfml/
bool ClickTrigger(sf::Sprite &av_Sprite, sf::RenderWindow &av_Window)
{
    int mouseX = sf::Mouse::getPosition().x;
    int mouseY = sf::Mouse::getPosition().y;
    sf::Vector2i windowPosition = av_Window.getPosition();
    if(mouseX > av_Sprite.getPosition().x + windowPosition.x && mouseX < ( av_Sprite.getPosition().x + av_Sprite.getGlobalBounds().width + windowPosition.x)
        && mouseY > av_Sprite.getPosition().y + windowPosition.y  && mouseY < ( av_Sprite.getPosition().y + av_Sprite.getGlobalBounds().height + windowPosition.y) )
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            return true;
        }
        return false;
    }
    return false;
};

string toString(int num)
{
    std::ostringstream ss;
    ss << num;
    return ss.str() ;
};

class Nodo
{
    public:
        int num;
        Nodo *izq, *der;
        Nodo(int NUM)
        {
            this->num=NUM;
            izq=NULL;
            der=NULL;
        }
};

class Arbol
{
    public:
    Nodo* raiz;

    Arbol()
    {
        raiz=NULL;
    }

    void insertar(Nodo* nuevo)
    {
        if(raiz!=NULL)
        {
            Insertar(raiz,nuevo);
        }
        else
        {
            raiz=nuevo;
        }
    }

    void Insertar(Nodo* actual,Nodo* nuevo)
    {
        if(nuevo->num<actual->num)
        {
            //izq
            if(actual->izq==NULL)
            {
                //insertar
                actual->izq=nuevo;
            }
            else
            {
                //llamada recursiva
                Insertar(actual->izq,nuevo);
            }
        }
        else
        {
            //der
            if(actual->der==NULL)
            {
                //insertar
                actual->der=nuevo;
            }
            else
            {
                //llamada recursiva
                Insertar(actual->der,nuevo);
            }
        }
    }

    void imprimir()
    {
        imprimir(raiz);
    }

    void imprimir(Nodo* actual)
    {
        if(actual==NULL)
        return;
        cout<<actual->num<<endl;
        imprimir(actual->izq);
        imprimir(actual->der);
    }

    void DibujarNodo(Nodo* actual, int x, int y)
    {
        if(actual==NULL)
        return;
        if(actual->num==0)
        {
            text0d.setPosition(x,y);
            line01.setPosition(x+25,y+45);
            line02.setPosition(x,y+50);
        }
        if(actual->num==1)
        {
            text1d.setPosition(x,y);
            line11.setPosition(x+25,y+45);
            line12.setPosition(x,y+50);
        }
        if(actual->num==2)
        {
            text2d.setPosition(x,y);
            line21.setPosition(x+25,y+45);
            line22.setPosition(x,y+50);
        }
        if(actual->num==3)
        {
            text3d.setPosition(x,y);
            line31.setPosition(x+25,y+45);
            line32.setPosition(x,y+50);
        }
        if(actual->num==4)
        {
            text4d.setPosition(x,y);
            line41.setPosition(x+25,y+45);
            line42.setPosition(x,y+50);
        }
        if(actual->num==5)
        {
            text5d.setPosition(x,y);
            line51.setPosition(x+25,y+45);
            line52.setPosition(x,y+50);
        }
        if(actual->num==6)
        {
            text6d.setPosition(x,y);
            line61.setPosition(x+25,y+45);
            line62.setPosition(x,y+50);
        }
        if(actual->num==7)
        {
            text7d.setPosition(x,y);
            line71.setPosition(x+25,y+45);
            line72.setPosition(x,y+50);
        }
        if(actual->num==8)
        {
            text8d.setPosition(x,y);
            line81.setPosition(x+25,y+45);
            line82.setPosition(x,y+50);
        }
        if(actual->num==9)
        {
            text9d.setPosition(x,y);
            line91.setPosition(x+25,y+45);
            line92.setPosition(x,y+50);
        }
        DibujarNodo(actual->izq,x-50,y+50);
        DibujarNodo(actual->der,x+50,y+50);
    }
};

int main()
{
    Arbol arb;
    sf::Font font;
    font.loadFromFile("daniela.ttf");

    sf::Texture fondo;
    fondo.loadFromFile("arbol.jpg");
    //fondo.loadFromFile("arbol.jpg", sf::IntRect(100, 100, 1002, 1002));   para cargar solo una parte de la imagen

    sf::Sprite sfondo(fondo);
    sf::Text text0;
    text0.setFont(font);
    text0.setString(toString(n0));
    text0.setCharacterSize(70); // in pixels, not points!
    text0.setColor(sf::Color::Red);// set the color
    text0.setPosition(sf::Vector2f(40,0));
    sf::Texture texture0;
    texture0.create(35,35);
    sf::Sprite stexture0(texture0);
    stexture0.setPosition(sf::Vector2f(40,0));

    sf::Text text1;
    text1.setFont(font);
    text1.setString(toString(n1));
    text1.setCharacterSize(70); // in pixels, not points!
    text1.setColor(sf::Color::Red);// set the color
    text1.setPosition(sf::Vector2f(40,70));
    sf::Texture texture1;
    texture1.create(35,35);
    sf::Sprite stexture1(texture1);
    stexture1.setPosition(sf::Vector2f(40,70));

    sf::Text text2;
    text2.setFont(font);
    text2.setString(toString(n2));
    text2.setCharacterSize(70); // in pixels, not points!
    text2.setColor(sf::Color::Red);// set the color
    text2.setPosition(sf::Vector2f(40,140));
    sf::Texture texture2;
    texture2.create(35,35);
    sf::Sprite stexture2(texture2);
    stexture2.setPosition(sf::Vector2f(40,140));

    sf::Text text3;
    text3.setFont(font);
    text3.setString(toString(n3));
    text3.setCharacterSize(70); // in pixels, not points!
    text3.setColor(sf::Color::Red);// set the color
    text3.setPosition(sf::Vector2f(40,210));
    sf::Texture texture3;
    texture3.create(35,35);
    sf::Sprite stexture3(texture3);
    stexture3.setPosition(sf::Vector2f(40,210));

    sf::Text text4;
    text4.setFont(font);
    text4.setString(toString(n4));
    text4.setCharacterSize(70); // in pixels, not points!
    text4.setColor(sf::Color::Red);// set the color
    text4.setPosition(sf::Vector2f(40,280));
    sf::Texture texture4;
    texture4.create(35,35);
    sf::Sprite stexture4(texture4);
    stexture4.setPosition(sf::Vector2f(40,280));

    sf::Text text5;
    text5.setFont(font);
    text5.setString(toString(n5));
    text5.setCharacterSize(70); // in pixels, not points!
    text5.setColor(sf::Color::Red);// set the color
    text5.setPosition(sf::Vector2f(40,350));
    sf::Texture texture5;
    texture5.create(35,35);
    sf::Sprite stexture5(texture5);
    stexture5.setPosition(sf::Vector2f(40,350));

    sf::Text text6;
    text6.setFont(font);
    text6.setString(toString(n6));
    text6.setCharacterSize(70); // in pixels, not points!
    text6.setColor(sf::Color::Red);// set the color
    text6.setPosition(sf::Vector2f(40,420));
    sf::Texture texture6;
    texture6.create(35,35);
    sf::Sprite stexture6(texture6);
    stexture6.setPosition(sf::Vector2f(40,420));

    sf::Text text7;
    text7.setFont(font);
    text7.setString(toString(n7));
    text7.setCharacterSize(70); // in pixels, not points!
    text7.setColor(sf::Color::Red);// set the color
    text7.setPosition(sf::Vector2f(40,485));
    sf::Texture texture7;
    texture7.create(35,35);
    sf::Sprite stexture7(texture7);
    stexture7.setPosition(sf::Vector2f(40,485));

    sf::Text text8;
    text8.setFont(font);
    text8.setString(toString(n8));
    text8.setCharacterSize(70); // in pixels, not points!
    text8.setColor(sf::Color::Red);// set the color
    text8.setPosition(sf::Vector2f(40,550));
    sf::Texture texture8;
    texture8.create(35,35);
    sf::Sprite stexture8(texture8);
    stexture8.setPosition(sf::Vector2f(40,550));

    sf::Text text9;
    text9.setFont(font);
    text9.setString(toString(n9));
    text9.setCharacterSize(70); // in pixels, not points!
    text9.setColor(sf::Color::Red);// set the color
    text9.setPosition(sf::Vector2f(40,610));
    sf::Texture texture9;
    texture9.create(35,35);
    sf::Sprite stexture9(texture9);
    stexture9.setPosition(sf::Vector2f(40,610));

    sf::SoundBuffer buffer;
    buffer.loadFromFile("jugar.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);

    int flag0 = -10,flag1 = -1,flag2 = -2, flag3 = -3, flag4 = -4, flag5 = -5, flag6 = -6, flag7 = -7, flag8 = -8, flag9 = -9;

    text0d.setFont(font); text1d.setFont(font);text2d.setFont(font);text3d.setFont(font);text4d.setFont(font);
    text5d.setFont(font); text6d.setFont(font);text7d.setFont(font);text8d.setFont(font);text9d.setFont(font);

    while (window.isOpen())
    {
        window.draw(sfondo,sf::RenderStates::Default); //se dibuja el fondo en pantalla
        window.draw(text0);
        window.draw(stexture0,sf::RenderStates::Default); //se dibuja el sprite de la pila 1 en pantalla
        window.draw(text1);
        window.draw(stexture1,sf::RenderStates::Default); //se dibuja el sprite de la pila 1 en pantalla
        window.draw(text2);
        window.draw(stexture2,sf::RenderStates::Default); //se dibuja el sprite de la pila 1 en pantalla
        window.draw(text3);
        window.draw(stexture3,sf::RenderStates::Default); //se dibuja el sprite de la pila 1 en pantalla
        window.draw(text4);
        window.draw(stexture4,sf::RenderStates::Default); //se dibuja el sprite de la pila 1 en pantalla
        window.draw(text5);
        window.draw(stexture5,sf::RenderStates::Default); //se dibuja el sprite de la pila 1 en pantalla
        window.draw(text6);
        window.draw(stexture6,sf::RenderStates::Default); //se dibuja el sprite de la pila 1 en pantalla
        window.draw(text7);
        window.draw(stexture7,sf::RenderStates::Default); //se dibuja el sprite de la pila 1 en pantalla
        window.draw(text8);
        window.draw(stexture8,sf::RenderStates::Default); //se dibuja el sprite de la pila 1 en pantalla
        window.draw(text9);
        window.draw(stexture9,sf::RenderStates::Default); //se dibuja el sprite de la pila 1 en pantalla
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) //si se cierra manualmente
            {
                window.close();
                cout<<"usted cerro el programa dandole clic al boton";
            }
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) //si se presiona ESC
            {
                window.close();
                cout<<"usted cerro el programa usando ESC: ";
            }
            if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::R)) //barra espaciadora activa musica
            {
                sound.play();
                sound.setLoop(true);
            }
            if((event.type== sf::Event::KeyPressed)&& (event.key.code == sf::Keyboard::P))
            {
                sound.pause();
            }
            if(flag0==-10)
            {
                if (ClickTrigger(stexture0,window)||(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num0)) //verifica si se le da click a la primera pila
                {
                    arb.insertar(new Nodo(n0));
                    flag0=0;
                    text0d.setString(toString(n0));
                    text0d.setCharacterSize(50); // in pixels, not points!
                    text0d.setColor(sf::Color::Red);// set the color
                    text0.setColor(sf::Color::Black);
                    arb.DibujarNodo(arb.raiz,600,0);
                    line01.setFillColor(sf::Color::Blue);
                    line01.rotate(45);
                    window.draw(line01);
                    line02.setFillColor(sf::Color::Blue);
                    line02.rotate(135);

                    arb.imprimir();
                    cout<<"=============="<<endl;
                }
            }
            if(flag1==-1)
            {
                if (ClickTrigger(stexture1,window)||(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num1)) //verifica si se le da click a la primera pila
                {
                    arb.insertar(new Nodo(n1));
                    flag1=1;
                    text1d.setString(toString(n1));
                    text1d.setCharacterSize(50); // in pixels, not points!
                    text1d.setColor(sf::Color::Red);// set the color
                    text1.setColor(sf::Color::Black);
                    arb.DibujarNodo(arb.raiz,600,0);
                    line11.setFillColor(sf::Color::Blue);
                    line11.rotate(45);
                    window.draw(line01);
                    line12.setFillColor(sf::Color::Blue);
                    line12.rotate(135);

                    arb.imprimir();
                    cout<<"=============="<<endl;
                }
            }
            if(flag2==-2)
            {
                if (ClickTrigger(stexture2,window)||(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num2)) //verifica si se le da click a la primera pila
                {
                    arb.insertar(new Nodo(n2));
                    flag2=2;
                    text2d.setString(toString(n2));
                    text2d.setCharacterSize(50); // in pixels, not points!
                    text2d.setColor(sf::Color::Red);// set the color
                    text2.setColor(sf::Color::Black);
                    arb.DibujarNodo(arb.raiz,600,0);
                    line21.setFillColor(sf::Color::Blue);
                    line21.rotate(45);
                    window.draw(line01);
                    line22.setFillColor(sf::Color::Blue);
                    line22.rotate(135);

                    arb.imprimir();
                    cout<<"=============="<<endl;
                }
            }
            if(flag3==-3)
            {
                if (ClickTrigger(stexture3,window)||(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num3)) //verifica si se le da click a la primera pila
                {
                    arb.insertar(new Nodo(n3));
                    flag3=3;
                    text3d.setString(toString(n3));
                    text3d.setCharacterSize(50); // in pixels, not points!
                    text3d.setColor(sf::Color::Red);// set the color
                    text3.setColor(sf::Color::Black);
                    arb.DibujarNodo(arb.raiz,600,0);
                    line31.setFillColor(sf::Color::Blue);
                    line31.rotate(45);
                    window.draw(line01);
                    line32.setFillColor(sf::Color::Blue);
                    line32.rotate(135);

                    arb.imprimir();
                    cout<<"=============="<<endl;
                }
            }
            if(flag4==-4)
            {
                if (ClickTrigger(stexture4,window)||(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num4)) //verifica si se le da click a la primera pila
                {
                    arb.insertar(new Nodo(n4));
                    flag4=4;
                    text4d.setString(toString(n4));
                    text4d.setCharacterSize(50); // in pixels, not points!
                    text4d.setColor(sf::Color::Red);// set the color
                    text4.setColor(sf::Color::Black);
                    arb.DibujarNodo(arb.raiz,600,0);
                    line41.setFillColor(sf::Color::Blue);
                    line41.rotate(45);
                    window.draw(line01);
                    line42.setFillColor(sf::Color::Blue);
                    line42.rotate(135);

                    arb.imprimir();
                    cout<<"=============="<<endl;
                }
            }
            if(flag5==-5)
            {
                if (ClickTrigger(stexture5,window)||(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num5)) //verifica si se le da click a la primera pila
                {
                    arb.insertar(new Nodo(n5));
                    flag5=0;
                    text5d.setString(toString(n5));
                    text5d.setCharacterSize(50); // in pixels, not points!
                    text5d.setColor(sf::Color::Red);// set the color
                    text5.setColor(sf::Color::Black);
                    arb.DibujarNodo(arb.raiz,600,0);
                    line51.setFillColor(sf::Color::Blue);
                    line51.rotate(45);
                    window.draw(line01);
                    line52.setFillColor(sf::Color::Blue);
                    line52.rotate(135);

                    arb.imprimir();
                    cout<<"=============="<<endl;
                }
            }
            if(flag6==-6)
            {
                if (ClickTrigger(stexture6,window)||(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num6)) //verifica si se le da click a la primera pila
                {
                    arb.insertar(new Nodo(n6));
                    flag6=0;
                    text6d.setString(toString(n6));
                    text6d.setCharacterSize(50); // in pixels, not points!
                    text6d.setColor(sf::Color::Red);// set the color
                    text6.setColor(sf::Color::Black);
                    arb.DibujarNodo(arb.raiz,600,0);
                    line61.setFillColor(sf::Color::Blue);
                    line61.rotate(45);
                    window.draw(line01);
                    line62.setFillColor(sf::Color::Blue);
                    line62.rotate(135);

                    arb.imprimir();
                    cout<<"=============="<<endl;
                }
            }
            if(flag7==-7)
            {
                if (ClickTrigger(stexture7,window)||(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num7)) //verifica si se le da click a la primera pila
                {
                    arb.insertar(new Nodo(n7));
                    flag7=0;
                    text7d.setString(toString(n7));
                    text7d.setCharacterSize(50); // in pixels, not points!
                    text7d.setColor(sf::Color::Red);// set the color
                    text7.setColor(sf::Color::Black);
                    arb.DibujarNodo(arb.raiz,600,0);
                    line71.setFillColor(sf::Color::Blue);
                    line71.rotate(45);
                    window.draw(line01);
                    line72.setFillColor(sf::Color::Blue);
                    line72.rotate(135);

                    arb.imprimir();
                    cout<<"=============="<<endl;
                }
            }
            if(flag8==-8)
            {
                if (ClickTrigger(stexture8,window)||(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num8)) //verifica si se le da click a la primera pila
                {
                    arb.insertar(new Nodo(n8));
                    flag8=0;
                    text8d.setString(toString(n8));
                    text8d.setCharacterSize(50); // in pixels, not points!
                    text8d.setColor(sf::Color::Red);// set the color
                    text8.setColor(sf::Color::Black);
                    arb.DibujarNodo(arb.raiz,600,0);
                    line81.setFillColor(sf::Color::Blue);
                    line81.rotate(45);
                    window.draw(line01);
                    line82.setFillColor(sf::Color::Blue);
                    line82.rotate(135);

                    arb.imprimir();
                    cout<<"=============="<<endl;
                }
            }
            if(flag9==-9)
            {
                if (ClickTrigger(stexture9,window)||(event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num9)) //verifica si se le da click a la primera pila
                {
                    arb.insertar(new Nodo(n9));
                    flag9=0;
                    text9d.setString(toString(n9));
                    text9d.setCharacterSize(50); // in pixels, not points!
                    text9d.setColor(sf::Color::Red);// set the color
                    text9.setColor(sf::Color::Black);
                    arb.DibujarNodo(arb.raiz,600,0);
                    line91.setFillColor(sf::Color::Blue);
                    line91.rotate(45);
                    window.draw(line01);
                    line92.setFillColor(sf::Color::Blue);
                    line92.rotate(135);

                    arb.imprimir();
                    cout<<"=============="<<endl;
                }
            }
        }
        window.draw(text0d,sf::RenderStates::Default);
        window.draw(text1d,sf::RenderStates::Default);
        window.draw(text2d,sf::RenderStates::Default);
        window.draw(text3d,sf::RenderStates::Default);
        window.draw(text4d,sf::RenderStates::Default);
        window.draw(text5d,sf::RenderStates::Default);
        window.draw(text6d,sf::RenderStates::Default);
        window.draw(text7d,sf::RenderStates::Default);
        window.draw(text8d,sf::RenderStates::Default);
        window.draw(text9d,sf::RenderStates::Default);
        window.draw(line01);
        window.draw(line02);
        window.draw(line11);
        window.draw(line12);
        window.draw(line21);
        window.draw(line22);
        window.draw(line31);
        window.draw(line32);
        window.draw(line41);
        window.draw(line42);
        window.draw(line51);
        window.draw(line52);
        window.draw(line61);
        window.draw(line62);
        window.draw(line71);
        window.draw(line72);
        window.draw(line81);
        window.draw(line82);
        window.draw(line91);
        window.draw(line92);
        window.display();
    }
}
