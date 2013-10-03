#include "CApp.h"
#include "MovementHandler.h"
#include "Delta.h"
#include "LoopUtils.h"
#include "Vector2f.h"
 
void CApp::OnLoop() {
	Delta::set();

	SpaceShip& player = scene->getPlayerShip();
	
	MovementHandler::movePlayer(player);

	player.generateVertices();

	scene->removeUnusableObjects();

	LoopUtils::moveBullets(*scene->getEnemyBullets());
	LoopUtils::moveBullets(*scene->getPlayerBullets());

	bulletMaker.makeBullets();

	waveMaker.startWave();
}