#pragma once
#include <string>
#include "ofMain.h"
#include "guiVoyageurEspace.h"
#include "GrapheScene.h"
#include "modele3D.h"
#include "firstPersonneCam.h"
#include "PerspectiveCam.h"
#include "thirdPersonneCam.h"
#include "Player.h"

class ofApp : public ofBaseApp{
	private:
		static const std::string XN;
		static const std::string XP;
		static const std::string YN;
		static const std::string YP;
		static const std::string ZN;
		static const std::string ZP;

		GrapheScene* graphe_scene;
		IElementDessinable* gui;
		IElementDessinable* sun;
		IElementDessinable* earth;
		IElementDessinable* moon;
		IElementDessinable* cubemap;
		IElementDessinable* vaisseau;
		ofLight light;
		ofCamera cam;
		firstPersonneCam fp_cam;
		PerspectiveCam pers_cam;
		thirdPersonneCam td_cam;
		Player player_fp;
		Player player_td;

		bool fp_cam_enabled;
		bool td_cam_enabled;

	public:
		void setup();
		void update();
		void draw();
		void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
};
