#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

#include <vector>
#include <iostream>

sf::RenderWindow window(sf::VideoMode(600, 600), "Game", sf::Style::Close);
sf::View view;
sf::Clock cl;
float elapsedTime;
bool isBlack = true;

class Figur{
	public:
		int _x;
		int _y;
		sf::Texture _texture;
		sf::RectangleShape _sprite;
		sf::Texture _texture2;
		sf::RectangleShape _sprite2;
		bool _isLoaded;

		int ammountDiagonal;
		int ammountStraigt;
		bool isBauer;
		bool isPferd;
		bool isWhiteTeam;
		Figur(){ }
		Figur(int x, int y, bool isWTeam){ }
		virtual ~Figur(){ _isLoaded=false; }
		virtual void draw(){
			if(_isLoaded){
				window.draw(_sprite);
				window.draw(_sprite2);
			}
		}
		void load(std::string s){
			_texture.loadFromFile(s, sf::IntRect(0, 0, 125, 125)); 
			_sprite.setTexture(&_texture);
			_sprite.setSize(sf::Vector2f(25, 25));
			_sprite.setPosition(sf::Vector2f(_x*125+50, _y*125+50));
			_isLoaded = true;
		}
		void load(sf::Color color){
			_sprite.setTexture(&_texture);
			_sprite.setFillColor(color);
			_sprite.setSize(sf::Vector2f(25, 25));
			_sprite.setPosition(sf::Vector2f(_x*125+50, _y*125+50));
			_sprite2.setTexture(&_texture2);
			if(isWhiteTeam)
				_sprite2.setFillColor(sf::Color::White);
			else
				_sprite2.setFillColor(sf::Color::Black);
			_sprite2.setSize(sf::Vector2f(10, 10));
			_sprite2.setPosition(sf::Vector2f(_x*125+20, _y*125+20));
			_isLoaded = true;
		}
};
class Leer : public Figur{
	public: 
		Leer(int x, int y, bool isWTeam){_x=x; _y=y;_isLoaded=false;isWhiteTeam=isWTeam;load(sf::Color::Transparent);_isLoaded=false;}
		~Leer(){ _isLoaded=false; }
		virtual void draw(){
			if(_isLoaded){
				_sprite.setPosition(sf::Vector2f(_x*125+50, _y*125+50));
				window.draw(_sprite);
				_sprite2.setPosition(sf::Vector2f(_x*125+57.5, _y*125+57.5));
				window.draw(_sprite2);
			}
		}
};
class Bauer : public Figur{
	public: 
		Bauer(int x, int y, bool isWTeam){_x=x; _y=y;_isLoaded=false;isWhiteTeam=isWTeam;load(sf::Color::Red);ammountStraigt=2;ammountDiagonal=0;isBauer=true;isPferd=false;}
		~Bauer(){ _isLoaded=false; }
		virtual void draw(){
			if(_isLoaded){
				_sprite.setPosition(sf::Vector2f(_x*125+50, _y*125+50));
				window.draw(_sprite);
				_sprite2.setPosition(sf::Vector2f(_x*125+57.5, _y*125+57.5));
				window.draw(_sprite2);
			}
		}
};
class Turm : public Figur{
	public: 
		Turm(int x, int y, bool isWTeam){_x=x; _y=y;_isLoaded=false;isWhiteTeam=isWTeam;load(sf::Color::Cyan);ammountStraigt=8;ammountDiagonal=0;isBauer=false;isPferd=false;}
		~Turm(){ _isLoaded=false; }
		virtual void draw(){
			if(_isLoaded){
				_sprite.setPosition(sf::Vector2f(_x*125+50, _y*125+50));
				window.draw(_sprite);
				_sprite2.setPosition(sf::Vector2f(_x*125+57.5, _y*125+57.5));
				window.draw(_sprite2);
			}
		}
};
class Laeufer : public Figur{
	public: 
		Laeufer(int x, int y, bool isWTeam){_x=x; _y=y;_isLoaded=false;isWhiteTeam=isWTeam;load(sf::Color::Blue);ammountStraigt=0;ammountDiagonal=8;isBauer=false;isPferd=false; }
		~Laeufer(){ _isLoaded=false; }
		virtual void draw(){
			if(_isLoaded){
				_sprite.setPosition(sf::Vector2f(_x*125+50, _y*125+50));
				window.draw(_sprite);
				_sprite2.setPosition(sf::Vector2f(_x*125+57.5, _y*125+57.5));
				window.draw(_sprite2);
			}
		}
};
class Pferdchen : public Figur{
	public: 
		Pferdchen(int x, int y, bool isWTeam){_x=x; _y=y;_isLoaded=false;isWhiteTeam=isWTeam;load(sf::Color::Green);isBauer=false;isPferd=true; }
		~Pferdchen(){ _isLoaded=false; }
		virtual void draw(){
			if(_isLoaded){
				_sprite.setPosition(sf::Vector2f(_x*125+50, _y*125+50));
				window.draw(_sprite);
				_sprite2.setPosition(sf::Vector2f(_x*125+57.5, _y*125+57.5));
				window.draw(_sprite2);
			}
		}
};
class Dame : public Figur{
	public: 
		Dame(int x, int y, bool isWTeam){_x=x; _y=y;_isLoaded=false;isWhiteTeam=isWTeam;load(sf::Color::Magenta);ammountStraigt=8;ammountDiagonal=8;isBauer=false;isPferd=false;}
		~Dame(){ _isLoaded=false; }
		virtual void draw(){
			if(_isLoaded){
				_sprite.setPosition(sf::Vector2f(_x*125+50, _y*125+50));
				window.draw(_sprite);
				_sprite2.setPosition(sf::Vector2f(_x*125+57.5, _y*125+57.5));
				window.draw(_sprite2);
			}
		}
};
class Koenig : public Figur{
	public: 
		Koenig(int x, int y, bool isWTeam){_x=x; _y=y;_isLoaded=false;isWhiteTeam=isWTeam;load(sf::Color::Yellow);ammountStraigt=1;ammountDiagonal=1;isBauer=false;isPferd=false;}
		~Koenig(){ _isLoaded=false; }
		virtual void draw(){
			if(_isLoaded){
				_sprite.setPosition(sf::Vector2f(_x*125+50, _y*125+50));
				window.draw(_sprite);
				_sprite2.setPosition(sf::Vector2f(_x*125+57.5, _y*125+57.5));
				window.draw(_sprite2);
			}
		}
};

std::vector<std::vector<Figur*>*>* _figuren;
sf::Texture _textureB;
sf::Texture _textureW;
sf::RectangleShape _sprite;
bool wasLeft = false;
sf::Vector2i clicked;
std::vector<sf::Vector2i> possiblePos;

bool isClient = false;
sf::UdpSocket socket;


int main(){
	if(isClient){
		if (socket.bind(54000) != sf::Socket::Done){
			return 1;
		}
	}else	
		if (socket.bind(55000) != sf::Socket::Done){
			return 1;
		}
	socket.setBlocking(false);
	clicked=sf::Vector2i(-1, -1);
	window.setView(view);
	elapsedTime = cl.restart().asMilliseconds();
	window.setFramerateLimit(120);
	_textureB.loadFromFile("black.png", sf::IntRect(0, 0, 125, 125)); 
	_textureW.loadFromFile("white.png", sf::IntRect(0, 0, 125, 125)); 
	int list[64]={
		2, 4, 3, 5, 6, 3, 4, 2,		//0 - Leer
		1, 1, 1, 1, 1, 1, 1, 1, 	//1 - Bauer
		0, 0, 0, 0, 0, 0, 0, 0,		//2 - Turm
		0, 0, 0, 0, 0, 0, 0, 0,		//3 - Laeufer
		0, 0, 0, 0, 0, 0, 0, 0,		//4 - Pferdchen
		0, 0, 0, 0, 0, 0, 0, 0,		//5 - Dame
		1, 1, 1, 1, 1, 1, 1, 1,		//6 - Koenig
		2, 4, 3, 5, 6, 3, 4, 2
	};
	_figuren = new std::vector<std::vector<Figur*>*>();
	bool b = false;
	for(int i=0;i<8;i++){
		if(i>4)
			b=true;
		_figuren->push_back(new std::vector<Figur*>());
		for(int e=0;e<8;e++)
			if(list[8*i+e]==0)
				_figuren->at(i)->push_back(new Leer(e, i, b));
			else if(list[8*i+e]==1)
				_figuren->at(i)->push_back(new Bauer(e, i, b));
			else if(list[8*i+e]==2)
				_figuren->at(i)->push_back(new Turm(e, i, b));
			else if(list[8*i+e]==3)
				_figuren->at(i)->push_back(new Laeufer(e, i, b));
			else if(list[8*i+e]==4)
				_figuren->at(i)->push_back(new Pferdchen(e, i, b));
			else if(list[8*i+e]==5)
				_figuren->at(i)->push_back(new Dame(e, i, b));
			else if(list[8*i+e]==6)
				_figuren->at(i)->push_back(new Koenig(e, i, b));
		isBlack=!isBlack;
	}
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
				break;
			}
		}
		elapsedTime = cl.restart().asMilliseconds();
		if(isClient){
			char data[100];
			std::size_t received;
			sf::IpAddress sender;
			unsigned short port;
			if (socket.receive(data, 100, received, sender, port) == sf::Socket::Done){
				std::cout << "Received " << received << " bytes from " << sender << " on port " << port << std::endl;
			}
		}else{
			char data[100];
			sf::IpAddress recipient = "192.168.178.24";
			unsigned short port = 54000;
			if (socket.send(data, 100, recipient , port) == sf::Socket::Done){
				std::cout << "Nope" << std::endl;
			}
		}

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			if(!wasLeft){
				if(sf::IntRect(0, 0, 600, 600).contains(sf::Mouse::getPosition(window))){
					bool iss = false;
					for each(sf::Vector2i pos in possiblePos)
						if(pos==sf::Vector2i(sf::Mouse::getPosition(window).x/75, sf::Mouse::getPosition(window).y/75))
							iss=true;
					if(iss){
						sf::Vector2i prevpos = clicked;
						_figuren->at(sf::Mouse::getPosition(window).y/75)->at(sf::Mouse::getPosition(window).x/75)=_figuren->at(prevpos.y)->at(prevpos.x);
						_figuren->at(sf::Mouse::getPosition(window).y/75)->at(sf::Mouse::getPosition(window).x/75)->_x=sf::Mouse::getPosition(window).x/75;
						_figuren->at(sf::Mouse::getPosition(window).y/75)->at(sf::Mouse::getPosition(window).x/75)->_y=sf::Mouse::getPosition(window).y/75;
						_figuren->at(prevpos.y)->at(prevpos.x)=new Leer(clicked.x, clicked.y, true);
						possiblePos.clear();
						if(_figuren->at(sf::Mouse::getPosition(window).y/75)->at(sf::Mouse::getPosition(window).x/75)->isBauer)
							_figuren->at(sf::Mouse::getPosition(window).y/75)->at(sf::Mouse::getPosition(window).x/75)->ammountStraigt=1;
						clicked=sf::Vector2i(-1, -1);
					}else{
						clicked=sf::Vector2i(sf::Mouse::getPosition(window).x/75, sf::Mouse::getPosition(window).y/75);
						if(_figuren->at(clicked.y)->at(clicked.x)->_isLoaded){
							possiblePos.clear();
							if((_figuren->at(clicked.y)->at(clicked.x)->ammountStraigt>0)){
								int e=_figuren->at(clicked.y)->at(clicked.x)->ammountStraigt+1;
								if(!_figuren->at(clicked.y)->at(clicked.x)->isBauer||(_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam&&_figuren->at(clicked.y)->at(clicked.x)->isBauer))
									for(int i=1;i<e;i++)
										if(clicked.y-i>-1&&clicked.y-i<8){
											if(_figuren->at(clicked.y-i)->at(clicked.x)->_isLoaded){
												if(_figuren->at(clicked.y-i)->at(clicked.x)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam&&!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
													possiblePos.push_back(sf::Vector2i(clicked.x,clicked.y-i));
												break;
											}else
												possiblePos.push_back(sf::Vector2i(clicked.x,clicked.y-i));
										}
								if(!_figuren->at(clicked.y)->at(clicked.x)->isBauer||(!_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam&&_figuren->at(clicked.y)->at(clicked.x)->isBauer))
									for(int i=-1;i>-e;i--)
										if(clicked.y-i>-1&&clicked.y-i<8){
											if(_figuren->at(clicked.y-i)->at(clicked.x)->_isLoaded){
												if(_figuren->at(clicked.y-i)->at(clicked.x)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam&&!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
													possiblePos.push_back(sf::Vector2i(clicked.x,clicked.y-i));
												break;
											}else
												possiblePos.push_back(sf::Vector2i(clicked.x,clicked.y-i));
										}
								if(!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
									for(int i=1;i<e;i++)
										if(clicked.x-i>-1&&clicked.x-i<8){
											if(_figuren->at(clicked.y)->at(clicked.x-i)->_isLoaded){
												if(_figuren->at(clicked.y)->at(clicked.x-i)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam&&!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
													possiblePos.push_back(sf::Vector2i(clicked.x-i,clicked.y));
												break;
											}else
												possiblePos.push_back(sf::Vector2i(clicked.x-i,clicked.y));
										}
								if(!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
									for(int i=-1;i>-e;i--)
										if(clicked.x-i>-1&&clicked.x-i<8){
											if(_figuren->at(clicked.y)->at(clicked.x-i)->_isLoaded){
												if(_figuren->at(clicked.y)->at(clicked.x-i)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam&&!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
													possiblePos.push_back(sf::Vector2i(clicked.x-i,clicked.y));
												break;
											}else
												possiblePos.push_back(sf::Vector2i(clicked.x-i,clicked.y));
										}
							}
							if((_figuren->at(clicked.y)->at(clicked.x)->ammountDiagonal>0)){
								int e=_figuren->at(clicked.y)->at(clicked.x)->ammountDiagonal+1;
								if(!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
									for(int i=1;i<e;i++)
										if(clicked.x-i>-1&&clicked.x-i<8&&clicked.y-i>-1&&clicked.y-i<8){
											if(_figuren->at(clicked.y-i)->at(clicked.x-i)->_isLoaded){
												if(_figuren->at(clicked.y-i)->at(clicked.x-i)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
													possiblePos.push_back(sf::Vector2i(clicked.x-i,clicked.y-i));
												break;
											}else
												possiblePos.push_back(sf::Vector2i(clicked.x-i,clicked.y-i));
										}
								if(!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
									for(int i=-1;i>-e;i--)
										if(clicked.x-i>-1&&clicked.x-i<8&&clicked.y-i>-1&&clicked.y-i<8){
											if(_figuren->at(clicked.y-i)->at(clicked.x-i)->_isLoaded){
												if(_figuren->at(clicked.y-i)->at(clicked.x-i)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
													possiblePos.push_back(sf::Vector2i(clicked.x-i,clicked.y-i));
												break;
											}else
												possiblePos.push_back(sf::Vector2i(clicked.x-i,clicked.y-i));
										}
								if(!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
									for(int i=1;i<e;i++)
										if(clicked.x+i>-1&&clicked.x+i<8&&clicked.y-i>-1&&clicked.y-i<8){
											if(_figuren->at(clicked.y-i)->at(clicked.x+i)->_isLoaded){
												if(_figuren->at(clicked.y-i)->at(clicked.x+i)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
													possiblePos.push_back(sf::Vector2i(clicked.x+i,clicked.y-i));
												break;
											}else
												possiblePos.push_back(sf::Vector2i(clicked.x+i,clicked.y-i));
										}
								if(!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
									for(int i=-1;i>-e;i--)
										if(clicked.x+i>-1&&clicked.x+i<8&&clicked.y-i>-1&&clicked.y-i<8){
											if(_figuren->at(clicked.y-i)->at(clicked.x+i)->_isLoaded){
												if(_figuren->at(clicked.y-i)->at(clicked.x+i)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam&&!_figuren->at(clicked.y)->at(clicked.x)->isBauer)
													possiblePos.push_back(sf::Vector2i(clicked.x+i,clicked.y-i));
												break;
											}else
												possiblePos.push_back(sf::Vector2i(clicked.x+i,clicked.y-i));
										}
							}			
							if(_figuren->at(clicked.y)->at(clicked.x)->isBauer)
								if(_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam){
									if(clicked.x>0&&clicked.y>0)
										if(_figuren->at(clicked.y-1)->at(clicked.x-1)->_isLoaded&&!_figuren->at(clicked.y-1)->at(clicked.x-1)->isWhiteTeam)
											possiblePos.push_back(sf::Vector2i(clicked.x-1,clicked.y-1));
									if(clicked.x<7&&clicked.y>0)
										if(_figuren->at(clicked.y-1)->at(clicked.x+1)->_isLoaded&&!_figuren->at(clicked.y-1)->at(clicked.x+1)->isWhiteTeam)
											possiblePos.push_back(sf::Vector2i(clicked.x+1,clicked.y-1));
								}else{
									if(clicked.x>0&&clicked.y<7)
										if(_figuren->at(clicked.y+1)->at(clicked.x-1)->_isLoaded&&_figuren->at(clicked.y+1)->at(clicked.x-1)->isWhiteTeam)
											possiblePos.push_back(sf::Vector2i(clicked.x-1,clicked.y+1));
									if(clicked.x<7&&clicked.y<7)
										if(_figuren->at(clicked.y+1)->at(clicked.x+1)->_isLoaded&&_figuren->at(clicked.y+1)->at(clicked.x+1)->isWhiteTeam)
											possiblePos.push_back(sf::Vector2i(clicked.x+1,clicked.y+1));
								}

							if(_figuren->at(clicked.y)->at(clicked.x)->isPferd){
									if(clicked.x>0&&clicked.y>1)//TOP-LEFT
										if(_figuren->at(clicked.y-2)->at(clicked.x-1)->_isLoaded){
											if(_figuren->at(clicked.y-2)->at(clicked.x-1)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
												possiblePos.push_back(sf::Vector2i(clicked.x-1,clicked.y-2));
										}else
											possiblePos.push_back(sf::Vector2i(clicked.x-1,clicked.y-2));
									if(clicked.x<7&&clicked.y>1)//TOP-RIGHT
										if(_figuren->at(clicked.y-2)->at(clicked.x+1)->_isLoaded){
											if(_figuren->at(clicked.y-2)->at(clicked.x+1)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
												possiblePos.push_back(sf::Vector2i(clicked.x+1,clicked.y-2));
										}else
											possiblePos.push_back(sf::Vector2i(clicked.x+1,clicked.y-2));

									if(clicked.x>0&&clicked.y<6)//BOTTOM-LEFT
										if(_figuren->at(clicked.y+2)->at(clicked.x-1)->_isLoaded){
											if(_figuren->at(clicked.y+2)->at(clicked.x-1)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
												possiblePos.push_back(sf::Vector2i(clicked.x-1,clicked.y+2));
										}else
											possiblePos.push_back(sf::Vector2i(clicked.x-1,clicked.y+2));
									if(clicked.x<7&&clicked.y<6)//BOTTOM-RIGHT
										if(_figuren->at(clicked.y+2)->at(clicked.x+1)->_isLoaded){
											if(_figuren->at(clicked.y+2)->at(clicked.x+1)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
												possiblePos.push_back(sf::Vector2i(clicked.x+1,clicked.y+2));
										}else
											possiblePos.push_back(sf::Vector2i(clicked.x+1,clicked.y+2));

									if(clicked.x<6&&clicked.y>0)//RIGHT-TOP
										if(_figuren->at(clicked.y-1)->at(clicked.x+2)->_isLoaded){
											if(_figuren->at(clicked.y-1)->at(clicked.x+2)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
												possiblePos.push_back(sf::Vector2i(clicked.x+2,clicked.y-1));
										}else
											possiblePos.push_back(sf::Vector2i(clicked.x+2,clicked.y-1));
									if(clicked.x<6&&clicked.y<7)//RIGHT-BOTTOM
										if(_figuren->at(clicked.y+1)->at(clicked.x+2)->_isLoaded){
											if(_figuren->at(clicked.y+1)->at(clicked.x+2)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
												possiblePos.push_back(sf::Vector2i(clicked.x+2,clicked.y+1));
										}else
											possiblePos.push_back(sf::Vector2i(clicked.x+2,clicked.y+1));

									if(clicked.x>2&&clicked.y>0)//LEFT-TOP
										if(_figuren->at(clicked.y-1)->at(clicked.x-2)->_isLoaded){
											if(_figuren->at(clicked.y-1)->at(clicked.x-2)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
												possiblePos.push_back(sf::Vector2i(clicked.x-2,clicked.y-1));
										}else
											possiblePos.push_back(sf::Vector2i(clicked.x-2,clicked.y-1));
									if(clicked.x>2&&clicked.y<7)//LEFT-BOTTOM
										if(_figuren->at(clicked.y+1)->at(clicked.x-2)->_isLoaded){
											if(_figuren->at(clicked.y+1)->at(clicked.x-2)->isWhiteTeam!=_figuren->at(clicked.y)->at(clicked.x)->isWhiteTeam)
												possiblePos.push_back(sf::Vector2i(clicked.x-2,clicked.y+1));
										}else
											possiblePos.push_back(sf::Vector2i(clicked.x-2,clicked.y+1));


							}
						}else{
							possiblePos.clear();
							clicked=sf::Vector2i(-1, -1);
						}
					}
				}else{
					possiblePos.clear();
					clicked=sf::Vector2i(-1, -1);
				}
			}
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			wasLeft = true;
		else
			wasLeft = false;
		
		window.clear();
		_sprite.setSize(sf::Vector2f(125, 125));
		for(int i=0;i<8;i++){
			for(int e=0;e<8;e++){
				_sprite.setPosition(sf::Vector2f(e*125, i*125)); 
				if(clicked!=sf::Vector2i(e, i)){
					bool is = false;
					for each(sf::Vector2i pos in possiblePos)
						if(pos==sf::Vector2i(e, i))
							is=true;
					if(is){
						_sprite.setFillColor(sf::Color(180, 180, 180));
					}else{
						if(isBlack)
							_sprite.setFillColor(sf::Color(255, 255, 255));
						else 
							_sprite.setFillColor(sf::Color(0, 0, 0));
					}
					
				}else{
					_sprite.setFillColor(sf::Color(128, 128, 128));
				}
				isBlack=!isBlack;
				window.draw(_sprite);
			}
			isBlack=!isBlack;
		}
		for each(std::vector<Figur*>* figurenListe in *_figuren)
			for each(Figur* figur in *figurenListe)
				figur->draw();
		window.display();
	}
	return 0;
}

