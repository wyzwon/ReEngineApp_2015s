#ifndef __THISAPP_H_
#define __THISAPP_H_

#include <SFML\Graphics.hpp>
#include "RE\ReEngAppClass.h"

using namespace ReEng;

class CustomCamera
{
public:
	quaternion CameraTransform;
	matrix4 cameraView;
	matrix4 cameraProjection;
	bool cameraOrtho;
	vector3 CameraPosition;
	glm::vec3 target;
	glm::vec3 forward;
	vector3 CameraForward;
	vector3 CameraUp;
	vector3 CameraRight;


	CustomCamera(void) {}

	~CustomCamera(void) {}

	matrix4 CustomCamera::getView();

	matrix4 CustomCamera::getProjection(bool bOrthographic);

	void CustomCamera::updateforward();

	void CustomCamera::initVariables();

	void CustomCamera::setPosition(glm::vec3 newPosition);

	void CustomCamera::setTarget(glm::vec3 newTarget);

	void CustomCamera::setUp(glm::vec3 newUp);

	void CustomCamera::moveForward(float floatIncrement);

	void CustomCamera::moveSideways(float floatIncrement);

	void CustomCamera::moveVerticle(float floatIncrement);

	void CustomCamera::ChangePitch(float floatIncrement);

	glm::mat4x4 CustomCamera::getPosition();

	
};

#endif //__THISAPP_H_