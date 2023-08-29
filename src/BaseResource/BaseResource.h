#pragma once //include guards
#include "../header.h"

/*class BaseResource {
    public:
        BaseResource();
        virtual bool loadFromFile(const std::string& path = "");
        ~BaseResource();
};

class TextureLoad : public BaseResource {
    public:
        TextureLoad() : BaseResource() {};
        sf::Texture texture;
        
        bool loadFromFile(const std::string& path) override {
            return texture.loadFromFile(path);
        }

        ~TextureLoad();
};

class ImageLoad : public BaseResource {
    public:
        ImageLoad() : BaseResource() {};
        sf::Image image;

        bool loadFromFile(const std::string& path) override {
            return image.loadFromFile(path);
        }
};

class BufferLoad : public BaseResource {
    public:
        BufferLoad() : BaseResource() {};
        sf::SoundBuffer buffer;

        bool loadFromFile(const std::string& path) override {
            return buffer.loadFromFile(path);
        }

        ~BufferLoad();
};

class MusicLoad : public BaseResource {
    public:
        MusicLoad() : BaseResource() {};
        sf::Music music;

        bool loadFromFile(const std::string& path) override {
            return music.openFromFile(path);
        }

        ~MusicLoad();
};

class CursorLoad : public BaseResource {
    public:
        CursorLoad() : BaseResource() {};
        sf::Cursor::Type cursor_arrow;

        sf::Cursor::Type loadCursorArrow() {
            return sf::Cursor::Arrow;
        }

        sf::Cursor::Type loadCursorHand() {
            return sf::Cursor::Hand;
        }
    
        ~CursorLoad();
};*/