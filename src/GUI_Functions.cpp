/*
 *   Copyright (C) 2011, 2012 Marko Stanić
 *   Copyright (C) 2014 QuadAssault contributors    
 *
 *   This file is part of QuadAssault.
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with This program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "GUI_Functions.h"

GameState* gameState;

void SetupLightGUI()
{
    gameState->SetupLight();
}

void SetupTriggerGUI()
{
    gameState->SetupMobTrigger();
}

void GameState::SetupLight()
{
    if(lightSet==false)
	{
        lightSet=true;
        light=GetLight(true);
        light->Init(mousePos, 128, this);
        light->Postavke(Vec3(1.0, 1.0, 1.0), 8);
	}
}

void GameState::SetupMobTrigger()
{
    if(mobTriggerSet==0)
	{		
        mobTriggerSet=1;
        triggers.push_back(new Trigger());
	}
}

void GenerateEmptyLevelGUI()
{
    gameState->GenerateEmptyLevel();
}

void SaveLevelGUI()
{
    gameState->SaveBlocks();
}
