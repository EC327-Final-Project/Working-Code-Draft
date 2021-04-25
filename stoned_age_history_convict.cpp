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
  int msx = sf::Mouse::getPosition(window).x;
  int msy = sf::Mouse::getPosition(window).y;

  // Button Start Position coords
  int btnx = button.getPosition().x;
  int btny = button.getPosition().y;

  // Button End Position coords
  int btnxx = button.getPosition().x + bwidth;
  int btnyy = button.getPosition().y + bheight;

  // Check to see if mouse is within button bounds
  if (msx < btnx && msx > btnx - bwidth && msy < btnyy && msy > btny) {
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

  // Next Page button and label declarations
  sf::RectangleShape next(sf::Vector2f(bheight, bwidth));
  next.setPosition(430, 400);
  next.setFillColor(sf::Color::White);
  next.setRotation(90);
  sf::Text nextlabel;
  nextlabel.setFont(font);
  nextlabel.setFillColor(sf::Color(39, 121, 21));
  nextlabel.setOutlineColor(sf::Color::Black);
  nextlabel.setOutlineThickness(0.2);
  nextlabel.setPosition(350, 407);

  window.setFramerateLimit(5);
  sf::Event event;

  while (window.isOpen()) {
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

        // Repeat above setup for all button objects
      }
    }
  }
  return 0;
}
