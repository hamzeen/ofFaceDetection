#include "testApp.h"
#include "ofAppGlutWindow.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 360, 340, OF_WINDOW);
	ofRunApp(new testApp());
}
