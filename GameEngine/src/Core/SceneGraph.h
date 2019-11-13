#pragma once
#include "GameObject.h"
#include "FileReader.h"

class SceneGraph {
private:
	std::vector<GameObject*> gameobjects;

public:
	GameObject* AddGameObject(std::string path);
};

