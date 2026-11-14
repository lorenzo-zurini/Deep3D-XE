// Windows: opengl32.dll has only OpenGL 1.1; every later function the game
// and the M3G engine call comes from the driver (wglGetProcAddress), looked up
// on first use, when a context is current. Add a function here when the
// Windows build reports it undefined (its prototype is in GL/glext.h).
#ifdef _WIN32
#include <windows.h>
#define GL_GLEXT_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glext.h>

#include <cstdio>
#include <cstdlib>

namespace {
PROC proc(const char* name) {
    PROC p = wglGetProcAddress(name);
    // some drivers answer 1, 2, 3 or -1 for "none"
    if (!p || p == (PROC) 1 || p == (PROC) 2 || p == (PROC) 3 || p == (PROC) -1) {
        fprintf(stderr, "[gl] the driver has no %s: OpenGL 3.2 or later is needed\n", name);
        std::abort();
    }
    return p;
}
}  // namespace

extern "C" {
void APIENTRY glActiveTexture(GLenum texture) { static auto f = (decltype(&glActiveTexture)) proc("glActiveTexture"); f(texture); }
void APIENTRY glAttachShader(GLuint program, GLuint shader) { static auto f = (decltype(&glAttachShader)) proc("glAttachShader"); f(program, shader); }
void APIENTRY glBindBuffer(GLenum target, GLuint buffer) { static auto f = (decltype(&glBindBuffer)) proc("glBindBuffer"); f(target, buffer); }
void APIENTRY glBindFramebuffer(GLenum target, GLuint framebuffer) { static auto f = (decltype(&glBindFramebuffer)) proc("glBindFramebuffer"); f(target, framebuffer); }
void APIENTRY glBlendEquation(GLenum mode) { static auto f = (decltype(&glBlendEquation)) proc("glBlendEquation"); f(mode); }
void APIENTRY glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) { static auto f = (decltype(&glBlitFramebuffer)) proc("glBlitFramebuffer"); f(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter); }
void APIENTRY glClientActiveTexture(GLenum texture) { static auto f = (decltype(&glClientActiveTexture)) proc("glClientActiveTexture"); f(texture); }
void APIENTRY glCompileShader(GLuint shader) { static auto f = (decltype(&glCompileShader)) proc("glCompileShader"); f(shader); }
void APIENTRY glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data) { static auto f = (decltype(&glCompressedTexImage2D)) proc("glCompressedTexImage2D"); f(target, level, internalformat, width, height, border, imageSize, data); }
GLuint APIENTRY glCreateProgram(void) { static auto f = (decltype(&glCreateProgram)) proc("glCreateProgram"); return f(); }
GLuint APIENTRY glCreateShader(GLenum type) { static auto f = (decltype(&glCreateShader)) proc("glCreateShader"); return f(type); }
void APIENTRY glDeleteShader(GLuint shader) { static auto f = (decltype(&glDeleteShader)) proc("glDeleteShader"); f(shader); }
void APIENTRY glDeleteSync(GLsync sync) { static auto f = (decltype(&glDeleteSync)) proc("glDeleteSync"); f(sync); }
void APIENTRY glDisableVertexAttribArray(GLuint index) { static auto f = (decltype(&glDisableVertexAttribArray)) proc("glDisableVertexAttribArray"); f(index); }
void APIENTRY glEnableVertexAttribArray(GLuint index) { static auto f = (decltype(&glEnableVertexAttribArray)) proc("glEnableVertexAttribArray"); f(index); }
GLsync APIENTRY glFenceSync(GLenum condition, GLbitfield flags) { static auto f = (decltype(&glFenceSync)) proc("glFenceSync"); return f(condition, flags); }
void APIENTRY glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) { static auto f = (decltype(&glFramebufferTexture2D)) proc("glFramebufferTexture2D"); f(target, attachment, textarget, texture, level); }
void APIENTRY glGenFramebuffers(GLsizei n, GLuint *framebuffers) { static auto f = (decltype(&glGenFramebuffers)) proc("glGenFramebuffers"); f(n, framebuffers); }
void APIENTRY glGenQueries(GLsizei n, GLuint *ids) { static auto f = (decltype(&glGenQueries)) proc("glGenQueries"); f(n, ids); }
void APIENTRY glGenVertexArrays(GLsizei n, GLuint *arrays) { static auto f = (decltype(&glGenVertexArrays)) proc("glGenVertexArrays"); f(n, arrays); }
void APIENTRY glGenerateMipmap(GLenum target) { static auto f = (decltype(&glGenerateMipmap)) proc("glGenerateMipmap"); f(target); }
GLint APIENTRY glGetAttribLocation(GLuint program, const GLchar *name) { static auto f = (decltype(&glGetAttribLocation)) proc("glGetAttribLocation"); return f(program, name); }
void APIENTRY glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { static auto f = (decltype(&glGetProgramInfoLog)) proc("glGetProgramInfoLog"); f(program, bufSize, length, infoLog); }
void APIENTRY glGetProgramiv(GLuint program, GLenum pname, GLint *params) { static auto f = (decltype(&glGetProgramiv)) proc("glGetProgramiv"); f(program, pname, params); }
void APIENTRY glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 *params) { static auto f = (decltype(&glGetQueryObjectui64v)) proc("glGetQueryObjectui64v"); f(id, pname, params); }
void APIENTRY glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog) { static auto f = (decltype(&glGetShaderInfoLog)) proc("glGetShaderInfoLog"); f(shader, bufSize, length, infoLog); }
void APIENTRY glGetShaderiv(GLuint shader, GLenum pname, GLint *params) { static auto f = (decltype(&glGetShaderiv)) proc("glGetShaderiv"); f(shader, pname, params); }
GLint APIENTRY glGetUniformLocation(GLuint program, const GLchar *name) { static auto f = (decltype(&glGetUniformLocation)) proc("glGetUniformLocation"); return f(program, name); }
GLboolean APIENTRY glIsFramebuffer(GLuint framebuffer) { static auto f = (decltype(&glIsFramebuffer)) proc("glIsFramebuffer"); return f(framebuffer); }
GLboolean APIENTRY glIsProgram(GLuint program) { static auto f = (decltype(&glIsProgram)) proc("glIsProgram"); return f(program); }
void APIENTRY glLinkProgram(GLuint program) { static auto f = (decltype(&glLinkProgram)) proc("glLinkProgram"); f(program); }
void APIENTRY glQueryCounter(GLuint id, GLenum target) { static auto f = (decltype(&glQueryCounter)) proc("glQueryCounter"); f(id, target); }
void APIENTRY glShaderSource(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length) { static auto f = (decltype(&glShaderSource)) proc("glShaderSource"); f(shader, count, string, length); }
void APIENTRY glUniform1f(GLint location, GLfloat v0) { static auto f = (decltype(&glUniform1f)) proc("glUniform1f"); f(location, v0); }
void APIENTRY glUniform1i(GLint location, GLint v0) { static auto f = (decltype(&glUniform1i)) proc("glUniform1i"); f(location, v0); }
void APIENTRY glUniform2f(GLint location, GLfloat v0, GLfloat v1) { static auto f = (decltype(&glUniform2f)) proc("glUniform2f"); f(location, v0, v1); }
void APIENTRY glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) { static auto f = (decltype(&glUniform3f)) proc("glUniform3f"); f(location, v0, v1, v2); }
void APIENTRY glUniform3fv(GLint location, GLsizei count, const GLfloat *value) { static auto f = (decltype(&glUniform3fv)) proc("glUniform3fv"); f(location, count, value); }
void APIENTRY glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) { static auto f = (decltype(&glUniform4f)) proc("glUniform4f"); f(location, v0, v1, v2, v3); }
void APIENTRY glUniform4fv(GLint location, GLsizei count, const GLfloat *value) { static auto f = (decltype(&glUniform4fv)) proc("glUniform4fv"); f(location, count, value); }
void APIENTRY glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value) { static auto f = (decltype(&glUniformMatrix4fv)) proc("glUniformMatrix4fv"); f(location, count, transpose, value); }
void APIENTRY glUseProgram(GLuint program) { static auto f = (decltype(&glUseProgram)) proc("glUseProgram"); f(program); }
void APIENTRY glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer) { static auto f = (decltype(&glVertexAttribPointer)) proc("glVertexAttribPointer"); f(index, size, type, normalized, stride, pointer); }
void APIENTRY glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) { static auto f = (decltype(&glWaitSync)) proc("glWaitSync"); f(sync, flags, timeout); }
}
#endif
