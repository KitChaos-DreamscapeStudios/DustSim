#include <SFML/Graphics.hpp>

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <map>
#include <tuple>
#include <vector>
struct Vector2 {
  int x;
  int y;
  Vector2(int X, int Y){
    x = X;
    y = Y;
  }
  Vector2 RelValue(Vector2 Diff){
    return  Vector2(x+Diff.x, y+Diff.y);
  }
};
class Pixel {
public:
  Vector2 Position= Vector2(0,0);


  bool HasGravity = true;
  
  Pixel(Vector2 Pos){
   Position=Pos;
  }
};
class World {
public:
  std::vector<Pixel> Pixels; // Active pixel objects
  std::map<Vector2, Pixel> PositionsOfPixels;
  void Tick() {
    for (Pixel p : Pixels) {
        PositionsOfPixels.erase(PositionsOfPixels.find( Vector2(p.Position.x, p.Position.y)));
        if(p.HasGravity){
            if(p.Position.y > 0 && PositionsOfPixels.find( p.Position.RelValue( Vector2(0,-1)) )==PositionsOfPixels.end()){
                p.Position.y-=1;
            }
        }
        PositionsOfPixels.at( Vector2(p.Position.x, p.Position.y)) = p;
    }
  }
};

int main() {
    
    //sf::RenderWindow window(sf::VideoMode(200, 200),  "SFML works!",sf::Style::Fullscreen);
    World w =  World();
    w.Pixels.emplace_back(new Pixel( Vector2(20,20)));
    while (true) {
        //w.Tick();
    }
  
//   while (window.isOpen()) {
//     sf::Event event;
//     while (window.pollEvent(event)) {
//       if (event.type == sf::Event::Closed)
//         window.close();
//     }
//     w.Tick();
//     window.clear();
//     for(Pixel p :w.Pixels){
//         sf::CircleShape shape(1.f);
//         shape.setFillColor(sf::Color::Red);
//         shape.setPosition(p.Position.x,p.Position.y);

//         window.draw(shape);
//         window.display();
//     }
  
//   }

  return 0;
}
