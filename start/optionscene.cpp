/**
 * This class describes OptionScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "optionscene.h"

OptionScene::OptionScene() : Scene()
{
	_gridx = ManageScene::Xsize;
	_gridy = ManageScene::Ysize;
	_maxClicks = ManageScene::Clicks;
	_timeToBeat = ManageScene::Time;
	Xscroll = new ScrollArea;
	Yscroll = new ScrollArea;
	Clickscroll = new ScrollArea;
	Timescroll = new ScrollArea;
	Colorscroll = new ScrollArea;

	optionText = new Text;
	UpdateText();
	optionText->position = Point2(SWIDTH / 5, SHEIGHT / 8);
	optionText->scale = Point2(0.4, 0.4);
	this->addChild(optionText);

	enterX = new Button("set grid width");
	enterX->position = Point2(SWIDTH / 4, SHEIGHT / 4);
	enterX->setCallbackFunction(std::bind(&OptionScene::OpenGridWidth, this));
	this->addChild(enterX);
	Buttons.push_back(enterX);

	enterY = new Button("set grid height");
	enterY->position = Point2(SWIDTH / 4 * 3, SHEIGHT / 4);
	enterY->setCallbackFunction(std::bind(&OptionScene::OpenGridHeight, this));
	this->addChild(enterY);
	Buttons.push_back(enterY);

	enterClick = new Button("set max clicks");
	enterClick->position = Point2(SWIDTH / 4, SHEIGHT / 2);
	enterClick->setCallbackFunction(std::bind(&OptionScene::OpenClicks, this));
	this->addChild(enterClick);
	Buttons.push_back(enterClick);

	enterTime = new Button("set time amount");
	enterTime->position = Point2(SWIDTH / 4 * 3, SHEIGHT / 2);
	enterTime->setCallbackFunction(std::bind(&OptionScene::OpenTime, this));
	this->addChild(enterTime);
	Buttons.push_back(enterTime);

	enterColors = new Button("set color amount");
	enterColors->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	enterColors->setCallbackFunction(std::bind(&OptionScene::OpenColors, this));
	this->addChild(enterColors);
	Buttons.push_back(enterColors);

	exitoptions = new Button("Back");
	exitoptions->position = Point2(SWIDTH / 2, SHEIGHT / 6 * 5);
	exitoptions->setCallbackFunction(std::bind(&OptionScene::CloseOptions, this));
	this->addChild(exitoptions);
	Buttons.push_back(exitoptions);

	SetupButtons();
}


OptionScene::~OptionScene()
{
	this->removeChild(optionText);
	delete optionText;
	optionText = nullptr;

	this->removeChild(enterX);
	delete enterX;
	enterX = nullptr;

	this->removeChild(enterY);
	delete enterY;
	enterY = nullptr;

	this->removeChild(exitoptions);
	delete exitoptions;
	exitoptions = nullptr;

	for (Button* option : Xoptions)
	{
		delete option;
		option = nullptr;
	}
	for (Button* option : Yoptions)
	{
		delete option;
		option = nullptr;
	}

	if (Xscroll->parent() == NULL)
	{
		this->removeChild(Xscroll);
	}
	if (Yscroll->parent() == NULL)
	{
		this->removeChild(Yscroll);
	}
	if (Clickscroll->parent() == NULL)
	{
		this->removeChild(Clickscroll);
	}
	if (Timescroll->parent() == NULL)
	{
		this->removeChild(Timescroll);
	}
	if (Colorscroll->parent() == NULL)
	{
		this->removeChild(Colorscroll);
	}
	delete Xscroll;
	delete Yscroll;
	delete Clickscroll;
	delete Timescroll;
	delete Colorscroll;
	Xscroll = nullptr;
	Yscroll = nullptr;
	Clickscroll = nullptr;
	Timescroll = nullptr;
	Colorscroll = nullptr;
}

void OptionScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

void OptionScene::CloseOptions()
{
	ManageScene::activescene = 0;
}

void OptionScene::SetGridWidth(int width)
{
	//something to set _gridX
	std::cout << "width pressed: " << width << std::endl;
	if (width == 0)
	{
	}
	else
	{
		ManageScene::Xsize = width;
		_gridx = width;
	}
	EnableButtons();
	UpdateText();
	Xscroll->active = false;
	this->removeChild(Xscroll);
}
void OptionScene::OpenGridWidth()
{
	//something to set _gridX
	this->addChild(Xscroll);
	Xscroll->active = true;
	DisableButtons();
}

void OptionScene::SetGridHeight(int height)
{
	//something to set _gridY
	std::cout << "height pressed: " << height << std::endl;
	if (height == 0)
	{
	}
	else
	{
		ManageScene::Ysize = height;
		_gridy = height;
	}
	EnableButtons();
	UpdateText();
	Yscroll->active = false;
	this->removeChild(Yscroll);
}
void OptionScene::OpenGridHeight()
{
	//something to set _gridY
	this->addChild(Yscroll);
	Yscroll->active = true;
	DisableButtons();
}

void OptionScene::SetClicks(int amount)
{
	std::cout << "clicks pressed: " << amount << std::endl;
	if (amount == 0)
	{
	}
	else
	{
		ManageScene::Clicks = amount;
		_maxClicks = amount;
	}
	EnableButtons();
	UpdateText();
	Clickscroll->active = false;
	this->removeChild(Clickscroll);
}
void OptionScene::OpenClicks()
{
	this->addChild(Clickscroll);
	Clickscroll->active = true;
	DisableButtons();
}

void OptionScene::SetTime(int amount)
{
	std::cout << "Time pressed: " << amount << std::endl;
	if (amount == 0)
	{
	}
	else
	{
		ManageScene::Time = amount;
		_timeToBeat = amount;
	}
	EnableButtons();
	UpdateText();
	Timescroll->active = false;
	this->removeChild(Timescroll);
}
void OptionScene::OpenTime()
{
	this->addChild(Timescroll);
	Timescroll->active = true;
	DisableButtons();
}

void OptionScene::SetColors(int amount)
{
	std::cout << "Color pressed: " << amount << std::endl;
	if (amount == 0)
	{
	}
	else
	{
		ManageScene::Colors = amount;
		_colorAmount = amount;
	}
	EnableButtons();
	UpdateText();
	Colorscroll->active = false;
	this->removeChild(Colorscroll);
}
void OptionScene::OpenColors()
{
	this->addChild(Colorscroll);
	Colorscroll->active = true;
	DisableButtons();
}

void OptionScene::DisableButtons()
{
	for (Button* butt : Buttons)
	{
		this->removeChild(butt);
	}
}
void OptionScene::EnableButtons()
{
	for (Button* butt : Buttons)
	{
		this->addChild(butt);
	}
}

void OptionScene::UpdateText()
{
	std::string display = "current options: Width = ";
	display += std::to_string(_gridx);
	display += " height = ";
	display += std::to_string(_gridy);
	display += " Clicks = ";
	display += std::to_string(_maxClicks);
	display += " Time = ";
	display += std::to_string(_timeToBeat);
	optionText->message(display);
}

void OptionScene::SetupButtons()
{
	for (size_t i = 0; i <= 26; i++)
	{
		Button* option;
		if (i == 0)
		{
			option = new Button("Close");
		}
		else
		{
			option = new Button(std::to_string(i));
		}
		option->sprite()->spritescale = Point2(0.5, 0.5);
		option->setCallbackFunction(std::bind(&OptionScene::SetGridWidth, this, i));
		option->position = Point2(SWIDTH / 2, option->sprite()->size.y + i * option->sprite()->size.y);
		Xoptions.push_back(option);
		Xscroll->addChild(option);
	}
	//----------------------------------------------------------//
	for (int i = 0; i <= 12; i++)
	{
		Button* option;
		if (i == 0)
		{
			option = new Button("Close");
		}
		else
		{
			option = new Button(std::to_string(i));
		}
		option->sprite()->spritescale = Point2(0.5, 0.5);
		option->setCallbackFunction(std::bind(&OptionScene::SetGridHeight, this, i));
		option->position = Point2(SWIDTH / 2, option->sprite()->size.y + i * option->sprite()->size.y);
		Yoptions.push_back(option);
		Yscroll->addChild(option);
	}
	//----------------------------------------------------------//
	for (int i = 0; i <= 25; i++)
	{
		Button* option;
		if (i == 0)
		{
			option = new Button("Close");
		}
		else
		{
			option = new Button(std::to_string(i * 2) + " clicks");
		}
		option->sprite()->spritescale = Point2(0.5, 0.5);
		option->setCallbackFunction(std::bind(&OptionScene::SetClicks, this, (i * 2)));
		option->position = Point2(SWIDTH / 2, option->sprite()->size.y + i * option->sprite()->size.y);
		ClickOptions.push_back(option);
		Clickscroll->addChild(option);
	}
	//----------------------------------------------------------//
	for (int i = 0; i <= 25; i++)
	{
		Button* option;
		if (i == 0)
		{
			option = new Button("Close");
		}
		else
		{
			option = new Button(std::to_string(i * 10) + " seconds");
		}
		option->sprite()->spritescale = Point2(0.5, 0.5);
		option->setCallbackFunction(std::bind(&OptionScene::SetTime, this, (i * 10)));
		option->position = Point2(SWIDTH / 2, option->sprite()->size.y + i * option->sprite()->size.y);
		TimeOptions.push_back(option);
		Timescroll->addChild(option);
	}
	//----------------------------------------------------------//
	for (int i = 0; i <= 25; i++)
	{
		Button* option;
		if (i == 0)
		{
			option = new Button("Close");
		}
		else
		{
			option = new Button(std::to_string(i) + " Colors");
		}
		option->sprite()->spritescale = Point2(0.5, 0.5);
		option->setCallbackFunction(std::bind(&OptionScene::SetColors, this, i));
		option->position = Point2(SWIDTH / 2, option->sprite()->size.y + i * option->sprite()->size.y);
		ColorOptions.push_back(option);
		Colorscroll->addChild(option);
	}
}