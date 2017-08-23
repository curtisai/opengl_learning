#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h> // Always include it before gl.h and glfw.h

#include <glfw3.h>


#include <glm/glm.hpp>

using namespace glm;

int main( void )
{
	// Initialize GLFW
	if ( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);  // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Using opengl 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // TODO: Fingure out
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// don't want the old OpenGL
	
	// Open a window and create its OpenGL context
	GLFWwindow* window;
	window = glfwCreateWindow( 1024, 768, "Playground", NULL, NULL);
	if ( window == nullptr )
	{
		fprintf( stderr, "Failed to open GLFW window.");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent( window ); // Initialize GLEW
	glewExperimental = true;

	if ( glewInit() != GLEW_OK )
	{
		fprintf( stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode( window, GLFW_STICKY_KEYS, GL_TRUE);
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	do
	{
		glClear(GL_COLOR_BUFFER_BIT);
		// Draw nothing

		// Swap buffers
		glfwSwapBuffers( window );
		glfwPollEvents();
	}
	while ( glfwGetKey( window, GLFW_KEY_ESCAPE ) != GLFW_PRESS 
			&& glfwWindowShouldClose( window ) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
	return 0;
}
