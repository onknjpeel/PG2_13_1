#pragma once
#include "Vector2.h"
class Bullet
{
public:
	Vector2 pos_;
	float speed_;
	float radius_;
	bool isShot_;

public:
	Bullet(Vector2 pos,float speed,float radius,bool isShot);
	~Bullet();
	void Move();
	void Draw();
};

