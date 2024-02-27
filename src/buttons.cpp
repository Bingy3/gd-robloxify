#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/binding/ProfilePage.hpp>

// buttons

class $modify(ButtonEdit, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {return false;}
        
        auto menu = this->getChildByID("main-menu");
        auto bottomMenu = this->getChildByID("bottom-menu");

        auto play = menu->getChildByID("play-button");
        auto garage = menu->getChildByID("icon-kit-button");
        auto editor = menu->getChildByID("editor-button");
        
        auto home = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Home"),
            this,
            menu_selector(MenuLayer::onPlay)
        );

        auto avatar = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Avatar"),
            this,
            menu_selector(MenuLayer::onGarage)
        );

        auto games = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Discover"),
            this,
            menu_selector(MenuLayer::onCreator)
        );

        auto settings = CCMenuItemSpriteExtra::create(
            ButtonSprite::create("Settings"),
            this,
            menu_selector(MenuLayer::onOptions)
        );

        home->setPosition(200, 50);
        avatar->setPosition(200, 15);
        games->setPosition(200, -20);
        settings->setPosition(200, -55);
        
        home->setID("home-button");
        avatar->setID("avatar-button");
        games->setID("discover-button");
        settings->setID("settings-button");

        menu->addChild(home);
        menu->addChild(avatar);
        menu->addChild(games);
        menu->addChild(settings);
        menu->setScale(1.15);

        play->removeFromParent();
        garage->removeFromParent();
        editor->removeFromParent();

        menu->setPosition(295, 220);

        return true;
    }
};