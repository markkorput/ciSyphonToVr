// cinder
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/CameraUi.h"
// cinder blocks
#include "cinderSyphon.h"
// local
#include "VrApp.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MainApp : public App {
public:
  // MainApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(KeyEvent event) override;

private:
  void createScenes();
  void drawScene();
  void drawDebugToFbo();
  void activateScene(int idx);

  VrApp vrApp;
  ci::Timer timer;
  syphonClient mClientSyphon;
};

void MainApp::setup() {
  // setWindowSize( 1280, 480 );
  vrApp.setup();
  vrApp.renderSceneSignal.connect([this](){ this->drawScene(); });

  mClientSyphon.set("", "Simple Server");
}

void MainApp::update() {
  auto dt = this->timer.getSeconds();
  this->timer.start();
}

void MainApp::draw() {
  gl::clear( Color( 0, 0, 0 ) );
  vrApp.draw(); // this will trigger our drawScene method (which was registered in our setup method)

  gl::draw(mClientSyphon.getTexture());
}

void MainApp::drawScene(){
  // sceneSystemRef->draw(this->entities);
}

void MainApp::keyDown(KeyEvent event){
  // switch(event.getChar()){
  // }
}

CINDER_APP( MainApp, RendererGl )
