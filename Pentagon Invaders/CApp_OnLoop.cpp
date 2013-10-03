#include "CApp.h"
#include "MovementHandler.h"
#include "Delta.h"
#include "LoopUtils.h"
#include "Vector2f.h"
 
void CApp::OnLoop() {
	Delta::set();

	SpaceShip& player = scene->getPlayerShip();
	
	LoopUtils::damageShip(player, *(scene->getEnemyBullets()));
	LoopUtils::damageShips(*(scene->getShips()), *(scene->getPlayerBullets()));
	
	MovementHandler::movePlayer(player);

	player.generateVertices();

	scene->removeUnusableObjects();

	LoopUtils::moveBullets(*scene->getEnemyBullets());
	LoopUtils::moveBullets(*scene->getPlayerBullets());

	bulletMaker.makeBullets();

	waveMaker.startWave();
}