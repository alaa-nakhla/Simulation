#pragma once
#include "camera.h"
#include "thirdpersoncamera.h"
#include "firstpersoncamera.h"

class Cameras
{
public:
	Cameras();

	void keyPress(unsigned char key);
	void addCamera(std::string str, Camera* camera);

	CameraMap  theCameras;
	Camera*    currentCamera;
};
