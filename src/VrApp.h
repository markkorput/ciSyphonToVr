#pragma once

// EANBLE VR ON WINDOWS
// #ifdef CINDER_MSW
  #define VR_ENABLED
// #endif

#ifdef VR_ENABLED
  #include "cinder/vr/Vr.h"
  // VR implementation based on;
  // https://gist.github.com/lithium-snepo/772eddede79b960666e521a8d1789d9c
  // and Cinder-VR block's Basic samples
#endif

#include "cinder/CameraUi.h"
#include "cinder/app/App.h"

class VrApp {

public:
  VrApp();
  void setup();
  void update();
  void draw();

  #ifdef VR_ENABLED
    void setMirroredMode(int mode);
  #endif

  void mouseDown(ci::app::MouseEvent event);
  void mouseDrag(ci::app::MouseEvent event);
  void keyDown(ci::app::KeyEvent event);

  // ci::Camera* getActiveCamera(){
  //   #ifdef VR_ENABLED
  //     if(this->mHmd)
  //       return &this->getEyeCamera(ci::vr::EYE_HMD);
  //   #endif
  //   return &this->mCam;
  // }
public: // signals

  ci::signals::Signal<void(void)>
    renderSceneSignal,
    renderVrSignal,
    renderNoVrSignal;

private: // attributes

  #ifdef VR_ENABLED
    ci::vr::Context* mVrContext = nullptr;
    ci::vr::Hmd* mHmd = nullptr;
    const ci::vr::Controller* pController = NULL;

    // Only applies to HTC Vive with standing tracking origin
    bool mRecalcOrigin = false;
    bool drawMirrored = true;
  #endif

  // when VR is not available, we'll use CamerUI to
  // let the user rotate the camera using the mouse
  ci::CameraPersp mCam;
  ci::CameraUi mCamUi;
};
