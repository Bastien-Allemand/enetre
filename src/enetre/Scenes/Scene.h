#pragma once
#include "../Obj/Entity.h"
class Scene
{
	std::vector<Entity*> m_entities;
public:
	template<class T>
	T* GetEntity();
	template<class T>
	void AddEntity();
	template<class T>
	void removeEntitybytype();

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
};

