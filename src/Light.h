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

#ifndef SVJETLO_H
#define SVJETLO_H
#include "Object.h"
#include "Shader.h"

class GameState;

class Svjetlo : public Objekt
{
private:	
	GameState* stanje;
public:

	float radius;
	float intenzitet;
	Vec3 boja;

	Vec2 smjer; //normala u kojem smjeru je svjetlo okrenuto (baterija)
	float kut; //od 0.0 do 1.0, odredjuje kut djelovanja baterije

	bool staticno;

	bool explozija;

	Svjetlo();
	~Svjetlo();
	void Init(Vec2 poz, float radius, GameState* stanje);
	void Postavke(Vec3 boja, float intenzitet);
	void PostaviExplozija(bool explozija);
	void PostavkeKuta(Vec2 smjer, float kut);
	void Update(float deltaT);
	void RenderNaFBO(Shader* s, Objekt* kamera, GLuint normalmapa);	
	void Unisti();	
	
	bool unisteno;
};

#endif