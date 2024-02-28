#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/binding/ProfilePage.hpp>

// buttons

class $modify(ButtonEdit, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) {return false;}
        
        auto menu = this->getChildByID("main-menu");
        // creating a new menu
        auto newMenu = CCMenu::create();

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

        home->setPosition(284, 210);
        avatar->setPosition(284, 175);
        games->setPosition(284, 140);
        settings->setPosition(284, 105);
        
        home->setID("home-button");
        avatar->setID("avatar-button");
        games->setID("discover-button");
        settings->setID("settings-button");

        newMenu->addChild(home);
        newMenu->addChild(avatar);
        newMenu->addChild(games);
        newMenu->addChild(settings);
        newMenu->setScale(1.15);

        play->setVisible(false);
        garage->setVisible(false);
        // checking for gdlite by YellowCat98
        if (!this->getChildByID("lite-button")) {
            editor->setVisible(false);
        }

        newMenu->setPosition(-5, 0);
        newMenu->setID("robloxify.menu-buttons");

        this->addChild(newMenu);

        return true;
    }
};