#include "pch.h"

GLuint colorbuffer;
GLuint vertexBuffer;
GLuint vao;

void OpenGLRenderer::GLFWInit()
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
}

void OpenGLRenderer::RenderFrameworkInit(GLFWwindow* window)
{
    Console::Log("OpenGL Starting");
}

void OpenGLRenderer::RenderInit()
{
    glClearColor(1, 0, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGLRenderer::Render()
{
   auto BATCH = MeshBatch::GetInstance().GetBatch();
   
   for (auto batchGroup = BATCH->begin(); batchGroup != BATCH->end(); ++batchGroup)
   {
       GLuint vao = (GLuint)batchGroup->first->GetVao();


       //TODO: Setup material and shaders


       glBindVertexArray(vao);

       glEnableVertexArrayAttrib(vao, 0);
       glEnableVertexArrayAttrib(vao, 1);
       glEnableVertexArrayAttrib(vao, 2);

       glDrawArraysInstanced(GL_TRIANGLES, 0, batchGroup->first->GetMeshSize(), batchGroup->second.size());
       
       glDisableVertexArrayAttrib(vao, 0);
       glDisableVertexArrayAttrib(vao, 1);
       glDisableVertexArrayAttrib(vao, 2);
       glBindVertexArray(0);

   }
}

void OpenGLRenderer::RenderEnd()
{
    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {

    }
}

void OpenGLRenderer::RenderFrameworkCleanup()
{
   
}
