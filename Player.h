#pragma once
#include "Vector2.h"
#include "Bullet.h"
class Player
{
public:
	Bullet* bullet_[10];
	Vector2 pos_;
	float speed_;
	float radius_;

public:
	Player(Vector2 pos,float speed,float radius);
	~Player();
	void Move(const char* keys);
	void Draw();
};

