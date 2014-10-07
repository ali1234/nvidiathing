// preload.c
// Alistair Buxton <a.j.buxton@gmail.com>

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>

void __attribute__ ((constructor)) load(void);

// Called when the library is loaded and before dlopen() returns
void load(void)
{
    fprintf(stderr, "preload hack loaded...\n");
}


typedef void (* glBindBuffer_func)(GLenum target,  GLuint buffer);

void glBindBuffer(GLenum target, GLuint buffer) {

    void *gl_handle;

    if(target != GL_ARRAY_BUFFER || buffer != 0) {
        gl_handle = dlopen("libGL.so", RTLD_LAZY);
        glBindBuffer_func gbb = dlsym(gl_handle, "glBindBuffer");
        gbb(target, buffer);
    }
}
