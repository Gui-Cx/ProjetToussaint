#pragma once

#include <memory>
#include "core.h"
#include "window.h"

class Application {
    public:
        static std::unique_ptr<Application> app_instance;
        Window window;
        bool app_running;

        Application();
        static void run();
        bool init();
        static std::unique_ptr<Application>& get_instance();

        ~Application(); 
    private:
        void init_callbacks();
};
namespace Input {
    void update_keys(std::unique_ptr<Application>& app); 
    void update_cursorpos(std::unique_ptr<Application>& app); 
    void update_mouse_buttons(std::unique_ptr<Application>& app); 
    void update(std::unique_ptr<Application>& app);
    void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods); 
    void mouse_mv_callback(GLFWwindow* window, double xpos, double ypos); 
    bool is_key_down(int key);
    bool is_mousebutton_down(int mouse_button);
}