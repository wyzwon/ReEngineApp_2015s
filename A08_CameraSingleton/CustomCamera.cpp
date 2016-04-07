#include "CustomCamera.h"



void CustomCamera::initVariables()
{
	glm::quat identity;
	CameraTransform = IDENTITY_M4;

	target = glm::vec3(0.0f, 0.0f, 0.0f);
	cameraOrtho = false;
	CameraPosition = vector3(-10.0f, 0.0f, 0.0f);
	cameraProjection = IDENTITY_M4;
	
}

matrix4 CustomCamera::getView()
{
	return cameraView;
}

matrix4 CustomCamera::getProjection(bool bOrthographic)
{
	if (bOrthographic) //orthographic
	{
		cameraOrtho = true;
		return cameraView;
	}
	else
	{
		cameraOrtho = false;
		return cameraView;
	}
	
}

void CustomCamera::setPosition(glm::vec3 newPosition)
{
	//glm::translate(CameraTransform, newPosition);
	CameraPosition = newPosition;
}

void CustomCamera::setTarget(glm::vec3 newTarget)
{
	target = newTarget;
}

void CustomCamera::setUp(glm::vec3 newUp)
{
	CameraUp = glm::rotate(CameraForward, 90.0f, vector3(1, 0, 0));
}

void CustomCamera::moveForward(float floatIncrement)
{
	CameraPosition += (forward * floatIncrement);
}

void CustomCamera::moveSideways(float floatIncrement)
{
	vector3 sidways = glm::rotate(CameraForward, 90.0f, vector3(0, 1, 0));
	CameraPosition += (sidways * floatIncrement);
}

void CustomCamera::moveVerticle(float floatIncrement)
{
	vector3 sidways = glm::rotate(CameraForward, 90.0f, vector3(1, 0, 0));
	CameraPosition += (sidways * floatIncrement);
}

void CustomCamera::ChangePitch(float floatIncrement)
{
	glm::quat rotationMat;

	glm::mat4x4 posXrot = glm::mat4x4(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.9993f, -0.0348f, 0.0f,
		0.0f, 0.0348, 0.9993, 0.0f,
		1.0f, 1.0f, 1.0f, 1.0f);


	/*CameraTransform *= glm::mat4x4(
	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.9993f, -0.0348f, 0.0f,
	0.0f, 0.0348, 0.9993, 0.0f,
	1.0f, 1.0f, 1.0f, 1.0f);*/

	//rotationMat = glm::rotateX(

	rotationMat = glm::angleAxis((float)(PI / 180), vector3(rotationMat.x));
}

void CustomCamera::updateforward()
{
	CameraForward = glm::normalize(target - CameraPosition);
}

glm::mat4x4 CustomCamera::getPosition()
{
	//return glm::
}




//CustomCamera::CustomCamera()
//{
//
//}


//CustomCamera::~CustomCamera()
//{
//}
