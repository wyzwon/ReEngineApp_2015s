/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@rit.edu)
Date: 2015/08
Notes: This is a simplified version of MeshClass
inside of ReEng.dll, its stripped out of a lot
of functionality in order to focuss on important
concepts of OpenGL, please use a MeshClass object
for better functionality.
----------------------------------------------*/
#ifndef __MYMESH_H_
#define __MYMESH_H_

#include "RE\ReEng.h"

//System Class
class MyMesh
{
protected:
	bool m_bBinded = false; //Binded flag
	int m_nVertexCount = 0; //Number of Vertices in this Mesh

	GLuint m_vao = 0;			//OpenGL Vertex Array Object
	GLuint m_VertexBuffer = 0;	//OpenGL Buffer (Will hold the vertex buffer pointer)
	GLuint m_ColorBuffer = 0;	//OpenGL Buffer (Will hold the color buffer pointer)

	ShaderManagerSingleton* m_pShaderMngr = nullptr;	//Shader Manager

	std::vector<vector3> m_lVertexPos;	//List of Vertices
	std::vector<vector3> m_lVertexCol;	//List of Colors

public:
	/*
	USAGE: Constructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	MyMesh(void);
	/*
	USAGE: Copy Constructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	MyMesh(MyMesh const& other);
	/*
	USAGE: Copy Assignment Operator
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	MyMesh& operator=(MyMesh const& other);
	/*
	USAGE: Destructor
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	~MyMesh(void);
	/*
	USAGE: Swaps the contents of the object with another object's content
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void Swap(MyMesh& other);
	/*
	USAGE: Compiles the Mesh for OpenGL 3.X use
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void CompileOpenGL3X(void);
	/*
	USAGE: Returns the total number of vertices in this Mesh
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	int GetVertexTotal(void);
	/*
	USAGE: Adds a new point to the vector of vertices
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void AddVertexPosition(vector3 a_v3Input);
	/*
	USAGE: Adds a new color to the vector of vertices
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void AddVertexColor(vector3 a_v3Input);
	/*
	USAGE: Renders the shape
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void RenderList(matrix4 a_mProjectionMatrix, matrix4 a_mViewMatrix, float* a_fMatrixArray, int a_nInstances);
	/*
	USAGE: Renders the shape asking for its position in the world and a color
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void Render(matrix4 a_mProjectionMatrix, matrix4 a_mViewMatrix, matrix4 a_mToWorld = IDENTITY_M4);

protected:
	/*
	USAGE: Initialize the object's fields
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void Init(void);
	/*
	USAGE: Releases the object from memory
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	virtual void Release(void);
	/*
	USAGE: Completes the information missing to create the mesh
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void CompleteMesh(void);

public:
	/*
	USAGE: Completes the triangle information
	ARGUMENTS: ---
	OUTPUT: ---
	*/
	void CompleteTriangleInfo(void);
};
/*
USAGE
ARGUMENTS: ---
OUTPUT: ---
*/
#endif //__MYMESH_H_