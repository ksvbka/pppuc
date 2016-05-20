// /*
//  main

//  Copyright 2012 Thomas Dalling - http://tomdalling.com/

//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at

//      http://www.apache.org/licenses/LICENSE-2.0

//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//  */

// #include "platform.hpp"

// // third-party libraries
// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>

// // standard C++ libraries
// #include <cassert>
// #include <iostream>
// #include <stdexcept>
// #include <cmath>

// // tdogl classes
// #include "tdogl/Program.h"
// #include "tdogl/Texture.h"
// #include "tdogl/Camera.h"

// // constants
// const glm::vec2 SCREEN_SIZE(800, 600);

// // globals
// GLFWwindow* gWindow = NULL;
// double gScrollY = 0.0;
// tdogl::Texture* gTexture = NULL;
// tdogl::Program* gProgram = NULL;
// tdogl::Camera gCamera;
// GLuint gVAO = 0;
// GLuint gVBO = 0;
// GLfloat gDegreesRotated = 0.0f;


// // loads the vertex shader and fragment shader, and links them to make the global gProgram
// static void LoadShaders() {
//     std::vector<tdogl::Shader> shaders;
//     shaders.push_back(tdogl::Shader::shaderFromFile(ResourcePath("vertex-shader.txt"), GL_VERTEX_SHADER));
//     shaders.push_back(tdogl::Shader::shaderFromFile(ResourcePath("fragment-shader.txt"), GL_FRAGMENT_SHADER));
//     gProgram = new tdogl::Program(shaders);
// }


// // loads a cube into the VAO and VBO globals: gVAO and gVBO
// static void LoadCube() {
//     // make and bind the VAO
//     glGenVertexArrays(1, &gVAO);
//     glBindVertexArray(gVAO);

//     // make and bind the VBO
//     glGenBuffers(1, &gVBO);
//     glBindBuffer(GL_ARRAY_BUFFER, gVBO);

//     // Make a cube out of triangles (two triangles per side)
//     GLfloat vertexData[] = {
//         //  X     Y     Z       U     V
//         // bottom
//         -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
//          1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
//         -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
//          1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
//          1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
//         -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,

//         // top
//         -1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
//         -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
//          1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
//          1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
//         -1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
//          1.0f, 1.0f, 1.0f,   1.0f, 1.0f,

//         // front
//         -1.0f,-1.0f, 1.0f,   1.0f, 0.0f,
//          1.0f,-1.0f, 1.0f,   0.0f, 0.0f,
//         -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
//          1.0f,-1.0f, 1.0f,   0.0f, 0.0f,
//          1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
//         -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,

//         // back
//         -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
//         -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,
//          1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
//          1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
//         -1.0f, 1.0f,-1.0f,   0.0f, 1.0f,
//          1.0f, 1.0f,-1.0f,   1.0f, 1.0f,

//         // left
//         -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
//         -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,
//         -1.0f,-1.0f,-1.0f,   0.0f, 0.0f,
//         -1.0f,-1.0f, 1.0f,   0.0f, 1.0f,
//         -1.0f, 1.0f, 1.0f,   1.0f, 1.0f,
//         -1.0f, 1.0f,-1.0f,   1.0f, 0.0f,

//         // right
//          1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
//          1.0f,-1.0f,-1.0f,   1.0f, 0.0f,
//          1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
//          1.0f,-1.0f, 1.0f,   1.0f, 1.0f,
//          1.0f, 1.0f,-1.0f,   0.0f, 0.0f,
//          1.0f, 1.0f, 1.0f,   0.0f, 1.0f
//     };
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

//     // connect the xyz to the "vert" attribute of the vertex shader
//     glEnableVertexAttribArray(gProgram->attrib("vert"));
//     glVertexAttribPointer(gProgram->attrib("vert"), 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), NULL);

//     // connect the uv coords to the "vertTexCoord" attribute of the vertex shader
//     glEnableVertexAttribArray(gProgram->attrib("vertTexCoord"));
//     glVertexAttribPointer(gProgram->attrib("vertTexCoord"), 2, GL_FLOAT, GL_TRUE,  5*sizeof(GLfloat), (const GLvoid*)(3 * sizeof(GLfloat)));

//     // unbind the VAO
//     glBindVertexArray(0);
// }


// // loads the file "wooden-crate.jpg" into gTexture
// static void LoadTexture() {
//     tdogl::Bitmap bmp = tdogl::Bitmap::bitmapFromFile(ResourcePath("wooden-crate.jpg"));
//     bmp.flipVertically();
//     gTexture = new tdogl::Texture(bmp);
// }


// // draws a single frame
// static void Render() {
//     // clear everything
//     glClearColor(0, 0, 0, 1); // black
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//     // bind the program (the shaders)
//     gProgram->use();

//     // set the "camera" uniform
//     gProgram->setUniform("camera", gCamera.matrix());

//     // set the "model" uniform in the vertex shader, based on the gDegreesRotated global
//     gProgram->setUniform("model", glm::rotate(glm::mat4(), glm::radians(gDegreesRotated), glm::vec3(0,1,0)));

//     // bind the texture and set the "tex" uniform in the fragment shader
//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D, gTexture->object());
//     gProgram->setUniform("tex", 0); //set to 0 because the texture is bound to GL_TEXTURE0

//     // bind the VAO (the triangle)
//     glBindVertexArray(gVAO);

//     // draw the VAO
//     glDrawArrays(GL_TRIANGLES, 0, 6*2*3);

//     // unbind the VAO, the program and the texture
//     glBindVertexArray(0);
//     glBindTexture(GL_TEXTURE_2D, 0);
//     gProgram->stopUsing();

//     // swap the display buffers (displays what was just drawn)
//     glfwSwapBuffers(gWindow);
// }


// // update the scene based on the time elapsed since last update
// void Update(float secondsElapsed) {
//     //rotate the cube
//     const GLfloat degreesPerSecond = 180.0f;
//     gDegreesRotated += secondsElapsed * degreesPerSecond;
//     while(gDegreesRotated > 360.0f) gDegreesRotated -= 360.0f;

//     //move position of camera based on WASD keys, and XZ keys for up and down
//     const float moveSpeed = 2.0; //units per second
//     if(glfwGetKey(gWindow, 'S')){
//         gCamera.offsetPosition(secondsElapsed * moveSpeed * -gCamera.forward());
//     } else if(glfwGetKey(gWindow, 'W')){
//         gCamera.offsetPosition(secondsElapsed * moveSpeed * gCamera.forward());
//     }
//     if(glfwGetKey(gWindow, 'A')){
//         gCamera.offsetPosition(secondsElapsed * moveSpeed * -gCamera.right());
//     } else if(glfwGetKey(gWindow, 'D')){
//         gCamera.offsetPosition(secondsElapsed * moveSpeed * gCamera.right());
//     }
//     if(glfwGetKey(gWindow, 'Z')){
//         gCamera.offsetPosition(secondsElapsed * moveSpeed * -glm::vec3(0,1,0));
//     } else if(glfwGetKey(gWindow, 'X')){
//         gCamera.offsetPosition(secondsElapsed * moveSpeed * glm::vec3(0,1,0));
//     }

//     //rotate camera based on mouse movement
//     const float mouseSensitivity = 0.1f;
//     double mouseX, mouseY;
//     glfwGetCursorPos(gWindow, &mouseX, &mouseY);
//     gCamera.offsetOrientation(mouseSensitivity * (float)mouseY, mouseSensitivity * (float)mouseX);
//     glfwSetCursorPos(gWindow, 0, 0); //reset the mouse, so it doesn't go out of the window

//     //increase or decrease field of view based on mouse wheel
//     const float zoomSensitivity = -0.2f;
//     float fieldOfView = gCamera.fieldOfView() + zoomSensitivity * (float)gScrollY;
//     if(fieldOfView < 5.0f) fieldOfView = 5.0f;
//     if(fieldOfView > 130.0f) fieldOfView = 130.0f;
//     gCamera.setFieldOfView(fieldOfView);
//     gScrollY = 0;
// }

// // records how far the y axis has been scrolled
// void OnScroll(GLFWwindow* window, double deltaX, double deltaY) {
//     gScrollY += deltaY;
// }

// void OnError(int errorCode, const char* msg) {
//     throw std::runtime_error(msg);
// }

// // the program starts here
// void AppMain() {
//     // initialise GLFW
//     glfwSetErrorCallback(OnError);
//     if(!glfwInit())
//         throw std::runtime_error("glfwInit failed");

//     // open a window with GLFW
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
//     glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//     gWindow = glfwCreateWindow((int)SCREEN_SIZE.x, (int)SCREEN_SIZE.y, "OpenGL Tutorial", NULL, NULL);
//     if(!gWindow)
//         throw std::runtime_error("glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");

//     // GLFW settings
//     glfwSetInputMode(gWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//     glfwSetCursorPos(gWindow, 0, 0);
//     glfwSetScrollCallback(gWindow, OnScroll);
//     glfwMakeContextCurrent(gWindow);

//     // initialise GLEW
//     glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
//     if(glewInit() != GLEW_OK)
//         throw std::runtime_error("glewInit failed");

//     // GLEW throws some errors, so discard all the errors so far
//     while(glGetError() != GL_NO_ERROR) {}

//     // print out some info about the graphics drivers
//     std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
//     std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
//     std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
//     std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

//     // make sure OpenGL version 3.2 API is available
//     if(!GLEW_VERSION_3_2)
//         throw std::runtime_error("OpenGL 3.2 API is not available.");

//     // OpenGL settings
//     glEnable(GL_DEPTH_TEST);
//     glDepthFunc(GL_LESS);
//     glEnable(GL_BLEND);
//     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//     // load vertex and fragment shaders into opengl
//     LoadShaders();

//     // load the texture
//     LoadTexture();

//     // create buffer and fill it with the points of the triangle
//     LoadCube();

//     // setup gCamera
//     gCamera.setPosition(glm::vec3(0,0,4));
//     gCamera.setViewportAspectRatio(SCREEN_SIZE.x / SCREEN_SIZE.y);

//     // run while the window is open
//     double lastTime = glfwGetTime();
//     while(!glfwWindowShouldClose(gWindow)){
//         // process pending events
//         glfwPollEvents();

//         // update the scene based on the time elapsed since last update
//         double thisTime = glfwGetTime();
//         Update((float)(thisTime - lastTime));
//         lastTime = thisTime;

//         // draw one frame
//         Render();

//         // check for errors
//         GLenum error = glGetError();
//         if(error != GL_NO_ERROR)
//             std::cerr << "OpenGL Error " << error << std::endl;

//         //exit program if escape key is pressed
//         if(glfwGetKey(gWindow, GLFW_KEY_ESCAPE))
//             glfwSetWindowShouldClose(gWindow, GL_TRUE);
//     }

//     // clean up and exit
//     glfwTerminate();
// }


// int main(int argc, char *argv[]) {
//     try {
//         AppMain();
//     } catch (const std::exception& e){
//         std::cerr << "ERROR: " << e.what() << std::endl;
//         return EXIT_FAILURE;
//     }

//     return EXIT_SUCCESS;
// }

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;
/*
4.
*/
void tolower(char* s){
    while(*s != '\0'){
        if('A' <= *s && *s <= 'Z')
            *s += 32;
        s++;
    }
}
/*
5. Write a function, char* findx(const char* s, const char* x), that finds the
   first occurrence of the C-style string x in s.
*/
const char* findx(const char* s, const char* x){
    while(*s != '\0'){
        const char* p = s;
        const char* q = x;

        while(*p++ == *q++);
        if(*q == '\0')
            return s;
        ++s;
    }
    return NULL;
}

/*
6. This chapter does not say what happens when you run out of memory using new.
   That’s called memory exhaustion. Find out what happens. You have two obvious
   alternatives: look for documentation, or write a program with an infinite
   loop that allocates but never deallocates. Try both. Approximately how much
   memory did you manage to allocate before failing?
*/
void Memory_exhoustion(){
    while(1){
        char* p = new char[1000000];
    }
}
/*
7. Write a program that reads characters from cin into an array that you
   allocate on the free store. Read individual characters until an exclamation
   mark (!) is entered. Do not use a std::string. Do not worry about memory
   exhaustion.
*/
char* Cin_to_buffer(int buffer_size){
    char ch;
    int i;
    char* buff = new char[buffer_size];
    for(i =0; cin >> ch && ch != '!'; i++){
        if(i == buffer_size)
            throw runtime_error("Overflow buffer!");
        buff[i] = ch;
    }
    buff[i] = '\0';

    return buff;
}
/*
8. Do exercise 7 again, but this time read into a std::string rather than to
   memory you put on the free store (string knows how to use the free store for
   you).
*/

string Cin_to_buffer_string(){
    string ret;
    string stream_buff;
    bool flag = 1;

    while(flag){
        cin >> stream_buff;
        for(int i = 0; i < stream_buff.size(); ++i){
            if(stream_buff[i] != '!')
                ret += stream_buff[i];
            else
                flag = 0;
        }
    }
    return ret;
}

/*
9. Which way does the stack grow: up (toward higher addresses) or down (toward
   lower addresses)? Which way does the free store initially grow (that is,
   before you use delete)? Write a program to determine the answers.
*/


/*
10. Look at your solution of exercise 7. Is there any way that input could get
    the array to overflow; that is, is there any way you could enter more
    characters than you allocated space for (a serious error)? Does anything
    reasonable happen if you try to enter more characters than you allocated?
*/

/*
11. Complete the “list of gods” example from §17.10.1 and run it.
*/


/*
12. Why did we define two versions of find()?
    Because const object only call a const memberfunction => define two version
    of find() to use for const and no-const object
*/


/*
13. Modify the Link class from §17.10.1 to hold a value of a struct God. struct
    God should have members of type string: name, mythology, vehicle, and
    weapon. For example, God{"Zeus", "Greek", "", "lightning"} and God{"Odin",
    "Norse", "Eight-legged flying horse called Sleipner", "Spear called
    Gungnir"}. Write a print_all() function that lists gods with their
    attributes one per line. Add a member function add_ordered() that places its
    new element in its correct lexicographical position. Using the Links with
    the values of type God, make a list of gods from three mythologies; then
    move the elements (gods) from that list to three lexicographically ordered
    lists — one for each mythology.
*/

/*
14. Could the “list of gods” example from §17.10.1 have been written using a
    singly-linked list; that is, could we have left the prev member out of Link?
    Why might we want to do that? For what kind of examples would it make sense
    to use a singly-linked list? Re-implement that example using only a singly-
    linked list.*/


int main(int argc, char const *argv[])
{
    try{
        // char* s = Cin_to_buffer(10);
        string s = Cin_to_buffer_string();
        cout << s << endl;
    }catch(runtime_error &e){
        cout << e.what() << endl;
    }catch(...){
        cout << "Exiting...!" << endl;
    }
}
