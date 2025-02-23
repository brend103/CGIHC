//Práctica 2: índices, mesh, proyecciones, transformaciones geométricas
#include <stdio.h>
#include <string.h>
#include<cmath>
#include<vector>
#include <glew.h>
#include <glfw3.h>
//glm
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
//clases para dar orden y limpieza al código
#include"Mesh.h"
#include"Shader.h"
#include"Window.h"
//Dimensiones de la ventana
const float toRadians = 3.14159265f/180.0; //grados a radianes
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<MeshColor*> meshColorList;
std::vector<Shader>shaderList;
//Vertex Shader
static const char* vShader = "shaders/shader.vert";
static const char* fShader = "shaders/shader.frag";
static const char* vShaderColor = "shaders/shadercolor.vert";
static const char* fShaderColor = "shaders/shadercolor.frag";
static const char* vShaderverde = "shaders/shader_verde.vert";
static const char* vShaderazul = "shaders/shader_azul.vert";
static const char* vShadercafe = "shaders/shader_cafe.vert";
static const char* vShaderverdezote = "shaders/shader_verdezote.vert";
static const char* vShaderrojo = "shaders/shader_rojo.vert";
//static const char* vShaderColor = "shaders/shadercolor.frag";
//shaders nuevos se crearían acá

float angulo = 0.0f;

//color café en RGB : 0.478, 0.255, 0.067

//Pirámide triangular regular
void CreaPiramide()
{
	unsigned int indices[] = { 
		0,1,2,
		1,3,2,
		3,0,2,
		1,0,3
		
	};
	GLfloat vertices[] = {
		-0.8f, 0.2f,0.0f,  
		0.8f,0.2f,0.0f,	
		0.0f,1.0f, -0.25f,	
		0.0f,0.2f,-0.5f,	
		//3

	};
	Mesh *obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 24, 12);	//No siempre es el mismo valor
	meshList.push_back(obj1);
}

void CreaPiramideArbol()
{
	unsigned int indices[] = {
		0,1,2,
		1,3,2,
		3,0,2,
		1,0,3

	};
	GLfloat vertices[] = {
		-0.25f, -0.5f,0.0f,
		0.25f,-0.5f,0.0f,
		0.0f,0.0f, -0.25f,
		0.0f,-0.5f,-0.5f,
		//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 24, 12);	//No siempre es el mismo valor
	meshList.push_back(obj1);
}
//Vértices de un cubo
void CrearCubo()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

GLfloat cubo_vertices[] = {
	// front
	-0.55f, -0.8f,  0.4f,
	0.55f, -0.8f,  0.4f,
	0.55f,  0.2f,  0.4f,
	-0.55f,  0.2f,  0.4f,
	// back
	-0.55f, -0.8f, -0.4f,
	0.55f, -0.8f, -0.4f,
	0.55f,  0.2f, -0.4f,
	-0.55f,  0.2f, -0.4f
};
Mesh *cubo = new Mesh();
cubo->CreateMesh(cubo_vertices, cubo_indices,24, 36);
meshList.push_back(cubo);
}

void Crearventana()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};
	GLfloat cubo_vertices[] = {
		// front
		-0.15f, -0.8f,  0.2f,
		0.15f, -0.5f,  0.2f,
		0.15f,  -0.5f,  0.2f,
		-0.15f,  -0.5f,  0.2f,
		// back
		-0.15f, -0.8f, -0.2f,
		0.15f, -0.8f, -0.2f,
		0.15f,  -0.5f, -0.2f,
		-0.15f,  -0.5f, -0.2f
	};
	Mesh* cubo = new Mesh();
	cubo->CreateMesh(cubo_vertices, cubo_indices, 24, 36);
	meshList.push_back(cubo);
}

void Creartronco()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};
	GLfloat cubo_vertices[] = {
		// front
		-0.07f, -0.8f,  0.2f,
		0.07f, -0.65f,  0.2f,
		0.07f,  -0.65f,  0.2f,
		-0.07f,  -0.65f,  0.2f,
		// back
		-0.07f, -0.8f, -0.2f,
		0.07f, -0.8f, -0.2f,
		0.07f,  -0.65f, -0.2f,
		-0.07f,  -0.65f, -0.2f
	};
	Mesh* cubo = new Mesh();
	cubo->CreateMesh(cubo_vertices, cubo_indices, 24, 36);
	meshList.push_back(cubo);
}

void CrearLetrasyFiguras()
{
	GLfloat vertices_letras[] = {	
			//X			Y			Z			R		G		B
			-1.0f,	-1.0f,		0.5f,			0.0f,	1.0f,	0.0f,
			1.0f,	-1.0f,		0.5f,			0.0f,	1.0f,	0.0f,
			1.0f,	1.0f,		0.5f,			0.0f,	1.0f,	0.0f,
			//1.0f,	1.0f,		0.5f,			1.0f,	0.0f,	0.0f,
			//-1.0f,  1.0f,		0.5f,			1.0f,	0.0f,	0.0f,
			//-1.0f,	-1.0f,		0.5f,			1.0f,	0.0f,	0.0f,
			
	};
	MeshColor *letras = new MeshColor();
	letras->CreateMeshColor(vertices_letras,18);
	meshColorList.push_back(letras);

	GLfloat vertices_letrab[] = {
		
-0.78f, 0.3f, 0.0f, 	1.0f,	5.0f,	0.0f,					 // Triangulo 1
-0.7f, 0.3f, 0.0f,		1.0f,	5.0f,	0.0f,
-0.7f,  -0.2f, 0.0f,	1.0f,	5.0f,	0.0f,

-0.78f,  0.3f, 0.0f,  1.0f, 5.0f, 0.0f,  // Triangulo 2
-0.78f, -0.2f, 0.0f,  1.0f, 5.0f, 0.0f,
-0.7f,  -0.2f, 0.0f,  1.0f, 5.0f, 0.0f,

-0.7f, 0.3f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 3
-0.7f, 0.2f, 0.0f,   1.0f, 5.0f, 0.0f,
-0.6f,  0.2f, 0.0f,  1.0f, 5.0f, 0.0f,

-0.7f, 0.3f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 4
-0.6f,  0.3f, 0.0f,  1.0f, 5.0f, 0.0f,
-0.6f,  0.2f, 0.0f,  1.0f, 5.0f, 0.0f,

-0.6f, 0.3f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 5
-0.6f,  0.2f, 0.0f,  1.0f, 5.0f, 0.0f,
-0.5f,  0.2f, 0.0f,  1.0f, 5.0f, 0.0f,

-0.6f, 0.2f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 6
-0.5f,  0.2f, 0.0f,  1.0f, 5.0f, 0.0f,
-0.6f,  0.1f, 0.0f,  1.0f, 5.0f, 0.0f,

-0.5f, 0.2f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 7
-0.5f,  0.1f, 0.0f,  1.0f, 5.0f, 0.0f,
-0.6f,  0.1f, 0.0f,  1.0f, 5.0f, 0.0f,

-0.5f, 0.1f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 8
-0.6f,  0.1f, 0.0f,  1.0f, 5.0f, 0.0f,
-0.6f,  0.05f, 0.0f, 1.0f, 5.0f, 0.0f,

-0.5f, 0.0f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 9
-0.6f,  0.0f, 0.0f,  1.0f, 5.0f, 0.0f,
-0.6f,  0.05f, 0.0f, 1.0f, 5.0f, 0.0f,

-0.5f, 0.0f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 10
-0.6f,  0.0f, 0.0f,  1.0f, 5.0f, 0.0f,
-0.6f,  -0.1f, 0.0f, 1.0f, 5.0f, 0.0f,

-0.5f, 0.0f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 11
-0.6f,  -0.1f, 0.0f, 1.0f, 5.0f, 0.0f,
-0.5f,  -0.1f, 0.0f, 1.0f, 5.0f, 0.0f,

-0.5f, -0.1f, 0.0f,  1.0f, 5.0f, 0.0f,  // Triangulo 12
-0.6f,  -0.1f, 0.0f, 1.0f, 5.0f, 0.0f,
-0.6f,  -0.2f, 0.0f, 1.0f, 5.0f, 0.0f,

-0.7f, -0.2f, 0.0f,  1.0f, 5.0f, 0.0f,  // Triangulo 13
-0.6f,  -0.2f, 0.0f, 1.0f, 5.0f, 0.0f,
-0.6f,  -0.1f, 0.0f, 1.0f, 5.0f, 0.0f,

-0.6f, -0.1f, 0.0f,  1.0f, 5.0f, 0.0f,  // Triangulo 14
-0.7f,  -0.1f, 0.0f, 1.0f, 5.0f, 0.0f,
-0.7f,  -0.2f, 0.0f, 1.0f, 5.0f, 0.0f,

-0.7f, 0.0f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 15
-0.6f,  0.0f, 0.0f,  1.0f, 5.0f, 0.0f,
-0.6f,  0.1f, 0.0f,  1.0f, 5.0f, 0.0f,

-0.6f, 0.1f, 0.0f,   1.0f, 5.0f, 0.0f,  // Triangulo 16
-0.7f,  0.1f, 0.0f,  1.0f, 5.0f, 0.0f,
-0.7f,  0.0f, 0.0f,  1.0f, 5.0f, 0.0f,

		
	};

	MeshColor* letrab = new MeshColor();
	letrab->CreateMeshColor(vertices_letrab, 316);
	meshColorList.push_back(letrab);


	GLfloat vertices_letral[] = {
		// Triangulo 1
// Triangulo 1
-0.38f, 0.3f, 0.0f,   1.0f, 0.55f, 0.41f,
-0.3f, 0.3f, 0.0f,    1.0f, 0.55f, 0.41f,
-0.3f, -0.2f, 0.0f,   1.0f, 0.55f, 0.41f,

// Triangulo 2
-0.38f, 0.3f, 0.0f,   1.0f, 0.55f, 0.41f,
-0.38f, -0.2f, 0.0f,  1.0f, 0.55f, 0.41f,
-0.3f, -0.2f, 0.0f,   1.0f, 0.55f, 0.41f,

// Triangulo 3
-0.3f, -0.1f, 0.0f,   1.0f, 0.55f, 0.41f,
-0.1f, -0.2f, 0.0f,   1.0f, 0.55f, 0.41f,
-0.1f, -0.1f, 0.0f,   1.0f, 0.55f, 0.41f,

// Triangulo 4
-0.1f, -0.2f, 0.0f,   1.0f, 0.55f, 0.41f,
-0.3f, -0.1f, 0.0f,   1.0f, 0.55f, 0.41f,
-0.3f, -0.2f, 0.0f,   1.0f, 0.55f, 0.41f,



	};
	MeshColor* letral = new MeshColor();
	letral->CreateMeshColor(vertices_letral, 72);
	meshColorList.push_back(letral);


GLfloat vertices_letraF[] = {
// Triangulo 1
0.02f, 0.3f, 0.0f,  0.13f, 0.55f, 0.54f,
0.1f, 0.3f, 0.0f,   0.13f, 0.55f, 0.54f,
0.1f, -0.2f, 0.0f,  0.13f, 0.55f, 0.54f,

// Triangulo 2
0.02f, 0.3f, 0.0f,  0.13f, 0.55f, 0.54f,
0.02f, -0.2f, 0.0f, 0.13f, 0.55f, 0.54f,
0.1f, -0.2f, 0.0f,  0.13f, 0.55f, 0.54f,

// Triangulo 3
0.1f, 0.3f, 0.0f,   0.13f, 0.55f, 0.54f,
0.1f, 0.2f, 0.0f,   0.13f, 0.55f, 0.54f,
0.3f, 0.3f, 0.0f,   0.13f, 0.55f, 0.54f,

// Triangulo 4
0.3f, 0.3f, 0.0f,   0.13f, 0.55f, 0.54f,
0.3f, 0.2f, 0.0f,   0.13f, 0.55f, 0.54f,
0.1f, 0.2f, 0.0f,   0.13f, 0.55f, 0.54f,

// Triangulo 5
0.1f, 0.1f, 0.0f,   0.13f, 0.55f, 0.54f,
0.1f, 0.0f, 0.0f,   0.13f, 0.55f, 0.54f,
0.3f, 0.1f, 0.0f,   0.13f, 0.55f, 0.54f,

// Triangulo 6
0.3f, 0.0f, 0.0f,   0.13f, 0.55f, 0.54f,
0.3f, 0.1f, 0.0f,   0.13f, 0.55f, 0.54f,
0.1f, 0.0f, 0.0f,   0.13f, 0.55f, 0.54f,



	};
	MeshColor* letraF = new MeshColor();
	letraF->CreateMeshColor(vertices_letraF, 108);
	meshColorList.push_back(letraF);

	GLfloat vertices_letraR[] = {
		// Triangulo 1
		0.42f, 0.3f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.5f, 0.3f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.5f, -0.2f, 0.0f,   0.0f, 0.18f, 0.65f,

		// Triangulo 2
		0.42f, 0.3f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.42f, -0.2f, 0.0f,  0.0f, 0.18f, 0.65f,
		0.5f, -0.2f, 0.0f,   0.0f, 0.18f, 0.65f,

		// Triangulo 3
		0.5f, 0.3f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.5f, 0.2f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.7f, 0.3f, 0.0f,    0.0f, 0.18f, 0.65f,

		// Triangulo 4
		0.7f, 0.3f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.7f, 0.2f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.5f, 0.2f, 0.0f,    0.0f, 0.18f, 0.65f,

		// Triangulo 5
		0.5f, 0.1f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.5f, 0.0f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.7f, 0.1f, 0.0f,    0.0f, 0.18f, 0.65f,

		// Triangulo 6
		0.7f, 0.0f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.7f, 0.1f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.5f, 0.0f, 0.0f,    0.0f, 0.18f, 0.65f,

		// Triangulo 7
		0.7f, 0.2f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.75f, 0.2f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.7f, 0.1f, 0.0f,    0.0f, 0.18f, 0.65f,

		// Triangulo 8
		0.75f, 0.2f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.75f, 0.1f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.7f, 0.1f, 0.0f,    0.0f, 0.18f, 0.65f,

		// Triangulo 9
		0.75f, 0.2f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.7f, 0.2f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.7f, 0.3f, 0.0f,    0.0f, 0.18f, 0.65f,

		// Triangulo 10
		0.75f, 0.1f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.7f, 0.1f, 0.0f,    0.0f, 0.18f, 0.65f,
		0.7f, 0.05f, 0.0f,   0.0f, 0.18f, 0.65f,

		// Triangulo 11
		0.75f, 0.0f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.7f, 0.05f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.7f, 0.0f, 0.0f,    0.0f, 0.18f, 0.65f,

		// Triangulo 12
		0.65f, 0.0f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.75f, 0.0f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.75f, -0.2f, 0.0f,  0.0f, 0.18f, 0.65f,

		// Triangulo 13
		0.65f, 0.0f, 0.0f,   0.0f, 0.18f, 0.65f,
		0.65f, -0.2f, 0.0f,  0.0f, 0.18f, 0.65f,
		0.75f, -0.2f, 0.0f,  0.0f, 0.18f, 0.65f,



	};
	MeshColor* letraR = new MeshColor();
	letraR->CreateMeshColor(vertices_letraR, 234);
	meshColorList.push_back(letraR);

}


void CreateShaders()
{

	Shader *shader1 = new Shader(); //shader para usar índices: objetos: cubo y  pirámide
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);

	Shader *shader2 = new Shader();//shader para usar color como parte del VAO: letras 
	shader2->CreateFromFiles(vShaderColor, fShaderColor);
	shaderList.push_back(*shader2);

	Shader* shader3 = new Shader();//shader para usar color como parte del VAO: letras 
	shader3->CreateFromFiles(vShaderverde, fShaderColor);
	shaderList.push_back(*shader3);

	Shader* shader4 = new Shader();//shader para usar color como parte del VAO: letras 
	shader4->CreateFromFiles(vShaderazul, fShaderColor);
	shaderList.push_back(*shader4);

	Shader* shader5 = new Shader();//shader para usar color como parte del VAO: letras 
	shader5->CreateFromFiles(vShadercafe, fShaderColor);
	shaderList.push_back(*shader5);

	Shader* shader6 = new Shader();//shader para usar color como parte del VAO: letras 
	shader6->CreateFromFiles(vShaderverdezote, fShaderColor);
	shaderList.push_back(*shader6);

	Shader* shader7 = new Shader();//shader para usar color como parte del VAO: letras 
	shader7->CreateFromFiles(vShaderrojo, fShaderColor);
	shaderList.push_back(*shader7);

}


int main()
{
	mainWindow = Window(800, 800);
	mainWindow.Initialise();
	CreaPiramide();
	CrearLetrasyFiguras();
	CreaPiramideArbol();
	CrearCubo();
	Crearventana();
	Creartronco();
	//índice 1 en MeshList
	 //usa MeshColor, índices en MeshColorList
	CreateShaders();
	GLuint uniformProjection = 0;
	GLuint uniformModel = 0;
	//Projection: Matriz de Dimensión 4x4 para indicar si vemos en 2D( orthogonal) o en 3D) perspectiva
	glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
	//glm::mat4 projection = glm::perspective(glm::radians(45.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
	
	//Model: Matriz de Dimensión 4x4 en la cual se almacena la multiplicación de las transformaciones geométricas.
	glm::mat4 model(1.0); //fuera del while se usa para inicializar la matriz con una identidad
	
	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
		
													
		//Para las letras hay que usar el segundo set de shaders con índice 1 en ShaderList 
		shaderList[1].useShader();
		uniformModel = shaderList[1].getModelLocation();
		uniformProjection = shaderList[1].getProjectLocation();
		
		//Inicializar matriz de dimensión 4x4 que servirá como matriz de modelo para almacenar las transformaciones geométricas
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));	//Traslación para que los vértices en z positivo se vean en la pantalla
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA y se envían al shader como variables de tipo uniform
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[1]->RenderMeshColor();	//Se dibuja el triángulo azul 
		
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));	//Traslación para que los vértices en z positivo se vean en la pantalla
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA y se envían al shader como variables de tipo uniform
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[2]->RenderMeshColor();	//Se dibuja el triángulo azul 

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));	//Traslación para que los vértices en z positivo se vean en la pantalla
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA y se envían al shader como variables de tipo uniform
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[3]->RenderMeshColor();	//Se dibuja el triángulo azul 

		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));	//Traslación para que los vértices en z positivo se vean en la pantalla
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA y se envían al shader como variables de tipo uniform
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[4]->RenderMeshColor();	//Se dibuja el triángulo azul 



		/*/Para el cubo y la pirámide se usa el primer set de shaders con índice 0 en ShaderList
		shaderList[3].useShader();
		uniformModel = shaderList[3].getModelLocation();
		uniformProjection = shaderList[3].getProjectLocation();
		angulo += 0.01; 
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -0.25f, 0.0f));
		//model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));//gira en el eje y
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[0]->RenderMesh();
		//Cubo de la casa
		shaderList[6].useShader();
		uniformModel = shaderList[6].getModelLocation();
		uniformProjection = shaderList[6].getProjectLocation();
		angulo += 0.01;
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -0.25f, 0.0f));
		//model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));//gira en el eje y
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[2]->RenderMesh();

		//ventana 
		shaderList[2].useShader();
		uniformModel = shaderList[2].getModelLocation();
		uniformProjection = shaderList[2].getProjectLocation();
		angulo += 0.01;
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, -0.25f, 0.0f));
		//model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));//gira en el eje y
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[3]->RenderMesh();
		//ventana 1
		shaderList[2].useShader();
		uniformModel = shaderList[2].getModelLocation();
		uniformProjection = shaderList[2].getProjectLocation();
		angulo += 0.01;
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.25f, 0.25f, 0.0f));
		//model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));//gira en el eje y
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[3]->RenderMesh();

		//ventana 2
		shaderList[2].useShader();
		uniformModel = shaderList[2].getModelLocation();
		uniformProjection = shaderList[2].getProjectLocation();
		angulo += 0.01;
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.25f, 0.25f, 0.0f));
		//model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));//gira en el eje y
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[3]->RenderMesh();
		//Pico pino 1
		shaderList[5].useShader();
		uniformModel = shaderList[5].getModelLocation();
		uniformProjection = shaderList[5].getProjectLocation();
		angulo += 0.01;
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.8f, -0.4f, 0.0f));
		//model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));//gira en el eje y
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();
		
		//Pico pino 2
		shaderList[5].useShader();
		uniformModel = shaderList[5].getModelLocation();
		uniformProjection = shaderList[5].getProjectLocation();
		angulo += 0.01;
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.8f, -0.4f, 0.0f));
		//model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));//gira en el eje y
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[1]->RenderMesh();

		//tronco 
		shaderList[4].useShader();
		uniformModel = shaderList[4].getModelLocation();
		uniformProjection = shaderList[4].getProjectLocation();
		angulo += 0.01;
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(-0.8f, -0.25f, 0.0f));
		//model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));//gira en el eje y
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[4]->RenderMesh();

		//tronco 2
		shaderList[4].useShader();
		uniformModel = shaderList[4].getModelLocation();
		uniformProjection = shaderList[4].getProjectLocation();
		angulo += 0.01;
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.8f, -0.25f, 0.0f));
		//model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));//gira en el eje y
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshList[4]->RenderMesh();*/

		
		glUseProgram(0);
		mainWindow.swapBuffers();

	}
	return 0;
}
// inicializar matriz: glm::mat4 model(1.0);
// reestablecer matriz: model = glm::mat4(1.0);
//Traslación
//model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));
//////////////// ROTACIÓN //////////////////
//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
////////////////  ESCALA ////////////////
//model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
///////////////////// T+R////////////////
/*model = glm::translate(model, glm::vec3(valor, 0.0f, 0.0f));
model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));
*/
/////////////R+T//////////
/*model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::translate(model, glm::vec3(valor, 0.0f, 0.0f));
*/