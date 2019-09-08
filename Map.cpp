#include "Map.hpp"

Map::Map(){
    
}

Map::~Map(){

}

void Map::load(){
    /*if(this->mapTexture.loadFromFile("Resources/thesettllers100x100a.png"))
    {
        this->mapSprite.setTexture(mapTexture);
        this->mapSprite.setTextureRect(sf::IntRect(0,0, 4000, 4000));
        this->mapSprite.setPosition(0, 0);
    }*/
    
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
        {
            float smoothness = 40;
            this->mapSquares[i][j] = 7 + (SimplexNoise::noise(i/smoothness, j/smoothness) * 6);
            
            this->square[i][j].setSize(sf::Vector2f(GRID, GRID));
            this->square[i][j].setPosition(i*GRID, j*GRID);
            
            switch (mapSquares [i][j]) {
                case 1:
                    this->square[i][j].setFillColor(sf::Color(0,255,0,255));
                    break;
                    
                case 2:
                    this->square[i][j].setFillColor(sf::Color(0,204,0,255));
                    break;
                    
                case 3:
                    this->square[i][j].setFillColor(sf::Color(0,153,0,255));
                    break;
                    
                case 4:
                    this->square[i][j].setFillColor(sf::Color(255,255,0,255));
                    break;
                    
                case 5:
                    this->square[i][j].setFillColor(sf::Color(255,178,102,255));
                    break;
                    
                case 6:
                    this->square[i][j].setFillColor(sf::Color(255,128,0,255));
                    break;
                    
                case 7:
                    this->square[i][j].setFillColor(sf::Color(255,102,102,255));
                    break;
                    
                case 8:
                    this->square[i][j].setFillColor(sf::Color(255,51,51,255));
                    break;
                    
                case 9:
                    this->square[i][j].setFillColor(sf::Color(255,0,0,255));
                    break;
                    
                case 10:
                    this->square[i][j].setFillColor(sf::Color(127,0,255,255));
                    break;
                    
                case 11:
                    this->square[i][j].setFillColor(sf::Color(102,0,204,255));
                    break;
                    
                case 12:
                    this->square[i][j].setFillColor(sf::Color(76,0,153,255));
                    break;
                    
                default:
                    break;
            }
            
        }
}

void Map::draw(sf::RenderWindow & w){
    //w.draw(this->mapSprite);
    
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
        {
            w.draw(this->square[i][j]);
        }
}

void Map::checkMouseOver(float mx, float my, float cx, float cy, sf::RenderWindow & w) {
    
    float x = mx + cx - WIN_WIDTH/2;
    float y = my + cy - WIN_HEIGHT/2;
    
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    
    sf::FloatRect rect [100][100];
    
    sf::RectangleShape checkRect;
    checkRect.setFillColor(sf::Color::Black);
    checkRect.setOutlineColor(sf::Color::Black);
    checkRect.setOutlineThickness(2);
    
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            rect[i][j] = square[i][j].getLocalBounds();
            rect[i][j].left = i * GRID;
            rect[i][j].top = j * GRID;
            sf::Color fCol = square[i][j].getFillColor();
            
            if(rect[i][j].contains(x, y))
            {
                fCol.a = 150;
                square[i][j].setFillColor(fCol);
                std::cout << "CONTAINS" << std::endl;
            }
            else
            {
                fCol.a = 255;
                square[i][j].setFillColor(fCol);
            }
        }
    }
}
