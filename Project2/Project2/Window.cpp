#include "Window.h"

Window::Window()
{
	width = 800;
	height = 600;
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}
}
Window::Window(GLint windowWidth, GLint windowHeight)
{
	width = windowWidth;
	height = windowHeight;
	muevex = 2.0f;
	articulacion1 = 0.0f;
	articulacion2 = 0.0f;
	articulacion3 = 0.0f;
	articulacion4 = 0.0f;
	articulacion5 = 0.0f;
	articulacion6 = 0.0f;
	articulacion7 = 0.0f;
	articulacion8 = 0.0f;
	articulacion9 = 0.0f;
	articulacion10 = 0.0f;
	articulacion11 = 0.0f;
	articulacion12 = 0.0f;
	helicoptero = 2.0f;
	arregloLuces = 0.0f;
	banderamovimiento = 0.0f;
	for (size_t i = 0; i < 1024; i++)
	{
		keys[i] = 0;
	}

}
int Window::Initialise()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	mainWindow = glfwCreateWindow(width, height, "PracticaXX:Nombre de la practica", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//MANEJAR TECLADO y MOUSE
	createCallbacks();


	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST); //HABILITAR BUFFER DE PROFUNDIDAD
							 // Asignar valores de la ventana y coordenadas
							 
							 //Asignar Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);
	//Callback para detectar que se está usando la ventana
	glfwSetWindowUserPointer(mainWindow, this);
}

void Window::createCallbacks()
{
	glfwSetKeyCallback(mainWindow, ManejaTeclado);
	glfwSetCursorPosCallback(mainWindow, ManejaMouse);
}
GLfloat Window::getXChange()
{
	GLfloat theChange = xChange;
	xChange = 0.0f;
	return theChange;
}

GLfloat Window::getYChange()
{
	GLfloat theChange = yChange;
	yChange = 0.0f;
	return theChange;
}




void Window::ManejaTeclado(GLFWwindow* window, int key, int code, int action, int mode)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (key == GLFW_KEY_Y)
	{
		theWindow-> muevex += 1.0;
	}
	if (key == GLFW_KEY_U)
	{
		theWindow-> muevex -= 1.0;
	}

	if (key == GLFW_KEY_I)
	{
		theWindow->helicoptero += 1.0;
	}
	if (key == GLFW_KEY_O)
	{
		theWindow->helicoptero -= 1.0;
	}

	if (key == GLFW_KEY_F)
	{
		theWindow->articulacion1 += 5.0;
	}

	if (key == GLFW_KEY_G)
	{
		theWindow->articulacion1 -= 5.0;
	}
	if (key == GLFW_KEY_H)
	{
		if (theWindow->articulacion3 < 45) {
			theWindow->articulacion3 += 5.0;
			theWindow->articulacion4 -= 5.0;
		}
	}
	if (key == GLFW_KEY_J)
	{
		if (theWindow->articulacion4 < 0) {
			theWindow->articulacion4 += 5.0;
			theWindow->articulacion3 -= 5.0;
		}
	}
	if (key == GLFW_KEY_K)
	{
		if (theWindow->articulacion5 < 45) {
			theWindow->articulacion5 += 5.0;
			theWindow->articulacion6 -= 5.0;
		}
	}
	if (key == GLFW_KEY_L)
	{
		if (theWindow->articulacion6 < 45) {
			theWindow->articulacion6 += 5.0;
			theWindow->articulacion5 -= 5.0;
		}
	}

	if (key == GLFW_KEY_Y)
	{
		if (theWindow->articulacion7 < 45) {
			theWindow->articulacion7 += 5.0;
			theWindow->articulacion8 -= 5.0;
		}
	}
	if (key == GLFW_KEY_U)
	{
		if (theWindow->articulacion8 < 45) {
			theWindow->articulacion8 += 5.0;
			theWindow->articulacion7 -= 5.0;
		}
	}
	// Articulacion mandibula 
	if (key == GLFW_KEY_I)
	{
		if (theWindow->articulacion9 > -25) {
			theWindow->articulacion9 -= 5.0;
			theWindow->articulacion10 += 5.0;
		}
	}
	if (key == GLFW_KEY_O)
	{
		if (theWindow->articulacion10 > 0) {
			theWindow->articulacion10 -= 5.0;
			theWindow->articulacion9 += 5.0;
		}
	}



	//Articulacion cola 
	if (key == GLFW_KEY_N)
	{
		if (theWindow->articulacion11 < 25) {
			theWindow->articulacion11 += 5.0;
			theWindow->articulacion12 -= 5.0;
		}
	}
	if (key == GLFW_KEY_M)
	{
		if (theWindow->articulacion12 < 25) {
			theWindow->articulacion12 += 5.0;
			theWindow->articulacion11 -= 5.0;

		}
	}

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			theWindow->keys[key] = true;
			//printf("se presiono la tecla %d'\n", key);
		}
		else if (action == GLFW_RELEASE)
		{
			theWindow->keys[key] = false;
			//printf("se solto la tecla %d'\n", key);
		}
	}
	if (key == GLFW_KEY_Z)
	{
		theWindow->arregloLuces = 0;
	}
	if (key == GLFW_KEY_X)
	{
		theWindow->arregloLuces = 1;
	}
	if (key == GLFW_KEY_U)
	{
		theWindow->banderamovimiento = 0;
	}
	if (key == GLFW_KEY_Y)
	{
		theWindow->banderamovimiento = 1;
	}

}

void Window::ManejaMouse(GLFWwindow* window, double xPos, double yPos)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (theWindow->mouseFirstMoved)
	{
		theWindow->lastX = xPos;
		theWindow->lastY = yPos;
		theWindow->mouseFirstMoved = false;
	}

	theWindow->xChange = xPos - theWindow->lastX;
	theWindow->yChange = theWindow->lastY - yPos;

	theWindow->lastX = xPos;
	theWindow->lastY = yPos;
}


Window::~Window()
{
	glfwDestroyWindow(mainWindow);
	glfwTerminate();

}
