#include <SFML\Graphics.hpp>
#include <iostream>
#include <cstddef>
#include "Animation.h"
#include "Player.h"
#include "Platform.h"
#include<fstream>
#include<cctype>
#include <string>
#include "Menu.h"
#include <SFML\Audio.hpp>
#include <sstream>
using namespace sf;
using namespace std;
static const float VIEW_HEIGHT = 550.0f;
int pagenumber = 5, tryAgain, Highscore, varTime = 120;
vector<Sprite> lives;
int calculatescore(int x, int y)
{
	Highscore += (x * 2 + y * 2 + lives.size() * 3);
	return Highscore;
}
bool name = false, resumed = false, beepbool = true, playerCheck1 = true, lvl2bool = false, kfaya = false, playerCheck2 = true, setscore = false, stop = false, stop2 = false, go = false, watergo = false, waterDmg = false, cat1go = false, watergo2 = false, waterDmg2 = false, watergo3 = false, waterDmg3 = false, paused = true, extraLifeFlag = true, sideCar1 = false, sideCar2 = false, sh3bi = false, gamestart = false;
void ResizeView(const RenderWindow& renderWindow, View& view)
{
	float aspectRatio = float(renderWindow.getSize().x) / float(renderWindow.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
RectangleShape car(Vector2f(50, 120));
Collider getCollider() { return Collider(car); }

int main()
{
	string playerInput;

	SoundBuffer menuselect, dmgbuffer, jumpbuffer, gameoverbuffer, coincollectorbuffer, healthcollectorbuffer, carhitbuffer, lvl2buffer;
	if (!menuselect.loadFromFile("sounds/Select.Wav"))
	{
	}
	Sound select;
	select.setBuffer(menuselect);
	select.setVolume(40);

	if (!healthcollectorbuffer.loadFromFile("sounds/health.Wav"))
	{
	}
	Sound health;
	health.setBuffer(healthcollectorbuffer);

	if (!carhitbuffer.loadFromFile("sounds/carhit.Wav"))
	{
	}
	Sound carhit;
	carhit.setBuffer(carhitbuffer);

	if (!jumpbuffer.loadFromFile("sounds/Jump.Wav"))
	{
	}
	Sound jump;
	jump.setBuffer(jumpbuffer);

	if (!coincollectorbuffer.loadFromFile("sounds/coin.Wav"))
	{
	}
	Sound coincollect;
	coincollect.setBuffer(coincollectorbuffer);

	if (!gameoverbuffer.loadFromFile("sounds/GameOver.Wav"))
	{
	}
	Sound gameover;
	gameover.setBuffer(gameoverbuffer);

	if (!dmgbuffer.loadFromFile("sounds/Hurt.Wav"))
	{
	}
	Sound dmgbuff;
	dmgbuff.setBuffer(dmgbuffer);

	if (!lvl2buffer.loadFromFile("sounds/lvl2.Wav"))
	{
	}
	Sound lvl2begin;
	lvl2begin.setBuffer(lvl2buffer);

	Music music;
	if (!music.openFromFile("sounds/Kalimba.ogg"))
	{
	}
	Music lvl2music;
	if (!lvl2music.openFromFile("sounds/sh3bi.ogg"))
	{
	}
	lvl2music.setVolume(20);
	Texture carTexture;
	carTexture.loadFromFile("images/mar3iobus.png");
	car.setTexture(&carTexture);
	car.setOrigin(200, -90);
	car.setPosition(5080.91, 16);

	Texture checkptexture1, checkptexture2;
	checkptexture1.loadFromFile("images/checkpoint.png");
	checkptexture2.loadFromFile("images/checkpoint2.png");

	RectangleShape check1(Vector2f(50, 50)), check2(Vector2f(50, 50)), check11(Vector2f(50, 50)), check22(Vector2f(50, 50));

	check1.setTexture(&checkptexture1);
	check11.setTexture(&checkptexture1);
	check2.setTexture(&checkptexture2);
	check22.setTexture(&checkptexture2);

	check1.setOrigin(200, -90);
	check11.setOrigin(200, -90);
	check2.setOrigin(200, -90);
	check22.setOrigin(200, -90);

	check1.setPosition(1712.33, 20);
	check22.setPosition(1712.33, 20);
	check11.setPosition(3898.99, 20);
	check2.setPosition(3898.99, 20);
	string tries;
	Texture sidetaxitexture;
	Texture taxitexture;
	Texture busTexture;
	Texture sidebusTexture;
	Texture bigBusTexture;
	Texture comingTaxi;
	Texture comingBus;
	Texture sideBus;
	Texture sideBus2;
	Texture BigIsComing;
	taxitexture.loadFromFile("images/taxi2.png");
	sidetaxitexture.loadFromFile("images/taxi.png");
	busTexture.loadFromFile("images/minibus.png");
	sidebusTexture.loadFromFile("images/bigbus.png");
	bigBusTexture.loadFromFile("images/bigbus2.png");
	comingTaxi.loadFromFile("images/taxi3.png");
	comingBus.loadFromFile("images/minibus3.png");
	sideBus.loadFromFile("images/minibus4.png");
	sideBus2.loadFromFile("images/minibus5.png");
	BigIsComing.loadFromFile("images/big_is_coming.png");

	Platform sideTaxiBG2(&sidetaxitexture, Vector2f(100, 60), Vector2f(4850, -1049));
	Platform taxiBG2(&taxitexture, Vector2f(50, 100), Vector2f(5165, -635.561));
	Platform BUSBG2(&busTexture, Vector2f(50, 120), Vector2f(5171, -871.683));
	Platform taxiBG3(&taxitexture, Vector2f(50, 100), Vector2f(5000, -1364.26));
	Platform taxiBG4(&taxitexture, Vector2f(50, 100), Vector2f(5171, -1894.17));
	Platform sidebusBG3(&sidebusTexture, Vector2f(130, 80), Vector2f(4950, -1719.44));
	Platform movingBusBG6(&busTexture, Vector2f(50, 120), Vector2f(5113.34, -2544.12));
	Platform BUSBG6(&busTexture, Vector2f(50, 120), Vector2f(5045.66, -2557.96));
	Platform sideTaxiBG6(&sidetaxitexture, Vector2f(80, 60), Vector2f(5250.68, -3000));
	Platform busBG7(&bigBusTexture, Vector2f(60, 190), Vector2f(5123.72, -3327.19));
	Platform comingTaxiBG9(&comingTaxi, Vector2f(50, 100), Vector2f(5078.67, -4200.57));
	Platform comingBusBG9(&comingBus, Vector2f(50, 120), Vector2f(5165, -4650.57));
	Platform busBG8(&BigIsComing, Vector2f(60, 190), Vector2f(4994.88, -4000.23));
	Platform sideBusBG8(&sideBus, Vector2f(120, 60), Vector2f(5200.29, -4327.11));
	Platform sideBus2BG8(&sideBus2, Vector2f(120, 60), Vector2f(4880.88, -4255.66));
	Platform taxi_1_BG9(&comingTaxi, Vector2f(60, 100), Vector2f(5080.44, -4814.54));
	Platform bus_1_BG9(&busTexture, Vector2f(80, 120), Vector2f(4990.22, -4652.04));
	Platform bigbus_1_BG9(&BigIsComing, Vector2f(065, 145), Vector2f(5147.8, -5122.43));
	Platform t3ala_taxi_1_BG10(&comingTaxi, Vector2f(065, 120), Vector2f(5083.99, -5299.89));
	Platform bus_1_BG10(&busTexture, Vector2f(065, 120), Vector2f(5006.1, -5135.07));
	Platform bus_2_BG10(&busTexture, Vector2f(065, 120), Vector2f(5151.81, -5272.68));
	Platform bus_1_BG1(&busTexture, Vector2f(065, 120), Vector2f(4994.72, -195.554));

	Font font;
	font.loadFromFile("arial.ttf");

	Text text;
	text.setFont(font);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold);
	text.setPosition(0, 0);

	Text triesText;
	triesText.setFont(font);
	triesText.setCharacterSize(50);
	triesText.setFillColor(sf::Color::White);
	triesText.setStyle(sf::Text::Bold);
	triesText.setPosition(400, 200);

	Text playAgainText;
	playAgainText.setFont(font);
	playAgainText.setCharacterSize(50);
	playAgainText.setFillColor(sf::Color::White);
	playAgainText.setStyle(sf::Text::Bold);
	playAgainText.setPosition(400, 290);
	playAgainText.setString("Press Y to try again");


	Text scoreText, Highscoretext;
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color(212, 175, 55));
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setPosition(0, 0);

	Text playerText;
	playerText.setFont(font);
	playerText.setCharacterSize(20);
	playerText.setFillColor(sf::Color(212, 175, 55));
	playerText.setStyle(sf::Text::Bold);
	playerText.setPosition(50, 100);

	Text playerName;
	playerName.setFont(font);
	playerName.setCharacterSize(45);
	playerName.setFillColor(sf::Color::Cyan);
	playerName.setStyle(sf::Text::Bold);
	playerName.setPosition(550, 200);

	Highscoretext.setFont(font);
	Highscoretext.setCharacterSize(45);
	Highscoretext.setFillColor(sf::Color::Cyan);
	Highscoretext.setStyle(sf::Text::Bold);
	Highscoretext.setPosition(550, 300);

	Texture moovet;
	Texture juumpt;
	Texture sprintt;
	Texture mud;
	Texture rockTexture;
	Texture bla3a;

	mud.loadFromFile("images/mud.png");
	rockTexture.loadFromFile("images/rock.png");
	bla3a.loadFromFile("images/hole.png");

	RectangleShape hole(Vector2f(50, 50));
	hole.setTexture(&bla3a);
	hole.setOrigin(200, -90);
	hole.setPosition(4025, 35);

	RectangleShape mudshape(Vector2f(450, 60));
	mudshape.setTexture(&mud);
	mudshape.setOrigin(200, -90);
	mudshape.setPosition(3190, 35);

	Clock pause;
	Time pauseTime;
	int pauseCt;

	Texture coinTexture;
	coinTexture.loadFromFile("images/coin.png");
	Animation coinAnimation(&coinTexture, Vector2u(6, 1), 0.2f);

	RectangleShape moove(Vector2f(75, 75));
	RectangleShape juump(Vector2f(75, 75));
	RectangleShape sprint(Vector2f(75, 75));


	moovet.loadFromFile("images/move.png");
	juumpt.loadFromFile("images/jump.png");
	sprintt.loadFromFile("images/sprint.png");


	moove.setTexture(&moovet);
	juump.setTexture(&juumpt);
	sprint.setTexture(&sprintt);

	moove.setOrigin(200, -190);
	juump.setOrigin(-50, -200);
	sprint.setOrigin(-800, -190);

	Texture pausetexture;
	Texture trashTexture;
	Texture yousefZbala;
	Texture yousefZbala2;
	Texture yousefZbala3;
	Texture yahiaZbala;
	Texture yahiaZbala2;
	pausetexture.loadFromFile("images/Pause.png");
	yahiaZbala.loadFromFile("images/trash1.png");
	yahiaZbala2.loadFromFile("images/trash2.png");
	yousefZbala.loadFromFile("images/trash1.png");
	yousefZbala2.loadFromFile("images/trash2.png");
	trashTexture.loadFromFile("images/trash3.png");
	Platform trash(&trashTexture, Vector2f(40, 50), Vector2f(340, 16));
	Platform trash1(&trashTexture, Vector2f(40, 50), Vector2f(920, 16));
	Platform trash2(&trashTexture, Vector2f(40, 50), Vector2f(1100, 16));
	Platform trash3(&trashTexture, Vector2f(40, 50), Vector2f(2500, 16));
	Platform trash4(&trashTexture, Vector2f(40, 50), Vector2f(2540, 16));
	Platform trash5(&trashTexture, Vector2f(40, 50), Vector2f(2540, -21));
	Platform trash6(&trashTexture, Vector2f(40, 50), Vector2f(4400, 16));
	Platform trash7(&trashTexture, Vector2f(40, 50), Vector2f(5052.71 + 40, 16));
	Platform trash8(&trashTexture, Vector2f(40, 50), Vector2f(5052.71 + 40, 16 - 40));
	Platform trash9(&trashTexture, Vector2f(40, 50), Vector2f(5052.71 + 40 + 40, 16));
	Platform trash10(&trashTexture, Vector2f(40, 50), Vector2f(5052.71 + 40 + 40, 16 - 40));
	Platform trash11(&trashTexture, Vector2f(40, 50), Vector2f(5052.71 + 40 + 40, 16 - 80));


	RectangleShape Pausesign(Vector2f(130, 150));
	RectangleShape trashBag(Vector2f(70, 50));
	RectangleShape trashBag1(Vector2f(70, 50));
	RectangleShape trashBag2(Vector2f(70, 50));
	RectangleShape trashBag3(Vector2f(70, 50));
	RectangleShape trashBag4(Vector2f(70, 50));
	RectangleShape trashBag5(Vector2f(70, 50));
	Pausesign.setTexture(&pausetexture);
	trashBag.setTexture(&yousefZbala);
	trashBag1.setTexture(&yousefZbala2);
	trashBag2.setTexture(&yousefZbala2);
	trashBag3.setTexture(&yousefZbala);
	trashBag4.setTexture(&yahiaZbala);
	trashBag5.setTexture(&yahiaZbala2);

	Pausesign.setOrigin(200, -120);
	trashBag.setOrigin(200, -120);
	trashBag1.setOrigin(200, -120);
	trashBag2.setOrigin(200, -120);
	trashBag3.setOrigin(200, -120);
	trashBag4.setOrigin(200, -120);
	trashBag5.setOrigin(200, -120);

	trashBag.setPosition(930, 0);
	trashBag3.setPosition(980, 0);
	trashBag2.setPosition(1000, 0);
	trashBag1.setPosition(950, 0);
	trashBag4.setPosition(1030, 0);
	trashBag5.setPosition(1055, 0);


	Texture waterTexture;
	Texture splashTexture;
	waterTexture.loadFromFile("images/water.png");
	splashTexture.loadFromFile("images/splash.png");
	RectangleShape water;
	RectangleShape splash;
	water.setTexture(&waterTexture);
	splash.setTexture(&splashTexture);
	water.setSize(Vector2f(30, 50));
	splash.setSize(Vector2f(60, 50));
	water.setOrigin(200, -90);
	splash.setOrigin(200, -90);
	water.setPosition(730, -185);
	splash.setPosition(718, 16);

	RectangleShape water2;
	RectangleShape splash2;
	water2.setTexture(&waterTexture);
	splash2.setTexture(&splashTexture);
	water2.setSize(Vector2f(30, 50));
	splash2.setSize(Vector2f(60, 50));
	water2.setOrigin(200, -90);
	splash2.setOrigin(200, -90);
	water2.setPosition(1829, -185);
	splash2.setPosition(1820, 16);

	RectangleShape water3;
	RectangleShape splash3;
	water3.setTexture(&waterTexture);
	splash3.setTexture(&splashTexture);
	water3.setSize(Vector2f(30, 50));
	splash3.setSize(Vector2f(60, 50));
	water3.setOrigin(200, -90);
	splash3.setOrigin(200, -90);
	water3.setPosition(2895.95 + 35, -185);
	splash3.setPosition(2895.95 + 35 - 9, 16);

	Texture damage;
	damage.loadFromFile("images/Damage.png");
	RectangleShape dmg;
	dmg.setTexture(&damage);
	dmg.setSize(Vector2f(590.0f, 650.0f));
	dmg.setOrigin(240.0f, 350);

	Texture tile;
	tile.loadFromFile("images/platform.png");

	Platform floor(&tile, Vector2f(11000.0f, 20.0f), Vector2f(200.0f, 40.0f));



	Platform rock1(&rockTexture, Vector2f(30, 40), Vector2f(3243.84, 30));
	Platform rock2(&rockTexture, Vector2f(30, 40), Vector2f(3320.3, 30));
	Platform rock3(&rockTexture, Vector2f(30, 40), Vector2f(3391.49, 30));
	Platform rock4(&rockTexture, Vector2f(30, 40), Vector2f(3474.09, 30));
	Platform rock5(&rockTexture, Vector2f(30, 40), Vector2f(3576.26, 30));


	Texture livesTexture;
	livesTexture.loadFromFile("images/Lives.png");
	Sprite live1(livesTexture);
	Sprite live2(livesTexture);
	Sprite live3(livesTexture);
	RectangleShape extraLife(Vector2f(20, 20));
	extraLife.setOrigin(200, -90);
	extraLife.setPosition(3749.54, -20);
	extraLife.setTexture(&livesTexture);
	live1.setScale(0.1, 0.1);
	live1.setPosition(200, -100);
	live2.setScale(0.1, 0.1);
	live2.setPosition(190, -100);
	live3.setScale(0.1, 0.1);
	live3.setPosition(180, -100);

	lives.push_back(live1);
	lives.push_back(live2);
	lives.push_back(live3);


	Texture BackGround;
	Texture BackGround2;
	BackGround.loadFromFile("images/background.png");
	BackGround2.loadFromFile("images/background2.png");

	Texture deathbg1;
	Texture deathbg2;
	Texture scoreboard;
	scoreboard.loadFromFile("images/scoreboard.png");
	deathbg1.loadFromFile("images/compilation.png");
	deathbg2.loadFromFile("images/runtime.png");
	RectangleShape scoreboardshape;
	RectangleShape deathmenu1;
	RectangleShape deathmenu2;

	deathmenu1.setTexture(&deathbg1);
	deathmenu1.setSize(Vector2f(1280.0f, 800.0f));
	deathmenu1.setOrigin(0.0f, 0);
	deathmenu2.setTexture(&deathbg2);
	deathmenu2.setSize(Vector2f(1280.0f, 800.0f));
	deathmenu2.setOrigin(0.0f, 0);

	scoreboardshape.setTexture(&scoreboard);
	scoreboardshape.setSize(Vector2f(1024, 768));
	scoreboardshape.setOrigin(0.0f, 0);

	RectangleShape BG;
	RectangleShape BG1;
	RectangleShape BG2;
	RectangleShape BG3;
	RectangleShape BG4;
	RectangleShape BG5;
	RectangleShape BG6;
	RectangleShape BG7;
	RectangleShape BG8;
	RectangleShape BG9;


	Texture DogTexture;
	Texture catTexture;
	Texture ratTexture;
	Texture catwalk;
	Texture menutexture;

	menutexture.loadFromFile("images/menu.png");
	RectangleShape menushape(Vector2f(1024, 768));
	menushape.setTexture(&menutexture);
	menushape.setOrigin(0, 0);

	Texture optionsmenutexture;
	optionsmenutexture.loadFromFile("images/options.png");
	RectangleShape optionsshape(Vector2f(1024, 768));
	optionsshape.setTexture(&optionsmenutexture);
	optionsshape.setOrigin(0, 0);

	Texture storytexture;
	storytexture.loadFromFile("images/story.png");
	RectangleShape storyshape(Vector2f(1024, 768));
	storyshape.setTexture(&storytexture);
	storyshape.setOrigin(0, 0);

	DogTexture.loadFromFile("images/dog.png");
	catTexture.loadFromFile("images/cats.png");
	ratTexture.loadFromFile("images/rat.png");
	catwalk.loadFromFile("images/cats2.png");


	RectangleShape cat(Vector2f(50, 50));
	RectangleShape dog(Vector2f(50, 50));
	RectangleShape dog1(Vector2f(50, 50));
	RectangleShape rat(Vector2f(30, 30));
	RectangleShape cat1(Vector2f(50, 50));

	dog.setTexture(&DogTexture);
	dog1.setTexture(&DogTexture);
	cat.setTexture(&catTexture);
	rat.setTexture(&ratTexture);
	cat1.setTexture(&catwalk);

	cat.setOrigin(200, -90);
	rat.setOrigin(200, -90);
	dog.setOrigin(200, -90);
	dog1.setOrigin(200, -90);
	cat1.setOrigin(200, -90);

	cat.setPosition(-103, 15);
	dog.setPosition(2000, 15);
	dog1.setPosition(2500, 15);
	rat.setPosition(4050, 30);
	cat1.setPosition(940, 15);

	Animation dogAnimation(&DogTexture, Vector2u(3, 1), 0.2f);
	Animation dogAnimation1(&DogTexture, Vector2u(3, 1), 0.2f);
	Animation catAnimation(&catTexture, Vector2u(3, 1), 0.2f);
	Animation ratAnimation(&ratTexture, Vector2u(3, 1), 0.2f);
	Animation cat1Animation(&catwalk, Vector2u(3, 1), 0.2f);

	BG.setTexture(&BackGround);
	BG.setSize(Vector2f(550.0f, 650.0f));
	BG.setOrigin(256.0f, 350);
	BG1.setTexture(&BackGround2);
	BG1.setSize(Vector2f(550, 650));
	BG1.setOrigin(256.0f - BG.getSize().x, 350);
	BG2.setTexture(&BackGround);
	BG2.setSize(Vector2f(550, 650));
	BG2.setOrigin(256.0f - BG.getSize().x * 2, 350);
	BG3.setTexture(&BackGround2);
	BG3.setSize(Vector2f(550, 650));
	BG3.setOrigin(256.0f - BG.getSize().x * 3, 350);
	BG4.setTexture(&BackGround);
	BG4.setSize(Vector2f(550, 650));
	BG4.setOrigin(256.0f - BG.getSize().x * 4, 350);
	BG5.setTexture(&BackGround2);
	BG5.setSize(Vector2f(550, 650));
	BG5.setOrigin(256.0f - BG.getSize().x * 5, 350);
	BG6.setTexture(&BackGround);
	BG6.setSize(Vector2f(550, 650));
	BG6.setOrigin(256.0f - BG.getSize().x * 6, 350);
	BG7.setTexture(&BackGround);
	BG7.setSize(Vector2f(550, 650));
	BG7.setOrigin(256.0f - BG.getSize().x * 7, 350);
	BG8.setTexture(&BackGround);
	BG8.setSize(Vector2f(550, 650));
	BG8.setOrigin(256.0f - BG.getSize().x * 8, 350);
	BG9.setTexture(&BackGround);
	BG9.setSize(Vector2f(550, 650));
	BG9.setOrigin(256.0f - BG.getSize().x * 9, 350);

	Texture lvl2Texture;
	lvl2Texture.loadFromFile("images/lvl2start.png");
	Texture lvl2Texture1;
	lvl2Texture1.loadFromFile("images/lvl22.png");
	RectangleShape lvl2;
	lvl2.setTexture(&lvl2Texture);
	lvl2.setSize(Vector2f(550, 650));
	lvl2.setOrigin(320.0f - BG.getSize().x * 9, 310);


	Texture lvl2BGTexture;
	lvl2BGTexture.loadFromFile("images/lvl2.png");

	RectangleShape level2BGs[10];

	for (int i = 1; i < 10; i++)
	{
		level2BGs[i].setTexture(&lvl2BGTexture);
		level2BGs[i].setSize(Vector2f(550, 650));
		level2BGs[i].setOrigin(256.0f - BG.getSize().x * 9 + 62, 350 * i * 2 - 50 * i);
	}
	level2BGs[0].setOrigin(256.0f - BG.getSize().x * 9 + 62, 350);

	RectangleShape level2Bg(Vector2f(500, 800));
	level2Bg.setTexture(&lvl2BGTexture);
	level2Bg.setSize(Vector2f(550, 650));
	level2Bg.setOrigin(256.0f - BG.getSize().x * 9 + 62, 350);
	RectangleShape level2Bg2(Vector2f(500, 800));
	level2Bg2.setTexture(&lvl2BGTexture);
	level2Bg2.setSize(Vector2f(550, 650));
	level2Bg2.setOrigin(256.0f - BG.getSize().x * 9 + 62, 350 * 3 - 50);
	RectangleShape level2Bg3(Vector2f(500, 800));
	level2Bg3.setTexture(&lvl2BGTexture);
	level2Bg3.setSize(Vector2f(550, 650));
	level2Bg3.setOrigin(256.0f - BG.getSize().x * 9 + 62, 350 * 5 - 50 * 2);
	RectangleShape level2Bg4(Vector2f(500, 800));
	level2Bg4.setTexture(&lvl2BGTexture);
	level2Bg4.setSize(Vector2f(550, 650));
	level2Bg4.setOrigin(256.0f - BG.getSize().x * 9 + 62, 350 * 7 - 50 * 3);
	RectangleShape level2Bg5(Vector2f(500, 800));
	level2Bg5.setTexture(&lvl2BGTexture);
	level2Bg5.setSize(Vector2f(550, 650));
	level2Bg5.setOrigin(256.0f - BG.getSize().x * 9 + 62, 350 * 9 - 50 * 4);
	RectangleShape level2Bg6(Vector2f(500, 800));
	level2Bg6.setTexture(&lvl2BGTexture);
	level2Bg6.setSize(Vector2f(550, 650));
	level2Bg6.setOrigin(256.0f - BG.getSize().x * 9 + 62, 350 * 11 - 50 * 5);
	RectangleShape level2Bg7(Vector2f(500, 800));
	level2Bg7.setTexture(&lvl2BGTexture);
	level2Bg7.setSize(Vector2f(550, 650));
	level2Bg7.setOrigin(256.0f - BG.getSize().x * 9 + 62, 350 * 13 - 50 * 6);
	RectangleShape level2Bg8(Vector2f(500, 800));
	level2Bg8.setTexture(&lvl2BGTexture);
	level2Bg8.setSize(Vector2f(550, 650));
	level2Bg8.setOrigin(256.0f - BG.getSize().x * 9 + 62, 350 * 15 - 50 * 7);
	RectangleShape level2Bg9(Vector2f(500, 800));
	level2Bg9.setTexture(&lvl2Texture1);
	level2Bg9.setSize(Vector2f(550, 650));
	level2Bg9.setOrigin(256.0f - BG.getSize().x * 9 + 62, 350 * 17 - 50 * 8);

	Texture playerTexture;
	playerTexture.loadFromFile("images/Mar3io.png");
	Player player(&playerTexture, Vector2u(3, 3), 0.2f, 196.0f, 50.0f);
	player.SetPosition(Vector2f(player.GetPosition().x + 23, player.GetPosition().y));
	Platform paltform2(nullptr, Vector2f(10.0f, 600.0f), Vector2f(player.GetPosition().x - 30, player.GetPosition().y - 248));


	Platform platform3(nullptr, Vector2f(11000, 50.0f), Vector2f(6000, player.GetPosition().y - 50));


	float deltaTime = 0.0f, t = 0, time = 50, s = 0, l = 0, l1 = 0, ground = player.GetPosition().y, push = 0.5, checkpoint = 20;
	Clock clock, c, d, d1, sahyana, c2;
	int ct = 0, s2, score = 0;
	Time ti, di, di1, ti2;
	string number, scr, hscorestring;
	float lvl2Timer = 0;
	Clock lvl2Clock;
	Time lvl2Time;

	map<int, bool> coinFlags;
	for (int i = 1; i < 19; i++)
	{
		coinFlags[i] = true;
	}
	RectangleShape coins[19] = {};
	for (int i = 1; i < 19; i++)
	{
		coins[i].setSize(Vector2f(35, 35));
		coins[i].setOrigin(200, -90);
		coins[i].setPosition(1200 + 100 * i, 20);
		coins[i].setTexture(&coinTexture);
	}
	for (int i = 5; i < 14; i++)
	{
		coins[i].setSize(Vector2f(35, 35));
		coins[i].setOrigin(200, -90);
		coins[i].setPosition(2002 + 100 * i, -12);
		coins[i].setTexture(&coinTexture);
	}
	coins[5].setPosition(2502, -60);
	coins[6].setPosition(2600, -120);
	coins[10].setPosition(3293.3 + 5, -60);
	coins[11].setPosition(3422.56 + 15, -60);
	coins[12].setPosition(3349.34 + 25, -60);
	coins[13].setPosition(3515.2 + 15, -60);
	int coinCounter = 0;
	for (int i = 14; i < 19; i++)
	{
		coins[i].setPosition(3788.14 + coinCounter, 20);
		coinCounter += 50;
	}
	double carSpeed = 0;

	RenderWindow menuwindow(VideoMode(1024, 768), "Mar3i");

	Menu menu(1024, 768);
	Event eve, retry, menuoptions, menustory, scoreevent;
	while (true)
	{
		while (menuwindow.pollEvent(eve))
		{
			if (eve.type == Event::Closed)
				menuwindow.close();

			if (eve.type == Event::KeyReleased)
			{
				if (eve.key.code == Keyboard::Up)
				{
					menu.moveup();
					select.play();

				}
				if (eve.key.code == Keyboard::Down)
				{
					menu.movedown();
					select.play();

				}
				if (eve.key.code == Keyboard::Return)
				{
					select.play();

					if (!menu.mainmenupressed())
					{
						menuwindow.close();
						pagenumber = 0;
					}
					if (menu.mainmenupressed() == 1)
					{
						pagenumber = 1;
					}
					if (menu.mainmenupressed() == 2)
					{
						pagenumber = 2;
					}

					if (menu.mainmenupressed() == 3)
					{
						menuwindow.close();
						pagenumber = 3;
					}
				}
			}

			menuwindow.clear();
			menuwindow.draw(menushape);
			menu.draw(menuwindow);
			menuwindow.display();

			if (pagenumber == 1)
			{
				RenderWindow optionswindow(VideoMode(1024, 768), "Mar3i");

				while (optionswindow.isOpen())
				{
					while (optionswindow.pollEvent(menuoptions))
					{

						switch (menuoptions.type)
						{
						case Event::Closed:
						{
							optionswindow.close();
							menuwindow.close();
							break;
						}
						}
						if (menuoptions.key.code == Keyboard::Escape)
						{
							select.play();
							pagenumber = 5;
							optionswindow.close();
						}
					}
					optionswindow.clear();

					optionswindow.draw(optionsshape);
					optionswindow.display();
				}
			}
			if (pagenumber == 2)
			{
				RenderWindow storywindow(VideoMode(1024, 768), "Mar3i");
				while (storywindow.isOpen())
				{
					while (storywindow.pollEvent(menustory))
					{
						switch (menustory.type)
						{
						case Event::Closed:
						{
							storywindow.close();
							menuwindow.close();
							break;
						}
						}
						if (menustory.key.code == Keyboard::Escape)
						{
							select.play();
							pagenumber = 5;
							storywindow.close();
						}
					}
					storywindow.clear();
					storywindow.draw(storyshape);
					storywindow.display();
				}
			}

			if (!pagenumber || gamestart)
			{
				c2.restart();
				music.play();
				RenderWindow renderWindow(VideoMode(1280, 800), "Mar3i");
				View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
				Event event;
				paused = false;
				while (renderWindow.isOpen())
				{

					if (Keyboard::isKeyPressed(Keyboard::P) && paused == false)
					{
						pause.restart().asSeconds();
						paused = true;
						music.pause();
						if (sh3bi) lvl2music.pause();
					}

					if (Keyboard::isKeyPressed(Keyboard::R) && paused == true)
					{
						resumed = true;
						paused = false;
						if (!sh3bi) music.play();
						if (sh3bi) lvl2music.play();

					}

					if (paused)
					{
						if (player.GetPosition().x >= 5326.35)
							Pausesign.setPosition(5040.91, car.getPosition().y - 300);
						else
							Pausesign.setPosition(player.GetPosition().x + 130, -180);
						renderWindow.draw(Pausesign);
						renderWindow.display();
						pauseTime = pause.getElapsedTime();

					}
					if (resumed)
					{
						varTime += pauseTime.asSeconds();
						resumed = false;
					}

					if (!paused)
					{

						ti2 = c2.getElapsedTime();
						s2 = varTime - ti2.asSeconds();

						stringstream ss;
						ss << s2;
						ss >> number;

						stringstream sc;
						sc << score;
						sc >> scr;

						stringstream st;
						st << 2 - tryAgain;
						st >> tries;
						triesText.setString("    Attempts left: " + tries);
						renderWindow.draw(text);
						renderWindow.draw(scoreText);

						if (Keyboard::isKeyPressed(Keyboard::Space) &&player.canJ())
							jump.play();

						deltaTime = clock.restart().asSeconds();

						if (deltaTime > 1.0f / 20.0f)
						{
							deltaTime = 1.0f / 20.0f;
						}
						while (renderWindow.pollEvent(event))
						{
							switch (event.type)
							{
							case Event::Closed:
							{renderWindow.close();
							music.stop();
							if (sh3bi)
								lvl2music.stop();
							break; }
							case Event::Resized:
							{ResizeView(renderWindow, view);
							break; }
							}

						}


						Vector2f direction;
						dogAnimation.Update(0, deltaTime, true);
						catAnimation.Update(0, deltaTime, false);
						ratAnimation.Update(0, deltaTime, true);
						coinAnimation.Update(0, deltaTime, true);
						cat1Animation.Update(0, deltaTime, true);


						player.Update(deltaTime);

						if (player.GetPosition().x < 1712.33)
							checkpoint = 20;

						if (player.GetPosition().x >= 1712.33)
							checkpoint = 1712.33;

						if (player.GetPosition().x >= 3898.99)
							checkpoint = 3898.99;

						if (player.GetPosition().x >= 5000)
							checkpoint = 4900;

						if (player.GetPosition().x >= 1712.33)
							playerCheck1 = false;

						if (player.GetPosition().x >= 3898.88)
							playerCheck2 = false;




						if (trash.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (trash1.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (trash2.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (trash3.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (trash4.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (trash5.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (trash6.GetCollider().CheckCollision(player.GetCollider(), direction, push))
						{
							if (player.GetPosition().y < ground)push = 1;
							else push = 0.5;
							if (trash6.GetPosition().x >= trash7.GetPosition().x - 40)
								push = 1;
							player.onCollision(direction);
						}
						if (trash7.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (trash8.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (trash9.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (trash10.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (trash11.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}

						if (Keyboard::isKeyPressed(Keyboard::Z)) //testing please dont touch!
						{
							player.SetPosition(Vector2f(5000, ground));
						}

						paltform2.GetCollider().CheckCollision(player.GetCollider(), direction, 0.0f);
						if (rock1.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f) ||
							rock2.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f) ||
							rock3.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f) ||
							rock4.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f) ||
							rock5.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}
						if (floor.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
						{
							player.onCollision(direction);
						}

						if (player.GetPosition().x <= 4907 && player.GetPosition().x >= 9.2)
						{
							view.setCenter(player.GetPosition().x, 0);
						}


						renderWindow.clear();
						if (player.GetPosition().x <= 5326.35)
						{
							renderWindow.draw(BG);
							renderWindow.draw(BG1);
							renderWindow.draw(BG2);
							renderWindow.draw(BG3);
							renderWindow.draw(BG4);
							renderWindow.draw(BG5);
							renderWindow.draw(BG6);
							renderWindow.draw(BG7);
							renderWindow.draw(BG8);
							renderWindow.draw(BG9);
							renderWindow.draw(moove);
							renderWindow.draw(sprint);
							renderWindow.draw(juump);
							renderWindow.draw(mudshape);
							renderWindow.draw(hole);
						}


						renderWindow.setView(view);
						if (player.GetPosition().x <= 5326.35)
						{
							player.Draw(renderWindow);
							rock1.Draw(renderWindow);
							rock2.Draw(renderWindow);
							rock3.Draw(renderWindow);
							rock4.Draw(renderWindow);
							rock5.Draw(renderWindow);
						}

						dog.setTextureRect(dogAnimation.uvRect);
						dog1.setTextureRect(dogAnimation.uvRect);
						cat.setTextureRect(catAnimation.uvRect);
						rat.setTextureRect(ratAnimation.uvRect);
						cat1.setTextureRect(cat1Animation.uvRect);

						for (int i = 1; i < 19; i++)
							coins[i].setTextureRect(coinAnimation.uvRect);

						renderWindow.draw(text);
						renderWindow.draw(scoreText);

						for (int i = 1; i < 19; i++)
						{
							if (coinFlags[i] == true)
							{
								if (abs(player.GetPosition().x - coins[i].getPosition().x) <= 25 && abs(player.GetPosition().y - coins[i].getPosition().y) <= 25)
								{
									coincollect.play();
									score += 50;
									coinFlags[i] = false;
								}
								renderWindow.draw(coins[i]);
							}
						}
						if (player.GetPosition().x >= 900)
							go = true;
						if (go && player.GetPosition().x <= 5326.35)
						{
							dog1.move(-180 * deltaTime, 0.0f);
							dog.move(-180 * deltaTime, 0.0f);
							cat.move(250 * deltaTime, 0.0f);
						}
						if (player.GetPosition().x >= 4050 && player.GetPosition().x <= 5326.35)
						{
							rat.move(+180 * deltaTime, 0.0f);
							renderWindow.draw(rat);
						}
						if (player.GetPosition().x >= 764.458)
							cat1go = true;

						if (cat1go)
						{
							cat1.move(-150 * deltaTime, 0.0f);
						}
						if (player.GetPosition().x <= 5326.35)
						{
							renderWindow.draw(dog);
							renderWindow.draw(dog1);
							renderWindow.draw(cat);
							renderWindow.draw(cat1);
						}
						if
							(
								abs(cat1.getPosition().x - player.GetPosition().x) < 20 && abs(cat1.getPosition().y - player.GetPosition().y) < 20
								||
								abs(cat.getPosition().x - player.GetPosition().x) < 20 && abs(cat.getPosition().y - player.GetPosition().y) < 20
								||
								abs(dog.getPosition().x - player.GetPosition().x) < 20 && abs(dog.getPosition().y - player.GetPosition().y) < 20
								||
								abs(dog1.getPosition().x - player.GetPosition().x) < 20 && abs(dog1.getPosition().y - player.GetPosition().y) < 20
								|| abs(water.getPosition().x - player.GetPosition().x) < 40 && abs(water.getPosition().y - player.GetPosition().y) < 40 && watergo == true && waterDmg == false
								||
								abs(water2.getPosition().x - player.GetPosition().x) < 40 && abs(water2.getPosition().y - player.GetPosition().y) < 40 && watergo2 == true && waterDmg2 == false
								||
								abs(water3.getPosition().x - player.GetPosition().x) < 40 && abs(water3.getPosition().y - player.GetPosition().y) < 40 && watergo3 == true && waterDmg3 == false
								||
								abs(water.getPosition().x - player.GetPosition().x) < 40 && abs(water.getPosition().y - player.GetPosition().y) < 40 && watergo == true && waterDmg == false
								||
								abs(trashBag.getPosition().x - player.GetPosition().x) < 20 && abs(trashBag.getPosition().y - player.GetPosition().y) < 20
								||
								abs(trashBag1.getPosition().x - player.GetPosition().x) < 20 && abs(trashBag1.getPosition().y - player.GetPosition().y) < 20
								||
								abs(trashBag2.getPosition().x - player.GetPosition().x) < 20 && abs(trashBag2.getPosition().y - player.GetPosition().y) < 20
								||
								abs(trashBag3.getPosition().x - player.GetPosition().x) < 20 && abs(trashBag3.getPosition().y - player.GetPosition().y) < 20
								||
								abs(trashBag4.getPosition().x - player.GetPosition().x) < 20 && abs(trashBag4.getPosition().y - player.GetPosition().y) < 20
								||
								abs(trashBag5.getPosition().x - player.GetPosition().x) < 20 && abs(trashBag5.getPosition().y - player.GetPosition().y) < 20
								||
								abs(rat.getPosition().x - player.GetPosition().x) < 10 && abs(rat.getPosition().y - player.GetPosition().y) < 30
								||
								player.GetPosition().x >= 4000 && player.GetPosition().x <= 4050 && player.GetPosition().y > ground
								)
						{
							if (abs(water.getPosition().x - player.GetPosition().x) < 40 && abs(water.getPosition().y - player.GetPosition().y))
							{
								waterDmg = true;
							}
							if (abs(water2.getPosition().x - player.GetPosition().x) < 40 && abs(water2.getPosition().y - player.GetPosition().y))
							{
								waterDmg2 = true;
							}
							if (abs(water3.getPosition().x - player.GetPosition().x) < 40 && abs(water3.getPosition().y - player.GetPosition().y))
							{
								waterDmg3 = true;
							}
							if (Keyboard::isKeyPressed(Keyboard::D))
								player.SetPosition(Vector2f(player.GetPosition().x - 50, player.GetPosition().y));
							else
								player.SetPosition(Vector2f(player.GetPosition().x + 50, player.GetPosition().y));

							if (lives.size() > 0)
							{
								dmgbuff.play();
								lives.pop_back();
							}
							time = 0;
						}



						if (lives.size() == 0)
						{
							paused = true;
							gameover.play();
							if (sh3bi)
								lvl2music.stop();
							music.stop();
							if (sh3bi)
								music.stop();
							RenderWindow loseWindow(VideoMode(1280, 800), "Mar3i");
							while (loseWindow.isOpen())
							{
								loseWindow.clear();
								loseWindow.draw(deathmenu1);

								loseWindow.draw(triesText);
								loseWindow.draw(playAgainText);
								if (Keyboard::isKeyPressed(Keyboard::Y) && tryAgain <= 1)
								{
									if (!sh3bi)
										music.play();
									tryAgain++;
									if (sh3bi && player.GetPosition().x >= 5320.14)
										lvl2music.play();
									lives.push_back(live1);
									paused = false;
									if (!lvl2bool)
										player.SetPosition(Vector2f(checkpoint, ground));
									else {
										car.setPosition(5080.91, 16);
									}
									loseWindow.close();
								}
								if (Keyboard::isKeyPressed(Keyboard::Escape))
								{
									renderWindow.close();
									loseWindow.close();
									break;
								}
								loseWindow.display();
							}
						}
						t = sahyana.restart().asSeconds();
						if (time < 2.20 - 1)
						{
							time += t;
							dmg.setPosition(player.GetPosition().x - 48, 0);
							renderWindow.draw(dmg);
						}
						for (int i = 0; i < lives.size(); i++)
						{

							if (player.GetPosition().x <= 4880)
								lives[i].setPosition(player.GetPosition().x + 230 - ct, -250);

							ct += 20;
						}
						if (ct == lives.size() * 20)
						{
							ct = 0;
						}
						for (int i = 0; i < lives.size(); i++)
						{
							renderWindow.draw(lives[i]);
						}
						if (abs(extraLife.getPosition().x - player.GetPosition().x) < 30 && abs(extraLife.getPosition().y - player.GetPosition().y) < 30 && extraLifeFlag)
						{
							health.play();
							if (lives.size() == 2)
							{
								lives.push_back(live3);
							}
							else if (lives.size() == 1)
							{
								lives.push_back(live2);
							}

							extraLifeFlag = false;
						}
						if (player.GetPosition().x >= 680 && water.getPosition().y <= 17.4526)
							watergo = true;

						if (water.getPosition().y > 17.5)
							watergo = false;

						if (watergo)
						{
							renderWindow.draw(water);
							water.move(0, 300 * deltaTime);
						}


						if (water.getPosition().y >= 10 && water.getPosition().y <= 11)
							c.restart().asSeconds();

						if (water.getPosition().y >= 10 && s < 1.1)
						{
							ti = c.getElapsedTime();
							s = ti.asSeconds();
							renderWindow.draw(splash);
						}
						if (player.GetPosition().x >= 1772.8 && water2.getPosition().y <= 17.4526)
							watergo2 = true;
						if (player.GetPosition().x >= 2895.95 && water3.getPosition().y <= 17.4526)
							watergo3 = true;

						if (water2.getPosition().y > 17.5)
							watergo2 = false;
						if (water3.getPosition().y > 17.5)
							watergo3 = false;

						if (watergo2)
						{
							renderWindow.draw(water2);
							water2.move(0, 300 * deltaTime);
						}
						if (watergo3)
						{
							renderWindow.draw(water3);
							water3.move(0, 305 * deltaTime);
						}


						if (water2.getPosition().y >= 10 && water2.getPosition().y <= 11)
							d.restart().asSeconds();

						if (water2.getPosition().y >= 10 && l < 1.1)
						{
							di = d.getElapsedTime();
							l = di.asSeconds();
							renderWindow.draw(splash2);
						}

						if (water3.getPosition().y >= 10 && water3.getPosition().y <= 11)
							d1.restart().asSeconds();

						if (water3.getPosition().y >= 10 && l1 < 1.1)
						{
							di1 = d1.getElapsedTime();
							l1 = di1.asSeconds();
							renderWindow.draw(splash3);
						}


						text.setString("Lecture starts in: " + number);
						if (s2 <= 0)
						{
							paused = true;
							gameover.play();
							music.stop();
							RenderWindow loseWindow(VideoMode(1280, 800), "Mar3i");
							while (loseWindow.isOpen())
							{
								loseWindow.clear();

								loseWindow.draw(deathmenu2);
								loseWindow.draw(triesText);
								loseWindow.draw(playAgainText);

								if (Keyboard::isKeyPressed(Keyboard::Y) && tryAgain <= 1)
								{
									if (!sh3bi)
										music.play();
									if (sh3bi)lvl2music.play();
									tryAgain++;
									s2 = c2.restart().asSeconds();
									paused = false;

									if (!lvl2bool)
										player.SetPosition(Vector2f(checkpoint, ground));
									else {
										car.setPosition(5080.91, 16);
									}
									loseWindow.close();
								}

								if (Keyboard::isKeyPressed(Keyboard::Escape))
								{
									renderWindow.close();
									loseWindow.close();
									break;
								}
								loseWindow.display();
							}


						}
						if (player.GetPosition().x <= 4880)
						{
							text.setPosition(player.GetPosition().x - 50, -250);
							scoreText.setPosition(player.GetPosition().x - 200, -250);
						}
						scoreText.setString("Coins: " + scr);
						if (player.GetPosition().x <= 5326.35)
						{
							trash.Draw(renderWindow);
							trash1.Draw(renderWindow);
							trash2.Draw(renderWindow);
							trash3.Draw(renderWindow);
							trash4.Draw(renderWindow);
							trash5.Draw(renderWindow);
							trash6.Draw(renderWindow);
							trash7.Draw(renderWindow);
							trash8.Draw(renderWindow);
							trash9.Draw(renderWindow);
							trash10.Draw(renderWindow);
							trash11.Draw(renderWindow);
							renderWindow.draw(trashBag);
							renderWindow.draw(trashBag1);
							renderWindow.draw(trashBag2);
							renderWindow.draw(trashBag3);
							renderWindow.draw(trashBag4);
							renderWindow.draw(trashBag5);

							if (!playerCheck1)
								renderWindow.draw(check22);
							if (!playerCheck2)
								renderWindow.draw(check2);

							if (playerCheck1)
								renderWindow.draw(check1);
							if (playerCheck2)
								renderWindow.draw(check11);


							if (extraLifeFlag)
								renderWindow.draw(extraLife);
						}
						if (player.GetPosition().x >= 5319.01 && lvl2Timer <= 3)
						{
							lvl2bool = true;
							music.stop();
							if (beepbool)
							{
								lvl2begin.play();
								beepbool = false;
							}
							if (lvl2Timer == 0)
							{
								lvl2Clock.restart().asSeconds();
							}
							lvl2Time = lvl2Clock.getElapsedTime();

							lvl2Timer = lvl2Time.asSeconds();
							renderWindow.draw(lvl2);
						}
						if (player.GetPosition().x >= 5319.01 && lvl2Timer >= 3 && car.getPosition().y > -20000)
						{
							if (!sh3bi)
							{
								lvl2begin.stop();
								lvl2music.play();
								sh3bi = true;
							}
							renderWindow.draw(level2Bg);
							renderWindow.draw(level2Bg2);
							renderWindow.draw(level2Bg3);
							renderWindow.draw(level2Bg4);
							renderWindow.draw(level2Bg5);
							renderWindow.draw(level2Bg6);
							renderWindow.draw(level2Bg7);
							renderWindow.draw(level2Bg8);
							renderWindow.draw(level2Bg9);

							taxiBG2.Draw(renderWindow);
							taxiBG3.Draw(renderWindow);
							taxiBG4.Draw(renderWindow);
							BUSBG2.Draw(renderWindow);
							bus_1_BG1.Draw(renderWindow);
							sideTaxiBG2.Draw(renderWindow);
							sidebusBG3.Draw(renderWindow);
							movingBusBG6.Draw(renderWindow);
							BUSBG6.Draw(renderWindow);
							sideTaxiBG6.Draw(renderWindow);
							busBG7.Draw(renderWindow);
							comingTaxiBG9.Draw(renderWindow);
							comingBusBG9.Draw(renderWindow);
							sideBusBG8.Draw(renderWindow);
							busBG8.Draw(renderWindow);
							sideBus2BG8.Draw(renderWindow);
							taxi_1_BG9.Draw(renderWindow);
							bus_1_BG9.Draw(renderWindow);
							bigbus_1_BG9.Draw(renderWindow);
							t3ala_taxi_1_BG10.Draw(renderWindow);
							bus_1_BG10.Draw(renderWindow);
							bus_2_BG10.Draw(renderWindow);
							renderWindow.draw(car);

							view.setCenter(4907, car.getPosition().y);

							car.move(0.0f, -carSpeed);

							for (int i = 0; i < lives.size(); i++)
							{
								lives[i].setPosition(5120.35 - ct, -270 + car.getPosition().y);
								ct += 20;
							}
							if (ct == lives.size() * 20)
							{
								ct = 0;
							}


							if (carSpeed <= double(70 * deltaTime))
							{
								carSpeed += double(4 * deltaTime);
							}
							if (Keyboard::isKeyPressed(Keyboard::D) && car.getPosition().x <= 5151.67)
							{
								car.move(double(120 * deltaTime), 0);
							}
							if (Keyboard::isKeyPressed(Keyboard::A) && car.getPosition().x >= 4994.88)
							{
								car.move(double(-120 * deltaTime), 0);
							}

							if (Keyboard::isKeyPressed(Keyboard::S))
							{

								if (carSpeed > 0 * (double)deltaTime)
									carSpeed -= double(3.05 * deltaTime);
							}

							bus_1_BG1.Move(Vector2f(0, double(-40 * deltaTime)));
							if (car.getPosition().y < -873.194)
							{
								sideCar1 = true;
							}
							if (sideCar1 == true)
							{
								sideCar1 = false;
								sideTaxiBG2.Move(Vector2f(245 * deltaTime, 0));
							}
							if (car.getPosition().y < -1488.06)
							{
								movingBusBG6.Move(Vector2f(0, 200 * deltaTime));
							}
							if (car.getPosition().y < -2790.14)
							{
								sideTaxiBG6.Move(Vector2f(-235 * deltaTime, 0));
							}
							if (car.getPosition().y < -4149.65)
							{
								comingBusBG9.Move(Vector2f(0, 275 * deltaTime));
							}
							if (car.getPosition().y < -3760.81)
								comingTaxiBG9.Move(Vector2f(0, 275 * deltaTime));
							if (car.getPosition().y < -4000)
							{
								sideBus2BG8.Move(Vector2f(130 * deltaTime, 0));
								sideBusBG8.Move(Vector2f(-130 * deltaTime, 0));

							}
							if (car.getPosition().y < -4368.48)
							{
								taxi_1_BG9.Move(Vector2f(0, 290 * deltaTime));
							}
							if (car.getPosition().y < -4609.82)
							{
								bigbus_1_BG9.Move(Vector2f(0, 120 * deltaTime));
							}
							if (car.getPosition().y < -4756.07)
							{
								t3ala_taxi_1_BG10.Move(Vector2f(0, 290 * deltaTime));
							}
							if (car.getPosition().y < -4588.48 && stop2 == false)
							{
								if (bus_1_BG10.GetPosition().y < -5469.21)
									stop2 = true;
								bus_1_BG10.Move(Vector2f(0, -70 * deltaTime));
							}

							if (car.getPosition().y < -4588.48 && stop == false)
							{
								if (bus_2_BG10.GetPosition().y < -5449.67)
									stop = true;
								bus_2_BG10.Move(Vector2f(0, -35 * deltaTime));
							}

							text.setPosition(4850.35, -270 + car.getPosition().y);
							scoreText.setPosition(4700.35, -270 + car.getPosition().y);
							if (car.getPosition().y <= -5266)
							{
								view.setCenter(4907, -5268);
								text.setPosition(4850.35, -5537);
								scoreText.setPosition(4700.35, -5537);
								for (int i = 0; i < lives.size(); i++)
								{
									lives[i].setPosition(5120.35 - ct, -5535);
									ct += 20;
									//renderWindow.draw(lives[i]);
								}
							}
							if (ct == lives.size() * 20)
							{
								ct = 0;
							}
							for (int i = 0; i < lives.size(); i++)
							{
								renderWindow.draw(lives[i]);
							}

							renderWindow.setView(view);


							if (
								sideTaxiBG2.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								taxiBG2.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								BUSBG2.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								taxiBG3.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								taxiBG4.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								sidebusBG3.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								movingBusBG6.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								BUSBG6.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								sideTaxiBG6.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								busBG7.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								comingTaxiBG9.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								comingBusBG9.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								busBG8.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								sideBusBG8.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								sideBus2BG8.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								taxi_1_BG9.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								bus_1_BG9.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								bigbus_1_BG9.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								t3ala_taxi_1_BG10.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								bus_1_BG10.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								bus_2_BG10.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								||
								bus_1_BG1.GetCollider().CheckCollision(getCollider(), direction, 1.0f)
								)
							{
								if (lives.size() > 0)
								{
									lives.pop_back();
								}
								time = 0;
								carSpeed = 0;

								car.setPosition(car.getPosition().x, car.getPosition().y + 50);
								if (Keyboard::isKeyPressed(Keyboard::S))
									car.setPosition(car.getPosition().x, car.getPosition().y - 100);
								carhit.play();
							}


							if (time < 2.20 - 1)
							{
								time += t;
								dmg.setPosition(5070.35 - 220, car.getPosition().y);
								renderWindow.draw(dmg);
							}

							renderWindow.draw(text);
							renderWindow.draw(scoreText);

						}
						if (Keyboard::isKeyPressed(Keyboard::X)) //testing please dont touch!
							cout << player.GetPosition().x << " " << player.GetPosition().y << " ";
						if (car.getPosition().y < -5772.49 && setscore == false)
						{
							name = true;
							renderWindow.close();
						}
						renderWindow.display();
					}
				}
			}
			else if (pagenumber == 3)
				break;
		}
		if (name)
		{


			RenderWindow name(VideoMode(600, 300), "Mar3i");
			Event nameevent;
			while (name.isOpen())
			{
				while (name.pollEvent(nameevent))
				{
					name.clear();
					name.draw(playerText);
					if (nameevent.type == Event::TextEntered)
					{
						playerInput += nameevent.text.unicode;
						playerText.setString("Type your name: " + playerInput);
						playerName.setString(playerInput);
					}
					name.draw(playerText);
					if (nameevent.key.code == Keyboard::Return)
					{
						setscore = true;
						name.close();
					}
				}
				name.clear();
				name.draw(playerText);
				name.display();
			}
		}
		if (setscore)
		{
			calculatescore(score, s2);
			stringstream  hscore;
			hscore << Highscore;
			hscore >> hscorestring;
			RenderWindow scorewindow(VideoMode(1024, 768), "Mar3i");
			while (scorewindow.isOpen())
			{
				while (scorewindow.pollEvent(scoreevent))
				{
					switch (scoreevent.type)
					{
					case Event::Closed:
					{
						scorewindow.close();
						kfaya = true;
						break;
					}
					}

				}
				lvl2music.stop();
				scorewindow.clear();
				Highscoretext.setString("Your Score: " + hscorestring);
				scorewindow.draw(scoreboardshape);
				scorewindow.draw(Highscoretext);
				scorewindow.draw(playerName);
				scorewindow.display();
			}
		}
		if (kfaya)
			break;
	}

}
