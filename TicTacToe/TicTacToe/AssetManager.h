#pragma once

#include <map>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class AssetManager
{
private:
	map<string, Texture> _textures;
	map<string, Font> _fonts;

public:
	AssetManager();
	~AssetManager();

	void LoadTexture(string name, string fileName);
	Texture& GetTexture(string name);
	void LoadFont(string name, string fileName);
	Font& GetFont(string name);
};

