#include "CustomCamera.h"



void CustomCamera::initVariables()
{
	CameraTransform = quaternion::tquat(IDENTITY_M4);

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
	vector3 upways = glm::rotate(CameraForward, 90.0f, vector3(0, 0, 1));
	CameraPosition += (upways * floatIncrement);
}

void CustomCamera::ChangePitch(float floatIncrement)
{
	//glm::rotate(CameraTransform, floatIncrement, forward);

	CameraTransform = glm::angleAxis(floatIncrement, CameraForward);
}

void CustomCamera::ChangeRoll(float floatIncrement)
{
	vector3 sidways = glm::rotate(CameraForward, 90.0f, vector3(0, 1, 0));
	CameraTransform = glm::angleAxis(floatIncrement, sidways);
}

void CustomCamera::ChangeYaw(float floatIncrement)
{
	//glm::quat rotationMat;
	vector3 upways = glm::rotate(CameraForward, 90.0f, vector3(0, 0, 1));

	CameraTransform = glm::angleAxis(floatIncrement, upways);
}

void CustomCamera::updateforward()
{
	CameraForward = glm::normalize(target - CameraPosition);
}




//CustomCamera::CustomCamera()
//{
//
//}


//CustomCamera::~CustomCamera()
//{
//}