#include "MyPrimitive.h"
MyPrimitive::MyPrimitive() { }
MyPrimitive::MyPrimitive(const MyPrimitive& other) { }
MyPrimitive& MyPrimitive::operator=(const MyPrimitive& other) { return *this; }
MyPrimitive::~MyPrimitive(void) { super::Release(); }
void MyPrimitive::CompileObject(vector3 a_v3Color)
{
	m_uVertexCount = static_cast<int> (m_lVertexPos.size());
	for (uint i = 0; i < m_uVertexCount; i++)
	{
		AddVertexColor(a_v3Color);
	}
	
	CompleteTriangleInfo(true);
	CompileOpenGL3X();

}
//C--D
//|\ |
//| \|
//A--B
//This will make the triang A->B->C and then the triang C->B->D
void MyPrimitive::AddQuad(vector3 a_vBottomLeft, vector3 a_vBottomRight, vector3 a_vTopLeft, vector3 a_vTopRight)
{
	AddVertexPosition(a_vBottomLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopLeft);

	AddVertexPosition(a_vTopLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopRight);
}
void MyPrimitive::GeneratePlane(float a_fSize, vector3 a_v3Color)
{
	if (a_fSize < 0.01f)
		a_fSize = 0.01f;

	Release();
	Init();

	float fValue = 0.5f * a_fSize;

	vector3 pointA(-fValue, -fValue, 0.0f); //0
	vector3 pointB(fValue, -fValue, 0.0f); //1
	vector3 pointC(fValue, fValue, 0.0f); //2
	vector3 pointD(-fValue, fValue, 0.0f); //3

	vector3 pointE(fValue, -fValue, -0.001f); //1
	vector3 pointF(-fValue, -fValue, -0.001f); //0
	vector3 pointG(fValue, fValue, -0.001f); //2
	vector3 pointH(-fValue, fValue, -0.001f); //3

											  //F
	AddQuad(pointA, pointB, pointD, pointC);
	//Double sided
	AddQuad(pointE, pointF, pointG, pointH);

	CompileObject(a_v3Color);
}
void MyPrimitive::GenerateCube(float a_fSize, vector3 a_v3Color)
{
	if (a_fSize < 0.01f)
		a_fSize = 0.01f;

	Release();
	Init();

	float fValue = 0.5f * a_fSize;
	//3--2
	//|  |
	//0--1
	vector3 point0(-fValue, -fValue, fValue); //0
	vector3 point1(fValue, -fValue, fValue); //1
	vector3 point2(fValue, fValue, fValue); //2
	vector3 point3(-fValue, fValue, fValue); //3

	vector3 point4(-fValue, -fValue, -fValue); //4
	vector3 point5(fValue, -fValue, -fValue); //5
	vector3 point6(fValue, fValue, -fValue); //6
	vector3 point7(-fValue, fValue, -fValue); //7

	//F
	AddQuad(point2, point3, point1, point0);

	//B
	AddQuad(point7, point6, point4, point5);

	//L
	AddQuad(point4, point0, point7, point3);

	//R
	AddQuad(point1, point5, point2, point6);

	//U
	AddQuad(point3, point2, point7, point6);

	//D
	AddQuad(point4, point5, point0, point1);

	CompileObject(a_v3Color);
}
void MyPrimitive::GenerateCone(float a_fRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	//Your code starts here
	float fValue = 0.5f;
	//3--2
	//|  |
	//0--1
	
	
	vector3 pointList[360] = {}; //I apologize for this, I got fed up trying to find a data structure that worked dynamically with vector3s
	

	vector3 point0a(0, a_fHeight, 0); //top point
	vector3 point1a(0, -a_fHeight, 0); //bottom point

	float rotateBy = ((PI/ 180) * (360 / a_nSubdivisions));
	for (int i = 0; i < a_nSubdivisions; i++)
	{
		float x = a_fRadius*cos(rotateBy * i);
		float z = a_fRadius*sin(rotateBy * i);
		pointList[i] = vector3(x, -a_fHeight, z);
	
	}

	


	//Cone walls
	for (int i = 0; i < a_nSubdivisions; i++) {
		AddQuad(point0a, pointList[i], pointList[i + 1], point0a);
	}
	AddQuad(point0a, pointList[a_nSubdivisions - 1], pointList[0], point0a);

	//cone floor
	for (int i = 0; i < a_nSubdivisions; i++) {
		AddQuad(point1a, pointList[i], pointList[i + 1], point1a);
	}
	AddQuad(point1a, pointList[a_nSubdivisions - 1], pointList[0], point1a);


	//vector3 point0(-fValue, -fValue, fValue); //0
	//vector3 point1(fValue * 20, -fValue, fValue); //1
	//vector3 point2(fValue, fValue, fValue); //2
	//vector3 point3(-fValue, fValue, fValue); //3
	//
	//AddQuad(point0, point1, point3, point2);
	//AddQuad(point0a, tree[1], tree[0], point1a);

	//Your code ends here
	CompileObject(a_v3Color);
}
void MyPrimitive::GenerateCylinder(float a_fRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	//Your code starts here
	float fValue = 0.5f;
	//3--2
	//|  |
	//0--1
	vector3 bottomPointList[360] = {}; 
	vector3 topPointList[360] = {};


	vector3 pointTopCenter(0, a_fHeight, 0); //top point
	vector3 pointBottomCenter(0, -a_fHeight, 0); //bottom point

	//bottom points
	float rotateBy = ((PI / 180) * (360 / a_nSubdivisions));
	for (int i = 0; i < a_nSubdivisions; i++)
	{
		float x = a_fRadius*cos(rotateBy * i);
		float z = a_fRadius*sin(rotateBy * i);
		bottomPointList[i] = vector3(x, -a_fHeight, z);

	}

	//top points
	for (int i = 0; i < a_nSubdivisions; i++)
	{
		float x = a_fRadius*cos(rotateBy * i);
		float z = a_fRadius*sin(rotateBy * i);
		topPointList[i] = vector3(x, a_fHeight, z);

	}

	//cone floor
	for (int i = 0; i < a_nSubdivisions; i++) {
		AddQuad(pointBottomCenter, bottomPointList[i], bottomPointList[i + 1], pointBottomCenter);
	}
	AddQuad(pointBottomCenter, bottomPointList[a_nSubdivisions - 1], bottomPointList[0], pointBottomCenter);


	//cone roof
	for (int i = 0; i < a_nSubdivisions; i++) {
		AddQuad(pointTopCenter, topPointList[i], topPointList[i + 1], pointTopCenter);
	}
	AddQuad(pointTopCenter, topPointList[a_nSubdivisions - 1], topPointList[0], pointTopCenter);

	//wall
	//up pointing triangles
	for (int i = 0; i < a_nSubdivisions; i++) {
		AddQuad(topPointList[i], bottomPointList[i],bottomPointList[i+1] , topPointList[i + 1]);
	}
	AddQuad(topPointList[a_nSubdivisions - 1], bottomPointList[a_nSubdivisions - 1], bottomPointList[0], topPointList[0]);

	//down pointing triangles
	for (int i = 0; i < a_nSubdivisions; i++) {
		AddQuad(bottomPointList[i], topPointList[i], topPointList[i + 1], bottomPointList[i + 1]);
	}
	AddQuad(bottomPointList[a_nSubdivisions - 1], topPointList[a_nSubdivisions - 1], topPointList[0], bottomPointList[0]);

	//vector3 point0(-fValue, -fValue, fValue); //0
	//vector3 point1(fValue, -fValue, fValue); //1
	//vector3 point2(fValue, fValue, fValue); //2
	//vector3 point3(-fValue, fValue, fValue); //3
	//
	//AddQuad(point0, point1, point3, point2);
	
	//Your code ends here
	CompileObject(a_v3Color);
}
void MyPrimitive::GenerateTube(float a_fOuterRadius, float a_fInnerRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	//Your code starts here
	float fValue = 0.5f;
	//3--2
	//|  |
	//0--1
	vector3 point0(-fValue, -fValue, fValue); //0
	vector3 point1(fValue, -fValue, fValue); //1
	vector3 point2(fValue, fValue, fValue); //2
	vector3 point3(-fValue, fValue, fValue); //3

	AddQuad(point0, point1, point3, point2);

	//Your code ends here
	CompileObject(a_v3Color);
}
void MyPrimitive::GenerateTorus(float a_fOuterRadius, float a_fInnerRadius, int a_nSubdivisionsA, int a_nSubdivisionsB, vector3 a_v3Color)
{
	if (a_fOuterRadius <= a_fInnerRadius + 0.1f)
		return;

	if (a_nSubdivisionsA < 3)
		a_nSubdivisionsA = 3;
	if (a_nSubdivisionsA > 25)
		a_nSubdivisionsA = 25;

	if (a_nSubdivisionsB < 3)
		a_nSubdivisionsB = 3;
	if (a_nSubdivisionsB > 25)
		a_nSubdivisionsB = 25;

	Release();
	Init();

	//Your code starts here
	float fValue = 0.5f;
	//3--2
	//|  |
	//0--1
	vector3 point0(-fValue, -fValue, fValue); //0
	vector3 point1(fValue, -fValue, fValue); //1
	vector3 point2(fValue, fValue, fValue); //2
	vector3 point3(-fValue, fValue, fValue); //3

	AddQuad(point0, point1, point3, point2);

	//Your code ends here
	CompileObject(a_v3Color);
}
void MyPrimitive::GenerateSphere(float a_fRadius, int a_nSubdivisions, vector3 a_v3Color)
{
	//Sets minimum and maximum of subdivisions
	if (a_nSubdivisions < 1)
	{
		GenerateCube(a_fRadius * 2, a_v3Color);
		return;
	}
	if (a_nSubdivisions > 6)
		a_nSubdivisions = 6;

	Release();
	Init();

	//Your code starts here
	float fValue = 0.5f;
	//3--2
	//|  |
	//0--1
	vector3 point0(-fValue, -fValue, fValue); //0
	vector3 point1(fValue, -fValue, fValue); //1
	vector3 point2(fValue, fValue, fValue); //2
	vector3 point3(-fValue, fValue, fValue); //3

	AddQuad(point0, point1, point3, point2);

	//Your code ends here
	CompileObject(a_v3Color);
}