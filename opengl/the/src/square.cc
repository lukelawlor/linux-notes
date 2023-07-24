// 4.12.23 12:51pm finished

#include <cstdio>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace the
{
	namespace con
	{
		constexpr int win_width = 666;
		constexpr int win_height = 666;
		constexpr const char *win_title = "opengl the";
		constexpr int err_log_len = 512;
	}

	// Called when the window is resized
	void glcb_resize(GLFWwindow *win, int width, int height);

	// Processes glfw input events
	void process_input(GLFWwindow *win);

	// Called when the window is resized
	void glcb_resize(GLFWwindow *win, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	// Processes glfw input events
	void process_input(GLFWwindow *win)
	{
		if (glfwGetKey(win, GLFW_KEY_Q) == GLFW_PRESS)
			glfwSetWindowShouldClose(win, true);
	}
}

int main(int, char **)
{
	using namespace the;

	// Init GLFW
	glfwInit();

	// Specify that we are using OpenGL 3.3 core profile
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef	__APPLE__
	// For Mac OS X compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// Window
	GLFWwindow *win = glfwCreateWindow(
		con::win_width,
		con::win_height,
		con::win_title,
		nullptr,
		nullptr
	);
	if (win == nullptr)
	{
		std::fprintf(stderr, "frick\n");
		glfwTerminate();
		return 1;
	}

	// Make the window an OpenGL context
	glfwMakeContextCurrent(win);

	// Init GLEW
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		std::fprintf(stderr, "frick: %s\n", glewGetErrorString(err));
		return 1;
	}
	std::printf("hi. using glew %s\n", glewGetString(GLEW_VERSION));

	// Resize callback setting yeah
	glfwSetFramebufferSizeCallback(win, glcb_resize);

	// OpenGL finally
	// Set the viewport that OpenGL uses to these dimensions on the context
	// glViewPort(x, y, width, height)
	glViewport(0, 0, con::win_width, con::win_height);

	// Create a basic vertex shader
	const char *glsl_vertex = R"(
		#version 330 core
		layout (location = 0) in vec3 aPos;

		void main()
		{
			gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);
		}
	)";

	// Compile the vertex shader
	unsigned int vertex_shader;
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);

	// Assign the source code to the shader
	// glShaderSource(1, 2, 3, 4)
	// 1 - object id of shader
	// 2 - number of strings of source code
	// 3 - pointer to pointer to char containing source code string
	// 4 - just leave as null for now
	glShaderSource(vertex_shader, 1, &glsl_vertex, nullptr);

	// Compile the shader
	glCompileShader(vertex_shader);

	// Check for compiling errors
	int success;
	char err_log[con::err_log_len];
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex_shader, con::err_log_len, nullptr, err_log);
		std::fprintf(stderr, "shader is kill. %s\n", err_log);
	}

	// Fragment shader source
	const char *glsl_fragment = R"(
		#version 330 core
		out vec4 FragColor;

		void main()
		{
			FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
		}
	)";

	// Create and compile the shader
	unsigned int fragment_shader;
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &glsl_fragment, nullptr);
	glCompileShader(fragment_shader);

	// Check for compiling errors
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment_shader, con::err_log_len, nullptr, err_log);
		std::fprintf(stderr, "frag shader si kill. %s\n", err_log);
	}

	// Time to make the shader program
	unsigned int shader_program;
	shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	// Check for linking errors
	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader_program, con::err_log_len, nullptr, err_log);
		std::fprintf(stderr, "link get bruhed. %s\n", err_log);
	}

	// Activate the program object
	// Every shader and rendering calla fter this will now use this program object and its shaders
	glUseProgram(shader_program);

	// We can delete the shader objects once they're linked into the program object
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);





















	// Shader stuff done

	// Square vertices
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,	// bottom left
		0.5f, -0.5f, 0.0f,	// bottom right
		-0.5f, 0.5f, 0.0f,	// top left
		0.5f, 0.5f, 0.0f,	// top right
	};

	// Indices to make the square
	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 1,
	};

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), reinterpret_cast<void *>(0));
	glEnableVertexAttribArray(0);

	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Draw in wireframe mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Draw in fill mode
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Render loop nice
	while (!glfwWindowShouldClose(win))
	{
		// Check if events are triggered (like keyboard input) and call their respective callback functions
		glfwPollEvents();

		process_input(win);

		// Rendering commands here

		// Clear the screen
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Render the square
		// glDrawElements(1, 2, 3, 4)
		// 1 - mode we want to draw in
		// 2 - number of vertices we'd like to draw
		// 3 - type of indicies
		// 4 - offset in the EBO
		glUseProgram(shader_program);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, reinterpret_cast<void *>(0));
		glBindVertexArray(0);

		// Swap the color buffer (a large 2d buffer that contains color values for each pixel in GLFW's window) that is used to render to during this render iteration and show it as output to the screen
		// OpenGL has two buffers used to store pixel data, a front and back buffer
		// Stuff is rendered on the back buffer which is then turned into the front buffer and displayed
		// While the front buffer is displayed, the cycle repeats. The back buffer is being drawn to until it's time to display another finished frame
		glfwSwapBuffers(win);

	}

	glfwTerminate();
	return 0;
}
