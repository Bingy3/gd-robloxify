#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>

// roblox logo

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		auto title = this->getChildByID("main-title");
		auto newTitle = CCMenuItemSprite::create(
			CCSprite::createWithSpriteFrameName("roblox-logo.png"_spr),
			nullptr,
			nullptr
		);

		title->setVisible(false);

		newTitle->setID("new-title");
		newTitle->setPosition(title->getPosition());
		newTitle->setScale(1.5);

		this->addChild(newTitle);

		return true;
	}
};
