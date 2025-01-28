#pragma once

#include "Scene.h"
#include "../Obj/Player.h"

class Scene1 : public Scene
{

public:
	Scene1();
	void addEntity(Entity* _entity);
	template<class T>
	T* GetEntity();
	template<class T>
	std::vector<T*> GetAllEntity();
	template<class T>
	void removeEntitybytype();
	void Init() override;
	void Update(float _dt) override;
	void Render() override;
	void Destroy() override;
};


