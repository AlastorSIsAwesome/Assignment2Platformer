/*******************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2026 Media Design School at Strayer
File Name : [CustomLibrary.h]
Description : [Headder file for enumerators that need to be accessed by multipule classes and files]
Author : [Alastor Spear]
Mail : alastor.spear@mds.ac.nz
*******************************/

#pragma once

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ACTIVE CHARACTER ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

enum ActiveCharacter
{
    Default = 0, // default has no functionality anywhere, is assumed to be a bug
    SisterNiki,
    SisterAl
};


/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ANIMATION TYPE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

enum AnimationType
{
    Idle = 0,
    WalkingLeft,
    WalkingRight
};