#include<iostream>
#include <SFML/Graphics.hpp>

// Constant button dimensions
const int bwidth = 100;
const int bheight = 30;

// Function for button pressing
bool isMouseOver(sf::RenderWindow &window, sf::RectangleShape &button) {
  // Mouse x and y coords
  int mouseX = sf::Mouse::getPosition(window).x;
  int mouseY = sf::Mouse::getPosition(window).y;

  // Button Start Position coords
  int btnPosX = button.getPosition().x;
  int btnPosY = button.getPosition().y;

  // Button End Position coords
  int btnxPosWidth = button.getPosition().x + bwidth;
  int btnyPosHeight = button.getPosition().y + bheight;

  // Check to see if mouse is within button bounds
  if (mouseX < btnPosX && mouseX > btnPosX - bwidth && mouseY < btnyPosHeight && mouseY > btnPosY) {
    return true;
  }
  return false;
}


int main() {
  // Set window and font
  sf::RenderWindow window(sf::VideoMode(500, 500), "Marijuana");
  sf::Font font;
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");

  // Title declarations
  sf::Text title;
  title.setFont(font);
  title.setFillColor(sf::Color::White);
  title.setOutlineColor(sf::Color(39, 121, 21));
  title.setOutlineThickness(1);
  title.setPosition(145, 10);

  // History button and label declarations
  sf::RectangleShape history(sf::Vector2f(bheight, bwidth));
  history.setPosition(150, 130);
  history.setFillColor(sf::Color::White);
  history.setRotation(90);
  sf::Text histlabel;
  histlabel.setFont(font);
  histlabel.setFillColor(sf::Color(39, 121, 21));
  histlabel.setOutlineColor(sf::Color::Black);
  histlabel.setOutlineThickness(0.2);
  histlabel.setPosition(150+15-bwidth, 130+5); // Weird numbers for formatting

  // Conviction Erasure button and label declarations
  sf::RectangleShape convict(sf::Vector2f(bheight, bwidth));
  convict.setPosition(450, 130);
  convict.setFillColor(sf::Color::White);
  convict.setRotation(90);
  sf::Text convlabel;
  convlabel.setFont(font);
  convlabel.setFillColor(sf::Color(39, 121, 21));
  convlabel.setOutlineColor(sf::Color::Black);
  convlabel.setOutlineThickness(0.2);
  convlabel.setPosition(450+2-bwidth, 130+10); // Weird numbers for formatting

  // Home button and label declarations
  sf::RectangleShape home(sf::Vector2f(bheight, bwidth));
  home.setPosition(300, 10);
  home.setFillColor(sf::Color::White);
  home.setRotation(90);
  sf::Text homelabel;
  homelabel.setFont(font);
  homelabel.setFillColor(sf::Color(39, 121, 21));
  homelabel.setOutlineColor(sf::Color::Black);
  homelabel.setOutlineThickness(0.2);
  homelabel.setPosition(210, 17);
  // Repeat button and label declarations using above template as needed

  // Framerate limit and declaring event for use
  window.setFramerateLimit(5);
  sf::Event event;

  // Window operations
  while (window.isOpen()) {
    // Set all objects into SFML
    title.setString("Marijuana Info");
    window.draw(title);
    window.draw(history);
    histlabel.setString("History");
    histlabel.setCharacterSize(20);
    window.draw(histlabel);
    window.draw(convict);
    convlabel.setString("Conviction Erasure");
    convlabel.setCharacterSize(11);
    window.draw(convlabel);
    window.display();
    window.clear(sf::Color(137, 197, 125));

    // Count for back to home button push
    int count = 0;

    // Check for events (window closing or button pushing)
    sf::Event event;
    while (window.pollEvent(event)) {
      // Close window/program on exit click (top right 'x')
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Button click events
      if (sf::Event::MouseButtonPressed) {

        // History button click
        if (isMouseOver(window, history)) {
          if (event.mouseButton.button == sf::Mouse::Left) {
            while(window.isOpen()) {
              window.clear(sf::Color(137, 197, 125));
              window.draw(home);
              homelabel.setString("Back to Home");
              homelabel.setCharacterSize(12);
              window.draw(homelabel);
              sf::Text test;
              test.setFont(font);
              test.setFillColor(sf::Color::White);
              test.setOutlineColor(sf::Color(39, 121, 21));
              test.setOutlineThickness(1);
              test.setPosition(80, 200);
              test.setString("This would be info \nabout button clicked!!!");
              window.draw(test);
              window.display();

              // Check for events (window closing or button pushing)
              while (window.pollEvent(event)) {
                // Close window/program on exit click (top right 'x')
                if (event.type == sf::Event::Closed) {
                window.close();
                }
                if (sf::Event::MouseButtonPressed) {
                  if (isMouseOver(window, home)) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                      count++;
                      break;
                    }
                  }
                }
              }
              if (count > 0) {
                break;
              }
            }
          }
        }

        // Conviction erasure button click
        if (isMouseOver(window, convict)) {
          if (event.mouseButton.button == sf::Mouse::Left) {
            // Conviction erasure info page is displayed
            std::cout << "Button was Clicked!\n";
          }
        }

        // Repeat above setup for all button objects
      }
    }
  }
  return 0;
}
