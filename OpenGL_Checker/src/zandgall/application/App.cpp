#include "App.h"
#include "../base/glhelper.h"
#include "../base/handler.h"

unsigned tex;
App::App() {
	tex = loadTexture("res/ry.png", GL_NEAREST, GL_NEAREST);
}

void App::tick(double delta) {
	
}

void App::render() {
	GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	uniMat("screen", glm::perspective(3.14159265f/2.0f, 1.0f, 1.0f, 10.0f)); 
	glBindVertexArray(GLOBAL_GL_OBJECTS["Square VAO"]);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(GLOBAL_GL_OBJECTS["Square VAO2"]);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}