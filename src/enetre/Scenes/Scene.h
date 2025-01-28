#pragma once
#include <vector>
#include "../Obj/Entity.h"
#include "SFML/Graphics.hpp"


class Scene
{
public:
	std::vector<Entity*> m_entities;
	template<class T>
	T* GetEntity();
	template<class T>
	void AddEntity();
	template<class T>
	void removeEntitybytype();

	virtual void Init() = 0;
	virtual void Update(float _dt) = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
};
