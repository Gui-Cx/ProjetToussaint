#include "core/application.h"

std::unique_ptr<Application> Application::app_instance = nullptr;

Application::Application() 
: window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE) 
{
    
}

std::unique_ptr<Application>& Application::get_instance() {
    if (!Application::app_instance) {
        Application::app_instance = std::unique_ptr<Application>(new Application);
    }
    return Application::app_instance;
}

void Application::run() {
    auto& app_instance = Application::get_instance();      
    app_instance.get()->init();
    while (app_instance.get()->app_running) {
        app_instance->window.update();
        Input::update(app_instance);
    }
}

bool Application::init() {
    get_instance()->window.createWindow();
    init_callbacks();
    app_running = true;
    Shader exampleShader;
    exampleShader.compile();

    return true;
}

void Application::init_callbacks() {
    GLFWwindow* window = Application::get_instance().get()->window.get_window_instance();
    if (window != nullptr) {
        glfwSetKeyCallback(window, Input::key_callback);
        glfwSetCursorPosCallback(window, Input::mouse_mv_callback);
        glfwSetMouseButtonCallback(window, Input::mouse_button_callback);
    }
}

Application::~Application()  {
    printf("Destructing application\n");
}



namespace Input
{
    bool pressed_keys[GLFW_KEY_LAST] = {};
    bool pressed_mouse[GLFW_KEY_LAST] = {};
    float mouse_x = 0;
    float mouse_y = 0;
    float mouse_scroll_x = 0;
    float mouse_scroll_y = 0;

    void update_keys(std::unique_ptr<Application>& app) {
        if (is_key_down(GLFW_KEY_ESCAPE)) app.get()->app_running = false;
        if (is_key_down(GLFW_KEY_1)) triangleSetup();
    }

    void update_cursorpos(std::unique_ptr<Application>& app) {

    }

    void update_mouse_buttons(std::unique_ptr<Application>& app) {

    }

    void update(std::unique_ptr<Application>& app) {
        update_keys(app);
        update_cursorpos(app);
        update_mouse_buttons(app);
    }

    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key >= 0 && key <= GLFW_KEY_LAST) pressed_keys[key] = action == GLFW_PRESS;
    }

    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
        if (button >= 0 && button <= GLFW_MOUSE_BUTTON_LAST) pressed_mouse[button] = action == GLFW_PRESS;
    }

    void mouse_mv_callback(GLFWwindow* window, double xpos, double ypos) {
        mouse_x = (float)xpos;
        mouse_y = (float)ypos;
    }

    bool is_key_down(int key) {
        if (key >= 0 && key <= GLFW_KEY_LAST) return pressed_keys[key];
        return false;
    } 

    bool is_mousebutton_down(int mouse_button) {
        if (mouse_button >= 0 && mouse_button <= GLFW_MOUSE_BUTTON_LAST) return pressed_mouse[mouse_button];
        return false;
    }




} 