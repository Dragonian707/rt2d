#include <fstream>
#include <sstream>

#include "button.h"

Button::Button(std::string ButtonText) : Entity() {
	ButtonState = 0;
	//SpriteFrame = 3;
	_CallbackFunction = NULL;

	//this->addSpriteSheet("assets/button.tga", 1, 4); // divide Texture in 1x4 slices
	//this->sprite()->frame(SpriteFrame);
	this->addSprite("assets/button.tga");
	//this->sprite()->pivot = Point2(0, 0);
	this->sprite()->size = Point2(256, 64);

	//Text* line = new Text();
	textbox = new Text();
	textbox->scale = Point2(0.45f, 0.45f);
	textbox->message(ButtonText, WHITE);
	addChild(textbox);
	textbox->position.x -= (textbox->message().size() * 32 * textbox->scale.x / 2);

	std::cout << textbox->position << "  " << textbox->worldposition() << std::endl;
}

Button::~Button() {
	removeChild(textbox);
	delete textbox;
	textbox = nullptr;
}

void Button::update(float deltaTime) {

	int mousex = input()->getMouseX();
	int mousey = input()->getMouseY();

	Point2 pos = this->position;

	int left = pos.x - sprite()->size.x * 0.5f;
	int right = pos.x + sprite()->size.x * 0.5f;
	int top = pos.y - sprite()->size.y * 0.5f;
	int bottom = pos.y + sprite()->size.y * 0.5f;

	if (ButtonState != 3) {
		if (mousex > left && mousex < right && mousey > top && mousey < bottom) {
			if (input()->getMouseDown(0)) {
				//ButtonState = 2;
				//textbox->position = Point2(textbox->position.x, 32);

				if (_CallbackFunction != NULL) {
					_CallbackFunction();
				}
			}

			//if (ButtonState == 0 || input()->getMouseUp(0)) {
			//	ButtonState = 1;
			//	textbox->position = Point2(textbox->position.x, 28);
			//}
		}
		//else {
		//	ButtonState = 0;
		//	textbox->position = Point2(textbox->position.x, 28);
		//}
	}
	//else {
	//	textbox->position = Point2(textbox->position.x, 28);
	//}

	//switch (ButtonState) {
	//case 0: SpriteFrame = 3; break;	//Normal
	//case 1: SpriteFrame = 1; break;	//MouseOver
	//case 2: SpriteFrame = 2; break;	//MouseDown
	//case 3: SpriteFrame = 0; break;	//Disabled
	//}

	//this->sprite()->frame(SpriteFrame);
}

void Button::setCallbackFunction(std::function<void()> CallbackFunction) {
	_CallbackFunction = CallbackFunction;
}

void Button::Disable() {
	ButtonState = 3;
}

void Button::Enable() {
	ButtonState = 0;
}