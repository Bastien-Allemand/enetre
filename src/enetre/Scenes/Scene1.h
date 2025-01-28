#pragma once

#include "Scene.h"

class Scene1 : public Scene
{
	std::vector<Entity*> m_entities;
public:
	Scene1();
	~Scene1();
	void addEntity(Entity* _entity);
	void Init() override;
	void Update() override;
	void Render() override;
	void Destroy() override;
};

