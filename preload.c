// preload.c
// Alistair Buxton <a.j.buxton@gmail.com>

#define _GNU_SOURCE

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

    static glBindBuffer_func gbb = NULL;

    if(target == GL_ARRAY_BUFFER && buffer == 0) {
        return;
    }
    if(!gbb) {
        gbb = dlsym(RTLD_NEXT, "glBindBuffer");
    }
    gbb(target, buffer);
}

