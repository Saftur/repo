//------------------------------------------------------------------------------
//
// File Name:	BehaviorSpaceship.h
// Author(s):	Doug Schilling (dschilling), Jeremy Kings (j.kings)
// Project:		MyGame
// Course:		CS230S17
//
// Copyright � 2017 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "Behavior.h"

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Consts:
//------------------------------------------------------------------------------

// An example of the enums to be defined in BehaviorSpaceship.cpp.
#if 0
enum ShipState
{
	cSpaceshipInvalid,
	cSpaceshipIdle,
	cSpaceshipThrust,
	cSpaceshipDead,
};
#endif

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

class BehaviorSpaceship
{
public:
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	// Dynamically allocate a new (Spaceship) behavior component.
	// Params:
	//  parent = The object that owns this behavior.
	BehaviorSpaceship(GameObject& parent);

private:
	//------------------------------------------------------------------------------
	// Private Functions:
	//------------------------------------------------------------------------------

	// Copy an existing spaceship behavior component.
	// Params:
	//  other  = The behavior being copied.
	//  parent = The object that owns this behavior.
	BehaviorSpaceship(const Behavior& other, GameObject& parent);

	// The collision handling function for bullets, except it handles collisions as though it was a spaceship as a meme.
	// Params:
	//	 bullet = The bullet object.
	//	 other = The object the bullet is colliding with.
	static void CollisionHandler(GameObject& bullet, GameObject& other);

	// Clone an advanced behavior and return a pointer to the cloned object.
	// Params:
	//   behavior = Reference to the behavior that will be destroyed.
	//   parent = A reference to the parent object (the object that owns this component).
	// Returns:
	//   A pointer to an advanced behavior.
	static Behavior* Clone(const Behavior& behavior, GameObject& parent);

	// Destroy an advanced behavior.
	// Params:
	//   behavior = Reference to the behavior that will be destroyed.
	static void Destroy(Behavior& behavior);

	// Initialize the current state of the behavior component.
	// (Hint: Refer to the lecture notes on finite state machines (FSM).)
	// Params:
	//	 behavior = Pointer to the behavior component.
	static void Init(Behavior& behavior);

	// Update the current state of the behavior component.
	// (Hint: Refer to the lecture notes on finite state machines (FSM).)
	// Params:
	//	 behavior = Pointer to the behavior component.
	//	 dt = Change in time (in seconds) since the last game loop.
	static void Update(Behavior& behavior, float dt);

	// Exit the current state of the behavior component.
	// (Hint: Refer to the lecture notes on finite state machines (FSM).)
	// Params:
	//	 behavior = Pointer to the behavior component.
	//	 dt = Change in time (in seconds) since the last game loop.
	static void Exit(Behavior& behavior);

	// Calculate the rotation of the ship based on input.
	// Params:
	//	 behavior = Pointer to the behavior component.
	static void UpdateRotation(Behavior& behavior);

	// Calculate the velocity of the ship based on its direction.
	// Params:
	//   behavior = Pointer to the behavior component.
	//   dt = Change in time (in seconds) since the last game loop.
	static void UpdateVelocity(Behavior& behavior, float dt);

	// Update the weapon timer.
	// Params:
	//   behavior = Pointer to the behavior component.
	//   dt = Change in time (in seconds) since the last game loop.
	static void UpdateWeapon(Behavior& behavior, float dt);

	// Display a death effect.
	// Params:
	//	behavior = Pointer to the behavior component.
	static void UpdateDeathEffect(Behavior& behavior);
	
	// Spawn a bullet at the ship's position with velocity based on ship's direction.
	// Params:
	//   behavior = Pointer to the behavior component.
	//   dt = Change in time (in seconds) since the last game loop.
	static void SpawnBullet(Behavior& behavior);

	//------------------------------------------------------------------------------
	// Private Variables:
	//------------------------------------------------------------------------------

	// Inherit the base behavior
	Behavior base;

	//------------------------------------------------------------------------------
	// Private Consts:
	//------------------------------------------------------------------------------

	static const float spaceshipAcceleration;
	static const float spaceshipSpeedMax;
	static const float spaceshipTurnRateMax;
	static const float spaceshipWeaponCooldownTime;
	static const float spaceshipWeaponBulletSpeed;
	static const float spaceshipDeathDuration;
};

//------------------------------------------------------------------------------
