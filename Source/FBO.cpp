#include <FBO.h>

FBO::FBO(float width, float height)
{
    glGenTextures(1, &FBO_texture);
    glBindTexture(GL_TEXTURE_2D, FBO_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    glGenFramebuffers(1, &ID);
    glBindFramebuffer(GL_FRAMEBUFFER, ID);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, FBO_texture, 0);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
void FBO::Bind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, ID);
}
void FBO::Unbind()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
void FBO::Delete()
{
    glDeleteFramebuffers(1, &ID);
}


