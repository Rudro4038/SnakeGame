#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <utility>
#include <SFML/Graphics.hpp>
#include<SFML/window.hpp>
#include<SFML/audio.hpp>
#include<SFML/network.hpp>
#include<SFML/system.hpp>

//
using namespace sf;

//Variables

RenderWindow window(sf::VideoMode(1900, 1000), "Snake Hero");
RectangleShape orange(Vector2f(50.f, 50.f));
RectangleShape red(Vector2f(50.f, 50.f)); 
RectangleShape block(Vector2f(50.f, 50.f)); 

sf::Font font;

int game = 1, dir = 0, speed = 200, size = 1;
int  dir1= 0, speed1 = 200, size1 = 1;
int randomx = 0, randomy = 0;
int mx0 = 0, mx1 = 0, mx2 = 0, mx3 = 0, mx9 = 0;

Texture xyz;
RectangleShape PE(Vector2f(1900.0f, 1000.0f)); 
RectangleShape pointer(Vector2f(50.0f, 50.0f));
Texture page1tex,page2tex,pointertex;


Event appevent;

//Map
int map1x[150], map1y[150];
int map2x[150], map2y[150];
int map3x[150], map3y[150];

struct Point{
    int x = 0;
    int y = 0;
}p[1000],q[1000];

//Functions
void pagefront();
void pagemain();
void page1();
void page3();


int Game1(RenderWindow &window,int mode);
int GameEndless();

//Utility func
void highscore(); 
String toString(Int64 integer);
void makingmap();
int GameOver(int score);
int max(int a, int b);

int main()
{
    makingmap();
    window.setFramerateLimit(60);

    orange.setFillColor(Color(255, 120, 0));
    red.setFillColor(Color(255, 0, 36));
    block.setFillColor(Color(255, 255, 255));

    font.loadFromFile("D:/ProgectMaterial/fffff.ttf");

    xyz.loadFromFile("D:/ProgectMaterial/front.png");  
    page1tex.loadFromFile("D:/ProgectMaterial/page1.png"); 
    page2tex.loadFromFile("D:/ProgectMaterial/main.png"); 
    pointertex.loadFromFile("D:/ProgectMaterial/pointertex.png");

    pagefront();
    pagemain();
    return 0;
}


void pagefront() {
    Event ee;
    Clock clock; 
    PE.setTexture(&xyz); 

    while (clock.getElapsedTime().asMilliseconds() <= 3500) {
        while (window.pollEvent(ee)) {
            if (ee.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(PE);
        window.display();
    }
}

void pagemain() {
    PE.setTexture(&page2tex);
    pointer.setTexture(&pointertex);



    while (window.isOpen()) {
        Event ee;
        while (window.pollEvent(ee)) {
            //std::cout << "ok1 ";
            if (ee.type == Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // left click...
                std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << '\n';
                pointer.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

                int tempx = sf::Mouse::getPosition(window).x, tempy = sf::Mouse::getPosition(window).y;
                if (565 <= tempx && 295 <= tempy && 1005 >= tempx && 362 >= tempy) {
                    page1();
                    PE.setTexture(&page2tex);
                    pointer.setTexture(&pointertex);
                }
                if (565 <= tempx && 500 <= tempy && 1005 >= tempx && 575 >= tempy) {
                    GameEndless();
                }
                if (565 <= tempx && 710 <= tempy && 1005 >= tempx && 780 >= tempy) {
                    return;
                }
            }
        window.clear();
        window.draw(PE);
        window.draw(pointer);
        window.display();
        }
    }
}

void highscore() {
    std::cout << "HIGH\n";
    std::cout << mx0 << " " << mx1 << " " << mx2 << " " << mx3 << '\n';

    sf::Text text,text2;
    text.setString("High Scores : ");
    text.setFont(font); 
    text.setCharacterSize(80); 
    text.setFillColor(Color(255, 70, 0));
    text.setPosition(300.0f, 200.0f);

    text2.setString("Map 0 : "+ toString(mx0) +'\n' +
        "Map 1 : " + toString(mx1) + '\n'+
        "Map 2 : " + toString(mx2) + '\n'+
        "Map 3 : " + toString(mx3) + '\n');
    text2.setFont(font);
    text2.setCharacterSize(60);
    text2.setFillColor(Color(255, 100, 0));
    text2.setPosition(450.0f, 300.0f);


    window.clear(); 
    window.draw(text);
    window.draw(text2);
    window.display();
    sleep(seconds(3.5));
}

void page1() {
    PE.setTexture(&page1tex);
    pointer.setTexture(&pointertex);


    while (window.isOpen()) {
        Event ee;
        while (window.pollEvent(ee)) {
            //std::cout << "ok1 ";
            if (ee.type == Event::Closed)
                window.close();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                // left click...
                std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y<<'\n';
                pointer.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

                int tempx = sf::Mouse::getPosition(window).x, tempy = sf::Mouse::getPosition(window).y;
                if (565 <= tempx && 295<=tempy && 1005>=tempx && 362>=tempy ) {
                    Game1(window, 0);  
                }
                if (565 <= tempx && 500 <= tempy && 1005 >= tempx && 575 >= tempy) {
                    Game1(window, 1);
                }
                if (565 <= tempx && 710 <= tempy && 1005 >= tempx && 780 >= tempy) {
                    Game1(window, 2);
                }
                if (1275 <= tempx && 285 <= tempy && 1735 >= tempx && 362 >= tempy) {
                    Game1(window, 3);
                }
                if (1275 <= tempx && 500 <= tempy && 1735 >= tempx && 570 >= tempy) {
                    highscore();
                }
                if (1275 <= tempx && 705 <= tempy && 1735 >= tempx && 780 >= tempy) {
                    return;
                }
            }
        }
        window.clear();
        window.draw(PE);
        window.draw(pointer);
        window.display();
    }
}

void page3() {
    PE.setTexture(&page2tex); 
    while (window.isOpen()) {
        Event ee; 
        while (window.pollEvent(ee)) {
            //std::cout << "ok1 ";
            if ( ee.type == Event::Closed) 
                window.close();
            if (ee.type == Event::KeyPressed){
                if (ee.key.code == Keyboard::Left) std::cout << "ok\n "; 

                if (ee.key.code == Keyboard::Numpad0) {
                    
                }
                if (ee.key.code == Keyboard::Numpad1) {
                    std::cout << "in ";
                    Game1(window, 1);
                }
                if (ee.key.code == Keyboard::Numpad2) {
                    Game1(window, 2);
                }
                if (ee.key.code == Keyboard::Numpad3) {
                    Game1(window, 3);
                }
            }
        }
        window.clear();
        window.draw(PE);
        window.display();
    }
}

void makingmap() {
    for (int i = 0; i < 150; i++) {
        map1x[i] = -1;
        map1y[i] = -1;
        map2x[i] = -1;
        map2y[i] = -1;
        map3x[i] = -1;
        map3y[i] = -1;
    }
    // Map 1
    int j = 0;
    {
    for (int i = 0; i < 20; i++) {
        if (i < 10) {
            map1x[j] = 0;
            map1y[j] = i;
            //std::cout << map1x[j] << " " << map1y[j] <<" "<<j  << '\n';
            j++;
        }
        if (i == 9) {
            for (int ct = 1; ct < 37; ct++) {
                if (!(ct > 20)) continue;
                map1x[j] = ct;
                map1y[j] = i;
                //std::cout << map1x[j] << " " << map1y[j] << " " << j << '\n';
                j++;
            }
        }
        if (i > 8) {
            map1x[j] = 37;
            map1y[j] = i;
            //std::cout << map1x[j] << " " << map1y[j] << " " << j << '\n';
            j++;
        }
    }
    std::cout << j << '\n';
    map1x[j] = 1; map1y[j] = 0; j++;
    map1x[j] = 2; map1y[j] = 0; j++;
    map1x[j] = 36; map1y[j] = 19; j++;
    map1x[j] = 35; map1y[j] = 19; j++;
    std::cout << j << '\n';
    }

    /*for (int i = 0; i < 150; i++) {
        std::cout << map1x[i] << " " << map1y[i] << '\n';
    }*/
    //Map 2
    j = 0;
    {
        for (int i = 0; i < 12; i++) {
            map2x[j] = i;
            map2y[j] = 0;
            j++;
            map2x[j] = 37 - i;
            map2y[j] = 19;
            j++;
        }
        for (int i = 0; i < 12; i++) {
            map2x[j] = 18;
            map2y[j] = i+4;
            j++;
        }

    }
}

String toString(Int64 integer)
{
    std::ostringstream os;
    os << integer;
    return os.str();
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int GameOver(int score) {
    sf::Text text, text2;
    text.setString("Score : " + toString(score)) ;
    text.setFont(font); 
    text.setCharacterSize(80);
    text.setFillColor(Color(255, 70, 0));
    text.setPosition(300.0f, 200.0f);

    window.clear(); 
    window.draw(text); 
    window.draw(text2);  
    window.display();  

    sleep(seconds(2.5));
    return score;
}

int Game1(RenderWindow &window, int mode ) {

    size = 1, dir = 0,speed = 200;
    p[0].x = 100; p[0].y = 100;

    srand(time(NULL));

    int mapx[150], mapy[150];

    for (int i = 0; i < 150; i++) {
        mapx[i] =-1;
        mapy[i] = -1;
        if (mode == 1) {
            if (map1y[i] == -1 || map1x[i] == -1) continue;
            mapx[i] = map1x[i];
            mapy[i] = map1y[i];
            //std::cout << mapx[i] << " " << mapy[i] << '\n';
            //std::cout << "ok ";
        }
        if (mode == 2) {
            if (map2y[i] == -1 || map2x[i] == -1) continue;
            mapx[i] = map2x[i];
            mapy[i] = map2y[i];
        }
        if (mode == 3 && i < 35) {
            mapx[i] = rand() % 38;
            mapy[i] = rand() % 20;
            if (mapx[i]*50 == 500 && mapy[i]*50 == 500) mapx[i] = -1;
        }
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(34);
    text.setFillColor(Color(255, 70, 0));
    text.setPosition(50.0f, 950.0f);
    

    randomx = 500;
    randomy = 500;

    red.setPosition(randomx, randomy);

    Clock clock;
    bool chck = 1;

    while (window.isOpen())
    {

        while (window.pollEvent(appevent))
        {

            if (appevent.type == Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                return 0;
            }
        }             
        

        if (appevent.type == Event::KeyPressed) {
            chck = 1;
            if (appevent.key.code == Keyboard::Right && dir != 1 && dir != 0) dir = 0;
            else if (appevent.key.code == Keyboard::Left && dir != 0 && dir != 1) dir = 1;
            else if (appevent.key.code == Keyboard::Down && dir != 3 && dir != 2) dir = 2;
            else if (appevent.key.code == Keyboard::Up && dir != 2 && dir != 3) dir = 3;
            else chck = 0;
        }

        /*SURPRISINGLY IT DONT WORK --->  if (appevent.type == Event::KeyPressed)  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) std::cout << "W\n";
        BUT IT WORKS <3
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { 
                std::cout << "W\n";
        }*/

        //UPDATE
        if ( clock.getElapsedTime().asMilliseconds() >= speed || chck ) {


            // Updating body
            for (int i = size; i > 0; i--) {
                p[i].x = p[i - 1].x;
                p[i].y = p[i - 1].y;
            }
            //Updating head position
            if (dir == 0) p[0].x += 50;
            else if (dir == 1) p[0].x -= 50;
            else if (dir == 2) p[0].y += 50;
            else if (dir == 3) p[0].y -= 50;

            //If body goes out of display
            if (p[0].x == 1900) p[0].x = 0;
            else if (p[0].x == -50) p[0].x = 1850;
            else if (p[0].y == 1000) p[0].y = 0;
            else if (p[0].y == -50) p[0].y = 950;

            //Updating food
            red.setPosition(randomx, randomy);
            //If collision own body 
            for (int i = size; i > 0; i--) {
                if (p[0].x == p[i].x && p[0].y == p[i].y) {

                    if (mode == 0) mx0 = max(GameOver(size), mx0);
                    else if (mode == 1) mx1 = max(GameOver(size), mx1);
                    else if (mode == 2) mx2 = max(GameOver(size), mx2);
                    else if (mode == 3) mx3 = max(GameOver(size), mx3);
                    return 0;
                }
                
            }
            //If collision with map 
            for (int i = 0; i < 150; i++) {
                if ( mapy[i] == -1 || mapx[i] ==-1 ) continue;
                if (p[0].x == mapx[i]*50 && p[0].y == mapy[i] *50) {

                    if (mode == 0) mx0 = max(GameOver(size), mx0);
                    else if (mode == 1) mx1 = max(GameOver(size), mx1);
                    else if (mode == 2) mx2 = max(GameOver(size), mx2);
                    else if (mode == 3) mx3 = max(GameOver(size), mx3);
                    return 0;
                }
            }
            //If head eats food
            if (p[0].x == red.getPosition().x && p[0].y == red.getPosition().y) {
                size += 1;
                if (speed > 100) speed -= 15;
                bool good = true; 
                while (good) {
                    randomx = rand() % 1900;
                    randomy = rand() % 1000;
                    for (int i = 0; i < 38; i++) {
                        if (randomx < (i + 1) * 50 && randomx >= i * 50) randomx = (i) * 50;
                    }
                    for (int i = 0; i < 20; i++) {
                        if (randomy < (i + 1) * 50 && randomy >= i * 50) randomy = (i) * 50;
                    }

                    bool bdy = false ;
                    for (int i = 0; i < size; i++) {
                        if (p[i].x == randomx && p[i].y == randomy) {
                            bdy = true ;
                            break;
                        }
                        /*else if ((randomx != p[i].x || randomx != p[i].x) && i == size - 1) {
                            good = false;
                        }*/
                        //if (i == size - 1) bdy = true;
                    }

                    bool map = false;
                    for (int i = 0; i < 150; i++) {
                        if (mapy[i] == -1 || mapx[i] == -1) continue;
                        if (mapx[i]*50 == randomx && mapy[i]*50 == randomy) {
                            map = true;
                            break;
                        }
                        /*else if ((randomx != p[i].x || randomx != p[i].x) && i == size - 1) {
                            good = false;
                        }*/
                        //if (i == size - 1) map = true;

                    }
                    good = bdy || map; 
                }
            }
            clock.restart();
            chck = 0;
            //Checking colliding or not
        }


        // Drawing
            window.clear(Color(26, 28, 36));

        // Drawing food
            window.draw(red);
            //std::cout << red.getPosition().x << " " << red.getPosition().y << '\n';

        //Drawing body
            for (int i = 0; i < size; i++) {
            orange.setPosition(p[i].x, p[i].y);
            window.draw(orange);
        }

        //Drawing blocks
            for (int i = 0; i < 150; i++) {
                if (mapy[i] == -1 || mapx[i] == -1) continue;
                block.setPosition(mapx[i] * 50, mapy[i] * 50);
                window.draw(block);
            }

        //Drawing Score
            String s,ss; 
            s = toString(size) ;
            ss = "Score : " + s;
            text.setString(ss);
            window.draw(text); 
        // DISPLAY
            window.display();
        //Fixing the problem of being real time !! FIXED !!
        //sleep(milliseconds(speed));
    }
    return 0;
}

int GameEndless() {

    size = 1, dir = 0,speed =200;
    p[0].x = 0; p[0].y = 0;

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(34);
    text.setFillColor(Color(255, 70, 0));
    text.setPosition(50.0f, 950.0f);


    srand(time(NULL));
    randomx =  rand() % 1900;
    randomy =  rand() % 1000;
    for (int i = 0; i < 37; i++) {
        if (randomx < (i + 1) * 50 && randomx >= i * 50) randomx = (i) * 50;
    }
    for (int i = 0; i < 19; i++) {
        if (randomy < (i + 1) * 50 && randomy >= i * 50) randomy = (i) * 50;
    }
    red.setPosition(randomx, randomy);

    Clock clock;
    bool chck = 1;

    while (window.isOpen())
    {
        while (window.pollEvent(appevent))
        {
            if (appevent.type == Event::Closed)
                window.close();
            if (appevent.key.code == sf::Keyboard::Escape) {
                return 0;
            }
        }

        if (appevent.type == Event::KeyPressed) {
            chck = 1;
            if (appevent.key.code == Keyboard::Right && dir != 1 && dir != 0) dir = 0;
            else if (appevent.key.code == Keyboard::Left && dir != 0 && dir != 1) dir = 1;
            else if (appevent.key.code == Keyboard::Down && dir != 3 && dir != 2) dir = 2;
            else if (appevent.key.code == Keyboard::Up && dir != 2 && dir != 3) dir = 3;
            else chck = 0;
        }


        /*SURPRISINGLY IT DONT WORK --->  if (appevent.type == Event::KeyPressed)  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) std::cout << "W\n";
        BUT IT WORKS <3
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                std::cout << "W\n";
        }*/


        //UPDATE
        if (clock.getElapsedTime().asMilliseconds() >= speed || chck) {
            // Updating body
            for (int i = size; i > 0; i--) {
                p[i].x = p[i - 1].x;
                p[i].y = p[i - 1].y;
            }
            //Updating heaf position
            if (dir == 0) p[0].x += 50;
            else if (dir == 1) p[0].x -= 50;
            else if (dir == 2) p[0].y += 50;
            else if (dir == 3) p[0].y -= 50;

            //If body goes out of display
            if (p[0].x == 1900) p[0].x = 0;
            else if (p[0].x == -50) p[0].x = 1850;
            else if (p[0].y == 1000) p[0].y = 0;
            else if (p[0].y == -50) p[0].y = 950;

            //Updating food
            red.setPosition(randomx, randomy);
            //If head eats food
            if (p[0].x == red.getPosition().x && p[0].y == red.getPosition().y) {
                size += 1;
                if (speed > 100) speed -= 15;
                bool good = true;
                while (good) {
                    randomx = rand() % 1900;
                    randomy = rand() % 1000;
                    for (int i = 0; i < 38; i++) {
                        if (randomx < (i + 1) * 50 && randomx >= i * 50) randomx = (i) * 50;
                    }
                    for (int i = 0; i < 20; i++) {
                        if (randomy < (i + 1) * 50 && randomy >= i * 50) randomy = (i) * 50;
                    }

                    for (int i = 0; i < size; i++) {
                        if (p[i].x == randomx && p[i].y == randomy) {
                            break;
                        }
                        else if ((randomx != p[i].x || randomx != p[i].x) && i == size - 1) {
                            good = false;
                        }
                    }
                }
            }
            clock.restart();
            chck = 0;
            //Checking colliding or not
        }


        // Drawing
        window.clear(Color(26, 28, 36));
        // Drawing food
        window.draw(red);
        //Drawing body
        for (int i = 0; i < size; i++) {
            orange.setPosition(p[i].x, p[i].y);
            window.draw(orange);
            orange.setPosition(100 + p[i].x, 100 + p[i].y);
        }
        String s, ss;
        s = toString(size);
        ss = "Score : " + s;
        text.setString(ss);
        window.draw(text);
        //Drawing blocks

        // DISPLAY
        window.display();
        //Fixing the problem of being real time !! FIXED !!
        //sleep(milliseconds(speed));
    }
    return 0;
}