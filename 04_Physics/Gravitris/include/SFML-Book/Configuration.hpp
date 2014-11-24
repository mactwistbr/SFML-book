#ifndef BOOK_CONFIGURATION_HPP
#define BOOK_CONFIGURATION_HPP

#include <SFML/Graphics.hpp> //Texture
#include <SFML/Audio.hpp> //SoundBuffer

#include <SFML-Book/ResourceManager.hpp> //ResourceManager
#include <SFML-Book/ActionMap.hpp> //ActionMap

namespace book
{
    class Player;
    class Configuration
    {
        public:
            Configuration() = delete;
            Configuration(const Configuration&) = delete;
            Configuration& operator=(const Configuration&) = delete;

            enum Fonts : int {Gui};
            static ResourceManager<sf::Font,int> fonts;

            enum PlayerInputs : int {
                TurnLeft,
                TurnRight,
                HardDrop,
            };

            enum Musics : int {
                Theme
            };
            static ResourceManager<sf::Music,int> musics;

            static ActionMap<int> player_inputs;

            static void initialize();

        private:
            static int _score;
            static sf::Text   _txt_score;
            static sf::Sprite _spr_life;

            static void initTextures();
            static void initFonts();
            static void initSounds();
            static void initMusics();

            static void initPlayerInputs();
    };
}
#endif