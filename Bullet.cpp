#include "Bullet.h"
#include "Novice.h"

Bullet::Bullet(Vector2 pos, float speed, float radius, bool isShot)
{
	pos_ = pos;
	speed_ = speed;
	radius_ = radius;
	isShot_ = isShot;
}

Bullet::~Bullet()
{
}

void Bullet::Move()
{
	pos_.y -= speed_;
}

void Bullet::Draw()
{
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, WHITE, kFillModeSolid);
}
