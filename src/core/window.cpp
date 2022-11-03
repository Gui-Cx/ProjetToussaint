#include "core/window.h"

Window::Window(const int width, const int height, char* title) : width(width), height(height), title(title)
{
}

GLFWwindow* Window::createWindow() {
    // Init guard
    if (!glfwInit()) {
        printf("Failed to initialize glfw\n");
        return nullptr;
    }

    // Speficy versions
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    instance = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (instance == nullptr) {
        printf("Error creating the window\n");
        glfwTerminate();
        return nullptr;
    }

    glfwMakeContextCurrent(instance);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        printf("Failed to initialize glad\n");
        return nullptr;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    return instance;
}

void Window::update() {
    glClearColor(250.0f / 255.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(instance);
    glfwPollEvents();
}

void Window::close() {
    if (instance != nullptr) glfwSetWindowShouldClose(instance, GLFW_TRUE);
}

GLFWwindow* Window::get_window_instance() {
    return instance;
}
