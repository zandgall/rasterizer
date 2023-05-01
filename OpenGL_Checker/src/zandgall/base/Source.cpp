/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                  PROJECT TEMPLATE v0.0.7
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This is an C++ OpenGL Project template
Project specific code files go into a seperate folder (or just filter if desired),
renamed to whatever the project is, of course.
Any framework can be kept in the "base" folder, these can
later be added to the Project Template for use in future
projects.

Cheers! Happy Coding!
    ~ Zandgall
*/

#define GLM_FORCE_SWIZZLE
#include "glhelper.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <stb_image_write.h>

#include <stb_easy_font.h>
#include "handler.h"
#include <thread>
#include "../application/App.h"

int main(const char* args) {
    START_OPEN_GL(4, 6, "OpenGL Template", 1000, 1000);
    _addGLObject("default shader", loadShader("res/shaders/shader.shader"));
    glUseProgram(_getGLObject("default shader"));

    uniVec("col", glm::vec3(1, 0, 0));
    // VAO definitions
    float vertices[] = {
        0, -5, -5, 1, 0,
        4, 4, -5, 0, 1,
        -2, 2, -2, 1, 1
    };
    float vertices2[] = {
        -4, -5, -5, 1, 0,
        0.4, 0.5, -0.5, 1, 1,
        -4,  4, -5, 0, 1
    };
    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 2,   // first triangle
    };
    _addGLObject("Square VAO", 0);
    _addGLObject("Square VBO", 0);
    _addGLObject("Square EBO", 0);
    createVAO(&GLOBAL_GL_OBJECTS["Square VAO"]);
    createVBO(&GLOBAL_GL_OBJECTS["Square VBO"], vertices, sizeof(vertices));
    createEBO(&GLOBAL_GL_OBJECTS["Square EBO"], indices, sizeof(indices));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));

    _addGLObject("Square VAO2", 0);
    _addGLObject("Square VBO2", 0);
    _addGLObject("Square EBO2", 0);
    createVAO(&GLOBAL_GL_OBJECTS["Square VAO2"]);
    createVBO(&GLOBAL_GL_OBJECTS["Square VBO2"], vertices2, sizeof(vertices2));
    createEBO(&GLOBAL_GL_OBJECTS["Square EBO2"], indices, sizeof(indices));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    using fps60 = std::chrono::duration<int64_t, std::ratio<1, 60>>;
    using clock = std::chrono::high_resolution_clock;
    auto currentTime = clock::now() - fps60{1}, frame_next = clock::now() + fps60{1};
    double delta = 0, fps_last = glfwGetTime(), frame_start = glfwGetTime();
    int frames = 0, fps = 0;


    App app = App();
    // Main game loop
    while (!glfwWindowShouldClose(WINDOW)) {
        currentTime = clock::now();
        frame_next += fps60{1};

        double currentGLFWTime = glfwGetTime();
        delta = currentGLFWTime - frame_start;
        frame_start = currentGLFWTime;
        //std::cout << "Delta: " << delta << std::endl;
        if (delta < 0.01)
            frame_next = currentTime + fps60{ 1 };
        frames++;
        if (currentGLFWTime - fps_last >= 1) {
            std::cout << frames << " fps" << std::endl;
            fps = frames;
            frames = 0;
            fps_last = currentGLFWTime;
        }
        
        //Tick
        app.tick(delta);
        //Render
        if(WINDOW_WIDTH !=0 && WINDOW_HEIGHT != 0)
            app.render();

        glfwSwapBuffers(WINDOW);
        std::copy(keys, &keys[GLFW_KEY_LAST-1], pKeys);
        glfwPollEvents(); 

        std::this_thread::sleep_until(frame_next);
    }

    glfwTerminate();
    return 0;
}