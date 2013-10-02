#include "CApp.h"
#include "KeyboardHandler.h"
 
void CApp::OnEvent(SDL_Event& event) {
	switch (event.type) {
		case SDL_QUIT: {
			Running = false;
			break;
		}
		case SDL_KEYDOWN:
		case SDL_KEYUP: {
			KeyboardHandler& keyboard = KeyboardHandler::getInstance();

			switch (event.key.keysym.scancode) {
				case SDL_SCANCODE_W: {
					keyboard.w = event.key.state;
					break;
				}
				case SDL_SCANCODE_S: {
					keyboard.s = event.key.state;
					break;
				}
				case SDL_SCANCODE_A: {
					keyboard.a = event.key.state;
					break;
				}
				case SDL_SCANCODE_D: {
					keyboard.d = event.key.state;
					break;
				}
				case SDL_SCANCODE_LEFT: {
					keyboard.left = event.key.state;
					break;
				}
				case SDL_SCANCODE_RIGHT: {
					keyboard.right = event.key.state;
					break;
				}
				case SDL_SCANCODE_ESCAPE: {
					Running = false;
					break;
				}
			}

			break;
		}
	}
}