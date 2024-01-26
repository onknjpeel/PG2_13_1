#include "Player.h"
#include "Novice.h"

Player::Player(Vector2 pos, float speed, float radius)
{
	pos_ = pos;
	speed_ = speed;
	radius_ = radius;
	for (int i = 0; i < 10; i++) {
		bullet_[i] = new Bullet({ -100,-100 }, 20, 20, false);
	}
}

Player::~Player()
{
}

void Player::Move(const char* keys)
{
	if (keys[DIK_W]) {
		pos_.y -= speed_;
	}
	if (keys[DIK_S]) {
		pos_.y += speed_;
	}
	if (keys[DIK_A]) {
		pos_.x -= speed_;
	}
	if (keys[DIK_D]) {
		pos_.x += speed_;
	}
}

void Player::Draw()
{
	Novice::DrawEllipse(int(pos_.x), int(pos_.y), int(radius_), int(radius_), 0.0f, GREEN, kFillModeSolid);
}
