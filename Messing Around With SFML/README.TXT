/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [README.txt]
Description : [Readme file for the 2D platformer]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/


Win conditon art was commisioned from @mischievousemaiden on TikTok (with permission, can be provided on request).

All other assets were made by Alastor spear


CONTROLS:
WASD or arrow keys for movement (including space bar)

Press C to switch between characters

To open Debug Window, press the escape key
To reset back to last checkpoint, press R


Sister Niki Features:
- Can jump through purple platforms
- Dies in the sunlight (Vampire)

Sister Al Features
- purple platforms are treated as normal blocks for her
- Can walk through sunlight fine (She is a human)



BASIC FEATURES

Player Movement:

WASD or arrow keys for movement (including space bar)
When the S key or down arrow is pressed, the player can phase through purple platforms (regardless of character)


Enemies/Obstical:

Regular Obstical -> if player walks into it, they are reset back to the start
Sunlight -> if player has Sister Niki activated, it is treated like a regular obstical
Flowers -> Player cannot progress to next stage unless all flowers in the level have been collided with/collected

Collision Systems:
For all objects that the player may interact with, there is a collision check.
These collisions are resolved in the static class Collisions (in file Collisions.h)


Advanced Features:

Feature A: Level Loader/multipul levels
Once all flowers in a level have been collected, the player is moved to the next level. (there are 3 levels)