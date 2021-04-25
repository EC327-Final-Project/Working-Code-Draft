// Copyright 2021 Dylan McFarland dylanmc@bu.edu
// Copyright 2021 Karin Luna, kaluna@bu.edu
// Copyright 2021 Heran Haile hbhaile@bu.edu
// Copyright 2021 Robert Ling rling123@bu.edu

#include<iostream>
#include <SFML/Graphics.hpp>
#include<unistd.h>
#include<string>
// Constant button dimensions
const int bwidth = 100;
const int bheight = 30;
const int microsec = 1000000;

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
  // Set window font and backgrounds
  sf::RenderWindow window(sf::VideoMode(500, 500), "Marijuana");
  sf::Font font;
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-M.ttf");
  sf::Image image;
  image.loadFromFile("homebackground.jpg");
  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sprite.setOrigin(sf::Vector2f(16.f, 90.f));
  sprite.scale(1.15f,1.15f);
  sf::Image image2;
  image2.loadFromFile("surveybackground.jpg");
  sf::Texture texture2;
  texture2.loadFromImage(image2);
  sf::Sprite sprite2;
  sprite2.setTexture(texture2);
  sprite2.setOrigin(sf::Vector2f(16.f, 70.f));
  sprite2.scale(0.75f,0.75f);
  sf::Image image3;
  image3.loadFromFile("trial2.jpg");
  sf::Texture texture3;
  texture3.loadFromImage(image3);
  sf::Sprite sprite3;
  sprite3.setTexture(texture3);
  sprite3.setOrigin(sf::Vector2f(16.f, 70.f));
  sprite3.scale(0.75f,0.75f);
  sf::Image image4;
  image4.loadFromFile("background.jpg");
  sf::Texture texture4;
  texture4.loadFromImage(image4);
  sf::Sprite sprite4;
  sprite4.setTexture(texture4);
  sprite4.setOrigin(sf::Vector2f(15.f, 180.f));
  sprite4.scale(2.80f,2.80f);
  sprite4.setRotation(90.f);



  // Title declarations
  sf::Text title;
  title.setFont(font);
  title.setFillColor(sf::Color::White);
  title.setOutlineColor(sf::Color::Black);
  title.setOutlineThickness(2);
  title.setPosition(135, 4);

  // History button and label declarations
  sf::RectangleShape history(sf::Vector2f(bheight, bwidth));
  history.setPosition(150, 130);
  history.setFillColor(sf::Color::White);
  history.setRotation(90);
  history.setOutlineColor(sf::Color::Black);
  history.setOutlineThickness(2);
  sf::Text histlabel;
  histlabel.setFont(font);
  histlabel.setFillColor(sf::Color(39, 121, 21));
  histlabel.setOutlineColor(sf::Color::Black);
  histlabel.setOutlineThickness(0.2);
  histlabel.setPosition(150+15-bwidth, 130+4); // Weird numbers for formatting

  // Conviction Erasure button and label declarations
  sf::RectangleShape convict(sf::Vector2f(bheight, bwidth));
  convict.setPosition(450, 130);
  convict.setFillColor(sf::Color::White);
  convict.setRotation(90);
  convict.setOutlineColor(sf::Color::Black);
  convict.setOutlineThickness(2);
  sf::Text convlabel;
  convlabel.setFont(font);
  convlabel.setFillColor(sf::Color(39, 121, 21));
  convlabel.setOutlineColor(sf::Color::Black);
  convlabel.setOutlineThickness(0.2);
  convlabel.setPosition(450+2-bwidth, 130+9); // Weird numbers for formatting

  // Home button and label declarations
  sf::RectangleShape home(sf::Vector2f(bheight, bwidth));
  home.setPosition(300, 10);
  home.setFillColor(sf::Color::White);
  home.setRotation(90);
  home.setOutlineColor(sf::Color::Black);
  home.setOutlineThickness(2);
  sf::Text homelabel;
  homelabel.setFont(font);
  homelabel.setFillColor(sf::Color(39, 121, 21));
  homelabel.setOutlineColor(sf::Color::Black);
  homelabel.setOutlineThickness(0.2);
  homelabel.setPosition(210, 18);

  // Locations button and label declarations
  sf::RectangleShape location(sf::Vector2f(bheight, bwidth));
  location.setPosition(150, 330);
  location.setFillColor(sf::Color::White);
  location.setRotation(90);
  location.setOutlineColor(sf::Color::Black);
  location.setOutlineThickness(2);
  sf::Text locationlabel;
  locationlabel.setFont(font);
  locationlabel.setFillColor(sf::Color(39, 121, 21));
  locationlabel.setOutlineColor(sf::Color::Black);
  locationlabel.setOutlineThickness(0.2);
  locationlabel.setPosition(150+8-bwidth, 330 + 2);

  // Survey button and label declarations
  sf::RectangleShape survey(sf::Vector2f(bheight, bwidth));
  survey.setPosition(450, 330);
  survey.setFillColor(sf::Color::White);
  survey.setRotation(90);
  survey.setOutlineColor(sf::Color::Black);
  survey.setOutlineThickness(2);
  sf::Text surveylabel;
  surveylabel.setFont(font);
  surveylabel.setFillColor(sf::Color(39, 121, 21));
  surveylabel.setOutlineColor(sf::Color::Black);
  surveylabel.setOutlineThickness(0.2);
  surveylabel.setPosition(450+17-bwidth, 330 + 2);

  // Pages within survey

  // Personal Recommendations
  sf::RectangleShape pers(sf::Vector2f(bheight, bwidth));
  pers.setPosition(300, 50);
  pers.setFillColor(sf::Color::White);
  pers.setRotation(90);
  pers.setOutlineColor(sf::Color::Black);
  pers.setOutlineThickness(2);
  sf::Text perslabel;
  perslabel.setFont(font);
  perslabel.setFillColor(sf::Color(39, 121, 21));
  perslabel.setOutlineColor(sf::Color::Black);
  perslabel.setOutlineThickness(0.2);
  perslabel.setPosition(300+5-bwidth, 50 + 6);

  // Pain
  sf::RectangleShape pain(sf::Vector2f(bheight, bwidth));
  pain.setPosition(150, 100);
  pain.setFillColor(sf::Color::White);
  pain.setOutlineColor(sf::Color::Black);
  pain.setOutlineThickness(2);
  pain.setRotation(90);
  sf::Text painlabel;
  painlabel.setFont(font);
  painlabel.setFillColor(sf::Color(39, 121, 21));
  painlabel.setOutlineColor(sf::Color::Black);
  painlabel.setOutlineThickness(0.2);
  painlabel.setPosition(150+18-bwidth, 100 + 6);

  // Sleep
  sf::RectangleShape sleep(sf::Vector2f(bheight, bwidth));
  sleep.setPosition(450, 100);
  sleep.setFillColor(sf::Color::White);
  sleep.setRotation(90);
  sleep.setOutlineColor(sf::Color::Black);
  sleep.setOutlineThickness(2);
  sf::Text sleeplabel;
  sleeplabel.setFont(font);
  sleeplabel.setFillColor(sf::Color(39, 121, 21));
  sleeplabel.setOutlineColor(sf::Color::Black);
  sleeplabel.setOutlineThickness(0.2);
  sleeplabel.setPosition(450+17-bwidth, 100 + 6);

  // Anxiety
  sf::RectangleShape anxiety(sf::Vector2f(bheight, bwidth));
  anxiety.setPosition(150, 200);
  anxiety.setFillColor(sf::Color::White);
  anxiety.setRotation(90);
  anxiety.setOutlineColor(sf::Color::Black);
  anxiety.setOutlineThickness(2);
  sf::Text anxietylabel;
  anxietylabel.setFont(font);
  anxietylabel.setFillColor(sf::Color(39, 121, 21));
  anxietylabel.setOutlineColor(sf::Color::Black);
  anxietylabel.setOutlineThickness(0.2);
  anxietylabel.setPosition(150+10-bwidth, 200 + 6);

  // Munchies
  sf::RectangleShape munchies(sf::Vector2f(bheight, bwidth));
  munchies.setPosition(450, 200);
  munchies.setFillColor(sf::Color::White);
  munchies.setRotation(90);
  munchies.setOutlineColor(sf::Color::Black);
  munchies.setOutlineThickness(2);
  sf::Text munchieslabel;
  munchieslabel.setFont(font);
  munchieslabel.setFillColor(sf::Color(39, 121, 21));
  munchieslabel.setOutlineColor(sf::Color::Black);
  munchieslabel.setOutlineThickness(0.2);
  munchieslabel.setPosition(450+3-bwidth, 200 + 7);

  // Productivity
  sf::RectangleShape prod(sf::Vector2f(bheight, bwidth));
  prod.setPosition(150, 300);
  prod.setFillColor(sf::Color::White);
  prod.setRotation(90);
  prod.setOutlineColor(sf::Color::Black);
  prod.setOutlineThickness(2);
  sf::Text prodlabel;
  prodlabel.setFont(font);
  prodlabel.setFillColor(sf::Color(39, 121, 21));
  prodlabel.setOutlineColor(sf::Color::Black);
  prodlabel.setOutlineThickness(0.2);
  prodlabel.setPosition(150+4-bwidth, 300 + 8);

  // Seniors
  sf::RectangleShape seniors(sf::Vector2f(bheight, bwidth));
  seniors.setPosition(450, 300);
  seniors.setFillColor(sf::Color::White);
  seniors.setRotation(90);
  seniors.setOutlineColor(sf::Color::Black);
  seniors.setOutlineThickness(2);
  sf::Text seniorslabel;
  seniorslabel.setFont(font);
  seniorslabel.setFillColor(sf::Color(39, 121, 21));
  seniorslabel.setOutlineColor(sf::Color::Black);
  seniorslabel.setOutlineThickness(0.2);
  seniorslabel.setPosition(450+11-bwidth, 300 + 7);

  // Sex
  sf::RectangleShape sex(sf::Vector2f(bheight, bwidth));
  sex.setPosition(150, 400);
  sex.setFillColor(sf::Color::White);
  sex.setRotation(90);
  sex.setOutlineColor(sf::Color::Black);
  sex.setOutlineThickness(2);
  sf::Text sexlabel;
  sexlabel.setFont(font);
  sexlabel.setFillColor(sf::Color(39, 121, 21));
  sexlabel.setOutlineColor(sf::Color::Black);
  sexlabel.setOutlineThickness(0.2);
  sexlabel.setPosition(150+22-bwidth, 400 + 7);

  // Working Out
  sf::RectangleShape wout(sf::Vector2f(bheight, bwidth));
  wout.setPosition(450, 400);
  wout.setFillColor(sf::Color::White);
  wout.setRotation(90);
  wout.setOutlineColor(sf::Color::Black);
  wout.setOutlineThickness(2);
  sf::Text woutlabel;
  woutlabel.setFont(font);
  woutlabel.setFillColor(sf::Color(39, 121, 21));
  woutlabel.setOutlineColor(sf::Color::Black);
  woutlabel.setOutlineThickness(0.2);
  woutlabel.setPosition(450+4-bwidth, 400 + 9);

  // medical button and label declarations
  sf::RectangleShape medical(sf::Vector2f(bheight, bwidth));
  medical.setPosition(450, 230);
  medical.setFillColor(sf::Color::White);
  medical.setRotation(90);
  medical.setOutlineColor(sf::Color::Black);
  medical.setOutlineThickness(2);
  sf::Text medlabel;
  medlabel.setFont(font);
  medlabel.setFillColor(sf::Color(39, 121, 21));
  medlabel.setOutlineColor(sf::Color::Green);
  medlabel.setOutlineThickness(0.2);
  medlabel.setPosition(450+6-bwidth, 230 + 1); // Weird numbers for formatting

  // Effects button and label declarations
  sf::RectangleShape effect(sf::Vector2f(bheight, bwidth));
  effect.setPosition(150, 230);
  effect.setFillColor(sf::Color::White);
  effect.setRotation(90);
  effect.setOutlineColor(sf::Color::Black);
  effect.setOutlineThickness(2);
  sf::Text effectlabel;
  effectlabel.setFont(font);
  effectlabel.setFillColor(sf::Color(39, 121, 21));
  effectlabel.setOutlineColor(sf::Color::White);
  effectlabel.setOutlineThickness(0.2);
  effectlabel.setPosition(150+11-bwidth, 230 + 3); // Weird numbers for formatting

  //THC VS CBD 
  sf::RectangleShape types(sf::Vector2f(bheight, bwidth));
  types.setPosition(450, 430);
  types.setFillColor(sf::Color::White);
  types.setRotation(90);
  types.setOutlineColor(sf::Color::Black);
  types.setOutlineThickness(2);
  sf::Text typelabel;
  typelabel.setFont(font);
  typelabel.setFillColor(sf::Color(39, 121, 21));
  typelabel.setOutlineColor(sf::Color::Black);
  typelabel.setOutlineThickness(0.2);
  typelabel.setPosition(450+1-bwidth,430 + 4);


  //Ways of Using 
  sf::RectangleShape waysofuse(sf::Vector2f(bheight, bwidth));
  waysofuse.setPosition(150, 430);
  waysofuse.setFillColor(sf::Color::White);
  waysofuse.setRotation(90);
  waysofuse.setOutlineColor(sf::Color::Black);
  waysofuse.setOutlineThickness(2);
  sf::Text uselabel;
  uselabel.setFont(font);
  uselabel.setFillColor(sf::Color(39, 121, 21));
  uselabel.setOutlineColor(sf::Color::Black);
  uselabel.setOutlineThickness(0.2);
  uselabel.setPosition(150+6-bwidth, 430+5);

  // Next Page button and label declarations
  sf::RectangleShape next(sf::Vector2f(bheight, bwidth));
  next.setPosition(430, 400);
  next.setFillColor(sf::Color::White);
  next.setRotation(90);
  next.setOutlineColor(sf::Color::Black);
  next.setOutlineThickness(2);
  sf::Text nextlabel;
  nextlabel.setFont(font);
  nextlabel.setFillColor(sf::Color(39, 121, 21));
  nextlabel.setOutlineColor(sf::Color::Black);
  nextlabel.setOutlineThickness(0.2);
  nextlabel.setPosition(350, 407);

  window.setFramerateLimit(5);
  sf::Event event;

  while (window.isOpen()) {
    window.draw(sprite);
    title.setString("Stoned Age");
    title.setCharacterSize(45);
    window.draw(title);
    window.draw(history);
    histlabel.setString("History");
    histlabel.setCharacterSize(20);
    window.draw(histlabel);
    window.draw(convict);
    convlabel.setString("Conviction Erasure");
    convlabel.setCharacterSize(11);
    window.draw(convlabel);
    window.draw(location);
    locationlabel.setString("Locations");
    locationlabel.setCharacterSize(19);
    window.draw(locationlabel);
    window.draw(survey);
    surveylabel.setString("Strains");
    surveylabel.setCharacterSize(20);
    window.draw(surveylabel);
    window.draw(medical);
    medlabel.setString("Medical \nApplications");
    medlabel.setCharacterSize(13);
    window.draw(medlabel);
    window.draw(effect);
    effectlabel.setString("Effects");
    effectlabel.setCharacterSize(20);
    window.draw(effectlabel);
    window.draw(types);
    typelabel.setString("THC vs CBD");
    typelabel.setCharacterSize(18);
    window.draw(typelabel);
    window.draw(waysofuse);
    uselabel.setString("Ways to Use");
    uselabel.setCharacterSize(15);
    window.draw(uselabel);
    window.display();
    window.clear(sf::Color(137, 197, 125));

    // Count for back to home button push
    int count = 0;
    // Pagecount for making sure click doesn't skip a page
    int pcount = 0;

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Button click events
      if (sf::Event::MouseButtonPressed) {

        // History button click
        if (isMouseOver(window, history)) {
          history.setFillColor(sf::Color::Black);
          if (event.mouseButton.button == sf::Mouse::Left) {
            history.setFillColor(sf::Color::White);
            home.setFillColor(sf::Color::White);
            while(window.isOpen()) {
              window.clear(sf::Color(137, 197, 125));
              window.draw(home);
              homelabel.setString("Back to Home");
              homelabel.setCharacterSize(12);
              window.draw(homelabel);
              window.draw(next);
              nextlabel.setString("Next Page");
              nextlabel.setCharacterSize(12);
              window.draw(nextlabel);
              sf::Text test;
              test.setFont(font);
              test.setFillColor(sf::Color::White);
              test.setOutlineColor(sf::Color(39, 121, 21));
              test.setOutlineThickness(0.5);
              test.setPosition(25, 100);
              test.setCharacterSize(12);
              test.setString("Marijuana has been used throughout history for its medicinal properties and \napplications. It was grown for use in hemp products but also ingested for its \npsychoactive properties. Typically, the plant was used to treat a number of \nailments such as depression, headaches, sleeplessness, and even for treating \naddictions to other drugs like opium. Many medical professionals prescribed \nmarijuana to patients as a regular drug around the world. In the United States, \nit was not until 1911 that the plant was first considered illegal when \nMassahcusetts became the first state to outlaw it. Many states began to \nfollow suit until 1937, where the Marijuana Tax Act was enacted and \nessentially classified the plant as an outlawed substance. Marijuana and its \neffects were still studied but its use was prohibited. In 1970, the United \nStates enacted the Controlled Substances Act and declared that \nmarijuana had no accepted medical uses. In contrast, the National Organization \nfor the Reform of Marijuana Laws was founded in 1970 as some people still \nfelt that marijuana prohibition was unjust.");
              window.draw(test);
              window.display();
              while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                window.close();
                }
                if (sf::Event::MouseButtonPressed) {
                  if (isMouseOver(window, home)) {
                    home.setFillColor(sf::Color::Black);
                    if (event.mouseButton.button == sf::Mouse::Left) {
                      count++;
                      break;
                    }
                  } else {
                      home.setFillColor(sf::Color::White);
                  }
                  if (isMouseOver(window, next)) {
                    next.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        next.setFillColor(sf::Color::White);
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(12);
                        window.draw(homelabel);
                        window.draw(next);
                        nextlabel.setString("Next Page");
                        nextlabel.setCharacterSize(12);
                        window.draw(nextlabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color(39, 121, 21));
                        test.setOutlineThickness(0.5);
                        test.setPosition(25, 100);
                        test.setCharacterSize(12);
                        test.setString("The climate surrounding marijuana did not change drastically until the Drug \nEnforcement Agency was founded in 1973 and began to crack down on marijuana \nregulations. Marijuana began to gain recognition for the remainder of the \n1970s as people began to reevaluate the dangers of the drug and learned \nabout its medicinal benefits. Robert Randall was the first U.S. citizen to \nbe legally granted access to medical marijuana in 1976, which was a large \nstep on the path to legalizing marijuana. San Francisco passed the first \nmedical marijuana initiative in 1991, relabeling marijuana as an available \nmedication in California. Marijuana was then medically legalized in the \nentire state of California in 1996, the first state to do so in America. \nMarijuana was still viewed by many as an evil drug, but people had still \nbeen using it ever since it was first criminalized in 1937; having the \nfirst medically legalized state was an important event for marijuana as it \nbecame more accepted. Alaska, Oregon, and Washington followed suit as they \nlegalized medical marijuana in 1998.");
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          while (isMouseOver(window, next) && pcount == 0) {
                            usleep(microsec*0.75);
                            pcount++;
                          }
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                            if (isMouseOver(window, next)) {
                              next.setFillColor(sf::Color::Black);
                              window.draw(next);
                              window.draw(nextlabel);
                              window.display();
                              if (window.pollEvent(event)) {
                                if (sf::Event::MouseButtonPressed) {
                                  if (isMouseOver(window, next)) {
                                  }
                                }
                              }
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                pcount = 0;
                                while (window.isOpen()) {
                                  next.setFillColor(sf::Color::White);
                                  window.clear(sf::Color(137, 197, 125));
                                  window.draw(home);
                                  homelabel.setString("Back to Home");
                                  homelabel.setCharacterSize(12);
                                  window.draw(homelabel);
                                  window.draw(next);
                                  nextlabel.setString("Next Page");
                                  nextlabel.setCharacterSize(12);
                                  window.draw(nextlabel);
                                  sf::Text test;
                                  test.setFont(font);
                                  test.setFillColor(sf::Color::White);
                                  test.setOutlineColor(sf::Color(39, 121, 21));
                                  test.setOutlineThickness(0.5);
                                  test.setPosition(25, 100);
                                  test.setCharacterSize(12);
                                  test.setString("Many other states began to allow the medicinal use of marijuana as the drug \nwas heavily researched and legislative progress was made. Massachusetts \npassed its medical marijuana laws in 2012 making it the 18th state to \nlegalize medical mariujuana. There was a lot of tension between state and \nfederal governments in regards to marijuana regulations and its medicinal \nuse, so it was big news for the movement when the Justice Department \ndeclared it will not challenge individual state marijuana laws. \nRegulations began to loosen until 2018 where Oklahoma became the \n30th state to legalize medical marijuana and President Trump later on signed \na bill legalizing industrial hemp. South Dakota and Mississippi are the most \nrecent states to legalize medical marijuana use in late 2020. The United \nStates officially decriminalized marijuana in December of 2020, arguably one \nof the most beneficial marijuana bills passed. Marijuana has a plethora of \nmedicinal properties and has been outlawed for some time now. The country \nis coming around to recognize the benefits of treating marijuana as a \nmedicine and many people believe it should be available for recreational use.");
                                  window.draw(test);
                                  window.display();
                                  while(window.pollEvent(event)) {
                                    while (isMouseOver(window, next) && pcount == 0) {
                                      usleep(microsec*0.75);
                                      pcount++;
                                    }
                                    if (event.type == sf::Event::Closed) {
                                      window.close();
                                    }
                                    if (sf::Event::MouseButtonPressed) {
                                      if (isMouseOver(window, home)) {
                                        home.setFillColor(sf::Color::Black);
                                        if (event.mouseButton.button == sf::Mouse::Left) {
                                          count++;
                                          break;
                                        }
                                      } else {
                                        home.setFillColor(sf::Color::White);
                                      }
                                      if (isMouseOver(window, next)) {
                                        next.setFillColor(sf::Color::Black);
                                        window.draw(next);
                                        window.draw(nextlabel);
                                        window.display();
                                        if (window.pollEvent(event)) {
                                          if (sf::Event::MouseButtonPressed) {
                                            if (isMouseOver(window, next)) {
                                            }
                                          }
                                        }
                                        if (event.mouseButton.button == sf::Mouse::Left) {
                                          while (window.isOpen()) {
                                            next.setFillColor(sf::Color::White);
                                            window.clear(sf::Color(137, 197, 125));
                                            window.draw(home);
                                            homelabel.setString("Back to Home");
                                            homelabel.setCharacterSize(12);
                                            window.draw(homelabel);
                                            sf::Text test;
                                            test.setFont(font);
                                            test.setFillColor(sf::Color::White);
                                            test.setOutlineColor(sf::Color(39, 121, 21));
                                            test.setOutlineThickness(0.5);
                                            test.setPosition(25, 100);
                                            test.setCharacterSize(12);
                                            test.setString("The history of recreationally legalized marijuana in the United States is much \nmore recent than its medical history. While state-level medicinal marijuana \nlegalization started back in 1996, marijuana was not recreationally legalized \nuntil Washington and Colorado did so in 2012. Since then, a multitude of \nstates are passing laws allowing recreational use of marijuana. The most \nrecent of which was New Mexico in April of 2021 as the 17th state to do so. As \ntime moves on, it is a safe assumption that marijuana will soon be legalized \nrecreationally on a federal level so everyone has access to the benefits \nassociated with its medicinal and recreational uses.");
                                            window.draw(test);
                                            window.display();
                                            while (window.pollEvent(event)) {
                                              if (event.type == sf::Event::Closed) {
                                                window.close();
                                              }
                                              if (sf::Event::MouseButtonPressed) {
                                                if (isMouseOver(window, home)) {
                                                  home.setFillColor(sf::Color::Black);
                                                  if (event.mouseButton.button == sf::Mouse::Left) {
                                                    count++;
                                                    break;
                                                  }
                                                } else {
                                                  home.setFillColor(sf::Color::White);
                                                }
                                              }
                                            }
                                            if (count > 0) {
                                              window.clear(sf::Color(137, 197, 125));
                                              break;
                                            }
                                          }
                                        }
                                      } else {
                                        next.setFillColor(sf::Color::White);
                                      }
                                    }
                                  }
                                  if (count > 0) {
                                    window.clear(sf::Color(137, 197, 125));
                                    break;
                                  }
                                }
                              }
                            } else {
                              next.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      next.setFillColor(sf::Color::White);
                  }
                }
              }
              if (count > 0) {
                window.clear(sf::Color(137, 197, 125));
                break;
              }
            }
          }
        } else {
          history.setFillColor(sf::Color::White);
        }

        // Conviction erasure button click
        if (isMouseOver(window, convict)) {
          convict.setFillColor(sf::Color::Black);
          if (event.mouseButton.button == sf::Mouse::Left) {
            convict.setFillColor(sf::Color::White);
            home.setFillColor(sf::Color::White);
            while(window.isOpen()) {
              window.clear(sf::Color(137, 197, 125));
              window.draw(home);
              homelabel.setString("Back to Home");
              homelabel.setCharacterSize(12);
              window.draw(homelabel);
              window.draw(next);
              nextlabel.setString("Next Page");
              nextlabel.setCharacterSize(12);
              window.draw(nextlabel);
              sf::Text test;
              test.setFont(font);
              test.setFillColor(sf::Color::White);
              test.setOutlineColor(sf::Color(39, 121, 21));
              test.setOutlineThickness(0.5);
              test.setPosition(25, 100);
              test.setCharacterSize(12);
              test.setString("With marijuana getting recreationally legalized across the United States, \nthe erasure of prior marijuana convictions has become a popular topic. These \nerasures are only applicable in states that have fully legalized marijuana, \nand each state follows its own specific guidelines and regulations. The \nerasure of convictions largely depends on how much marijuana a person \npossessed at their time of conviction and their recent criminal record history.");
              window.draw(test);
              window.display();
              while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                window.close();
                }
                if (sf::Event::MouseButtonPressed) {
                  if (isMouseOver(window, home)) {
                    home.setFillColor(sf::Color::Black);
                    if (event.mouseButton.button == sf::Mouse::Left) {
                      count++;
                      break;
                    }
                  } else {
                      home.setFillColor(sf::Color::White);
                  }
                  if (isMouseOver(window, next)) {
                    next.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        next.setFillColor(sf::Color::White);
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(12);
                        window.draw(homelabel);
                        window.draw(next);
                        nextlabel.setString("Next Page");
                        nextlabel.setCharacterSize(12);
                        window.draw(nextlabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color(39, 121, 21));
                        test.setOutlineThickness(0.5);
                        test.setPosition(25, 100);
                        test.setCharacterSize(12);
                        test.setString("It is important to ensure that prior convictions for marijuana possession in \nnow recreationally legalized states are seen through properly. While these \nconvictions will no longer be delivered in legalized states, they continue \nto have lasting effects on individuals. These convictions will remain on the \ncriminal offender record information of the accused and have the potential \nto prevent these individuals from securing a job, housing, or a number of \nother adverse consequences. Unless expunged from their records, these prior \npossession convictions will continue to haunt people for the rest of their lives.");
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          while (isMouseOver(window, next) && pcount == 0) {
                            usleep(microsec*0.75);
                            pcount++;
                          }
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                            if (isMouseOver(window, next)) {
                              next.setFillColor(sf::Color::Black);
                              window.draw(next);
                              window.draw(nextlabel);
                              window.display();
                              if (window.pollEvent(event)) {
                                if (sf::Event::MouseButtonPressed) {
                                  if (isMouseOver(window, next)) {
                                  }
                                }
                              }
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                pcount = 0;
                                while (window.isOpen()) {
                                  next.setFillColor(sf::Color::White);
                                  window.clear(sf::Color(137, 197, 125));
                                  window.draw(home);
                                  homelabel.setString("Back to Home");
                                  homelabel.setCharacterSize(12);
                                  window.draw(homelabel);
                                  sf::Text test;
                                  test.setFont(font);
                                  test.setFillColor(sf::Color::White);
                                  test.setOutlineColor(sf::Color(39, 121, 21));
                                  test.setOutlineThickness(0.5);
                                  test.setPosition(25, 100);
                                  test.setCharacterSize(12);
                                  test.setString("Another important factor to consider with the erasure of prior weed convictions \nis how they disproportionately affect African-Americans and other minority \ngroups. African-americans are almost four times more likely to be convicted \nfor possession of marijuana than white people, despite the fact that both \ngroups have similar marijuana usage rates. These racist convictions are \nprevalent among most non-white groups and people are suffering because of it. \nAlso, marijuana is proven to have medicinal properties and is now even \nprescribed to qualifying patients. Marijuana users who used the drug for its \nmedicinal qualities prior to legalization because they could not afford \nexpensive medications or did not have access to them have been unfairly \nprocessed based on the limited availability of some medicines. The war on \ndrugs has unfairly harmed low-income and minority groups and it is about \ntime things are set straight, especially since marijuana possession is \nnow legal in some areas.");
                                  window.draw(test);
                                  window.display();
                                  while(window.pollEvent(event)) {
                                    while (isMouseOver(window, next) && pcount == 0) {
                                      usleep(microsec*0.75);
                                      pcount++;
                                    }
                                    if (event.type == sf::Event::Closed) {
                                      window.close();
                                    }
                                    if (sf::Event::MouseButtonPressed) {
                                      if (isMouseOver(window, home)) {
                                        home.setFillColor(sf::Color::Black);
                                        if (event.mouseButton.button == sf::Mouse::Left) {
                                          count++;
                                          break;
                                        }
                                      } else {
                                        home.setFillColor(sf::Color::White);
                                      }
                                    }
                                  }
                                  if (count > 0) {
                                    window.clear(sf::Color(137, 197, 125));
                                    break;
                                  }
                                }
                              }
                            } else {
                              next.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      next.setFillColor(sf::Color::White);
                  }
                }
              }
              if (count > 0) {
                window.clear(sf::Color(137, 197, 125));
                break;
              }
            }
          }
        } else {
          convict.setFillColor(sf::Color::White);
        }

        // Survey button click
        if (isMouseOver(window, survey)) {
          survey.setFillColor(sf::Color::Black);
          if (event.mouseButton.button == sf::Mouse::Left) {
            survey.setFillColor(sf::Color::White);
            home.setFillColor(sf::Color::White);
            while(window.isOpen()) {
              window.clear(sf::Color(137, 197, 125));
              window.draw(sprite2);
              window.draw(home);
              homelabel.setString("Back to Home");
              homelabel.setCharacterSize(12);
              window.draw(homelabel);
              window.draw(pers);
              perslabel.setString("Personal Recs");
              perslabel.setCharacterSize(14);
              window.draw(perslabel);
              window.draw(pain);
              painlabel.setString("For Pain");
              painlabel.setCharacterSize(14);
              window.draw(painlabel);
              window.draw(sleep);
              sleeplabel.setString("For Sleep");
              sleeplabel.setCharacterSize(14);
              window.draw(sleeplabel);
              window.draw(anxiety);
              anxietylabel.setString("For Anxiety");
              anxietylabel.setCharacterSize(14);
              window.draw(anxietylabel);
              window.draw(munchies);
              munchieslabel.setString(" For Munchies");
              munchieslabel.setCharacterSize(14);
              window.draw(munchieslabel);
              window.draw(prod);
              prodlabel.setString("For Productivity");
              prodlabel.setCharacterSize(12);
              window.draw(prodlabel);
              window.draw(seniors);
              seniorslabel.setString("For Seniors");
              seniorslabel.setCharacterSize(14);
              window.draw(seniorslabel);
              window.draw(sex);
              sexlabel.setString("For Sex");
              sexlabel.setCharacterSize(14);
              window.draw(sexlabel);
              window.draw(wout);
              woutlabel.setString("For Working Out");
              woutlabel.setCharacterSize(12);
              window.draw(woutlabel);
              window.display();
              while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                window.close();
                }
                if (sf::Event::MouseButtonPressed) {
                  if (isMouseOver(window, home)) {
                    home.setFillColor(sf::Color::Black);
                    if (event.mouseButton.button == sf::Mouse::Left) {
                      count++;
                      break;
                    }
                  } else {
                      home.setFillColor(sf::Color::White);
                  }

                  if (isMouseOver(window, pers)) {
                    pers.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(sprite3);
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(12);
                        window.draw(homelabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color::Black);
                        test.setOutlineThickness(0.4);
                        test.setPosition(25, 100);
                        test.setCharacterSize(14);
                        test.setString("~Skywalker OG:\nindica dominant hybrid | spicy herbal scent with with notes of citrus\nhops and a peppery finish | takes you to a galaxy far far away\n~ Skittles:\nindica dominant | sweet, tropical, fruity profile\n~ Sherbert:\nindica leaning hybrid | skunky citrus, sweet berries, and\ncandy-like aroma\n~ Gelato:\nhybrid | fruity, dessert-like aroma\n~ Blue Dream:\nsativa dominant hybrid | sweet berry aroma and taste\n~ Pineapple Express:\nhybrid | fresh apple and mango aroma with a pineapple, pine,\nand cedar taste\n~ OG Kush:\nhybrid | notes of lemon, fuel, skunk, and spice\n~ Northern Lights:\nindica | sweet and spicy flavor profile\n~ Super Lemon Haze:\nsativa dominant hybrid | zesty aroma and a citrusy, slightly\ntart and sweet taste");
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          while (isMouseOver(window, pers) && pcount == 0) {
                            usleep(microsec*0.75);
                            pcount++;
                          }
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      pers.setFillColor(sf::Color::White);
                  }

                  if (isMouseOver(window, pain)) {
                    pain.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(sprite3);
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(12);
                        window.draw(homelabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color::Black);
                        test.setOutlineThickness(0.4);
                        test.setPosition(25, 100);
                        test.setCharacterSize(13);
                        test.setString("Recommendation: Patients using marijuana for pain relief report\nthat the most effective strains often have an equal balance of\nTHC and CBD. Research also suggests caryophyllene, a common terpene\nfound in cannabis, may be a factor in helping to reduce pain.\n\n~ACDC:\nCBD dominant | 20:1 CBD:THC ratio | sativa leaning hybrid |\ncherry and lemongrass\n~ Blueberry Kush:\n high THC | indica | sweet blueberry profile\n~ Harlequin:\nhigh CBD low THC | sativa | musky with traces of tropical fruits\n~ White Widow:\nhigh THC| indica leaning hybrid | fruity, musky and hashy\n~ CBD Critical Mass:\nCBD rich | 1:1 CBD to THC | indica dominant | earthy and pungent\n~ Master Kush:\npotent high THC | indica | light citrus smell and sweet earthy flavor\n~ Girls Scout Cookies:\nhigh THC | indica hybrid | sweet and pungent with notes of mint,\ncherry, and lemon\n~Cannatonic:\nvarying CBD:THC ratios | known for its CBD | earthy odor with\na sweet citrus flavor\n~ Afghan Kush:\nhigh THC and CBD | strong indica | earthy aroma with fruity taste\n");
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      pain.setFillColor(sf::Color::White);
                  }

                  if (isMouseOver(window, sleep)) {
                    sleep.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(sprite3);
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(12);
                        window.draw(homelabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color::Black);
                        test.setOutlineThickness(0.4);
                        test.setPosition(25, 100);
                        test.setCharacterSize(14);
                        test.setString("~ Granddaddy Purple:\npotent indica | sweet grape and a spicy pungency | striking purple buds\n~ Wedding Cake:\npotent indica hybrid | rich, tangy, earthy pepper flavor\n~ God's Gift:\nindica dominant | grape, citrus, and hash\n~ Tahoe OG Kush:\nhybrid indica | euphoric sativa component | earthy lemon taste\n~ Bubba Kush:\nindica | heavily tranquilizing | subtle chocolate and coffee notes\n~ Royal Highness:\nbalanced CBD:THC ratio | hybrid | fruity, spicy, and a little skunky\n~ Garanimals:\npotent indica dominant hybrid | doughy and spicy aroma\n~ Midnight Express:\nCBD rich | grape bubble gum profile | tropical and floral notes\n~ Remedy:\nhigh CBD indica | sweet floral notes | little to no psychoactive effects\n~ Northern Lights:\nindica | sweet and spicy flavor profile" );
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      sleep.setFillColor(sf::Color::White);
                  }

                  if (isMouseOver(window, anxiety)) {
                    anxiety.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(sprite3);
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(12);
                        window.draw(homelabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color::Black);
                        test.setOutlineThickness(0.4);
                        test.setPosition(25, 100);
                        test.setCharacterSize(14);
                        test.setString("~ ACDC:\nCBD dominant | 20:1 CBD:THC ratio | sativa leaning hybrid |\ncherry and lemongrass\n~ Granddaddy Purple:\npotent indica | sweet grape and a spicy pungency | striking purple buds\n~ Kosher Kush:\npotent indica | rich earth and fruit\n~ Elektra:\nCBD dominant hybrid | rich red wine, chocolate, and citrus aroma\n~ Amnesia Haze:\nsativa | earthy flavors of lemon and citrus\n~ Jack Herer:\nsativa dominant | spicy and pine scented\n~ Cherry Pie:\nhybrid | sweet and sour cherry pie\n~ Pennywise:\nhigh CBD | notes of coffee and pepper with undertones of\nlemon and bubblehum | Stephen King inspired\n~ Lemon Garlic OG:\nhybrid | spicy aroma with notes of garlic, citrus, and pine\n~ Blue OG:\nhybrid | notes of berry and citrus\n~ Chocolate Chunk:\npure indica | candy strain with a dessert-like aroma\n");
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      anxiety.setFillColor(sf::Color::White);
                  }

                  if (isMouseOver(window, munchies)) {
                    munchies.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(sprite3);
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(12);
                        window.draw(homelabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color::Black);
                        test.setOutlineThickness(0.4);
                        test.setPosition(25, 100);
                        test.setCharacterSize(14);
                        test.setString("~ Thin Mint Girls Scout Cookies:\npotent hybrid | sweet minty aroma | high psychoactivity\n~ Sour Diesel:\nsativa | pungent diesel-like profile\n~ Haze Berry:\ndominant sativa | indica-like berry flavors with sativa effects\n~ Royal Cookies:\nindica dominant hybrid | buttery, nutty flavor profile with\nvanilla undertones\n~ Diablo:\npotent sativa dominant hybrid | grapefruit and blueberry\nflavors with hash and black pepper undertones\n~ OG Kush:\nhybrid | notes of lemon, fuel, skunk, and spice\n~ Girls Scout Cookies:\nhigh THC | indica hybrid | sweet and pungent with notes of mint,\ncherry, and lemon\n~ Pineapple Express:\nhybrid | fresh apple and mango aroma with a pineapple, pine,\nand cedar taste\n~ Amnesia Haze:\nsativa | earthy flavors of lemon and citrus");
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      munchies.setFillColor(sf::Color::White);
                  }

                  if (isMouseOver(window, prod)) {
                    prod.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(sprite3);
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(12);
                        window.draw(homelabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color::Black);
                        test.setOutlineThickness(0.4);
                        test.setPosition(25, 100);
                        test.setCharacterSize(14);
                        test.setString("~ Sour Diesel:\nsativa | pungent diesel-like profile\n~ White Buffalo:\nsativa | sweet and sour | covered with glittery white trichomes\n~ Golden Goat:\nhybrid | sweet, sour, and spicy aroma | tropical fruit flavor\n~ Quantum Kush:\npotent sativa dominant hybrid | complex earthy and sweet aroma\n~ Durban Poison:\npotent pure sativa | earthy and sweet with a subtle pine aroma\n~ Chem Dawg:\npotent hybrid | distinct, sharp diesel aroma\n~ Kali Mist:\nsativa dominant hybrid | psychadelic at high doses\n~ Super Lemon Haze:\nsativa dominant hybrid | zesty aroma and a citrusy, slightly\ntart and sweet taste\n~ ACDC:\nCBD dominant | 20:1 CBD:THC ratio | sativa leaning hybrid |\ncherry and lemongrass\n~ Jack Herer:\nsativa dominant | spicy and pine scented");
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      prod.setFillColor(sf::Color::White);
                  }

                  if (isMouseOver(window, seniors)) {
                    seniors.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(sprite3);
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(14);
                        window.draw(homelabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color::Black);
                        test.setOutlineThickness(0.4);
                        test.setPosition(25, 100);
                        test.setCharacterSize(14);
                        test.setString("~ Lemon G:\npotent sativa | daytime painrelief | strong lemon and pine notes\n~ Durban Poison:\npure sativa | spicy and sweet anise-like profile | daytime pain relief\n~ Bio Jesus:\npotent hybrid | crisp, light, and slightly floral aroma | sleep\n~ Afghan Kush:\nhigh THC and CBD | strong indica | earthy aroma with fruity taste | sleep\n~ Blueberry Space Cake:\nindica dominant | strong berry and citrus aroma | sleep\n~ Green Crack:\npotent sativa | daytime energy | tangy, fruity, mango-like flavor\n~ Blue Dream:\nsativa dominant hybrid | sweet berry aroma and taste");
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      seniors.setFillColor(sf::Color::White);
                  }

                  if (isMouseOver(window, sex)) {
                    sex.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(sprite3);
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(12);
                        window.draw(homelabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color::Black);
                        test.setOutlineThickness(0.4);
                        test.setPosition(25, 100);
                        test.setCharacterSize(14);
                        test.setString("~ Mimosa:\nhybrid | fruit and citrus flavors with a light berry exhale\n~ Strawberry Cough:\npotent sativa | sweet smell of fresh strawberries\n~ Sour Diesel:\nsativa | pungent diesel-like profile\n~ Wedding Cake:\npotent indica hybrid | rich, tangy, earthy pepper flavor\n~ Trainwreck:\npotent sativa | sweet lemon and spicy pine aroma\n~ Bubblegum Kush:\nindica dominant | predominantely citrus aroma with sweet undertones\n~ Jillybean:\nindica dominant hybrid | tangy orange and mango\n~ Atomic Northern Lights:\nindica leaning hybrid | musky, earthy, fresh pine scent | pepper\nand piney exhale\n~ Do-Si-Dos:\npotent indica dominant hybrid | sweet minty aroma\naccented by lime and pine");
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      sex.setFillColor(sf::Color::White);
                  }

                  if (isMouseOver(window, wout)) {
                    wout.setFillColor(sf::Color::Black);
                    if (event.type == sf::Event::MouseButtonPressed) {
                      while(window.isOpen()) {
                        window.clear(sf::Color(137, 197, 125));
                        window.draw(sprite3);
                        window.draw(home);
                        homelabel.setString("Back to Home");
                        homelabel.setCharacterSize(12);
                        window.draw(homelabel);
                        sf::Text test;
                        test.setFont(font);
                        test.setFillColor(sf::Color::White);
                        test.setOutlineColor(sf::Color::Black);
                        test.setOutlineThickness(0.4);
                        test.setPosition(25, 100);
                        test.setCharacterSize(15);
                        test.setString("~ Green Crack:\npotent sativa | daytime energy | tangy, fruity, mango-like flavor\n~ Harlequin:\nhigh CBD low THC | sativa | musky with traces of tropical fruits\n~ Durban Poison:\npure sativa | spicy and sweet anise-like profile\n~ Jack Herer:\nsativa dominant | spicy and pine scented\n~ Super Lemon Haze:\nsativa dominant hybrid | zesty aroma and a citrusy, slightly\ntart and sweet taste\n~ Orange Diesel:\nsativa dominant hybrid | sweet citrus flavor with a\nslight diesel aftertaste\n~ Silver Haze:\nsativa dominant hybrid | pungent earthy pine\n");
                        window.draw(test);
                        window.display();
                        while(window.pollEvent(event)) {
                          if(event.type == sf::Event::Closed) {
                            window.close();
                          }
                          if (sf::Event::MouseButtonPressed) {
                            if (isMouseOver(window, home)) {
                              home.setFillColor(sf::Color::Black);
                              if (event.mouseButton.button == sf::Mouse::Left) {
                                count++;
                                break;
                              }
                            } else {
                              home.setFillColor(sf::Color::White);
                            }
                          }
                        }
                        if (count > 0) {
                          window.clear(sf::Color(137, 197, 125));
                          break;
                        }
                      }
                    }
                  } else {
                      wout.setFillColor(sf::Color::White);
                  }
                }
              }
              if (count > 0) {
                window.clear(sf::Color(137, 197, 125));
                break;
              }
            }
          }
        } else {
          survey.setFillColor(sf::Color::White);
        }

        // Medical button click
        if (isMouseOver(window, medical)) {
          medical.setFillColor(sf::Color::Black);
          if (event.mouseButton.button == sf::Mouse::Left) {
            medical.setFillColor(sf::Color::White);
            home.setFillColor(sf::Color::White);
            while(window.isOpen()) {
              window.clear(sf::Color(137, 197, 125));
              window.draw(sprite4);
              window.draw(home);
              homelabel.setString("Back to Home");
              homelabel.setCharacterSize(12);
              window.draw(homelabel);
              sf::Text test;
              test.setFont(font);
              test.setFillColor(sf::Color::Black);
              test.setOutlineColor(sf::Color::White);
              test.setOutlineThickness(0.5);
              test.setPosition(25, 100);
              test.setCharacterSize(18);
              test.setString("The main usage of marijuana in the medical aspect\nis for pain control!\n ~Lessens tremors in Parkinso's disease\n ~Also been used to help treat\nFibromyalgia, endometriosis, \nand intersitital cystitis\nThere has also been research in helping PTSD in veterans\nMarijuana can also be used to help nausea and appetite");
              window.draw(test);
              window.display();
              while(window.pollEvent(event)) {
                if(event.type == sf::Event::Closed) {
                  window.close();
                }
                if (sf::Event::MouseButtonPressed) {
                  if (isMouseOver(window, home)) {
                    home.setFillColor(sf::Color::Black);
                    if (event.mouseButton.button == sf::Mouse::Left) {
                      count++;
                      break;
                    }
                  } else {
                        home.setFillColor(sf::Color::White);
                  }
                }
              }
              if (count > 0) {
                window.clear(sf::Color(137, 197, 125));
                break;
              }
            }
          }
        } else {
            medical.setFillColor(sf::Color::White);
        }

        // Effect button click
        if (isMouseOver(window, effect)) {
          effect.setFillColor(sf::Color::Black);
          if (event.mouseButton.button == sf::Mouse::Left) {
            effect.setFillColor(sf::Color::White);
            home.setFillColor(sf::Color::White);
            while(window.isOpen()) {
              window.clear(sf::Color(137, 197, 125));
              window.draw(sprite4);
              window.draw(home);
              homelabel.setString("Back to Home");
              homelabel.setCharacterSize(12);
              window.draw(homelabel);
              sf::Text test;
              test.setFont(font);
              test.setFillColor(sf::Color::Black);
              test.setOutlineColor(sf::Color::White);
              test.setOutlineThickness(0.5);
              test.setPosition(25, 100);
              test.setCharacterSize(18);
              test.setString("SHORT TERM EFFECTS\n ~~altered senses\n ~~Altered senses of time\n ~~Changes in mood\n ~~Sometimes if taken in high doses, hallucinations\nmay occur\n LONG TERM EFFECTS\n ~~Can lead to anxiety\n ~~Can affect brain development\n ~~May impair thinking,memory, and learning functions\n");
              window.draw(test);
              window.display();
              while(window.pollEvent(event)) {
                if(event.type == sf::Event::Closed) {
                  window.close();
                }
                if (sf::Event::MouseButtonPressed) {
                  if (isMouseOver(window, home)) {
                    home.setFillColor(sf::Color::Black);
                    if (event.mouseButton.button == sf::Mouse::Left) {
                      count++;
                      break;
                    }
                  } else {
                        home.setFillColor(sf::Color::White);
                  }
                }
              }
              if (count > 0) {
                window.clear(sf::Color(137, 197, 125));
                break;
              }
            }
          }
        } else {
            effect.setFillColor(sf::Color::White);
        }

        //THC VS CBD buttons clicks
        if (isMouseOver(window, types)) {
          types.setFillColor(sf::Color::Black);
          if (event.mouseButton.button == sf::Mouse::Left) {
            types.setFillColor(sf::Color::White);
            home.setFillColor(sf::Color::White);
            while(window.isOpen()) {
              window.clear(sf::Color(137, 197, 125));
              window.draw(sprite4);
              window.draw(home);
              homelabel.setString("Back to Home");
              homelabel.setCharacterSize(12);
              window.draw(homelabel);
              sf::Text test;
              test.setFont(font);
              test.setFillColor(sf::Color::Black);
              test.setOutlineColor(sf::Color::White);
              test.setOutlineThickness(0.5);
              test.setPosition(25, 100);
              test.setCharacterSize(18);
              test.setString("CBD\n ~~Stands for Cannabidiol\n ~~Binds weakly to CB1 receptors\n ~~Became popular for natural treatment\n ~~Derived from HEMP or marijuana\n ~~Not psychoactive(doesn't lead to high)\n ~~More used for anxiety, depression or migraines\n THC\n ~~Stands for Tetrahydrocannabinol\n ~~Binds to CB1 recpetor which produces a high\n ~~Psychoactive, produces a high\n ~~More for glaucoma,insomnia, nausea ETC\n");
              window.draw(test);
              window.display();
              while(window.pollEvent(event)) {
                if(event.type == sf::Event::Closed) {
                  window.close();
                }
                if (sf::Event::MouseButtonPressed) {
                  if (isMouseOver(window, home)) {
                    home.setFillColor(sf::Color::Black);
                    if (event.mouseButton.button == sf::Mouse::Left) {
                      count++;
                      break;
                    }
                  } else {
                        home.setFillColor(sf::Color::White);
                  }
                }
              }
              if (count > 0) {
                window.clear(sf::Color(137, 197, 125));
                break;
              }
            }
          }
        } else {
            types.setFillColor(sf::Color::White);
        }

        //ways of using button click

        if (isMouseOver(window, waysofuse)) {
          waysofuse.setFillColor(sf::Color::Black);
          if (event.mouseButton.button == sf::Mouse::Left) {
            waysofuse.setFillColor(sf::Color::White);
            home.setFillColor(sf::Color::White);
            while(window.isOpen()) {
              window.clear(sf::Color(137, 197, 125));
              window.draw(sprite4);
              window.draw(home);
              homelabel.setString("Back to Home");
              homelabel.setCharacterSize(12);
              window.draw(homelabel);
              sf::Text test;
              test.setFont(font);
              test.setFillColor(sf::Color::Black);
              test.setOutlineColor(sf::Color::White);
              test.setOutlineThickness(0.5);
              test.setPosition(25, 100);
              test.setCharacterSize(18);
              test.setString("Inhalation\n ~~Vaporization; often dab or concentrates\n ~~Joints\n ~~Blunts\n ~~Hand pipes/one hitters\n ~~Water Pipes -> Bongs/Bubblers\n Oral Consumption\n ~~Edibles\n ~~Ingestible oils/capsules\n");
              window.draw(test);
              window.display();
              while(window.pollEvent(event)) {
                if(event.type == sf::Event::Closed) {
                  window.close();
                }
                if (sf::Event::MouseButtonPressed) {
                  if (isMouseOver(window, home)) {
                    home.setFillColor(sf::Color::Black);
                    if (event.mouseButton.button == sf::Mouse::Left) {
                      count++;
                      break;
                    }
                  } else {
                        home.setFillColor(sf::Color::White);
                  }
                }
              }
              if (count > 0) {
                window.clear(sf::Color(137, 197, 125));
                break;
              }
            }
          }
        } else {
            waysofuse.setFillColor(sf::Color::White);
        }
      }
    }
  }
  return 0;
}
