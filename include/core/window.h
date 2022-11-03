#pragma once
#ifndef WINDOW_H
#define WINDOW_H
#include "core.h"
#include "core/shader.h"
#include "core/vertex.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "CPPCRAFT"

class Window {
    private : 
        GLFWwindow* instance;
        int width;
        int height;
        char* title;

    public :
        Window(const int width, const int height, char* title);
        GLFWwindow* createWindow();
        GLFWwindow* get_window_instance();
        void update();
        void close();
};

#endif // !WINDOW_H
