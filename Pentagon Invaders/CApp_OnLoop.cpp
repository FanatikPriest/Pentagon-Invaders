#include <iostream>
#include <fstream>

#include "CApp.h"
#include "MovementHandler.h"
#include "Delta.h"
#include "LoopUtils.h"
#include "Vector2f.h"
 
void CApp::OnLoop() {




	Delta::set();

	SpaceShip& player = scene->getPlayerShip();

	// TODO damage player
	
	//LoopUtils::damageShip(player, *(scene->getEnemyBullets()));
	////LoopUtils::damageShips(*(scene->getShips()), *(scene->getPlayerBullets()));
	//
	//MovementHandler::movePlayer(player);

	//player.generateVertices();

	//scene->removeUnusableObjects();

std::ofstream file;
file.open ("logs\\example.txt", std::ios_base::app);

 file << "new frame: " << scene->getEnemyBullets()->size() << std::endl;
 LoopUtils::damageShip(player, *(scene->getEnemyBullets()));
 LoopUtils::damageShips(*(scene->getShips()), *(scene->getPlayerBullets()));
 file << "after damage: " << scene->getEnemyBullets()->size() << std::endl;
 MovementHandler::movePlayer(player);
 file << "after player movement: " << scene->getEnemyBullets()->size() << std::endl;
 player.generateVertices();
 file << "after vertices generation: " << scene->getEnemyBullets()->size() << std::endl;
 scene->removeUnusableObjects();
 file << "after removing unusable: " << scene->getEnemyBullets()->size() << std::endl;
 LoopUtils::moveBullets(*scene->getEnemyBullets());
 file << "-----------" << std::endl;

 file.close();

	LoopUtils::moveBullets(*scene->getEnemyBullets());
	LoopUtils::moveBullets(*scene->getPlayerBullets());

	bulletMaker.makeBullets();

	waveMaker.startWave();
}