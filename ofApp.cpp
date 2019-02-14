#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	for (auto scale = 1; scale < 20; scale += 1) {

		vector<glm::vec2> vertices;
		auto param = (ofGetFrameNum() * 2 + scale * 20) % 720;
		for (auto deg = 0; deg < 360; deg += 1) {

			if (param < 360) {

				if (deg < param) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
			}
			else {

				if (deg > param - 360) { vertices.push_back(this->make_point(deg * DEG_TO_RAD) * scale); }
			}

			if (deg == param % 360) {

				ofFill();
				ofDrawCircle(this->make_point(deg * DEG_TO_RAD) * scale, 3);
			}
		}

		ofNoFill();
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape();
	}
}

//--------------------------------------------------------------
//Reference by https://twitter.com/shiffman/status/1095764239665512453
glm::vec2 ofApp::make_point(float theta) {

	float x = 16 * (pow(sin(theta), 3));
	float y = 13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta);
	return glm::vec2(x, -y);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}