#pragma once
#include "core.h"
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

struct Vertex {
    glm::vec3 position;
    glm::vec4 color;
};

void triangleSetup();
