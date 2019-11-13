#include "SceneGraph.h"

GameObject* SceneGraph::AddGameObject(std::string path) {
	GameObject *go = FileReader::ExtractData(path);

	if (go == nullptr)
		return nullptr;

	gameobjects.push_back(go);
	return go;
}
