#include "core/vertex.h"

void triangleSetup() {
    Vertex myVertexArray[3] = {
        { glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec4(0.9f, 0.0f, 0.0f, 1.0f) },
        { glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec4(0.0f, 0.9f, 0.0f, 1.0f) },
        { glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec4(0.0f, 0.0f, 0.9f, 1.0f) }
    };

    uint32_t myVaoID;
    glCreateVertexArrays(1, &myVaoID);
    glBindVertexArray(myVaoID);

    uint32_t myVboID;
    glGenBuffers(1, &myVboID);
    glBindBuffer(GL_ARRAY_BUFFER, myVboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(myVertexArray), myVertexArray, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(1);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}