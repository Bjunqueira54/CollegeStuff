#include <cstdlib>
#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLint WIDTH = 800;
const GLint HEIGHT = 600;

void rotateTriangle(GLfloat*);

int main(int argc, char** argv)
{
	if (glfwInit() == GL_FALSE)
	{
		std::cout << "Failed to initialize GLFW." << std::endl;

		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* win = glfwCreateWindow(WIDTH, HEIGHT, "Test OpenGL", nullptr, nullptr);

	if (win == nullptr)
	{
		std::cout << "Failed to create OpenGL window" << std::endl;
		glfwTerminate();
		return -1;
	}

	int screenWidth, screenHeight;

	glfwGetFramebufferSize(win, &screenWidth, &screenHeight);

	glfwMakeContextCurrent(win);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		glfwTerminate();

		return -1;
	}

	glViewport(0, 0, screenWidth, screenHeight);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glfwSetInputMode(win, GLFW_STICKY_KEYS, GL_TRUE);

	static GLfloat g_vertex_buffer_data[] = {-1.0f, -1.0f, 0.0f,
												   1.0f, -1.0f, 0.0f,
												   0.0f,  1.0f, 0.0f };

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_DYNAMIC_DRAW);

	do
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);

		//code drawings here

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);

		glfwSwapBuffers(win);

		rotateTriangle(g_vertex_buffer_data);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_DYNAMIC_DRAW);
	}
	while(!glfwWindowShouldClose(win) && glfwGetKey(win, GLFW_KEY_ESCAPE) != GLFW_PRESS);

	glfwTerminate();

	return 0;
}

void rotateTriangle(GLfloat* g_vertex_buffer_data)
{
	GLfloat point[3][2];
	//pointRotation: Binary state machine, allows 4 states.
	bool pointRotation[3][2];

	point[0][0] = g_vertex_buffer_data[0];
	point[0][1] = g_vertex_buffer_data[1];
	pointRotation[0][0] = false;
	pointRotation[0][1] = false;

	point[1][0] = g_vertex_buffer_data[3];
	point[1][1] = g_vertex_buffer_data[4];
	pointRotation[1][0] = true;
	pointRotation[1][1] = false;

	point[2][0] = g_vertex_buffer_data[6];
	point[2][1] = g_vertex_buffer_data[7];
	pointRotation[2][0] = true;
	pointRotation[2][1] = true;

	for(int i = 0; i < 3; i++)
	{
		if (pointRotation[i][0] && pointRotation[i][1])
			point[i][1] -= 0.01f;
		else if (pointRotation[i][0] && !pointRotation[i][1])
			point[i][0] -= 0.01f;
		else if (!pointRotation[i][0] && !pointRotation[i][1])
			point[i][1] += 0.01f;
		else if (!pointRotation[i][0] && pointRotation[i][1])
			point[i][1] += 0.01f;

		if (point[i][0] == 1.0f && point[i][1] == 1.0f)
		{
			pointRotation[i][0] = true;
			pointRotation[i][1] = true;
		}
		else if (point[i][0] == 1.0f && point[i][1] == -1.0f)
		{
			pointRotation[i][0] = true;
			pointRotation[i][1] = false;
		}
		else if (point[i][0] == -1.0f && point[i][1] == -1.0f)
		{
			pointRotation[i][0] = false;
			pointRotation[i][1] = false;
		}
		else if (point[i][0] == -1.0f && point[i][1] == 1.0f)
		{
			pointRotation[i][0] = false;
			pointRotation[i][1] = true;
		}
	}
}