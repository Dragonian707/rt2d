#ifndef BUTTON_H
#define BUTTON_H

#include <rt2d/entity.h>
#include <rt2d/text.h>

#include <functional>

class Button : public Entity {
public:
	Button(std::string ButtonText);
	virtual ~Button();

	virtual void update(float deltaTime);

	Text* textbox;

	void setCallbackFunction(std::function<void()> CallbackFunction);
	void Disable();
	void Enable();

private:
	int ButtonState;
	//int SpriteFrame;

	std::function<void()> _CallbackFunction;
};

#endif /* Button_H */
