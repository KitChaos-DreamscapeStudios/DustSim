#include <SFML/Graphics.hpp>
#include <tuple>
#include <vector>
struct Vector2
{
  int x;
  int y;
};
class Pixel{
    public:std::tuple<Vector2> Positions;
    public:bool HasGravity=true;
};
class World{
     public:std::vector<Pixel> Pixels;//Active pixel objects
     public:std::vector<Vector2> AllWorldPositions;
     void Tick(){
        for(Pixel p:Pixels){

        }
     }
};

int main()
{
   
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
   

}
